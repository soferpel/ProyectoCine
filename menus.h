#ifndef MENUPRINCIPAL_H
#define MENUPRINCIPAL_H

//variables para opciones de los menus
int opcionBienvenida;

char nombre[16];
char apellido[20];
char nombreUsuario[16];
char contrasena[16];

//funciones de los menus
void menuBienvenida();
void menuInicioSesion();
void menuRegistro();
void menuModificarUsuario();
void menuMisEntradas();
void menuComprarEntradas();
void menuPrincipal();

#endif