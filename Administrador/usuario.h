#ifndef USUARIO_H
#define USUARIO_H
#include "configuracion.h"

typedef struct
{
    char nombre[16];  
    char respuesta[20];
    char correo[30];
    char contrasena[16];
    int idUsuarioInt;
    char idUsuarioChar[4];

} Usuario;

void guardarUsuario(PathDB rutaDB);
void modificarUsuario(PathDB rutaDB);
void validarUsuario(PathDB rutaDB);
int callbackUsuario(void *data, int argc, char **argv, char **col_names);

#endif