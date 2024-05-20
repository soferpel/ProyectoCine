#ifndef BBDD_H
#define BBDD_H
#include "configuracion.h"
#include "usuario.h"
#include "asiento.h"
#include "sala.h"
#include "cine.h"
#include "pelicula.h"
#include "actor.h"
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
Pelicula pelicula;
Actor actor;

//GESTION DE USUARIOS
int autenticacionExitosa;

//OTROS
char tablaEliminar[20];
char idEliminar[5];
char tablaVisualizar[20];
char idVisualizar[5];
int hayQueAnadirDatos;
int hayQueModificarDatos;

void crearTabla(PathDB rutaDB, Logger *logger);
void borrarTablas(PathDB rutaDB, Logger *logger);
void eliminarFila(PathDB rutaDB, Logger *logger);
int visualizarDatos(PathDB rutaDB, Logger *logger, char *buffer);

//VALIDACIONES Y CALLBACKS
int callbackVisualizarDatos(void *data, int argc, char **argv, char **azColName);

#endif