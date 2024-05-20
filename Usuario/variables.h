#ifndef VARIABLES_H
#define VARIABLES_H

#include "Usuario.h"
#include "Pelicula.h"
#include "Actor.h"
#include "Sala.h"
#include "Cine.h"
#include "Asiento.h"

extern int opcionModo;
extern int opcionEliminar;
extern int opcionVisualizar;
extern int opcionCliente;
extern int opcionAD;
extern int opcionAdministrador;
extern int opcionModificar;
extern int opcionBvda;
extern int opcionResetearBD;

extern int aElegidoModo;
extern int aIniciadoSesion;

extern Usuario usuario;
extern char usuarioAModificar[30];

extern Pelicula pelicula;
extern char PeliculaAModificar[4];

extern Actor actor;
extern char actorAModificar[4];

extern Sala sala;
extern char salaAModificar[4];

extern Cine cine;
extern char cineAModificar[4];

extern Asiento asiento;
extern char asientoAModificar[4];

extern char tablaEliminar[20];
extern char idEliminar[5];

extern char tablaVisualizar[20];


#endif