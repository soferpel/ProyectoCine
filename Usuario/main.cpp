#include "menus.h"
#include "configuracion.h"
#include "baseDeDatos.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <winsock2.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 6000

using namespace std;
using namespace menus;

int programaOperando = 1;

int main(int argc, char *argv[])
{
    WSADATA wsaData;
	SOCKET s;
	struct sockaddr_in server;
	char sendBuff[512], recvBuff[512];

	printf("\nInitialising Winsock...\n");
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		printf("Failed. Error Code : %d", WSAGetLastError());
		return -1;
	}

	printf("Initialised.\n");

	//SOCKET creation
	if ((s = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
	{
		printf("Could not create socket : %d", WSAGetLastError());
		WSACleanup();
		return -1;
	}

	printf("Socket created.\n");

	server.sin_addr.s_addr = inet_addr(SERVER_IP);
	server.sin_family = AF_INET;
	server.sin_port = htons(SERVER_PORT);

	//CONNECT to remote server
	if (connect(s, (struct sockaddr*) &server, sizeof(server)) == SOCKET_ERROR)
	{
		printf("Connection error: %d", WSAGetLastError());
		closesocket(s);
		WSACleanup();
		return -1;
	}

	printf("Connection stablished with: %s (%d)\n", inet_ntoa(server.sin_addr),
			ntohs(server.sin_port));

	//SEND and RECEIVE data (CLIENT/SERVER PROTOCOL)
	autenticacionExitosa = 0;
    
	do
	{
		strcpy(sendBuff, "CREARTABLAS");
		send(s, sendBuff, sizeof(sendBuff), 0);	

		menuEleccionModo();
		switch (opcionModo)
		{
		case 1:
			//CLIENTE
			break;
		case 2:
			if (autenticacionExitosa == 1)
			{
				hayQueAnadirDatos = 0;
				menuPrincipalAdministrador();
				switch(opcionAdministrador)
				{
					case 1:
						menuModificarDatos();
						strcpy(sendBuff, "MODIFICARDATOS");
						send(s, sendBuff, sizeof(sendBuff), 0);
						recv(s, recvBuff, sizeof(recvBuff), 0);
						if(recvBuff == 1)
						{
							hayQueModificarDatos = 0;
							switch(opcionModificar)
							{
								case 1:
									menuModificarUsuario();
									strcpy(sendBuff, "MODIFICARUSUARIO");
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, usuario.getCorreo());
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, usuario.getNombre());
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, usuario.getCorreo());
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, usuario.getContrasena());
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, usuario.getRespuestaSeguridad());
									send(s, sendBuff, sizeof(sendBuff), 0);
									if(recvBuff == 1)
									{
										hayQueModificarDatos = 0;
									}
									break;

								case 2:
									menuModificarCine();
									strcpy(sendBuff, "MODIFICARCINE");
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, cine.getIdAModificar());
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, cine.getNombre());
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, cine.getDireccion());
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, cine.getCiudad());
									send(s, sendBuff, sizeof(sendBuff), 0);
									if(recvBuff == 1)
									{
										hayQueModificarDatos = 0;
									}
									break;

								case 3:
									menuModificarActor();
									strcpy(sendBuff, "MODIFICARACTOR");
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, actor.getIdAModificar());
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, actor.getNombre());
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, actor.getIdPelicula());
									send(s, sendBuff, sizeof(sendBuff), 0);
									if(recvBuff == 1)
									{
										hayQueModificarDatos = 0;
									}
									break;
								
								case 4:
									menuModificarAsiento();
									strcpy(sendBuff, "MODIFICARASIENTO");
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, asiento.getIdAModificar());
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, asiento.getFila());
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, asiento.getNumero());
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, asiento.getFecha());
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, asiento.getIdSala());
									send(s, sendBuff, sizeof(sendBuff), 0);
									if(recvBuff == 1)
									{
										hayQueModificarDatos = 0;
									}
									break;

								case 5:
									menuModificarPelicula();
									strcpy(sendBuff, "MODIFICARPELICULA");
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, pelicula.getIdAModificar());
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, pelicula.getIdSala());
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, pelicula.getTitulo());
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, pelicula.getSinopsis());
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, pelicula.getHorario());
									send(s, sendBuff, sizeof(sendBuff), 0);
									if(recvBuff == 1)
									{
										hayQueModificarDatos = 0;
									}
									break;

								case 6:
									menuModificarSala();
									strcpy(sendBuff, "MODIFICARSALA");
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, sala.getIdAModificar());
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, sala.getNumero());
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, sala.getNColumnas());
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, sala.getNFilas());
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, sala.getIdCine());
									send(s, sendBuff, sizeof(sendBuff), 0);
									if(recvBuff == 1)
									{
										hayQueModificarDatos = 0;
									}
									break;
								
								case 7:
									cout << "Hasta luego!" << endl;
									strcpy(sendBuff, "EXIT");
									send(s, sendBuff, sizeof(sendBuff), 0);
									break;
							}
						}
						break;
					case 2:
						menuBorrarDatos();
						strcpy(sendBuff, "BORRARDATOS");
						send(s, sendBuff, sizeof(sendBuff), 0);
						strcpy(sendBuff, tablaEliminar);
						send(s, sendBuff, sizeof(sendBuff), 0);
						strcpy(sendBuff, idEliminar);
						send(s, sendBuff, sizeof(sendBuff), 0);
						break;
					case 3:
						menuAnadirDatos();
						hayQueAnadirDatos = 0;
						switch (opcionAD)
						{
						case 1:
							menuRegistro();
							strcpy(sendBuff, "REGISTRARSE");
							send(s, sendBuff, sizeof(sendBuff), 0);
							strcpy(sendBuff, usuario.getNombre());
							send(s, sendBuff, sizeof(sendBuff), 0);
							strcpy(sendBuff, usuario.getCorreoUsuario());
							send(s, sendBuff, sizeof(sendBuff), 0);
							strcpy(sendBuff, usuario.getContrasena());
							send(s, sendBuff, sizeof(sendBuff), 0);
							strcpy(sendBuff, usuario.getRespuestaSeguridad());
							send(s, sendBuff, sizeof(sendBuff), 0);
							recv(s, recvBuff, sizeof(recvBuff), 0);
							break;
						case 2:
							menuAnadirAsiento();
							strcpy(sendBuff, "ANADIRASIENTO");
							send(s, sendBuff, sizeof(sendBuff), 0);
							strcpy(sendBuff, asiento.getFechaAsiento);
							send(s, sendBuff, sizeof(sendBuff), 0);
							strcpy(sendBuff, asiento.getFilaAsiento);
							send(s, sendBuff, sizeof(sendBuff), 0);
							strcpy(sendBuff, asiento.getIdSala);
							send(s, sendBuff, sizeof(sendBuff), 0);
							strcpy(sendBuff, asiento.getNumeroAsiento);
							send(s, sendBuff, sizeof(sendBuff), 0);
							break;
						case 3:
							menuAnadirPelicula();
							strcpy(sendBuff, "ANADIRPELICULA");
							send(s, sendBuff, sizeof(sendBuff), 0);
							strcpy(sendBuff, pelicula.getHorario());
							send(s, sendBuff, sizeof(sendBuff), 0);
							strcpy(sendBuff, pelicula.getIdSala());
							send(s, sendBuff, sizeof(sendBuff), 0);
							strcpy(sendBuff, pelicula.getSinopsis());
							send(s, sendBuff, sizeof(sendBuff), 0);
							strcpy(sendBuff, pelicula.getTitulo());
							send(s, sendBuff, sizeof(sendBuff), 0);
							break;
						case 4:
							menuAnadirActor();
							strcpy(sendBuff, "ANADIRACTOR");
							send(s, sendBuff, sizeof(sendBuff), 0);
							strcpy(sendBuff, actor.getIdPelicula());
							send(s, sendBuff, sizeof(sendBuff), 0);
							strcpy(sendBuff, actor.getNombreActor());
							send(s, sendBuff, sizeof(sendBuff), 0);
							break;
						case 5:
							menuAnadirCine();
							strcpy(sendBuff, "ANADIRCINE");
							send(s, sendBuff, sizeof(sendBuff), 0);
							strcpy(sendBuff, cine.getCiudadCine());
							send(s, sendBuff, sizeof(sendBuff), 0);
							strcpy(sendBuff, cine.getDireccionCine());
							send(s, sendBuff, sizeof(sendBuff), 0);
							strcpy(sendBuff, cine.getNombreCine);
							send(s, sendBuff, sizeof(sendBuff), 0);
							break;
						case 6:
							menuAnadirSala();
							strcpy(sendBuff, "ANADIRSALA");
							send(s, sendBuff, sizeof(sendBuff), 0);
							strcpy(sendBuff, sala.getIdCine());
							send(s, sendBuff, sizeof(sendBuff), 0);
							strcpy(sendBuff, sala.getNColumnasSala());
							send(s, sendBuff, sizeof(sendBuff), 0);
							strcpy(sendBuff, sala.getNFilasSala());
							send(s, sendBuff, sizeof(sendBuff), 0);
							strcpy(sendBuff, sala.getNumeroSala());
							send(s, sendBuff, sizeof(sendBuff), 0);
							break;
						case 7:
							cout << "Hasta luego!" << endl;
							strcpy(sendBuff, "EXIT");
							send(s, sendBuff, sizeof(sendBuff), 0);
							break;
						default:
							break;
						}
						break;
					case 4:
						cout << "Hasta luego!" << endl;
						strcpy(sendBuff, "EXIT");
						send(s, sendBuff, sizeof(sendBuff), 0);
						break;
				}
			}
			else
			{
				menuBienvenida();
				switch(opcionBvda)
				{
					case 1:
						menuIniciarSesion();
						strcpy(sendBuff, "INICIARSESION");
						send(s, sendBuff, sizeof(sendBuff), 0);
						strcpy(sendBuff, usuario.getCorreoUsuario());
						send(s, sendBuff, sizeof(sendBuff), 0);
						strcpy(sendBuff, usuario.getContrasena());
						send(s, sendBuff, sizeof(sendBuff), 0);
						recv(s, recvBuff, sizeof(recvBuff), 0);
						if (recvBuff == 1)
						{
							menuPrincipalCliente();
						}
						break;
					
					case 2:
						menuRegistrarse();
						strcpy(sendBuff, "REGISTRARSE");
						send(s, sendBuff, sizeof(sendBuff), 0);
						strcpy(sendBuff, usuario.getNombre());
						send(s, sendBuff, sizeof(sendBuff), 0);
						strcpy(sendBuff, usuario.getCorreoUsuario());
						send(s, sendBuff, sizeof(sendBuff), 0);
						strcpy(sendBuff, usuario.getContrasena());
						send(s, sendBuff, sizeof(sendBuff), 0);
						strcpy(sendBuff, usuario.getRespuestaSeguridad());
						send(s, sendBuff, sizeof(sendBuff), 0);
						recv(s, recvBuff, sizeof(recvBuff), 0);
						if (recvBuff == 1)
						{
							menuPrincipalCliente();
						}
						break;
				}
			break;
		case 3:
			cout << "Hasta luego!" << endl;
			strcpy(sendBuff, "EXIT");
			send(s, sendBuff, sizeof(sendBuff), 0);
			break;
		default:
			menuBienvenida();
			break;
		}
		
    } while (programaOperando == 1);

    closesocket(s);
	WSACleanup();


	}    
	return 0;
}