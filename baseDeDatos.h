#ifndef BBDD_H
#define BBDD_H
#include "configuracion.h"

int validacionUsuario;
int validacionCine;
int validacionSala;
int validacionPelicula;
int validacionActor;

void crearTabla(PathDB rutaDB);
void borrarTablas(PathDB rutaDB);
void eliminarFila(PathDB rutaDB);
void anadirAsiento(PathDB rutaDB);
void anadirSala(PathDB rutaDB);
void anadirActor(PathDB rutaDB);
void anadirPelicula(PathDB rutaDB);
void anadirCine(PathDB rutaDB);
void guardarUsuario(PathDB rutaDB);
void modificarPelicula(PathDB rutaDB);
void modificarUsuario(PathDB rutaDB);
void modificarCine(PathDB rutaDB);
void modificarActor(PathDB rutaDB);
void modificarSala(PathDB rutaDB);
void modificarAsiento(PathDB rutaDB);

//VALIDACIONES Y CALLBACKS
void validarUsuario(PathDB rutaDB);
int callbackUsuario(void *data, int argc, char **argv, char **col_names);
void validarCine(PathDB rutaDB);
int callbackCine(void *data, int argc, char **argv, char **col_names);
void validarSala(PathDB rutaDB);
int callbackSala(void *data, int argc, char **argv, char **col_names);
void validarPelicula(PathDB rutaDB);
int callbackPelicula(void *data, int argc, char **argv, char **col_names);
void validarActor(PathDB rutaDB);
int callbackActor(void *data, int argc, char **argv, char **col_names);

#endif