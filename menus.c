#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menus.h"
#include "baseDeDatos.h"


void menuBienvenida()
{
    printf("\n==========\nBIENVENID@\n==========\n\n");
    printf("Que quieres hacer?\n\n");
    printf(" 1. Iniciar sesion\n 2. Registrarse\n 3. Salir\n\n");
    fgets(opcionCharBvda, 2, stdin);
    sscanf(opcionCharBvda, "%i", &opcionIntBvda);
}

void menuInicioSesion()
{
    printf("\n==============\nINICIAR SESION\n==============\n\n");
    printf("Introduce tu correo electronico: ");
    fgetc(stdin);
    fgets(usuario.correo, 30, stdin);
    printf("Introduce tu contrasena: ");
    fgets(usuario.contrasena, 16, stdin);
    printf("\n");
    printf("\n");
}

void menuRegistro()
{
    printf("\n============\nREGISTRARSE\n============\n\n");
    printf("Introduce tu nombre: ");
    fgetc(stdin);
    fgets(usuario.nombre, 16, stdin);
    printf("Respuesta de seguridad: Cual es tu pelicula favorita? ");
    fgets(usuario.respuesta, 20, stdin);
    printf("Introduce tu correo: ");
    fgets(usuario.correo, 30, stdin);
    printf("Introduce tu contrasena: ");
    fgets(usuario.contrasena, 16, stdin);
    
}

void menuAdministrador()
{
    printf("\n=============\nADMINISTRADOR\n=============\n\n");
    printf("Que quieres hacer?\n\n");
    printf(" 1. Modificar datos\n 2. Eliminar datos\n 3. Anadir datos\n 4. Salir\n\n");
    fgets(opcionCharAd, 2, stdin);
    sscanf(opcionCharAd, "%i", &opcionIntAd);
}

void menuModificarDatos()
{
    printf("\n============\nMODIFICAR DATOS\n============\n\n");
    printf("De que tabla quieres modificar datos?\n");
    printf("1. Usuario\n2. Cine\n3. Actor\n4. Asiento\n5. Pelicula\n6. Sala\n\n");
    fflush(stdin);
    fgets(opcionCharModificar, 4, stdin);
    sscanf(opcionCharModificar, "%i", &opcionIntModificar);
    hayQueModificarDatos = 1;
}

void menuBorrarDatos()
{
    printf("\n============\nBORRAR DATOS\n============\n\n");
    printf("De que tabla quieres eliminar datos?\n");
    printf("1. Usuario\n2. Cine\n3. Actor\n4. Asiento\n5. Pelicula\n6. Sala\n\n");
    fflush(stdin);
    fgets(opcionCharEliminar, 4, stdin);
    sscanf(opcionCharEliminar, "%i", &opcionIntEliminar);
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
    fgets(sala.idSalaChar, 4, stdin);
    sscanf(sala.idSalaChar, "%i", &sala.idSalaInt);
    printf("Introduce la fila del asiento: ");
    fgets(asiento.filaAsientoChar, 3, stdin);
    sscanf(asiento.filaAsientoChar, "%i", &asiento.filaAsientoInt);
    printf("Introduce el numero del asiento: ");
    fgets(asiento.numeroAsientoChar, 3, stdin);
    sscanf(asiento.numeroAsientoChar, "%i", &asiento.numeroAsientoInt);
    printf("Introduce la fecha del asiento: ");
    fgets(asiento.fechaAsiento, 11, stdin);

}

void menuAnadirDatos()
{
    hayQueAnadirDatos = 1;
    printf("\n============\nANADIR DATOS\n============\n\n");
    printf("Que datos quieres anadir?\n\n");
    printf(" 1. Usuario\n 2. Asiento\n 3. Pelicula\n 4. Actor\n 5. Cine\n 6. Sala\n 7. Salir\n\n");
    fflush(stdin);
    fgets(opcionCharAD, 2, stdin);
    sscanf(opcionCharAD, "%i", &opcionIntAD);
}

