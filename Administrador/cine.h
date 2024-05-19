#ifndef CINE_H
#define CINE_H
#include "configuracion.h"

typedef struct 
{
    int idCineInt;
    char idCineChar[4];
    char nombreCine[20];
    char direccionCine[20];
    char ciudadCine[20];

} Cine;

void anadirCine(PathDB rutaDB, Logger *logger); 
void modificarCine(PathDB rutaDB, Logger *logger);
void validarCine(PathDB rutaDB, Logger *logger);
int callbackCine(void *data, int argc, char **argv, char **col_names);

#endif