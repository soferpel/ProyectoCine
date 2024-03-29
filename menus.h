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

int opcionIntModificar;
char opcionCharModificar[4];

int autenticacionExitosa;
int hayQueAnadirDatos;
int hayQueModificarDatos;

char nombre[16];
char respuesta[20];
char correo[20];
char contrasena[16];
char tablaEliminar[20];
char idEliminar[5];

//ASIENTO
int idSalaInt;
char idSalaChar[4];
char filaAsiento[5];
char numeroAsiento[4];
char fechaAsiento[12];

//CINE
char nombreCine[20];
char direccionCine[20];
char ciudadCine[20];

//SALA
int idCineInt;
char idCineChar[4];
char numeroSala[20];
char nColumnasSala[20];
char nFilasSala[20];

//PELICULA
char titulo[20];
char sinopsis[100];
char horario[20];

//ACTOR
int idPeliculaInt;
char idPeliculaChar[4];
char nombreActor[20];

//funciones de los menus
void menuBienvenida();
void menuInicioSesion();
void menuRegistro();
void menuModificarDatos();
void menuModificarPelicula();
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

#endif