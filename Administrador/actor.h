#ifndef ACTOR_H
#define ACTOR_H
#include "configuracion.h"

typedef struct
{
    char idActorChar[3];
    int idActorInt;
    char nombreActor[20];
} Actor;

void validarActor(PathDB rutaDB);
int callbackActor(void *data, int argc, char **argv, char **col_names);
void anadirActor(PathDB rutaDB);
void modificarActor(PathDB rutaDB);

#endif