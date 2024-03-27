#ifndef BBDD_H
#define BBDD_H

char nomUsuario[20];
char contrasenya[20];
int validacionUsuario;

void guardarUsuario();
void validarUsuario();
int callbackUsuario(void *data, int argc, char **argv, char **col_names);

#endif