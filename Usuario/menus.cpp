#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menus.h"
#include <iostream>
#include "variables.h"

using namespace std;

void menuEleccionModo()
{
    cout << "===============" << endl;
    cout << " ELECCION MODO " << endl;
    cout << "===============" << endl;
    cout << endl;
    cout << "1. Cliente" << endl;
    cout << "2. Administrador" << endl;
    cout << "3. Salir" << endl;
    cout << endl;
    fflush(stdin);
    cin >> opcionModo;
    char c; while ((c = getchar()) != '\n' && c != EOF); // Vacía el buffer de entrada
}

void menuBienvenida()
{
    cout << "============" << endl;
    cout << " BIENVENIDO " << endl;
    cout << "============" << endl;
    cout << endl;
    cout << "Que desea hacer?" << endl;
    cout << endl;
    cout << "1. Iniciar sesion" << endl;
    cout << "2. Registrarse" << endl;
    cout << "3. Salir" << endl;
    cout << endl;
    fflush(stdin);
    cin >> opcionBvda;
    char c; while ((c = getchar()) != '\n' && c != EOF); // Vacía el buffer de entrada
}

void menuPrincipalCliente()
{
    cout << "=========" << endl;
    cout << " CLIENTE " << endl;
    cout << "=========" << endl;
    cout << endl;
    cout << "Que desea hacer?" << endl;
    cout << endl;
    cout << "1. Visualizar datos" << endl;
    cout << "2. Modificar datos" << endl;
    cout << "3. Salir" << endl;
    cout << endl;
    fflush(stdin);
    cin >> opcionCliente;
    char c; while ((c = getchar()) != '\n' && c != EOF); // Vacía el buffer de entrada
}

void menuVisualizarDatos()
{
    cout << "==================" << endl;
    cout << " VISUALIZAR DATOS " << endl;
    cout << "==================" << endl;
    cout << endl;
    fflush(stdin);
    cout << "Que tabla desea visualizar?" << endl;
    cin >> tablaVisualizar;
    char c; while ((c = getchar()) != '\n' && c != EOF); // Vacía el buffer de entrada
}

void menuPrincipalAdministrador()
{
    cout << "===============" << endl;
    cout << " ADMINISTRADOR " << endl;
    cout << "===============" << endl;
    cout << endl;
    cout << "Que desea hacer?" << endl;
    cout << endl;
    cout << "1. Modificar datos" << endl;
    cout << "2. Eliminar datos" << endl;
    cout << "3. Anadir datos" << endl;
    cout << "4. Salir" << endl;
    cout << endl;
    fflush(stdin);
    cin >> opcionAdministrador;
    char c; while ((c = getchar()) != '\n' && c != EOF); // Vacía el buffer de entrada
}

void menuIniciarSesion()
{
    char correo[30];
    char contrasena[16];
    cout << "================" << endl;
    cout << " INICIAR SESION " << endl;
    cout << "================" << endl;
    cout << endl;
    cout << "Ingrese su correo de usuario: ";
    fflush(stdin);
    cin >> correo;
    usuario.setCorreo(correo);
    cout << "Ingrese su contrasena: ";
    cin >> contrasena;
    usuario.setContrasena(contrasena);
    char c; while ((c = getchar()) != '\n' && c != EOF); // Vacía el buffer de entrada
}

void menuRegistrarse()
{
    char nombreUsuario[16];
    char correo[30];
    char contrasena[16];
    char respuestaSeguridad[20];
    cout << "=============" << endl;
    cout << " REGISTRARSE " << endl;
    cout << "=============" << endl;
    cout << endl;
    cout << "Ingrese su nombre de usuario: ";
    fflush(stdin);
    cin >> nombreUsuario;
    usuario.setNombre(nombreUsuario);
    cout << "Ingrese su correo electronico: ";
    cin >> correo;
    usuario.setCorreo(correo);
    cout << "Ingrese su contrasena: ";
    cin >> contrasena;
    usuario.setContrasena(contrasena);
    cout << "Responda esta pregunta de seguridad (Cual es su pelicula favorita?): ";
    cin >> respuestaSeguridad;
    usuario.setRespuesta(respuestaSeguridad);
    char c; while ((c = getchar()) != '\n' && c != EOF); // Vacía el buffer de entrada
}

