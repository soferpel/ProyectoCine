#include "menus.h"
#include <iostream>

using namespace std;

namespace menus
{
    MenuBienvenida::MenuBienvenida()
    {

    }

    MenuBienvenida::~MenuBienvenida()
    {

    }

    void MenuBienvenida::mostrar()
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
        cin >> this->opcion;
    }

    int MenuBienvenida::getOpcion()
    {
        return this->opcion;
    }

    MenuPrincipal::MenuPrincipal()
    {

    }

    MenuPrincipal::~MenuPrincipal()
    {

    }

    void MenuPrincipal::mostrar()
    {
        cout << "================" << endl;
        cout << " MENU PRINCIPAL " << endl;
        cout << "================" << endl;
        cout << endl;
        cout << "Que desea hacer?" << endl;
        cout << endl;
        cout << "1. Ver catalogo de peliculas" << endl;
        cout << "2. Comprar entradas" << endl;
        cout << "3. Mis entradas" << endl;
        cout << "4. Modificar usuario" << endl;
        cout << "5. Salir" << endl;
        cout << endl;
        cin >> this->opcion;
    }

    int MenuPrincipal::getOpcion()
    {
        return this->opcion;
    }

    MenuIniciarSesion::MenuIniciarSesion()
    {

    }

    MenuIniciarSesion::~MenuIniciarSesion()
    {

    }

    void MenuIniciarSesion::mostrar()
    {
        cout << "================" << endl;
        cout << " INICIAR SESION " << endl;
        cout << "================" << endl;
        cout << endl;
        cout << "Ingrese su nombre de usuario: ";
        cin >> this->nombreUsuario;
        cout << "Ingrese su contrasena: ";
        cin >> this->contrasena;
        MenuPrincipal menuPrincipal;
        menuPrincipal.mostrar();
    }

    string MenuIniciarSesion::getNombreUsuario()
    {
        return this->nombreUsuario;
    }

    string MenuIniciarSesion::getContrasena()
    {
        return this->contrasena;
    }

    MenuRegistrarse::MenuRegistrarse()
    {

    }

    MenuRegistrarse::~MenuRegistrarse()
    {

    }

    void MenuRegistrarse::mostrar()
    {
        cout << "=============" << endl;
        cout << " REGISTRARSE " << endl;
        cout << "=============" << endl;
        cout << endl;
        cout << "Ingrese su nombre de usuario: ";
        cin >> this->nombreUsuario;
        cout << "Ingrese su correo electronico: ";
        cin >> this->correoElectronico;
        cout << "Ingrese su contrasena: ";
        cin >> this->contrasena;
        cout << "Responda esta pregunta de seguridad (Cual es su pelicula favorita?): ";
        cin >> this->respuestaSeguridad;
    }

    string MenuRegistrarse::getNombreUsuario()
    {
        return this->nombreUsuario;
    }

    string MenuRegistrarse::getCorreoElectronico()
    {
        return this->correoElectronico;
    }

    string MenuRegistrarse::getContrasena()
    {
        return this->contrasena;
    }

    string MenuRegistrarse::getRespuestaSeguridad()
    {
        return this->respuestaSeguridad;
    }

    MenuComprarEntradas::MenuComprarEntradas()
    {

    }

    MenuComprarEntradas::~MenuComprarEntradas()
    {

    }

    void MenuComprarEntradas::mostrar()
    {
        cout << "==================" << endl;
        cout << " COMPRAR ENTRADAS " << endl;
        cout << "==================" << endl;
        cout << endl;
        cout << "Escriba el nombre de su ciudad: ";
        cin >> this->ciudadCine;
        cout << "Elija el cine: ";
        cin >> this->opcionCine;
        cout << "Elija la pelicula que desea ver: ";
        cin >> this->opcionPelicula;
        //sinopsis de la pelicula
        //duración de la pelicula
        //reparto de la pelicula
        cout << "Desea proceder con la compra? (s/n): ";
        cin >> this->confirmarCompra;
        cout << "Escriba la fecha en la que desea ver la pelicula (dd-MM-yyyy): ";
        cin >> this->fecha;
        //no vamos a contemplar el caso de que 
        //la pelicula no este disponible ese dia
        cout << "1. 15:00" << endl;
        cout << "2. 17:00" << endl;
        cout << "3. 19:30" << endl;
        cout << "4. 21:15" << endl;
        cout << "5. 23:00" << endl;
        //los horarios podemos ponerlos fijos o hacer 
        //que cada pelicula tenga sus propios horarios
        //la segunda opcion es mas complicada obviamente
        cin >> this->opcionHorario;
        cout << "Numero de entradas (6,99/entrada): ";
        cin >> this->numEntradas;
        cout << "SALA 4" << endl;
        //podemos poner numeros de sala aleatorios
        //o qe cada pelicula tenga su sala en cada cine
        //la segunda opcion es mas complicada obviamente
        //yo creo que lo mejor es numeros aleatorios
        cout << "    ______________    " << endl;
        cout << "       pantalla       " << endl;
        //dependiendo de la sala habra mas filas y columnas
        //sino, para facilitarnos la vida
        //todas las salas tienen las mismas filas y columnas
        cout << "1 |[][][][][][][][][][]";
    }

    string MenuComprarEntradas::getCiudadCine()
    {
        return this->ciudadCine;
    }

    int MenuComprarEntradas::getOpcionCine()
    {
        return this->opcionCine;
    }

    int MenuComprarEntradas::getOpcionPelicula()
    {
        return this->opcionPelicula;
    }

    string MenuComprarEntradas::getConfirmarCompra()
    {
        return this->confirmarCompra;
    }

    string MenuComprarEntradas::getFecha()
    {
        return this->fecha;
    }

    MenuCatalogoPeliculas::MenuCatalogoPeliculas()
    {

    }

    MenuCatalogoPeliculas::~MenuCatalogoPeliculas()
    {

    }

    void MenuCatalogoPeliculas::mostrar()
    {
        cout << "====================" << endl;
        cout << " CATALOGO PELICULAS " << endl;
        cout << "====================" << endl;
        cout << endl;
        cout << "Escriba el nombre de su ciudad: ";
        cin >> this->ciudadCine;
        cout << "Elija el cine: ";
        cin >> this->opcionCine;
        cout << "Elija la pelicula de la que desea ver la informacion: ";
        cin >> this->opcionPelicula;
        //sinopsis de la pelicula
        //duración de la pelicula
        //reparto de la pelicula
        cout << "Desea comprar una entrada para esta pelicula? (s/n): ";
        cin >> this->confirmarCompra;
        cout << "Escriba la fecha en la que desea ver la pelicula (dd-MM-yyyy): ";
        cin >> this->fecha;
        //no vamos a contemplar el caso de que 
        //la pelicula no este disponible ese dia
    }

    string MenuCatalogoPeliculas::getCiudadCine()
    {
        return this->ciudadCine;
    }

    int MenuCatalogoPeliculas::getOpcionCine()
    {
        return this->opcionCine;
    }

    int MenuCatalogoPeliculas::getOpcionPelicula()
    {
        return this->opcionPelicula;
    }

    int MenuCatalogoPeliculas::getConfirmarCompra()
    {
        return this->confirmarCompra;
    }

    string MenuCatalogoPeliculas::getFecha()
    {
        return this->fecha;
    }

