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
    autenticacionExitosa = 1;
}

void menuAdministrador()
{
    printf("\n============\nADMINISTRADOR\n============\n\n");
    printf("Que quieres hacer?\n\n");
    printf(" 1. Modificar datos\n 2. Eliminar datos\n 3. Anadir datos\n 4. Salir\n\n");
    fgets(opcionCharAd, 2, stdin);
    sscanf(opcionCharAd, "%d", &opcionIntAd);
}

void menuModificarDatos()
{
    printf("\n============\nMODIFICAR DATOS\n============\n\n");
    printf("Escribe el id de los datos a modificar: \n");
    fgets(id, 5, stdin);
    //funcion buscar id

}

void menuBorrarDatos()
{
    printf("\n============\nBORRAR DATOS\n============\n\n");
    printf("Escribe el id de los datos a borrar?\n");
    fgets(id, 5, stdin);
    //funcion buscar id
    
}

void menuAnadirDatos()
{
    printf("\n============\nANADIR DATOS\n============\n\n");
    printf("Que Datos quieres anadir?\n\n");
    printf(" 1. Usuario\n 2. Asiento\n 3. Pelicula\n 4. Actor\n 5. Cine\n 6. Sala\n 7. Salir\n\n");
    fgets(opcionCharAD, 2, stdin);
    sscanf(opcionCharAD, "%d", &opcionIntAD);
}

void menuPrincipal()
{
    printf("\n===============\nMENU PRINCIPAL\n===============\n\n");
    printf("Que quieres hacer?\n\n");
    printf(" 1. Ver el catalogo de una pelicula\n 2. Comprar entradas\n 3. Mis entradas\n 4. Modificar usuario\n 5. Salir\n\n");
    fgets(opcionCharPpal, 2, stdin);
    sscanf(opcionCharPpal, "%d", &opcionIntPpal);

}



