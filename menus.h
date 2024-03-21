#ifndef MENUPRINCIPAL_H
#define MENUPRINCIPAL_H

//variables para opciones de los menus
int opcionIntBvda;
char opcionCharBvda[2];   //Se llaman asi para diferenciarlas

int opcionIntAd;
char opcionCharAd[2];

int opcionIntPpal;
char opcionCharPpal[2];

int opcionIntAD;
char opcionCharAD[2];

int autenticacionExitosa;

char nombre[16];
char apellido[20];
char nombreUsuario[16];
char contrasena[16];
char id[5];

//funciones de los menus
void menuBienvenida();
void menuInicioSesion();
void menuRegistro();
void menuModificarDatos();
void menuBorrarDatos();
void menuAnadirDatos();
void menuAdministrador();
void menuMisEntradas();
void menuComprarEntradas();
void menuPrincipal();

#endif