#include <stdio.h>
#include <winsock2.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"
#include "baseDeDatos.h"
#include "configuracion.h" 

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 6000

int main(int argc, char *argv[]) 
{

    PathDB rutaDB = leerConfiguracion("configuracion.txt");
	WSADATA wsaData;
	SOCKET conn_socket;
	SOCKET comm_socket;
	struct sockaddr_in server;
	struct sockaddr_in client;
	char sendBuff[512], recvBuff[512];

	printf("\nInitialising Winsock...\n");
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
		printf("Failed. Error Code : %d", WSAGetLastError());
		return -1;
	}

	printf("Initialised.\n");

	//SOCKET creation
	if ((conn_socket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
		printf("Could not create socket : %d", WSAGetLastError());
		WSACleanup();
		return -1;
	}

	printf("Socket created.\n");

	server.sin_addr.s_addr = inet_addr(SERVER_IP);
	server.sin_family = AF_INET;
	server.sin_port = htons(SERVER_PORT);

	//BIND (the IP/port with socket)
	if (bind(conn_socket, (struct sockaddr*) &server,
			sizeof(server)) == SOCKET_ERROR) {
		printf("Bind failed with error code: %d", WSAGetLastError());
		closesocket(conn_socket);
		WSACleanup();
		return -1;
	}

	printf("Bind done.\n");

	//LISTEN to incoming connections (socket server moves to listening mode)
	if (listen(conn_socket, 1) == SOCKET_ERROR) {
		printf("Listen failed with error code: %d", WSAGetLastError());
		closesocket(conn_socket);
		WSACleanup();
		return -1;
	}

	//ACCEPT incoming connections (server keeps waiting for them)
	printf("Waiting for incoming connections...\n");
	int stsize = sizeof(struct sockaddr);
	comm_socket = accept(conn_socket, (struct sockaddr*) &client, &stsize);
	// Using comm_socket is able to send/receive data to/from connected client
	if (comm_socket == INVALID_SOCKET) {
		printf("accept failed with error code : %d", WSAGetLastError());
		closesocket(conn_socket);
		WSACleanup();
		return -1;
	}
	printf("Incomming connection from: %s (%d)\n", inet_ntoa(client.sin_addr),
			ntohs(client.sin_port));

	// Closing the listening sockets (is not going to be used anymore)
	closesocket(conn_socket);
    printf("Waiting for incoming commands from client... \n");
    do
    {
        recv(comm_socket, recvBuff, sizeof(recvBuff), 0);

		printf("Command received: %s \n", recvBuff);

		if(strcmp(recvBuff, "CREARTABLAS") == 0)
		{
			crearTabla(rutaDB);
		}

        if (strcmp(recvBuff, "INICIARSESION") == 0)
		{
            recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
            strcpy(usuario.correo, recvBuff);
            
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
            strcpy(usuario.contrasena, recvBuff);

            validarUsuario(rutaDB);
            
            sprintf(sendBuff, "%i", validacionUsuario);
			send(comm_socket, sendBuff, sizeof(sendBuff), 0);
			printf("Response sent: %s \n", sendBuff);
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
			
			guardarUsuario(rutaDB);

			sprintf(sendBuff, "%i", validacionUsuario);
			send(comm_socket, sendBuff, sizeof(sendBuff), 0);
			printf("Response sent: %s \n", sendBuff);
		}
	

		//NO SE SI ESTA PARTE ESTA BIEN
		if(strcmp(recvBuff, "MODIFICARDATOS") == 0)
		{
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			while (strcmp(recvBuff, "MODIFICARDATOS-END") != 0)
			{
				hayQueModificarDatos = 1;
				sprintf(sendBuff, "%i", hayQueModificarDatos);
				send(comm_socket, sendBuff, sizeof(sendBuff), 0);
			}
		}
		//--------------------------------

		if(strcmp(recvBuff, "MODIFICARPELICULA") == 0)
		{
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			strcpy(pelicula.idPeliculaInt, recvBuff);
			
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			strcpy(sala.idSalaInt, recvBuff);
			
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			strcpy(pelicula.titulo, recvBuff);
			
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			strcpy(pelicula.sinopsis, recvBuff);
			
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			strcpy(pelicula.horario, recvBuff);
				
			modificarPelicula(rutaDB);
			
			sprintf(sendBuff, "%i", hayQueModificarDatos);
			send(comm_socket, sendBuff, sizeof(sendBuff), 0);
			printf("Response sent: %s \n", sendBuff);
		
		}

		if(strcmp(recvBuff, "MODIFICARUSUARIO") == 0)
		{
			
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			strcpy(usuario.correo, recvBuff);
			
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			strcpy(usuario.nombre, recvBuff);

			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			strcpy(usuario.correo, recvBuff);

			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);	
			strcpy(usuario.contrasena, recvBuff);

			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);	
			strcpy(usuario.respuesta, recvBuff);
				
			modificarUsuario(rutaDB);
				
			sprintf(sendBuff, "%i", hayQueModificarDatos);
			send(comm_socket, sendBuff, sizeof(sendBuff), 0);
			printf("Response sent: %s \n", sendBuff);

		}

		if(strcmp(recvBuff, "MODIFICARCINE") == 0)
		{
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			strcpy(cine.idCineInt, recvBuff);
			
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			strcpy(cine.nombre, recvBuff);
			
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			strcpy(cine.direccion, recvBuff);
			
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			strcpy(cine.ciudad, recvBuff);
			
			modificarCine(rutaDB);
			
			sprintf(sendBuff, "%i", hayQueModificarDatos);
			send(comm_socket, sendBuff, sizeof(sendBuff), 0);
			printf("Response sent: %s \n", sendBuff);
		}

		if(strcmp(recvBuff, "MODIFICARACTOR") == 0)
		{
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			strcpy(actor.idActorInt, recvBuff);
			
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			strcpy(actor.nombre, recvBuff);
			
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			strcpy(actor.idPeliculaInt, recvBuff);
			
			modificarActor(rutaDB);
			
			sprintf(sendBuff, "%i", hayQueModificarDatos);
			send(comm_socket, sendBuff, sizeof(sendBuff), 0);
			printf("Response sent: %s \n", sendBuff);
		}

		if(strcmp(recvBuff, "MODIFICARASIENTO") == 0)
		{
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			strcpy(asiento.idAsientoInt, recvBuff);
			
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			strcpy(asiento.filaAsientoInt, recvBuff);
			
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			strcpy(asiento.numeroAsientoInt, recvBuff);
			
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			strcpy(asiento.fechaAsiento, recvBuff);
			
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			strcpy(sala.idSalaInt, recvBuff);

			modificarAsiento(rutaDB);
			
			sprintf(sendBuff, "%i", hayQueModificarDatos);
			send(comm_socket, sendBuff, sizeof(sendBuff), 0);
			printf("Response sent: %s \n", sendBuff);
		}

		if(strcmp(recvBuff, "MODIFICARSALA") == 0)
		{
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			strcpy(sala.idSalaInt, recvBuff);
			
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			strcpy(sala.numeroSalaInt, recvBuff);

			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			strcpy(sala.nColumnasSalaInt, recvBuff);

			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			strcpy(sala.nFilasSalaInt, recvBuff);

			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			strcpy(cine.idCineInt, recvBuff);

			modificarSala(rutaDB);

			sprintf(sendBuff, "%i", hayQueModificarDatos);
			send(comm_socket, sendBuff, sizeof(sendBuff), 0);
			printf("Response sent: %s \n", sendBuff);
		}
		
		if (strcmp(recvBuff, "BORRARDATOS") == 0)
		{
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			strcpy(tablaEliminar, recvBuff);
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			strcpy(idEliminar, recvBuff);
			eliminarFila(rutaDB);
		}

		if (strcmp(recvBuff, "ANADIRASIENTO") == 0)
		{
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			strcpy(asiento.fechaAsiento, recvBuff);
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			strcpy(asiento.filaAsientoInt, recvBuff);
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			strcpy(sala.idSalaInt, recvBuff);
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			strcpy(asiento.numeroAsientoInt, recvBuff);
			anadirAsiento(rutaDB);
		}

		if (strcmp(recvBuff, "ANADIRPELICULA") == 0)
		{
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			strcpy(pelicula.horario, recvBuff);
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			strcpy(cine.idCineInt, recvBuff);
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			strcpy(pelicula.sinopsis, recvBuff);
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			strcpy(pelicula.titulo, recvBuff);
			anadirPelicula(rutaDB);
		}

		if (strcmp(recvBuff, "ANADIRACTOR") == 0)
		{
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			strcpy(pelicula.idPeliculaInt, recvBuff);
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			strcpy(actor.nombreActor, recvBuff);
			anadirActor(rutaDB);
		}

		if (strcmp(recvBuff, "ANADIRCINE") == 0)
		{
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			strcpy(cine.ciudadCine, recvBuff);
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			strcpy(cine.direccionCine, recvBuff);
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			strcpy(cine.nombreCine, recvBuff);
			anadirCine(rutaDB);
		}

		if (strcmp(recvBuff, "ANADIRSALA") == 0)
		{
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			strcpy(cine.idCineInt, recvBuff);
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			strcpy(sala.nColumnasSalaInt, recvBuff);
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			strcpy(sala.nFilasSalaInt, recvBuff);
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			strcpy(sala.numeroSalaInt recvBuff);
		}

    	if (strcmp(recvBuff, "EXIT") == 0)
		{
			break;
		}
    } while (1);  
}
