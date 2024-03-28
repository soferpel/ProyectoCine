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

int opcionIntEliminar;
char opcionCharEliminar[4];

int autenticacionExitosa;
int hayQueAnadirDatos;

char nombre[16];
char respuesta[20];
char correo[20];
char contrasena[16];
char tabla[20];
char id[5];
//ASIENTO
int filaAsiento;
int numeroAsiento;
char fechaAsiento[12];

//CINE
char nombreCine[20];
char direccionCine[20];
char ciudadCine[20];

//SALA
int idCine;
char numeroSala[20];
char nColumnasSala[20];
char nFilasSala[20];

//PELICULA
int idSala;
char titulo[20];
char sinopsis[100];
char horario[20];

//funciones de los menus
void menuBienvenida();
void menuInicioSesion();
void menuRegistro();
void menuModificarDatos();
void menuBorrarDatos();
void menuAnadirDatos();
void menuAnadirAsiento();
// void menuAnadirPelicula();
// void menuAnadirActor();
// void menuAnadirCine();
// void menuAnadirSala();
void menuAdministrador();
void menuMisEntradas();
void menuComprarEntradas();
void menuPrincipal();

#endif