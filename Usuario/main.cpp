#include "menus.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <winsock2.h>
#include "variables.h"

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 6000

using namespace std;

int programaOperando = 1;
int autenticacionExitosa = 0;
int hayQueModificarDatos = 0;
int hayQueAnadirDatos = 0;

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
    strcpy(sendBuff, "CREARTABLAS");
	send(s, sendBuff, sizeof(sendBuff), 0);	
	do
	{
		if (aElegidoModo == 0)
		{
			menuEleccionModo();
			aElegidoModo = 1;
		}
		
		switch (opcionModo)
		{
			case 1:
			if(aIniciadoSesion == 1)
			{
				menuPrincipalCliente();
				switch (opcionCliente)
				{
				case 1:
					menuVisualizarDatos();
                    strcpy(sendBuff, "VISUALIZARDATOS");
                    send(s, sendBuff, sizeof(sendBuff), 0);
                    strcpy(sendBuff, tablaVisualizar);
                    send(s, sendBuff, sizeof(sendBuff), 0);
                    memset(recvBuff, 0, sizeof(recvBuff));
					recv(s, recvBuff, sizeof(recvBuff), 0);
                    cout << recvBuff << endl;
                    break;
				case 2:
					hayQueModificarDatos = 1;
						while (hayQueModificarDatos == 1)
						{
							menuModificarDatos();
							switch(opcionModificar)
							{
								case 1:
									menuModificarPelicula();
									strcpy(sendBuff, "MODIFICARPELICULA");
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, PeliculaAModificar);
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, pelicula.getIdSala());
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, pelicula.getTitulo());
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, pelicula.getSinopsis());
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, pelicula.getHorario());
									send(s, sendBuff, sizeof(sendBuff), 0);
									break;
								case 2:
									menuModificarUsuario();
									strcpy(sendBuff, "MODIFICARUSUARIO");
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, usuario.getNombre());
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, usuario.getCorreo());
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, usuario.getContrasena());
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, usuario.getRespuesta());
									send(s, sendBuff, sizeof(sendBuff), 0);
									break;
								case 3:
									menuModificarCine();
									strcpy(sendBuff, "MODIFICARCINE");
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, cineAModificar);
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, cine.getNombreCine());
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, cine.getDireccionCine());
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, cine.getCiudadCine());
									send(s, sendBuff, sizeof(sendBuff), 0);
									break;
								case 4:
									menuModificarActor();
									strcpy(sendBuff, "MODIFICARACTOR");
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, actorAModificar);
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, actor.getNombreActor());
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, actor.getIdPelicula());
									send(s, sendBuff, sizeof(sendBuff), 0);
									break;
								case 5:
									menuModificarSala();
									strcpy(sendBuff, "MODIFICARSALA");
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, salaAModificar);
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, sala.getNumeroSala());
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, sala.getNColumnasSala());
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, sala.getNFilasSala());
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, sala.getIdCine());
									send(s, sendBuff, sizeof(sendBuff), 0);
									break;
								case 6:
									menuModificarAsiento();
									strcpy(sendBuff, "MODIFICARASIENTO");
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, asientoAModificar);
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, asiento.getFilaAsiento());
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, asiento.getNumeroAsiento());
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, asiento.getFechaAsiento());
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, asiento.getIdSala());
									send(s, sendBuff, sizeof(sendBuff), 0);
									break;
								case 7:
									cout << "Volviendo al menu principal..." << endl;
									hayQueModificarDatos = 0;
									break;
								
								default:
									cout << "Opcion no valida" << endl;
									break;
							}
						}
						break;
				case 3:
					cout << "Hasta luego!" << endl;
					strcpy(sendBuff, "EXIT");
					send(s, sendBuff, sizeof(sendBuff), 0);
					programaOperando = 0;
					break;
				default:
					cout << "Opcion no valida" << endl;
					cout << "Hasta luego!" << endl;
					strcpy(sendBuff, "EXIT");
					send(s, sendBuff, sizeof(sendBuff), 0);
					programaOperando = 0;
					break;
				}
				break;
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
						strcpy(sendBuff, usuario.getCorreo());
						send(s, sendBuff, sizeof(sendBuff), 0);
						strcpy(sendBuff, usuario.getContrasena());
						send(s, sendBuff, sizeof(sendBuff), 0);
						recv(s, recvBuff, sizeof(recvBuff), 0);
						if(strcmp(recvBuff, "1") == 0)
						{
							aIniciadoSesion = 1;
						}
						else if(strcmp(recvBuff, "1") != 0)
						{
							aIniciadoSesion = 0;
						}
						break;
					
					case 2:
						menuRegistrarse();
						strcpy(sendBuff, "REGISTRARSE");
						send(s, sendBuff, sizeof(sendBuff), 0);
						strcpy(sendBuff, usuario.getNombre());
						send(s, sendBuff, sizeof(sendBuff), 0);
						strcpy(sendBuff, usuario.getCorreo());
						send(s, sendBuff, sizeof(sendBuff), 0);
						strcpy(sendBuff, usuario.getContrasena());
						send(s, sendBuff, sizeof(sendBuff), 0);
						strcpy(sendBuff, usuario.getRespuesta());
						send(s, sendBuff, sizeof(sendBuff), 0);
						recv(s, recvBuff, sizeof(recvBuff), 0);
						aIniciadoSesion = 1;
						break;
					
					case 3:
						cout << "Hasta luego!" << endl;
						strcpy(sendBuff, "EXIT");
						send(s, sendBuff, sizeof(sendBuff), 0);
						programaOperando = 0;
						break;

					default:
						cout << "Opcion no valida" << endl;
						cout << "Hasta luego!" << endl;
						strcpy(sendBuff, "EXIT");
						send(s, sendBuff, sizeof(sendBuff), 0);
						programaOperando = 0;
						break;
				}
			}
			break;
			case 2:
			if (aIniciadoSesion == 1)
			{
				hayQueAnadirDatos = 0;
				hayQueModificarDatos = 0;
				menuPrincipalAdministrador();
				switch(opcionAdministrador)
				{
					case 1:
						hayQueModificarDatos = 1;
						while (hayQueModificarDatos == 1)
						{
							menuModificarDatos();
							switch(opcionModificar)
							{
								case 1:
									menuModificarPelicula();
									strcpy(sendBuff, "MODIFICARPELICULA");
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, PeliculaAModificar);
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, pelicula.getIdSala());
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, pelicula.getTitulo());
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, pelicula.getSinopsis());
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, pelicula.getHorario());
									send(s, sendBuff, sizeof(sendBuff), 0);
									break;
								case 2:
									menuModificarUsuario();
									strcpy(sendBuff, "MODIFICARUSUARIO");
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, usuario.getNombre());
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, usuario.getCorreo());
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, usuario.getContrasena());
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, usuario.getRespuesta());
									send(s, sendBuff, sizeof(sendBuff), 0);
									break;
								case 3:
									menuModificarCine();
									strcpy(sendBuff, "MODIFICARCINE");
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, cineAModificar);
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, cine.getNombreCine());
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, cine.getDireccionCine());
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, cine.getCiudadCine());
									send(s, sendBuff, sizeof(sendBuff), 0);
									break;
								case 4:
									menuModificarActor();
									strcpy(sendBuff, "MODIFICARACTOR");
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, actorAModificar);
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, actor.getNombreActor());
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, actor.getIdPelicula());
									send(s, sendBuff, sizeof(sendBuff), 0);
									break;
								case 5:
									menuModificarSala();
									strcpy(sendBuff, "MODIFICARSALA");
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, salaAModificar);
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, sala.getNumeroSala());
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, sala.getNColumnasSala());
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, sala.getNFilasSala());
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, sala.getIdCine());
									send(s, sendBuff, sizeof(sendBuff), 0);
									break;
								case 6:
									menuModificarAsiento();
									strcpy(sendBuff, "MODIFICARASIENTO");
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, asientoAModificar);
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, asiento.getFilaAsiento());
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, asiento.getNumeroAsiento());
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, asiento.getFechaAsiento());
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, asiento.getIdSala());
									send(s, sendBuff, sizeof(sendBuff), 0);
									break;
								case 7:
									cout << "Volviendo al menu principal..." << endl;
									hayQueModificarDatos = 0;
									break;
								
								default:
									cout << "Opcion no valida" << endl;
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
						hayQueAnadirDatos = 1;
						while (hayQueAnadirDatos == 1)
						{
							menuAnadirDatos();
							switch (opcionAD)
							{
							case 1:
								menuRegistrarse();
								strcpy(sendBuff, "REGISTRARSE");
								send(s, sendBuff, sizeof(sendBuff), 0);
								strcpy(sendBuff, usuario.getNombre());
								send(s, sendBuff, sizeof(sendBuff), 0);
								strcpy(sendBuff, usuario.getCorreo());
								send(s, sendBuff, sizeof(sendBuff), 0);
								strcpy(sendBuff, usuario.getContrasena());
								send(s, sendBuff, sizeof(sendBuff), 0);
								strcpy(sendBuff, usuario.getRespuesta());
								send(s, sendBuff, sizeof(sendBuff), 0);
								recv(s, recvBuff, sizeof(recvBuff), 0);
								break;
							case 2:
								menuAnadirAsiento();
								printf("%s", asiento.getIdSala());
								printf("%s", asiento.getFilaAsiento());
								printf("%s", asiento.getNumeroAsiento());
								printf("%s", asiento.getFechaAsiento());
								strcpy(sendBuff, "ANADIRASIENTO");
								send(s, sendBuff, sizeof(sendBuff), 0);
								strcpy(sendBuff, asiento.getFechaAsiento());
								send(s, sendBuff, sizeof(sendBuff), 0);
								strcpy(sendBuff, asiento.getFilaAsiento());
								send(s, sendBuff, sizeof(sendBuff), 0);
								strcpy(sendBuff, asiento.getIdSala());
								send(s, sendBuff, sizeof(sendBuff), 0);
								strcpy(sendBuff, asiento.getNumeroAsiento());
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
								strcpy(sendBuff, cine.getNombreCine());
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
								cout << "Volviendo al menu principal..." << endl;
								hayQueAnadirDatos = 0;
								break;
							default:
								cout << "Opcion no valida" << endl;
								break;
							}
						}
						break;
					case 4:
						menuResetearBD();
						switch (opcionResetearBD)
						{
						case 1:
							strcpy(sendBuff, "RESETEARBD");
							send(s, sendBuff, sizeof(sendBuff), 0);
							break;
						case 2:
							cout << "Volviendo al menu principal..." << endl;
							break;
						default:
							cout << "Opcion no valida" << endl;
							break;
						}
						break;

					case 5:
						cout << "Hasta luego!" << endl;
						strcpy(sendBuff, "EXIT");
						send(s, sendBuff, sizeof(sendBuff), 0);
						closesocket(s);
						WSACleanup();
						programaOperando = 0;
						break;
					default:
						cout << "Opcion no valida" << endl;
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
						strcpy(sendBuff, usuario.getCorreo());
						send(s, sendBuff, sizeof(sendBuff), 0);
						strcpy(sendBuff, usuario.getContrasena());
						send(s, sendBuff, sizeof(sendBuff), 0);
						recv(s, recvBuff, sizeof(recvBuff), 0);
						if(strcmp(recvBuff, "1") == 0)
						{
							aIniciadoSesion = 1;
						}
						else if(strcmp(recvBuff, "1") != 0)
						{
							aIniciadoSesion = 0;
						}
						break;
					
					case 2:
						menuRegistrarse();
						strcpy(sendBuff, "REGISTRARSE");
						send(s, sendBuff, sizeof(sendBuff), 0);
						strcpy(sendBuff, usuario.getNombre());
						send(s, sendBuff, sizeof(sendBuff), 0);
						strcpy(sendBuff, usuario.getCorreo());
						send(s, sendBuff, sizeof(sendBuff), 0);
						strcpy(sendBuff, usuario.getContrasena());
						send(s, sendBuff, sizeof(sendBuff), 0);
						strcpy(sendBuff, usuario.getRespuesta());
						send(s, sendBuff, sizeof(sendBuff), 0);
						recv(s, recvBuff, sizeof(recvBuff), 0);
						if(strcmp(recvBuff, "1") == 0)
						{
							aIniciadoSesion = 1;
						}
						else if(strcmp(recvBuff, "1") != 0)
						{
							aIniciadoSesion = 0;
						}
						break;
					
					case 3:
						cout << "Hasta luego!" << endl;
						strcpy(sendBuff, "EXIT");
						send(s, sendBuff, sizeof(sendBuff), 0);
						programaOperando = 0;
						break;
					default:
						cout << "Opcion no valida" << endl;		
						break;
				}
			}
			break;

			case 3:
				cout << "Hasta luego!" << endl;
						strcpy(sendBuff, "EXIT");
						send(s, sendBuff, sizeof(sendBuff), 0);
						programaOperando = 0;
						break;
			default:
				cout << "Opcion no valida" << endl;		
				break;
		}
		
    } while (programaOperando != 0);

    closesocket(s);
	WSACleanup();
	return 0;
}