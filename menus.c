#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    fgets(correo, 16, stdin);
    printf("Introduce tu contrasena: ");
    fgets(contrasena, 16, stdin);
    printf("\n");
    printf("\n");
    validarUsuario();
}

void menuRegistro()
{
    printf("\n============\nREGISTRARSE\n============\n\n");
    printf("Introduce tu nombre: ");
    fgetc(stdin);
    fgets(nombre, 16, stdin);
    printf("Respuesta de seguridad: Cual es tu pelicula favorita? ");
    fgets(respuesta, 20, stdin);
    printf("Introduce tu correo: ");
    fgets(correo, 16, stdin);
    printf("Introduce tu contrasena: ");
    fgets(contrasena, 16, stdin);
    guardarUsuario();
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
    printf("De que tabla quieres eliminar datos?\n");
    printf("1. Usuario\n2. Cine\n3. Actor\n4. Asiento\n5. Pelicula\n6. Sala\n\n");
    fflush(stdin);
    fgets(opcionCharEliminar, 4, stdin);
    sscanf(opcionCharEliminar, "%d", &opcionIntEliminar);
    switch (opcionIntEliminar)
    {
    case 1:
        strcpy(tabla, "USUARIO");
        break;
    case 2:
        strcpy(tabla, "CINE");
        break;
    case 3:
        strcpy(tabla, "ACTOR");
        break;
    case 4:
        strcpy(tabla, "ASIENTO");
        break;
    case 5:
        strcpy(tabla, "PELICULA");
        break;
    case 6:
        strcpy(tabla, "SALA");
        break;
    }
    printf("Escribe el id de los datos a borrar?\n");
    fgets(id, 5, stdin);
    eliminarFila();
}

void menuAnadirAsiento()
{
    fgetc(stdin);
    printf("Introduce el id de la sala en la que esta el asiento: ");
    fgets(idSala, 3, stdin);
    printf("Introduce la fila del asiento: ");
    fgets(filaAsiento, 3, stdin);
    printf("Introduce el numero del asiento: ");
    fgets(numeroAsiento, 3, stdin);
    printf("Introduce la fecha del asiento: ");
    fgets(fechaAsiento, 12, stdin);
    anadirAsiento();
}

void menuAnadirDatos()
{
    hayQueAnadirDatos = 1;
    printf("\n============\nANADIR DATOS\n============\n\n");
    printf("Que Datos quieres anadir?\n\n");
    printf(" 1. Usuario\n 2. Asiento\n 3. Pelicula\n 4. Actor\n 5. Cine\n 6. Sala\n 7. Salir\n\n");
    fflush(stdin);
    fgets(opcionCharAD, 2, stdin);
    sscanf(opcionCharAD, "%d", &opcionIntAD);
    switch (opcionIntAD)
    {
        case 1:
            menuRegistro();
            break;
        case 2:
            menuAnadirAsiento();
            break;
        // case 3:
        //     menuAnadirPelicula();
        //     break;
        // case 4:
        //     menuAnadirActor();
        //     break;
        // case 5:
        //     menuAnadirCine();
        //     break;
        // case 6:
        //     menuAnadirSala();
        //     break;
        case 7:
            printf("Adios!\n");
            break;
    }
}

/*
void menuAnadirAsientos()
{
    printf("\n============\nANADIR ASIENTOS\n============\n\n");
    printf("A que sala pertenece este asiento?\n\n");
    fgets(opcionCharAD, 2, stdin);
}
*/

void menuAnadirCine()
{
    printf("\n============\nANADIR CINE\n============\n\n");
    printf("Cual es el nombre del cine?\n");
    fflush(stdin);
    fgets(nombreCine, 20, stdin);
    printf("Cual es la direccion del cine?\n");
    fgets(direccionCine, 20, stdin);
    printf("Cual es la ciudad del cine?\n");
    fgets(ciudadCine, 20, stdin);
    anadirCine();
    hayQueAnadirDatos = 0;
}

void menuPrincipal()
{
    printf("\n===============\nMENU PRINCIPAL\n===============\n\n");
    printf("Que quieres hacer?\n\n");
    printf(" 1. Ver el catalogo de una pelicula\n 2. Comprar entradas\n 3. Mis entradas\n 4. Modificar usuario\n 5. Salir\n\n");
    fgets(opcionCharPpal, 2, stdin);
    sscanf(opcionCharPpal, "%d", &opcionIntPpal);

}



