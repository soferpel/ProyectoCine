#ifndef BBDD_H
#define BBDD_H
#include "configuracion.h"
#include "usuario.h"
#include "asiento.h"
#include "sala.h"
#include "cine.h"
#include "sqlite3.h"

//VALIDACIONES 
int validacionUsuario;
int validacionCine;
int validacionSala;
int validacionPelicula;
int validacionActor;
int validacionAsiento;

Usuario usuario;
Asiento asiento;
Cine cine;
Sala sala;

//GESTION DE USUARIOS
int autenticacionExitosa;

//ASIENTO

//CINE

//SALA

//PELICULA
int idPeliculaInt;
char idPeliculaChar[4];
char titulo[20];
char sinopsis[100];
char horario[20];

//ACTOR
char idActorChar[3];
int idActorInt;
char nombreActor[20];

//OTROS
char tablaEliminar[20];
char idEliminar[5];
int hayQueAnadirDatos;
int hayQueModificarDatos;

void crearTabla(PathDB rutaDB);
void borrarTablas(PathDB rutaDB);
void eliminarFila(PathDB rutaDB);

void anadirActor(PathDB rutaDB);
void anadirPelicula(PathDB rutaDB);
void modificarPelicula(PathDB rutaDB);
void modificarActor(PathDB rutaDB);


//VALIDACIONES Y CALLBACKS

void validarPelicula(PathDB rutaDB);
int callbackPelicula(void *data, int argc, char **argv, char **col_names);
void validarActor(PathDB rutaDB);
int callbackActor(void *data, int argc, char **argv, char **col_names);

#endif