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
    printf("Introduce tu correo electronico: ");
    fgetc(stdin);
    fgets(correo, 16, stdin);
    printf("Introduce tu contrasena: ");
    fgets(contrasena, 16, stdin);
    printf("\n");
    printf("\n");
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
    printf("De que tabla quieres modificar datos?\n");
    printf("1. Usuario\n2. Cine\n3. Actor\n4. Asiento\n5. Pelicula\n6. Sala\n\n");
    fflush(stdin);
    fgets(opcionCharModificar, 4, stdin);
    sscanf(opcionCharModificar, "%d", &opcionIntModificar);
    hayQueModificarDatos = 1;
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
        strcpy(tablaEliminar, "USUARIO");
        break;
    case 2:
        strcpy(tablaEliminar, "CINE");
        break;
    case 3:
        strcpy(tablaEliminar, "ACTOR");
        break;
    case 4:
        strcpy(tablaEliminar, "ASIENTO");
        break;
    case 5:
        strcpy(tablaEliminar, "PELICULA");
        break;
    case 6:
        strcpy(tablaEliminar, "SALA");
        break;
    }
    printf("Escribe el id de los datos a borrar?\n");
    fgets(idEliminar, 5, stdin);

}

void menuAnadirAsiento()
{
    printf("\n============\nANADIR ASIENTO\n============\n\n");
    printf("Introduce el id de la sala en la que esta el asiento: ");
    fflush(stdin);
    fgets(idSalaChar, 4, stdin);
    sscanf(idSalaChar, "%d", &idSalaInt);
    printf("Introduce la fila del asiento: ");
    fgets(filaAsiento, 5, stdin);
    printf("Introduce el numero del asiento: ");
    fgets(numeroAsiento, 4, stdin);
    printf("Introduce la fecha del asiento: ");
    fgets(fechaAsiento, 12, stdin);

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
}

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

}

void menuAnadirSala()
{
    printf("\n============\nANADIR SALA\n============\n\n");
    printf("Introduce el id del cine en la que esta la sala: ");
    fflush(stdin);
    fgets(idCineChar, 3, stdin);
    sscanf(idCineChar, "%d", &idCineInt);
    printf("Cual es el numero de filas que contiene la sala? ");
    fgets(nFilasSalaChar, 3, stdin);
    sscanf(nFilasSalaChar, "%d", nFilasSalaInt);
    printf("Cual es el numero de columnas que contiene la sala? ");
    fgets(nColumnasSalaChar, 3, stdin);
    sscanf(nColumnasSalaChar, "%d", nColumnasSalaInt);
    printf("Cual es el numero de la sala? ");
    fgets(numeroSalaChar, 3, stdin);
    sscanf(numeroSalaChar, "%d", numeroSalaInt);

}

void menuAnadirActor()
{
    printf("\n============\nANADIR ACTOR\n============\n\n");
    printf("Introduce el id de la pelicula en la que actua el actor: ");
    fflush(stdin);
    fgets(idPeliculaChar, 3, stdin);
    sscanf(idPeliculaChar, "%d", &idPeliculaInt);
    printf("Cual es el nombre del actor? ");
    fgets(nombreActor, 20, stdin);

}

void menuAnadirPelicula()
{
    printf("\n============\nANADIR PELICULA\n============\n\n");
    printf("Introduce el id de la sala en la que se ve la pelicula: ");
    fflush(stdin);
    fgets(idSalaChar, 4, stdin);
    sscanf(idSalaChar, "%d", &idSalaInt);
    printf("Introduce el titulo de la pelicula: ");
    fgets(titulo, 20, stdin);
    printf("Introduce la sinopsis de la pelicula: ");
    fgets(sinopsis, 20, stdin);
    printf("Introduce el horario de la pelicula: ");
    fgets(horario, 20, stdin);

}

void menuModificarPelicula()
{
    printf("\n============\nMODIFICAR PELICULA\n============\n\n");
    printf("Introduce el id de la pelicula a modificar: ");
    fflush(stdin);
    fgets(idPeliculaChar, 4, stdin);
    sscanf(idPeliculaChar, "%d", &idPeliculaInt);
    printf("Introduce el id de la sala en la que se ve la pelicula: ");
    fflush(stdin);
    fgets(idSalaChar, 4, stdin);
    sscanf(idSalaChar, "%d", &idSalaInt);
    printf("Introduce el nuevo titulo de la pelicula: ");
    fgets(titulo, 20, stdin);
    printf("Introduce la nueva sinopsis de la pelicula: ");
    fgets(sinopsis, 20, stdin);
    printf("Introduce el nuevo horario de la pelicula: ");
    fgets(horario, 20, stdin);

}

void menuModificarUsuario()
{
    printf("\n============\nMODIFICAR USUARIO\n============\n\n");
    printf("Introduce el id del usuario a modificar: ");
    fflush(stdin);
    fgets(idUsuarioChar, 4, stdin);
    sscanf(idUsuarioChar, "%d", &idUsuarioInt);
    printf("Introduce el nuevo nombre del usuario: ");
    fflush(stdin);
    fgets(nombre, 16, stdin);
    printf("Introduce la nueva respuesta de seguridad: ");
    fgets(respuesta, 20, stdin);
    printf("Introduce el nuevo correo electronico: s");
    fgets(correo, 20, stdin);
    printf("Introduce la nueva contrasena: ");
    fgets(contrasena, 16, stdin);

}

void menuModificarCine()
{
    printf("\n=========\nMODIFICAR CINE\n=========\n\n");
    printf("Introduce el id del cine a modificar: ");
    fflush(stdin);
    fgets(idCineChar, 4, stdin);
    sscanf(idCineChar, "%d", &idCineInt);
    printf("Introduce el nuevo nombre del cine: ");
    fflush(stdin);
    fgets(nombreCine, 16, stdin);
    printf("Introduce la nueva direccion del cine: ");
    fgets(direccionCine, 20, stdin);
    printf("Introduce la nueva ciudad del cine:");
    fgets(ciudadCine, 20, stdin);
    
}

void menuModificarActor()
{
    printf("\n===========\nMODIFICAR ACTOR\n===========\n\n");
    printf("Introduce el id del actor a modificar: ");
    fflush(stdin);
    fgets(idActorChar, 4, stdin);
    sscanf(idActorChar, "%d", &idActorInt);
    printf("Introduce el nuevo id de la pelicula en la que actua el actor: ");
    fflush(stdin);
    fgets(idPeliculaChar, 4, stdin);
    sscanf(idPeliculaChar, "%d", &idPeliculaInt);
    printf("Introduce el nuevo nombre del actor: ");
    fgets(nombreActor, 20, stdin);
   
}

void menuPrincipal()
{
    printf("\n===============\nMENU PRINCIPAL\n===============\n\n");
    printf("Que quieres hacer?\n\n");
    printf(" 1. Ver el catalogo de una pelicula\n 2. Comprar entradas\n 3. Mis entradas\n 4. Modificar usuario\n 5. Salir\n\n");
    fgets(opcionCharPpal, 2, stdin);
    sscanf(opcionCharPpal, "%d", &opcionIntPpal);

}



