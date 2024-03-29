#ifndef BBDD_H
#define BBDD_H

int validacionUsuario;
int validacionCine;
int validacionSala;
int validacionPelicula;

void crearTabla();
void borrarTablas();
void eliminarFila();
void anadirAsiento();
void anadirSala();
void anadirActor();
void anadirPelicula();
void anadirCine();
void guardarUsuario();

//VALIDACIONES Y CALLBACKS
void validarUsuario();
int callbackUsuario(void *data, int argc, char **argv, char **col_names);
void validarCine();
int callbackCine(void *data, int argc, char **argv, char **col_names);
void validarSala();
int callbackSala(void *data, int argc, char **argv, char **col_names);
void validarPelicula();
int callbackPelicula(void *data, int argc, char **argv, char **col_names);

#endif