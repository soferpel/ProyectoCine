#include <stdio.h>
#include <winsock2.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"
#include "baseDeDatos.h"
#include "configuracion.h"
#include "logger.h"

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 6000
#define MAX_DATA_SIZE 4096

int main(int argc, char *argv[]) 
{

	Logger *logger = logger_init("server.log", LOG_INFO);
    if (!logger) {
        return -1;
    }
    logger_log(logger, LOG_INFO, "Server starting...");

    PathDB rutaDB = leerConfiguracion("configuracion.txt");
	WSADATA wsaData;
	SOCKET conn_socket;
	SOCKET comm_socket;
	struct sockaddr_in server;
	struct sockaddr_in client;
	char sendBuff[512], recvBuff[512];

	logger_log(logger, LOG_INFO, "Initialising Winsock...");
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        logger_log(logger, LOG_ERROR, "Failed to initialize Winsock. Error Code: %d", WSAGetLastError());
        logger_close(logger);
        return -1;
    }

	logger_log(logger, LOG_INFO, "Winsock initialized.");

	//SOCKET creation
	if ((conn_socket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        logger_log(logger, LOG_ERROR, "Could not create socket: %d", WSAGetLastError());
        WSACleanup();
        logger_close(logger);
        return -1;
    }

	logger_log(logger, LOG_INFO, "Socket created.");

	server.sin_addr.s_addr = inet_addr(SERVER_IP);
	server.sin_family = AF_INET;
	server.sin_port = htons(SERVER_PORT);

	//BIND (the IP/port with socket)
	if (bind(conn_socket, (struct sockaddr*)&server, sizeof(server)) == SOCKET_ERROR) {
        logger_log(logger, LOG_ERROR, "Bind failed with error code: %d", WSAGetLastError());
        closesocket(conn_socket);
        WSACleanup();
        logger_close(logger);
        return -1;
    }

	logger_log(logger, LOG_INFO, "Bind done.");

	//LISTEN to incoming connections (socket server moves to listening mode)
	if (listen(conn_socket, 1) == SOCKET_ERROR) {
        logger_log(logger, LOG_ERROR, "Listen failed with error code: %d", WSAGetLastError());
        closesocket(conn_socket);
        WSACleanup();
        logger_close(logger);
        return -1;
    }

	logger_log(logger, LOG_INFO, "Waiting for incoming connections...");
    int stsize = sizeof(struct sockaddr);
    comm_socket = accept(conn_socket, (struct sockaddr*)&client, &stsize);
    if (comm_socket == INVALID_SOCKET) {
        logger_log(logger, LOG_ERROR, "Accept failed with error code: %d", WSAGetLastError());
        closesocket(conn_socket);
        WSACleanup();
        logger_close(logger);
        return -1;
    }

	logger_log(logger, LOG_INFO, "Incoming connection from: %s (%d)", inet_ntoa(client.sin_addr), ntohs(client.sin_port));

	// Closing the listening sockets (is not going to be used anymore)
	closesocket(conn_socket);

    logger_log(logger, LOG_INFO, "Waiting for incoming commands from client...");

    do
    {
        memset(recvBuff, 0, sizeof(recvBuff));
        int recv_size = recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
        if (recv_size == SOCKET_ERROR) {
            logger_log(logger, LOG_ERROR, "recv failed with error code: %d", WSAGetLastError());
            break;
        } else if (recv_size == 0) {
            logger_log(logger, LOG_INFO, "Client disconnected");
            break;
        }

        logger_log(logger, LOG_INFO, "Command received: %s", recvBuff);

		if(strcmp(recvBuff, "CREARTABLAS") == 0)
		{
			crearTabla(rutaDB, logger);
			logger_log(logger, LOG_INFO, "Tabla creada.");
		}

		if(strcmp(recvBuff, "RESETEARBD") == 0)
		{
			borrarTablas(rutaDB, logger);
			logger_log(logger, LOG_INFO, "BD BORRADA");
		}

        if (strcmp(recvBuff, "INICIARSESION") == 0)
		{
            recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
            strcpy(usuario.correo, recvBuff);
            
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
            strcpy(usuario.contrasena, recvBuff);

            validarUsuario(rutaDB, logger);
            
            sprintf(sendBuff, "%i", validacionUsuario);
			send(comm_socket, sendBuff, sizeof(sendBuff), 0);
			logger_log(logger, LOG_INFO, "Response sent: %s", sendBuff);
        }

		if (strcmp(recvBuff, "REGISTRARSE") == 0)
		{
            recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			strcpy(usuario.nombre, recvBuff);

			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			strcpy(usuario.correo, recvBuff);

			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);		
			strcpy(usuario.contrasena, recvBuff);
			
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			strcpy(usuario.respuesta, recvBuff);
			
			guardarUsuario(rutaDB, logger);

			sprintf(sendBuff, "%i", validacionUsuario);
			send(comm_socket, sendBuff, sizeof(sendBuff), 0);
			printf("Response sent: %s \n", sendBuff);
			logger_log(logger, LOG_INFO, "Response sent: %s", sendBuff);
		}

		if(strcmp(recvBuff, "MODIFICARPELICULA") == 0)
		{
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			pelicula.idPeliculaInt = atoi(recvBuff);
			
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			sala.idSalaInt = atoi(recvBuff);
			
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			strcpy(pelicula.titulo, recvBuff);
			
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			strcpy(pelicula.sinopsis, recvBuff);
			
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			strcpy(pelicula.horario, recvBuff);

			modificarPelicula(rutaDB, logger);
			
			sprintf(sendBuff, "%i", hayQueModificarDatos);
			send(comm_socket, sendBuff, sizeof(sendBuff), 0);
			logger_log(logger, LOG_INFO, "Response sent: %s", sendBuff);
		
		}

		if(strcmp(recvBuff, "MODIFICARUSUARIO") == 0)
		{
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			strcpy(usuario.nombre, recvBuff);

			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			strcpy(usuario.correo, recvBuff);

			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);	
			strcpy(usuario.contrasena, recvBuff);

			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);	
			strcpy(usuario.respuesta, recvBuff);
				
			modificarUsuario(rutaDB, logger);
		}

		if(strcmp(recvBuff, "MODIFICARCINE") == 0)
		{
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			cine.idCineInt = atoi(recvBuff);
			
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			strcpy(cine.nombreCine, recvBuff);
			
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			strcpy(cine.direccionCine, recvBuff);
			
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			strcpy(cine.ciudadCine, recvBuff);
			
			modificarCine(rutaDB, logger);
			
			sprintf(sendBuff, "%i", hayQueModificarDatos);
			send(comm_socket, sendBuff, sizeof(sendBuff), 0);
			logger_log(logger, LOG_INFO, "Response sent: %s", sendBuff);
		}

		if(strcmp(recvBuff, "MODIFICARACTOR") == 0)
		{
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			actor.idActorInt = atoi(recvBuff);
			
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			strcpy(actor.nombreActor, recvBuff);
			
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			pelicula.idPeliculaInt = atoi(recvBuff);
			
			modificarActor(rutaDB, logger);
			
			sprintf(sendBuff, "%i", hayQueModificarDatos);
			send(comm_socket, sendBuff, sizeof(sendBuff), 0);
			logger_log(logger, LOG_INFO, "Response sent: %s", sendBuff);
		}

		if(strcmp(recvBuff, "MODIFICARASIENTO") == 0)
		{
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			asiento.idAsientoInt = atoi(recvBuff);
			
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			asiento.filaAsientoInt = atoi(recvBuff);
			
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			asiento.numeroAsientoInt = atoi(recvBuff);
			
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			strcpy(asiento.fechaAsiento, recvBuff);
			
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			sala.idSalaInt = atoi(recvBuff);

			modificarAsiento(rutaDB, logger);
			
			sprintf(sendBuff, "%i", hayQueModificarDatos);
			send(comm_socket, sendBuff, sizeof(sendBuff), 0);
			logger_log(logger, LOG_INFO, "Response sent: %s", sendBuff);
		}

		if(strcmp(recvBuff, "MODIFICARSALA") == 0)
		{
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			sala.idSalaInt = atoi(recvBuff);
			
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			sala.numeroSalaInt = atoi(recvBuff);

			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			sala.nColumnasSalaInt = atoi(recvBuff);

			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			sala.nFilasSalaInt = atoi(recvBuff);

			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			cine.idCineInt = atoi(recvBuff);

			modificarSala(rutaDB, logger);

			sprintf(sendBuff, "%i", hayQueModificarDatos);
			send(comm_socket, sendBuff, sizeof(sendBuff), 0);
			logger_log(logger, LOG_INFO, "Response sent: %s", sendBuff);
		}
		
		if (strcmp(recvBuff, "BORRARDATOS") == 0)
		{
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			strcpy(tablaEliminar, recvBuff);
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			strcpy(idEliminar, recvBuff);
			eliminarFila(rutaDB, logger);
		}

		if (strcmp(recvBuff, "ANADIRASIENTO") == 0)
		{
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			strcpy(asiento.fechaAsiento, recvBuff);
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			asiento.filaAsientoInt = atoi(recvBuff);
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			sala.idSalaInt = atoi(recvBuff);
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			asiento.numeroAsientoInt = atoi(recvBuff);
			anadirAsiento(rutaDB, logger);
		}

		if (strcmp(recvBuff, "ANADIRPELICULA") == 0)
		{
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			strcpy(pelicula.horario, recvBuff);
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			cine.idCineInt = atoi(recvBuff);
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			strcpy(pelicula.sinopsis, recvBuff);
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			strcpy(pelicula.titulo, recvBuff);
			anadirPelicula(rutaDB, logger);
		}

		if (strcmp(recvBuff, "ANADIRACTOR") == 0)
		{
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			pelicula.idPeliculaInt = atoi(recvBuff);
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			strcpy(actor.nombreActor, recvBuff);
			anadirActor(rutaDB, logger);
		}

		if (strcmp(recvBuff, "ANADIRCINE") == 0)
		{
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			strcpy(cine.ciudadCine, recvBuff);
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			strcpy(cine.direccionCine, recvBuff);
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			strcpy(cine.nombreCine, recvBuff);
			anadirCine(rutaDB, logger);
		}

		if (strcmp(recvBuff, "ANADIRSALA") == 0)
		{
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			cine.idCineInt = atoi(recvBuff);
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			sala.nColumnasSalaInt = atoi(recvBuff);
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			sala.nFilasSalaInt = atoi(recvBuff);
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			sala.numeroSalaInt = atoi(recvBuff);
			anadirSala(rutaDB, logger);
		}

		if (strcmp(recvBuff, "VISUALIZARDATOS") == 0)
		{
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			strcpy(tablaVisualizar, recvBuff);

			char dataBuffer[MAX_DATA_SIZE] = {0};

			int result = visualizarDatos(rutaDB, logger, dataBuffer);
			if (result == SQLITE_OK) {
				send(comm_socket, dataBuffer, strlen(dataBuffer), 0);
				logger_log(logger, LOG_INFO, "Datos enviados: %s", dataBuffer);
			} else {
				sprintf(sendBuff, "Error al visualizar datos");
				send(comm_socket, sendBuff, strlen(sendBuff), 0);
				logger_log(logger, LOG_ERROR, "Error al visualizar datos");
			}
		}

    	if (strcmp(recvBuff, "EXIT") == 0)
		{
			break;
		}
    } while (1);

	logger_log(logger, LOG_INFO, "Server shutting down...");
	closesocket(comm_socket);
    WSACleanup();
    logger_close(logger); 
}
