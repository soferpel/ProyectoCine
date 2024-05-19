#ifndef USUARIO_H
#define USUARIO_H
#include "configuracion.h"
#include "logger.h"

typedef struct
{
    char nombre[16];  
    char respuesta[20];
    char correo[30];
    char contrasena[16];
    int idUsuarioInt;
    char idUsuarioChar[4];

} Usuario;

void guardarUsuario(PathDB rutaDB, Logger *logger);
void modificarUsuario(PathDB rutaDB, Logger *logger);
void validarUsuario(PathDB rutaDB, Logger *logger);
int callbackUsuario(void *data, int argc, char **argv, char **col_names);

#endif