void menuAnadirCine()
{
    printf("\n============\nANADIR CINE\n============\n\n");
    printf("Cual es el nombre del cine?\n");
    fflush(stdin);
    fgets(cine.nombreCine, 20, stdin);
    printf("Cual es la direccion del cine?\n");
    fgets(cine.direccionCine, 20, stdin);
    printf("Cual es la ciudad del cine?\n");
    fgets(cine.ciudadCine, 20, stdin);

}

void menuAnadirSala()
{
    printf("\n============\nANADIR SALA\n============\n\n");
    printf("Introduce el id del cine en la que esta la sala: ");
    fflush(stdin);
    fgets(cine.idCineChar, 4, stdin);
    sscanf(cine.idCineChar, "%i", &cine.idCineInt);
    printf("Cual es el numero de filas que contiene la sala? ");
    fgets(sala.nFilasSalaChar, 3, stdin);
    sscanf(sala.nFilasSalaChar, "%i", sala.nFilasSalaInt);
    printf("Cual es el numero de columnas que contiene la sala? ");
    fgets(sala.nColumnasSalaChar, 3, stdin);
    sscanf(sala.nColumnasSalaChar, "%i", sala.nColumnasSalaInt);
    printf("Cual es el numero de la sala? ");
    fgets(sala.numeroSalaChar, 3, stdin);
    sscanf(sala.numeroSalaChar, "%i", sala.numeroSalaInt);

}

void menuAnadirActor()
{
    printf("\n============\nANADIR ACTOR\n============\n\n");
    printf("Introduce el id de la pelicula en la que actua el actor: ");
    fflush(stdin);
    fgets(idPeliculaChar, 4, stdin);
    sscanf(idPeliculaChar, "%i", &idPeliculaInt);
    printf("Cual es el nombre del actor? ");
    fgets(nombreActor, 20, stdin);

}

void menuAnadirPelicula()
{
    printf("\n============\nANADIR PELICULA\n============\n\n");
    printf("Introduce el id de la sala en la que se ve la pelicula: ");
    fflush(stdin);
    fgets(sala.idSalaChar, 4, stdin);
    sscanf(sala.idSalaChar, "%i", &sala.idSalaInt);
    printf("Introduce el titulo de la pelicula: ");
    fgets(titulo, 20, stdin);
    printf("Introduce la sinopsis de la pelicula: ");
    fgets(sinopsis, 100, stdin);
    printf("Introduce el horario de la pelicula: ");
    fgets(horario, 20, stdin);

}

void menuModificarPelicula()
{
    printf("\n============\nMODIFICAR PELICULA\n============\n\n");
    printf("Introduce el id de la pelicula a modificar: ");
    fflush(stdin);
    fgets(idPeliculaChar, 4, stdin);
    sscanf(idPeliculaChar, "%i", &idPeliculaInt);
    printf("Introduce el id de la sala en la que se ve la pelicula: ");
    fflush(stdin);
    fgets(sala.idSalaChar, 4, stdin);
    sscanf(sala.idSalaChar, "%i", &sala.idSalaInt);
    printf("Introduce el nuevo titulo de la pelicula: ");
    fgets(titulo, 20, stdin);
    printf("Introduce la nueva sinopsis de la pelicula: ");
    fgets(sinopsis, 100, stdin);
    printf("Introduce el nuevo horario de la pelicula: ");
    fgets(horario, 20, stdin);

}

void menuModificarUsuario()
{
    printf("\n============\nMODIFICAR USUARIO\n============\n\n");
    printf("Introduce el id del usuario a modificar: ");
    fflush(stdin);
    fgets(usuario.idUsuarioChar, 4, stdin);
    sscanf(usuario.idUsuarioChar, "%i", &usuario.idUsuarioInt);
    printf("Introduce el nuevo nombre del usuario: ");
    fflush(stdin);
    fgets(usuario.nombre, 16, stdin);
    printf("Introduce la nueva respuesta de seguridad: ");
    fgets(usuario.respuesta, 20, stdin);
    printf("Introduce el nuevo correo electronico: ");
    fgets(usuario.correo, 30, stdin);
    printf("Introduce la nueva contrasena: ");
    fgets(usuario.contrasena, 16, stdin);

}

