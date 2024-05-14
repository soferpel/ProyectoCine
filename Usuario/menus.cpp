#include "menus.h"
#include <iostream>

using namespace std;

namespace menus
{
    MenuEleccionModo::MenuEleccionModo()
    {

    }

    MenuEleccionModo::~MenuEleccionModo()
    {

    }

    void MenuEleccionModo::mostrar()
    {
        cout << "===============" << endl;
        cout << " ELECCION MODO " << endl;
        cout << "===============" << endl;
        cout << endl;
        cout << "1. Cliente" << endl;
        cout << "2. Administrador" << endl;
        cout << "3. Salir" << endl;
        cout << endl;
        cin >> this->opcion;
    }

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

    MenuPrincipalCliente::MenuPrincipalCliente()
    {

    }

    MenuPrincipalCliente::~MenuPrincipalCliente()
    {

    }

    void MenuPrincipalCliente::mostrar()
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
        cin >> this->opcion;
    }



    int MenuPrincipalCliente::getOpcion()
    {
        return this->opcion;
    }

    MenuPrincipalAdministrador::MenuPrincipalAdministrador()
    {

    }

    MenuPrincipalAdministrador::~MenuPrincipalAdministrador()
    {

    }

    void MenuPrincipalAdministrador::mostrar()
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
        cin >> this->opcion;
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
        cout << "Ingrese su correo de usuario: ";
        cin >> this->correoUsuario;
        cout << "Ingrese su contrasena: ";
        cin >> this->contrasena;
    }

    string MenuIniciarSesion::getCorreoUsuario()
    {
        return this->correoUsuario;
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

    MenuModificarDatos::MenuModificarDatos()
    {

    }

    MenuModificarDatos::~MenuModificarDatos()
    {

    }

    void MenuModificarDatos::mostrar()
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
        cin >> this->opcion;
    }

    int MenuModificarDatos::getOpcion()
    {
        return this->opcion;
    }

    MenuModificarPelicula::MenuModificarPelicula()
    {

    }

    MenuModificarPelicula::~MenuModificarPelicula()
    {

    }

    void MenuModificarPelicula::mostrar()
    {
        cout << "====================" << endl;
        cout << " MODIFICAR PELICULA " << endl;
        cout << "====================" << endl;
        cout << endl;
        cout << "Introduce el ID de la pelicula a modificar: ";
        cin >> this->idAModificar;
        cout << "Introduce el ID de la sala en la que se la pelicula: ";
        cin >> this->idSala;
        cout << "Introduce el nuevo titulo de la pelicula: ";
        cin >> this->titulo;
        cout << "Introduce la nueva sinopsis de la pelicula: ";
        cin >> this->sinopsis;
        cout << "Introduce el nuevo horario de la pelicula: ";
        cin >> this->horario;
        cout << endl;
    }

    int MenuModificarPelicula::getIdAModificar()
    {
        return this->idAModificar;
    }

    int MenuModificarPelicula::getIdSala()
    {
        return this->idSala;
    }

    char* MenuModificarPelicula::getTitulo()
    {
        return this->titulo;
    }

    char* MenuModificarPelicula::getSinopsis()
    {
        return this->sinopsis;
    }

    char* MenuModificarPelicula::getHorario()
    {
        return this->horario;
    }

    MenuModificarUsuario::MenuModificarUsuario()
    {

    }

    MenuModificarUsuario::~MenuModificarUsuario()
    {

    }

    void MenuModificarUsuario::mostrar()
    {
        cout << "===================" << endl;
        cout << " MODIFICAR USUARIO " << endl;
        cout << "===================" << endl;
        cout << endl;
        cout << "<< Solo podras modificartus propoios datos >>" << endl;
        cout << endl;
        cout << "Introduce tu correo electronico: ";
        cin >> this->correo;
        cout << "Introduce tu nuevo nombre: ";
        cin >> this->nombre;
        cout << "Introduce tu nuevo correo electronico: ";
        cin >> this->correo;
        cout << "Introduce tu neva contrasena: ";
        cin >> this->contrasena;
        cout << "Introduce tu nueva respuesta de seguridad (Cal es tu pelicula favorita?): ";
        cin >> this->respuestaSeguridad;
        cout << endl;
    }

    char* MenuModificarUsuario::getCorreo()
    {
        return this->correo;
    }

    char* MenuModificarUsuario::getContrasena()
    {
        return this->contrasena;
    }

    char* MenuModificarUsuario::getNombre()
    {
        return this->nombre;
    }

    char* MenuModificarUsuario::getRespuestaSeguridad()
    {
        return this->respuestaSeguridad;
    }

    MenuModificarCine::MenuModificarCine()
    {

    }

    MenuModificarCine::~MenuModificarCine()
    {

    }

    void MenuModificarCine::mostrar()
    {
        cout << "================" << endl;
        cout << " MODIFICAR CINE " << endl;
        cout << "================" << endl;
        cout << endl;
        cout << "Introduce el ID del cine a modificar: ";
        cin >> this->idAModificar;
        cout << "Introduce el nuevo nombre del cine: ";
        cin >> this->nombre;
        cout << "Introduce la nueva direccion del cine: ";
        cin >> this->direccion;
        cout << "Introduce la nueva ciudad del cine: ";
        cin >> this->ciudad;
        cout << endl;
    }

    int MenuModificarCine::getIdAModificar()
    {
        return this->idAModificar;
    }

    char* MenuModificarCine::getNombre()
    {
        return this->nombre;
    }

    char* MenuModificarCine::getDireccion()
    {
        return this->direccion;
    }

    char* MenuModificarCine::getCiudad()
    {
        return this->ciudad;
    }

    MenuModificarActor::MenuModificarActor()
    {

    }

    MenuModificarActor::~MenuModificarActor()
    {

    }

    void MenuModificarActor::mostrar()
    {
        cout << "=================" << endl;
        cout << " MODIFICAR ACTOR " << endl;
        cout << "=================" << endl;
        cout << endl;
        cout << "Introduce el ID del actor a modificar: ";
        cin >> this->idAModificar;
        cout << "Introduce el nuevo nombre del actor: ";
        cin >> this->nombre;
        cout << "Introduce el ID de la nueva pelicula en la que actua: ";
        cin >> this->idPelicula;
        cout << endl;
    }

    int MenuModificarActor::getIdAModificar()
    {
        return this->idAModificar;
    }

    char* MenuModificarActor::getNombre()
    {
        return this->nombre;
    }

    int MenuModificarActor::getIdPelicula()
    {
        return this->idPelicula;
    }

    MenuModificarSala::MenuModificarSala()
    {

    }

    MenuModificarSala::~MenuModificarSala()
    {

    }

    void MenuModificarSala::mostrar()
    {
        cout << "================" << endl;
        cout << " MODIFICAR SALA " << endl;
        cout << "================" << endl;
        cout << endl;
        cout << "Introduce el ID de la sala a modificar: ";
        cin >> this->idAModificar;
        cout << "Introduce el nuevo numero de la sala: ";
        cin >> this->numero;
        cout << "Introduce el nuevo numero de columnas de la sala: "
        cin >> this->numColumnas;
        cout << "Introduce el nuevo numero de filas de la sala: "
        cin >> this->numFilas;
        cout << "Introduce el nuevo ID del cine al que pertenece la sala: ";
        cin >> this->idCine;
        cout << endl;
    }

    int MenuModificarSala::getIdAModificar()
    {
        return this->idAModificar;
    }

    int MenuModificarSala::getNumero()
    {
        return this->numero;
    }

    int MenuModificarSala::getNumColumnas()
    {
        return this->numColumnas;
    }

    int MenuModificarSala::getNumFilas()
    {
        return this->numFilas;
    }

    int MenuModificarSala::getIdCine()
    {
        return this->idCine;
    }

    MenuModificarAsiento::MenuModificarAsiento()
    {

    }

    MenuModificarAsiento::~MenuModificarAsiento()
    {

    }

    void MenuModificarAsiento::mostrar()
    {
        cout << "===================" << endl;
        cout << " MODIFICAR ASIENTO " << endl;
        cout << "===================" << endl;
        cout << endl;
        cout << "Introduce el ID del asiento a modificar: ";
        cin >> this->idAModificar;
        cout << "Introduce la nueva fila del asiento: ";
        cin >> this->fila;
        cout << "Introduce la nueva columna del asiento: ";
        cin >> this->columna;
        cout << "Introduce la nueva fecha del asiento (dd-MM-yyyy): ";
        cin >> this->fecha;
        cout << "Introduce el nuevo ID de la sala a la que pertenece el asiento: ";
        cin >> this->idSala;
        cout << endl;
    }





}