void menuModificarDatos()
{
    cout << "=================" << endl;
    cout << " MODIFICAR DATOS " << endl;
    cout << "=================" << endl;
    cout << endl;
    cout << "Que desea modificar?" << endl;
    cout << endl;
    cout << "1. Pelicula" << endl;
    cout << "2. Usuario" << endl;
    cout << "3. Cine" << endl;
    cout << "4. Actor" << endl;
    cout << "5. Sala" << endl;
    cout << "6. Asiento" << endl;
    cout << "7. Salir" << endl;
    cout << endl;
    fflush(stdin);
    cin >> opcionModificar;
    char c; while ((c = getchar()) != '\n' && c != EOF); // Vacía el buffer de entrada
}

void menuModificarPelicula()
{
    char titulo[20];
    char sinopsis[100];
    char horario[20];
    char idSala[5];
    cout << "====================" << endl;
    cout << " MODIFICAR PELICULA " << endl;
    cout << "====================" << endl;
    cout << endl;
    cout << "Introduce el ID de la pelicula a modificar: ";
    fflush(stdin);
    cin >> PeliculaAModificar;
    cout << "Introduce el ID de la sala en la que se la pelicula: ";
    cin >> idSala;
    pelicula.setIdSala(idSala);
    cout << "Introduce el nuevo titulo de la pelicula: ";
    cin >> titulo;
    pelicula.setTitulo(titulo);
    cout << "Introduce la nueva sinopsis de la pelicula: ";
    cin >> sinopsis;
    pelicula.setSinopsis(sinopsis);
    cout << "Introduce el nuevo horario de la pelicula: ";
    cin >> horario;
    pelicula.setHorario(horario);
    cout << endl;
    char c; while ((c = getchar()) != '\n' && c != EOF); // Vacía el buffer de entrada
}

void menuModificarUsuario()
{
    char nombreUsuario[16];
    char correoNuevo[30];
    char contrasena[16];
    char respuestaSeguridad[20];
    cout << "===================" << endl;
    cout << " MODIFICAR USUARIO " << endl;
    cout << "===================" << endl;
    cout << endl;
    cout << "<< Solo podras modificar tus propios datos >>" << endl;
    cout << endl;
    cout << "Introduce tu correo electronico: ";
    fflush(stdin);
    cin >> usuarioAModificar;
    cout << "Introduce tu nuevo nombre: ";
    cin >> nombreUsuario;
    usuario.setNombre(nombreUsuario);
    cout << "Introduce tu nuevo correo electronico: ";
    cin >> correoNuevo;
    usuario.setCorreo(correoNuevo);
    cout << "Introduce tu neva contrasena: ";
    cin >> contrasena;
    usuario.setContrasena(contrasena);
    cout << "Introduce tu nueva respuesta de seguridad (Cal es tu pelicula favorita?): ";
    cin >> respuestaSeguridad;
    usuario.setRespuesta(respuestaSeguridad);
    cout << endl;
    char c; while ((c = getchar()) != '\n' && c != EOF); // Vacía el buffer de entrada
}

void menuModificarCine()
{
    char nombreCine[20];
    char direccionCine[20];
    char ciudadCine[20];
    cout << "================" << endl;
    cout << " MODIFICAR CINE " << endl;
    cout << "================" << endl;
    cout << endl;
    cout << "Introduce el ID del cine a modificar: ";
    fflush(stdin);
    cin >> cineAModificar;
    cout << "Introduce el nuevo nombre del cine: ";
    cin >> nombreCine;
    cine.setNombreCine(nombreCine);
    cout << "Introduce la nueva direccion del cine: ";
    cin >> direccionCine;
    cine.setDireccionCine(direccionCine);
    cout << "Introduce la nueva ciudad del cine: ";
    cin >> ciudadCine;
    cine.setCiudadCine(ciudadCine);
    cout << endl;
    char c; while ((c = getchar()) != '\n' && c != EOF); // Vacía el buffer de entrada
}

void menuModificarActor()
{
    char nombreActor[20];
    char idPelicula[5];
    cout << "=================" << endl;
    cout << " MODIFICAR ACTOR " << endl;
    cout << "=================" << endl;
    cout << endl;
    cout << "Introduce el ID del actor a modificar: ";
    fflush(stdin);
    cin >> actorAModificar;
    cout << "Introduce el nuevo nombre del actor: ";
    cin >> nombreActor;
    actor.setNombreActor(nombreActor);
    cout << "Introduce el ID de la nueva pelicula en la que actua: ";
    cin >> idPelicula;
    actor.setIdPelicula(idPelicula);
    cout << endl;
    char c; while ((c = getchar()) != '\n' && c != EOF); // Vacía el buffer de entrada
}