void menuModificarCine()
{
    printf("\n=========\nMODIFICAR CINE\n=========\n\n");
    printf("Introduce el id del cine a modificar: ");
    fflush(stdin);
    fgets(cine.idCineChar, 4, stdin);
    sscanf(cine.idCineChar, "%i", &cine.idCineInt);
    printf("Introduce el nuevo nombre del cine: ");
    fflush(stdin);
    fgets(cine.nombreCine, 20, stdin);
    printf("Introduce la nueva direccion del cine: ");
    fgets(cine.direccionCine, 20, stdin);
    printf("Introduce la nueva ciudad del cine:");
    fgets(cine.ciudadCine, 20, stdin);
    
}

void menuModificarActor()
{
    printf("\n===========\nMODIFICAR ACTOR\n===========\n\n");
    printf("Introduce el id del actor a modificar: ");
    fflush(stdin);
    fgets(idActorChar, 4, stdin);
    sscanf(idActorChar, "%i", &idActorInt);
    printf("Introduce el nuevo id de la pelicula en la que actua el actor: ");
    fflush(stdin);
    fgets(idPeliculaChar, 4, stdin);
    sscanf(idPeliculaChar, "%i", &idPeliculaInt);
    printf("Introduce el nuevo nombre del actor: ");
    fgets(nombreActor, 20, stdin);
   
}

void menuModificarSala()
{
    printf("\n===========\nMODIFICAR SALA\n===========\n\n");
    printf("Introduce el id de la sala a modificar: ");
    fflush(stdin);
    fgets(sala.idSalaChar, 4, stdin);
    sscanf(sala.idSalaChar, "%i", &sala.idSalaInt);
    printf("Introduce el nuevo id del cine en el que está la sala: ");
    fflush(stdin);
    fgets(cine.idCineChar, 4, stdin);
    sscanf(cine.idCineChar, "%i", &cine.idCineInt);
    printf("Introduce el nuevo numero de la sala: ");
    fgets(sala.numeroSalaChar, 3, stdin);
    sscanf(sala.numeroSalaChar, "%i", &sala.numeroSalaInt);
    printf("Introduce el nuevo numero de columnas de la sala: ");
    fgets(sala.nColumnasSalaChar, 3, stdin);
    sscanf(sala.nColumnasSalaChar, "%i", &sala.nColumnasSalaInt);
    printf("Introduce el nuevo numero de filas de la sala: ");
    fgets(sala.nFilasSalaChar, 3, stdin);
    sscanf(sala.nFilasSalaChar, "%i", &sala.nFilasSalaInt);
   
}

void menuModificarAsiento()
{
    printf("\n===========\nMODIFICAR ASIENTO\n===========\n\n");
    printf("Introduce el id del asiento a modificar: ");
    fflush(stdin);
    fgets(asiento.idAsientoChar, 4, stdin);
    sscanf(asiento.idAsientoChar, "%i", &asiento.idAsientoInt);
    printf("Introduce el nuevo id de la sala en la que esta el asiento: ");
    fflush(stdin);
    fgets(sala.idSalaChar, 4, stdin);
    sscanf(sala.idSalaChar, "%i", &sala.idSalaInt);
    printf("Introduce la nueva fila del asiento: ");
    fgets(asiento.filaAsientoChar, 3, stdin);
    sscanf(asiento.filaAsientoChar, "%i", &asiento.filaAsientoInt);
    printf("Introduce el nuevo numero del asiento: ");
    fgets(asiento.numeroAsientoChar, 3, stdin);
    sscanf(asiento.numeroAsientoChar, "%i", &asiento.numeroAsientoInt);
    printf("Introduce la nueva fecha del asiento: ");
    fgets(asiento.fechaAsiento, 11, stdin);
   
}



