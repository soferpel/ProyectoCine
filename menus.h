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

int autenticacionExitosa;
int hayQueAnadirDatos;
int hayQueModificarDatos;

char nombre[16];
char respuesta[20];
char correo[30];
char contrasena[16];
char tablaEliminar[20];
char idEliminar[5];

//USUARIO
int idUsuarioInt;
char idUsuarioChar[4];

//ASIENTO
char idAsientoChar[5];
int idAsientoInt;
int idSalaInt;
char idSalaChar[4];
char filaAsientoChar[3];
int filaAsientoInt;
char numeroAsientoChar[3];
int numeroAsientoInt;
char fechaAsiento[11];

//CINE
char nombreCine[20];
char direccionCine[20];
char ciudadCine[20];

//SALA
int idCineInt;
char idCineChar[4];
char numeroSalaChar[3];
int numeroSalaInt;
char nColumnasSalaChar[3];
int nColumnasSalaInt;
char nFilasSalaChar[3];
int nFilasSalaInt;

//PELICULA
char titulo[20];
char sinopsis[100];
char horario[20];

//ACTOR
char idActorChar[3];
int idActorInt;
int idPeliculaInt;
char idPeliculaChar[4];
char nombreActor[20];

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

#endif