void menuModificarSala()
{
    char idCine[5];
    char numeroSala[5];
    char nColumnasSala[5];
    char nFilasSala[5];
    cout << "================" << endl;
    cout << " MODIFICAR SALA " << endl;
    cout << "================" << endl;
    cout << endl;
    cout << "Introduce el ID de la sala a modificar: ";
    fflush(stdin);
    cin >> salaAModificar;
    cout << "Introduce el nuevo numero de la sala: ";
    cin >> numeroSala;
    sala.setNumeroSala(numeroSala);
    cout << "Introduce el nuevo numero de columnas de la sala: ";
    cin >> nColumnasSala;
    sala.setNColumnasSala(nColumnasSala);
    cout << "Introduce el nuevo numero de filas de la sala: ";
    cin >> nFilasSala;
    sala.setNFilasSala(nFilasSala);
    cout << "Introduce el nuevo ID del cine al que pertenece la sala: ";
    cin >> idCine;
    sala.setIdCine(idCine);
    cout << endl;
    char c; while ((c = getchar()) != '\n' && c != EOF); // Vacía el buffer de entrada
}

void menuModificarAsiento()
{
    char idSala[5];
    char filaAsiento[5];
    char numeroAsiento[5];
    char fechaAsiento[11];
    cout << "===================" << endl;
    cout << " MODIFICAR ASIENTO " << endl;
    cout << "===================" << endl;
    cout << endl;
    cout << "Introduce el ID del asiento a modificar: ";
    fflush(stdin);
    cin >> asientoAModificar;
    cout << "Introduce la nueva fila del asiento: ";
    cin >> filaAsiento;
    asiento.setFilaAsiento(filaAsiento);
    cout << "Introduce el nuevo numero del asiento: ";
    cin >> numeroAsiento;
    asiento.setNumeroAsiento(numeroAsiento);
    cout << "Introduce la nueva fecha del asiento (dd-MM-yyyy): ";
    cin >> fechaAsiento;
    asiento.setFechaAsiento(fechaAsiento);
    cout << "Introduce el nuevo ID de la sala a la que pertenece el asiento: ";
    cin >> idSala;
    asiento.setIdSala(idSala);
    cout << endl;
    char c; while ((c = getchar()) != '\n' && c != EOF); // Vacía el buffer de entrada
}

void menuBorrarDatos()
{
    cout << "================" << endl;
    cout << " ELIMINAR DATOS " << endl;
    cout << "================" << endl;
    cout << endl;
    cout << "De que tabla quieres eliminar datos?" << endl;
    cout << "1. Usuario\n2. Cine\n3. Actor\n4. Asiento\n5. Pelicula\n6. Sala" << endl;
    fflush(stdin);
    cin >> opcionEliminar;
    switch (opcionEliminar)
    {
    case 1:
        strcpy(tablaEliminar, "USUARIO");
        break;
    case 2:
        strcpy(tablaEliminar, "CINE");
        break;
    case 3:
        strcpy(tablaEliminar, "ACTOR");
        break;
    case 4:
        strcpy(tablaEliminar, "ASIENTO");
        break;
    case 5:
        strcpy(tablaEliminar, "PELICULA");
        break;
    case 6:
        strcpy(tablaEliminar, "SALA");
        break;
    }
    cout << "Escribe el id de los datos a borrar?" << endl;
    cin >> idEliminar;
    char c; while ((c = getchar()) != '\n' && c != EOF); // Vacía el buffer de entrada
}

void menuAnadirAsiento()
{
    char idSala[5];
    char filaAsiento[5];
    char numeroAsiento[5];
    char fechaAsiento[11];
    cout << "================" << endl;
    cout << " ANADIR ASIENTO " << endl;
    cout << "================" << endl;
    cout << "Introduce el id de la sala en la que esta el asiento: " << endl;
    fflush(stdin);
    cin >> idSala;
    asiento.setIdSala(idSala);
    cout << "Introduce la fila del asiento: " << endl;
    cin >> filaAsiento;
    asiento.setFilaAsiento(filaAsiento);
    cout << "Introduce el numero del asiento: " << endl;
    cin >> numeroAsiento;
    asiento.setNumeroAsiento(numeroAsiento);
    cout << "Introduce la fecha del asiento: " << endl;
    cin >> fechaAsiento;
    asiento.setFechaAsiento(fechaAsiento);
    char c; while ((c = getchar()) != '\n' && c != EOF); // Vacía el buffer de entrada
}

