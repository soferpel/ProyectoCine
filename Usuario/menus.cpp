#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menus.h"
#include <iostream>

void MenuEleccionModo()
{
    cout << "===============" << endl;
    cout << " ELECCION MODO " << endl;
    cout << "===============" << endl;
    cout << endl;
    cout << "1. Cliente" << endl;
    cout << "2. Administrador" << endl;
    cout << "3. Salir" << endl;
    cout << endl;
    cin >> opcionModo;
}

void MenuBienvenida()
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
    cin >> opcionBvda;
}

void MenuPrincipalCliente()
{
    cout << "=========" << endl;
    cout << " CLIENTE " << endl;
    cout << "=========" << endl;
    cout << endl;
    cout << "Que desea hacer?" << endl;
    cout << endl;
    cout << "1. Visualizar cines" << endl;
    cout << "2. Modificar datos" << endl;
    cout << "3. Salir" << endl;
    cout << endl;
    cin >> opcionCliente;
}

void MenuPrincipalAdministrador()
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
    cin >> opcionAdministrador;
}

void MenuIniciarSesion()
{
    char correo[30];
    char contrasena[16]
    cout << "================" << endl;
    cout << " INICIAR SESION " << endl;
    cout << "================" << endl;
    cout << endl;
    cout << "Ingrese su correo de usuario: ";
    cin >> correo;
    usuario.setCorreo(correo);
    cout << "Ingrese su contrasena: ";
    cin >> contrasena;
    usuario.setContrasena(contrasena);
}

void MenuRegistrarse()
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
}

void MenuModificarDatos()
{
    cout << "================" << endl;
    cout << " MODIFICAR DATOS " << endl;
    cout << "================" << endl;
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
    cin >> opcionModificar;
}

void MenuModificarPelicula()
{
    char titulo[20];
    char sinopsis[100];
    char horario[20];
    int idSala;
    cout << "====================" << endl;
    cout << " MODIFICAR PELICULA " << endl;
    cout << "====================" << endl;
    cout << endl;
    cout << "Introduce el ID de la pelicula a modificar: ";
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
}

void MenuModificarUsuario()
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
}

void MenuModificarCine()//pendiente
{
    cout << "================" << endl;
    cout << " MODIFICAR CINE " << endl;
    cout << "================" << endl;
    cout << endl;
    cout << "Introduce el ID del cine a modificar: ";
    cin >> idAModificar;
    cout << "Introduce el nuevo nombre del cine: ";
    cin >> nombre;
    cout << "Introduce la nueva direccion del cine: ";
    cin >> direccion;
    cout << "Introduce la nueva ciudad del cine: ";
    cin >> ciudad;
    cout << endl;
}

void MenuModificarActor()
{
    char nombreActor[20];
    int idPelicula;
    cout << "=================" << endl;
    cout << " MODIFICAR ACTOR " << endl;
    cout << "=================" << endl;
    cout << endl;
    cout << "Introduce el ID del actor a modificar: ";
    cin >> actorAModificar;
    cout << "Introduce el nuevo nombre del actor: ";
    cin >> nombreActor;
    actor.setNombreActor(nombreActor);
    cout << "Introduce el ID de la nueva pelicula en la que actua: ";
    cin >> idPelicula;
    actor.setIdPelicula(idPelicula);
    cout << endl;
}

void MenuModificarSala()//pendiente
{
    cout << "================" << endl;
    cout << " MODIFICAR SALA " << endl;
    cout << "================" << endl;
    cout << endl;
    cout << "Introduce el ID de la sala a modificar: ";
    cin >> idAModificar;
    cout << "Introduce el nuevo numero de la sala: ";
    cin >> numero;
    cout << "Introduce el nuevo numero de columnas de la sala: "
    cin >> numColumnas;
    cout << "Introduce el nuevo numero de filas de la sala: "
    cin >> numFilas;
    cout << "Introduce el nuevo ID del cine al que pertenece la sala: ";
    cin >> idCine;
    cout << endl;
}

