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

void MenuVisualizarDatos();
void menuBienvenida(); 
void MenuIniciarSesion();
void MenuRegistrarse(); 
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