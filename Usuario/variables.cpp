#include "variables.h"
int opcionModo;
int opcionEliminar;
int opcionCliente;
int opcionAD;
int opcionAdministrador;
int opcionModificar;
int opcionBvda;

Usuario usuario = Usuario("", "", "", "");
char usuarioAModificar[30];

Pelicula pelicula = Pelicula("", "", "", "");
char PeliculaAModificar[4];

Actor actor = Actor("", "");
char actorAModificar[4];

Sala sala = Sala("", "", "", "");
char salaAModificar[4];

Cine cine = Cine("", "", "");
char cineAModificar[4];

Asiento asiento = Asiento("", "", "", "");
char asientoAModificar[4];

char tablaEliminar[20];
char idEliminar[5];

char tablaVisualizar[20];
char idVisualizar[5];