void MenuModificarAsiento()//pendiente
    {
        cout << "===================" << endl;
        cout << " MODIFICAR ASIENTO " << endl;
        cout << "===================" << endl;
        cout << endl;
        cout << "Introduce el ID del asiento a modificar: ";
        cin >> idAModificar;
        cout << "Introduce la nueva fila del asiento: ";
        cin >> fila;
        cout << "Introduce el nuevo numero del asiento: ";
        cin >> numero;
        cout << "Introduce la nueva fecha del asiento (dd-MM-yyyy): ";
        cin >> fecha;
        cout << "Introduce el nuevo ID de la sala a la que pertenece el asiento: ";
        cin >> idSala;
        cout << endl;
    }

void menuBorrarDatos()
{
    cout << "===============" << endl;
    cout << " ELECCION MODO " << endl;
    cout << "===============" << endl;
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
}

void menuAnadirAsiento()//pendiente
{
    cout << "===============" << endl;
    cout << " ANADIR ASIENTO " << endl;
    cout << "===============" << endl;
    cout << "Introduce el id de la sala en la que esta el asiento: " << endl;
    fflush(stdin);
    cin >> idEliminar;
    fgets(sala.idSalaChar, 4, stdin);
    sscanf(sala.idSalaChar, "%i", &sala.idSalaInt);
    printf("Introduce la fila del asiento: ");
    fgets(asiento.filaAsientoChar, 3, stdin);
    sscanf(asiento.filaAsientoChar, "%i", &asiento.filaAsientoInt);
    printf("Introduce el numero del asiento: ");
    fgets(asiento.numeroAsientoChar, 3, stdin);
    sscanf(asiento.numeroAsientoChar, "%i", &asiento.numeroAsientoInt);
    printf("Introduce la fecha del asiento: ");
    fgets(asiento.fechaAsiento, 11, stdin);

}

void menuAnadirDatos()
{
    cout << "===============" << endl;
    cout << " ANADIR DATOS " << endl;
    cout << "===============" << endl;
    cout << "Que datos quieres anadir?" << endl;
    cout << "1. Usuario\n 2. Asiento\n 3. Pelicula\n 4. Actor\n 5. Cine\n 6. Sala\n 7. Salir" << endl;
    cin >> opcionAD;
}

void menuAnadirCine()//pendiente
{
    char nombreCine[20];
    char direccionCine[20];
    char ciudadCine[20];
    cout << "===============" << endl;
    cout << " ANADIR CINE " << endl;
    cout << "===============" << endl;
    cout << "Cual es el nombre del cine?" << endl;
    cin >> nombreCine;
    cine.setCiudadCine(nombreCine);
    cout << "Cual es la direccion del cine?" << endl;
    cin >> direccionCine;
    cine.setDireccionCine(direccionCine);
    cout << "Cual es la ciudad del cine?" << endl;
    cin >> ciudadCine;
    cine.setCiudadCine(ciudadCine);
}

void menuAnadirSala()
{
    int idCine;
    int numeroSala;
    int nColumnasSala;
    int nFilasSala;
    cout << "===============" << endl;
    cout << " ANADIR SALA " << endl;
    cout << "===============" << endl;
    cout << "Introduce el id del cine en la que esta la sala: " << endl;
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
}

void menuAnadirActor()
{
    char nombreActor[20];
    int idPelicula;
    cout << "===============" << endl;
    cout << " ANADIR ACTOR " << endl;
    cout << "===============" << endl;
    cout << "Introduce el id de la pelicula en la que actua el actor: " << endl;
    cin >> idPelicula;
    actor.setIdPelicula(idPelicula);
    cout << "Cual es el nombre del actor? " << endl;
    cin >> nombreActor;
    actor.setNombreActor(nombreActor);
}

void menuAnadirPelicula()
{
    int idSala;
    char titulo[20];
    char sinopsis[100];
    char horario[20];
    int idSala;
    cout << "===============" << endl;
    cout << " ANADIR PELICULA " << endl;
    cout << "===============" << endl;
    cout << "Introduce el id de la sala en la que se ve la pelicula: " << endl;
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
}
