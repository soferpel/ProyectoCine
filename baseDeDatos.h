#ifndef BBDD_H
#define BBDD_H

char nomUsuario[20];
char contrasenya[20];
int validacionUsuario;

void crearTabla();
void eliminarFila();
void menuAnadirAsiento();
void menuAnadirCine();
void anadirSala();
void anadirActor();
void anadirPelicula();
void anadirCine();
void guardarUsuario();
void validarUsuario();
int callbackUsuario(void *data, int argc, char **argv, char **col_names);

#endif