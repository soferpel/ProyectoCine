#include "menus.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <winsock2.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 6000

using namespace std;
using namespace menus;

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
    do
	{
		MenuBienvenida menuBienvenida;
        MenuIniciarSesion menuIniciarSesion;
        MenuRegistrarse menuRegistrarse;

        menuBienvenida.mostrar();

		if (menuBienvenida.getOpcion() == '1')
        {
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
                MenuPrincipal menuPrincipal;
                menuPrincipal.mostrar();
            }
            
        }
        else if (menuBienvenida.getOpcion() == '2')
        {
            menuRegistrarse.mostrar();
        }
        else if (menuBienvenida.getOpcion() == '3')
        {
            cout << "Hasta luego!" << endl;
            // SENDING command EXIT
			strcpy(sendBuff, "EXIT");
			send(s, sendBuff, sizeof(sendBuff), 0);
        }
        else
        {
            menuBienvenida.mostrar();
        }
		
    }while (menuBienvenida.getOpcion() != 3);

    closesocket(s);
	WSACleanup();

    return 0;
}