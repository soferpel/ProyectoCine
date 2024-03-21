#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "baseDeDatos.h"

void menuBienvenida()
{
    printf("\n===========\nBIENVENID@\n===========\n\n");
    printf("Que quieres hacer?\n\n");
    printf(" 1. Iniciar sesion\n 2. Registrarse\n 3. Salir\n\n");
    fgets(opcionCharBvda, 2, stdin);
    sscanf(opcionCharBvda, "%d", &opcionIntBvda);
}

void menuInicioSesion()
{
    printf("\n===============\nINICIAR SESION\n===============\n\n");
    printf("Introduce tu nombre de usuario: ");
    fgetc(stdin);
    fgets(nombreUsuario, 16, stdin);
    printf("Introduce tu contrasena: ");
    fgets(contrasena, 16, stdin);
    printf("\n");
    printf("\n");
    printf("Usuario: %s\n", nombreUsuario);
    printf("Contrasena: %s\n", contrasena);
    validarUsuario(nombreUsuario, contrasena);
}

void menuRegistro()
{
    printf("\n============\nREGISTRARSE\n============\n\n");
    printf("Introduce tu nombre: ");
    fgetc(stdin);
    fgets(nombre, 16, stdin);
    printf("Introduce tu apellido: ");
    fgets(apellido, 20, stdin);
    printf("Introduce tu nombre de usuario: ");
    fgets(nombreUsuario, 16, stdin);
    printf("Introduce tu contrasena: ");
    fgets(contrasena, 16, stdin);
    guardarUsuario();

}

void menuPrincipal()
{
    printf("\n===============\nMENU PRINCIPAL\n===============\n\n");
    printf("Que quieres hacer?\n\n");
    printf(" 1. Ver el catalogo de una pelicula\n 2. Comprar entradas\n 3. Mis entradas\n 4. Modificar usuario\n 5. Salir\n\n");
    fgets(opcionCharPpal, 2, stdin);
    sscanf(opcionCharPpal, "%d", &opcionIntPpal);

}



