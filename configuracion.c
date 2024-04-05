#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "configuracion.h" 

PathDB leerConfiguracion(char* fichero) {
    
    PathDB rutaDB;
    rutaDB.tamanyo = 8;
    rutaDB.ruta = (char*) malloc(sizeof(char) * rutaDB.tamanyo);
    FILE* f;
    f = fopen(fichero, "r");
    if (f == NULL) {
        perror("Error al abrir el archivo");
        exit(EXIT_FAILURE);
    }

    int path = 0; 
    int i = 0;
    do {
        path = fgetc(f);
        rutaDB.ruta[i] = path;
        i++;
    } while (path != EOF);
    rutaDB.ruta[i - 1] = '\0';

    fclose(f);

    return rutaDB;
}

