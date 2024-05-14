#ifndef MENUPRINCIPAL_H
#define MENUPRINCIPAL_H


//variables para opciones de los menus
int opcionIntBvda;
char opcionCharBvda[2];   //Se llaman asi para diferenciarlas

int opcionIntAd;
char opcionCharAd[2];

int opcionIntAD;
char opcionCharAD[2];

int opcionIntEliminar;
char opcionCharEliminar[4];

int opcionIntModificar;
char opcionCharModificar[4];


//funciones de los menus
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
void menuAdministrador(); 
void menuMisEntradas();
void menuComprarEntradas();
void menuPrincipal();
void seleccionarCine();

#endif