#ifndef PELICULA_H
#define PELICULA_H
#include "configuracion.h"

typedef struct
{
    int idPeliculaInt;
    char idPeliculaChar[4];
    char titulo[20];
    char sinopsis[100];
    char horario[20];

} Pelicula;

void validarPelicula(PathDB rutaDB, Logger *logger);
int callbackPelicula(void *data, int argc, char **argv, char **col_names);
void anadirPelicula(PathDB rutaDB, Logger *logger);
void modificarPelicula(PathDB rutaDB, Logger *logger);

#endif