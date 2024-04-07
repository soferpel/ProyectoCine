#ifndef BBDD_H
#define BBDD_H
#include "configuracion.h"
#include "usuario.h"
#include "asiento.h"
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

//GESTION DE USUARIOS
int autenticacionExitosa;

//ASIENTO


//CINE
int idCineInt;
char idCineChar[4];
char nombreCine[20];
char direccionCine[20];
char ciudadCine[20];

//SALA
int idSalaInt;
char idSalaChar[4];
char numeroSalaChar[3];
int numeroSalaInt;
char nColumnasSalaChar[3];
int nColumnasSalaInt;
char nFilasSalaChar[3];
int nFilasSalaInt;

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

void anadirSala(PathDB rutaDB);
void anadirActor(PathDB rutaDB);
void anadirPelicula(PathDB rutaDB);
void anadirCine(PathDB rutaDB);
void modificarPelicula(PathDB rutaDB);
void modificarCine(PathDB rutaDB);
void modificarActor(PathDB rutaDB);
void modificarSala(PathDB rutaDB);


//VALIDACIONES Y CALLBACKS

void validarCine(PathDB rutaDB);
int callbackCine(void *data, int argc, char **argv, char **col_names);
void validarSala(PathDB rutaDB);
int callbackSala(void *data, int argc, char **argv, char **col_names);
void validarPelicula(PathDB rutaDB);
int callbackPelicula(void *data, int argc, char **argv, char **col_names);
void validarActor(PathDB rutaDB);
int callbackActor(void *data, int argc, char **argv, char **col_names);

#endif