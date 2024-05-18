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
extern int opcionCliente;
extern int opcionAD;
extern int opcionAdministrador;
extern int opcionModificar;
extern int opcionBvda;

extern Usuario usuario = Usuario("", "", "", "");
extern char usuarioAModificar[30];

extern Pelicula pelicula = Pelicula("", "", "", "");
extern char PeliculaAModificar[4];

extern Actor actor = Actor("", "");
extern char actorAModificar[4];

extern Sala sala = Sala("", "", "", "");
extern char salaAModificar[4];

extern Cine cine = Cine("", "", "");
extern char cineAModificar[4];

extern Asiento asiento = Asiento("", "", "", "");
extern char asientoAModificar[4];

extern char tablaEliminar[20];
extern char idEliminar[5];

extern char tablaVisualizar[20];
extern char idVisualizar[5];

#endif // VARIABLES_H