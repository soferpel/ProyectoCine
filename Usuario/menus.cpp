#include "menus.h"
#include <iostream>

using namespace std;

namespace menus
{
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
        cout << "Ingrese su nombre de usuario:" << endl;
        cout << "Ingrese su contrasena:" << endl;
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
        cout << "Ingrese su nombre de usuario:" << endl;
        cout << "Ingrese su correo electronico:" << endl;
        cout << "Ingrese su coontrasena:" << endl;
        cout << "Responda esta pregunta de seguridad (Cual es su pelicula favorita?):" << endl;
    }
}