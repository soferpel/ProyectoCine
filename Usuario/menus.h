#ifndef MENUS_H
#define MENUS_H
#include "usuario.h"
#include "pelicula.h"
#include "actor.h"
#include "cine.h"
#include "sala.h"
#include "asiento.h"

int opcionModo;
int opcionEliminar;
int opcionCliente;
int opcionAD;
int opcionAdministrador;
int opcionModificar;
int opcionBvda;

Usuario usuario = Usuario("", "", "", "");
char usuarioAModificar[30];

Pelicula pelicula = Pelicula("", "", "", 0);
char PeliculaAModificar[4];

Actor actor = Actor("", 0);
char actorAModificar[4];

Sala sala = Sala(0, 0, 0, 0);
char salaAModificar[4];

Cine cine = Cine("", "", "");
char cineAModificar[4];

Asiento asiento = Asiento(0, 0, "", 0);
char asientoAModificar[4];

char tablaEliminar[20];
char idEliminar[5];

char tablaVisualizar[20];
char idVisualizar[5];

void MenuVisualizarDatos();
void menuBienvenida(); 
void menuInicioSesion(); 
void menuRegistro(); 
void menuModificarDatos(); 
void menuModificarPelicula();
void menuModificarUsuario();
void menuModificarCine();
void menuModificarActor();
void menuModificarSala();
void menuModificarAsiento();
void menuBorrarDatos();
void menuAnadirDatos();
void menuAnadirAsiento();
void menuAnadirPelicula();
void menuAnadirActor();
void menuAnadirCine();
void menuAnadirSala();
void menuPrincipalAdministrador(); 
void menuPrincipalCliente();
void menuEleccionModo();

#endif