void menuAnadirDatos()
{
    cout << "==============" << endl;
    cout << " ANADIR DATOS " << endl;
    cout << "==============" << endl;
    cout << "Que datos quieres anadir?" << endl;
    cout << "1. Usuario\n 2. Asiento\n 3. Pelicula\n 4. Actor\n 5. Cine\n 6. Sala\n 7. Salir" << endl;
    fflush(stdin);
    cin >> opcionAD;
    char c; while ((c = getchar()) != '\n' && c != EOF); // Vacía el buffer de entrada
}

void menuAnadirCine()
{
    char nombreCine[20];
    char direccionCine[20];
    char ciudadCine[20];
    cout << "=============" << endl;
    cout << " ANADIR CINE " << endl;
    cout << "=============" << endl;
    cout << "Cual es el nombre del cine?" << endl;
    fflush(stdin);
    cin >> nombreCine;
    cine.setNombreCine(nombreCine);
    cout << "Cual es la direccion del cine?" << endl;
    cin >> direccionCine;
    cine.setDireccionCine(direccionCine);
    cout << "Cual es la ciudad del cine?" << endl;
    cin >> ciudadCine;
    cine.setCiudadCine(ciudadCine);
    char c; while ((c = getchar()) != '\n' && c != EOF); // Vacía el buffer de entrada
}

void menuAnadirSala()
{
    char idCine[5];
    char numeroSala[5];
    char nColumnasSala[5];
    char nFilasSala[5];
    cout << "=============" << endl;
    cout << " ANADIR SALA " << endl;
    cout << "=============" << endl;
    cout << "Introduce el id del cine en la que esta la sala: " << endl;
    fflush(stdin);
    cin >> idCine;
    sala.setIdCine(idCine);
    cout << "Cual es el numero de filas que contiene la sala? " << endl;
    cin >> nFilasSala;
    sala.setNFilasSala(nFilasSala);
    cout << "Cual es el numero de columnas que contiene la sala? " << endl;
    cin >> nColumnasSala;
    sala.setNColumnasSala(nColumnasSala);
    cout << "Cual es el numero de la sala? " << endl;
    cin >> numeroSala;
    sala.setNumeroSala(numeroSala);
    char c; while ((c = getchar()) != '\n' && c != EOF); // Vacía el buffer de entrada
}

void menuAnadirActor()
{
    char nombreActor[20];
    char idPelicula[5];
    cout << "==============" << endl;
    cout << " ANADIR ACTOR " << endl;
    cout << "==============" << endl;
    cout << "Introduce el id de la pelicula en la que actua el actor: " << endl;
    fflush(stdin);
    cin >> idPelicula;
    actor.setIdPelicula(idPelicula);
    cout << "Cual es el nombre del actor? " << endl;
    cin >> nombreActor;
    actor.setNombreActor(nombreActor);
    char c; while ((c = getchar()) != '\n' && c != EOF); // Vacía el buffer de entrada
}

void menuAnadirPelicula()
{
    char idSala[5];
    char titulo[20];
    char sinopsis[100];
    char horario[20];
    cout << "=================" << endl;
    cout << " ANADIR PELICULA " << endl;
    cout << "=================" << endl;
    cout << "Introduce el id de la sala en la que se ve la pelicula: " << endl;
    fflush(stdin);
    cin >> idSala;
    pelicula.setIdSala(idSala);
    cout << "Introduce el titulo de la pelicula: " << endl;
    cin >> titulo;
    pelicula.setTitulo(titulo);
    cout << "Introduce la sinopsis de la pelicula: " << endl;
    cin >> sinopsis;
    pelicula.setSinopsis(sinopsis);
    cout << "Introduce el horario de la pelicula: " << endl;
    cin >> idSala;
    pelicula.setHorario(idSala);
    char c; while ((c = getchar()) != '\n' && c != EOF); // Vacía el buffer de entrada
}
