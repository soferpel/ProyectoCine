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

		MenuEleccionModo menuEleccionModo;
		menuEleccionModo.mostrar();
		switch (menuEleccionModo.getOpcion())
		{
		case 1:
			//CLIENTE
			break;
		case 2:
			if (autenticacionExitosa == 1)
			{
				hayQueAnadirDatos = 0;
				MenuPrincipalAdministrador menuPrincipalAdministrador;
				menuPrincipalAdministrador.mostrar();
				switch(menuPrincipalAdministrador.getOpcion)
				{
					case 1:
						MenuModificarDatos menuModificarDatos;
						menuModificarDatos.mostrar();
						strcpy(sendBuff, "MODIFICARDATOS");
						send(s, sendBuff, sizeof(sendBuff), 0);
						recv(s, recvBuff, sizeof(recvBuff), 0);
						if(recvBuff == 1)
						{
							hayQueModificarDatos = 0;
							switch(menuModificarDatos.getOpcion())
							{
								case 1:
									MenuModificarUsuario menuModificarUsuario;
									menuModificarUsuario.mostrar();
									strcpy(sendBuff, "MODIFICARUSUARIO");
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, menuModificarUsuario.getCorreo());
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, menuModificarUsuario.getNombre());
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, menuModificarUsuario.getCorreo());
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, menuModificarUsuario.getContrasena());
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, menuModificarUsuario.getRespuestaSeguridad());
									send(s, sendBuff, sizeof(sendBuff), 0);
									if(recvBuff == 1)
									{
										hayQueModificarDatos = 0;
									}
									break;

								case 2:
									MenuModificarCine menuModificarCine;
									menuModificarCine.mostrar();
									strcpy(sendBuff, "MODIFICARCINE");
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, menuModificarCine.getIdAModificar());
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, menuModificarCine.getNombre());
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, menuModificarCine.getDireccion());
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, menuModificarCine.getCiudad());
									send(s, sendBuff, sizeof(sendBuff), 0);
									if(recvBuff == 1)
									{
										hayQueModificarDatos = 0;
									}
									break;

								case 3:
									MenuModificarActor menuModificarActor;
									menuModificarActor.mostrar();
									strcpy(sendBuff, "MODIFICARACTOR");
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, menuModificarActor.getIdAModificar());
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, menuModificarActor.getNombre());
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, menuModificarActor.getIdPelicula());
									send(s, sendBuff, sizeof(sendBuff), 0);
									if(recvBuff == 1)
									{
										hayQueModificarDatos = 0;
									}
									break;
								
								case 4:
									MenuModificarAsiento menuModificarAsiento;
									menuModificarAsiento.mostrar();
									strcpy(sendBuff, "MODIFICARASIENTO");
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, menuModificarAsiento.getIdAModificar());
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, menuModificarAsiento.getFila());
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, menuModificarAsiento.getNumero());
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, menuModificarAsiento.getFecha());
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, menuModificarAsiento.getIdSala());
									send(s, sendBuff, sizeof(sendBuff), 0);
									if(recvBuff == 1)
									{
										hayQueModificarDatos = 0;
									}
									break;

								case 5:
									MenuModificarPelicula menuModificarPelicula;
									menuModificarPelicula.mostrar();
									strcpy(sendBuff, "MODIFICARPELICULA");
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, menuModificarPelicula.getIdAModificar());
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, menuModificarPelicula.getIdSala());
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, menuModificarPelicula.getTitulo());
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, menuModificarPelicula.getSinopsis());
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, menuModificarPelicula.getHorario());
									send(s, sendBuff, sizeof(sendBuff), 0);
									if(recvBuff == 1)
									{
										hayQueModificarDatos = 0;
									}
									break;

								case 6:
									MenuModificarSala menuModificarSala;
									menuModificarSala.mostrar();
									strcpy(sendBuff, "MODIFICARSALA");
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, menuModificarSala.getIdAModificar());
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, menuModificarSala.getNumero());
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, menuModificarSala.getNColumnas());
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, menuModificarSala.getNFilas());
									send(s, sendBuff, sizeof(sendBuff), 0);
									strcpy(sendBuff, menuModificarSala.getIdCine());
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
				}
			}
			else
			{
				MenuBienvenida menuBienvenida;
				menuBienvenida.mostrar();
				switch(menuBienvenida.getOpcion())
				{
					case 1:
						MenuIniciarSesion menuIniciarSesion;
						menuIniciarSesion.mostrar();
						strcpy(sendBuff, "INICIARSESION");
						send(s, sendBuff, sizeof(sendBuff), 0);
						strcpy(sendBuff, menuIniciarSesion.getCorreoUsuario());
						send(s, sendBuff, sizeof(sendBuff), 0);
						strcpy(sendBuff, menuIniciarSesion.getContrasena());
						send(s, sendBuff, sizeof(sendBuff), 0);
						recv(s, recvBuff, sizeof(recvBuff), 0);
						if (recvBuff == 1)
						{
							MenuPrincipalCliente menuPrincipalCliente;
							menuPrincipalCliente.mostrar();
						}
						break;
					
					case 2:
						MenuRegistrarse menuRegistrarse;
						menuRegistrarse.mostrar();
						strcpy(sendBuff, "REGISTRARSE");
						send(s, sendBuff, sizeof(sendBuff), 0);
						strcpy(sendBuff, menuRegistrarse.getNombre());
						send(s, sendBuff, sizeof(sendBuff), 0);
						strcpy(sendBuff, menuRegistrarse.getCorreoUsuario());
						send(s, sendBuff, sizeof(sendBuff), 0);
						strcpy(sendBuff, menuRegistrarse.getContrasena());
						send(s, sendBuff, sizeof(sendBuff), 0);
						strcpy(sendBuff, menuRegistrarse.getRespuestaSeguridad());
						send(s, sendBuff, sizeof(sendBuff), 0);
						recv(s, recvBuff, sizeof(recvBuff), 0);
						if (recvBuff == 1)
						{
							MenuPrincipalCliente menuPrincipalCliente;
							menuPrincipalCliente.mostrar();
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
			menuBienvenida.mostrar();
			break;
		}
		
    } while (programaOperando == 1);

    closesocket(s);
	WSACleanup();


	}    
	return 0;
}