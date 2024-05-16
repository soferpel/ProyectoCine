#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menus.h"
#include <iostream>

void MenuEleccionModo::mostrar()
{
    cout << "===============" << endl;
    cout << " ELECCION MODO " << endl;
    cout << "===============" << endl;
    cout << endl;
    cout << "1. Cliente" << endl;
    cout << "2. Administrador" << endl;
    cout << "3. Salir" << endl;
    cout << endl;
    cin >> opcionModo;
}

void menuBorrarDatos()
{
    cout << "===============" << endl;
    cout << " ELECCION MODO " << endl;
    cout << "===============" << endl;
    cout << endl;
    cout << "De que tabla quieres eliminar datos?\n" << endl;
    cout << "1. Usuario\n2. Cine\n3. Actor\n4. Asiento\n5. Pelicula\n6. Sala\n\n" << endl;
    fflush(stdin);
    cin >> opcionEliminar;
    switch (opcionEliminar)
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
    cout << "Escribe el id de los datos a borrar?\n" << endl;
    cin >> idEliminar;
}

void menuAnadirAsiento()
{
    cout << "===============" << endl;
    cout << " ANADIR ASIENTO " << endl;
    cout << "===============" << endl;
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
    fgets(cine.direccionCine, 40, stdin);
    printf("Cual es la ciudad del cine?\n");
    fgets(cine.ciudadCine, 20, stdin);

}

void menuAnadirSala() {
    printf("\n============\nANADIR SALA\n============\n\n");
    
    printf("Introduce el id del cine en la que esta la sala: ");
    fflush(stdin);
    fgets(cine.idCineChar, 4, stdin);
    sscanf(cine.idCineChar, "%i", &cine.idCineInt);
    printf("Cual es el numero de filas que contiene la sala? ");
    fgets(sala.nFilasSalaChar, 3, stdin);
    limpiarBuffer();
    sscanf(sala.nFilasSalaChar, "%i", &sala.nFilasSalaInt);
    printf("Cual es el numero de columnas que contiene la sala? ");
    fgets(sala.nColumnasSalaChar, 3, stdin);
    sscanf(sala.nColumnasSalaChar, "%i", &sala.nColumnasSalaInt);
    printf("Cual es el numero de la sala? ");
    fgets(sala.numeroSalaChar, 3, stdin);
    sscanf(sala.numeroSalaChar, "%i", &sala.numeroSalaInt);
}

void menuAnadirActor()
{
    printf("\n============\nANADIR ACTOR\n============\n\n");
    printf("Introduce el id de la pelicula en la que actua el actor: ");
    fflush(stdin);
    fgets(pelicula.idPeliculaChar, 4, stdin);
    sscanf(pelicula.idPeliculaChar, "%i", &pelicula.idPeliculaInt);
    printf("Cual es el nombre del actor? ");
    fgets(actor.nombreActor, 20, stdin);

}

void menuAnadirPelicula()
{
    printf("\n============\nANADIR PELICULA\n============\n\n");
    printf("Introduce el id de la sala en la que se ve la pelicula: ");
    fflush(stdin);
    fgets(sala.idSalaChar, 4, stdin);
    sscanf(sala.idSalaChar, "%i", &sala.idSalaInt);
    printf("Introduce el titulo de la pelicula: ");
    fgets(pelicula.titulo, 20, stdin);
    printf("Introduce la sinopsis de la pelicula: ");
    fgets(pelicula.sinopsis, 200, stdin);
    printf("Introduce el horario de la pelicula: ");
    fgets(pelicula.horario, 20, stdin);

}
