#ifndef BBDD_H
#define BBDD_H
#include "configuracion.h"

//VALIDACIONES 
int validacionUsuario;
int validacionCine;
int validacionSala;
int validacionPelicula;
int validacionActor;
int validacionAsiento;


//GESTION DE USUARIOS
char nombre[16];  //Estas variables tambien sirven para la tabla de usuarios de la bbdd
char respuesta[20];
char correo[30];
char contrasena[16];
int autenticacionExitosa;


//TABLAS BASE DE DATOS
//USUARIO
int idUsuarioInt;
char idUsuarioChar[4];

//ASIENTO
char idAsientoChar[5];
int idAsientoInt;
char filaAsientoChar[3];
int filaAsientoInt;
char numeroAsientoChar[3];
int numeroAsientoInt;
char fechaAsiento[11];

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