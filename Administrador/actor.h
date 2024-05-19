#ifndef ACTOR_H
#define ACTOR_H
#include "configuracion.h"
#include "logger.h"

typedef struct
{
    char idActorChar[3];
    int idActorInt;
    char nombreActor[20];
} Actor;

void validarActor(PathDB rutaDB, Logger *logger);
int callbackActor(void *data, int argc, char **argv, char **col_names);
void anadirActor(PathDB rutaDB, Logger *logger);
void modificarActor(PathDB rutaDB, Logger *logger);

#endif