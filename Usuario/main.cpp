#include "menus.h"
#include <iostream>
#include <string>

using namespace std;
using namespace menus;

int main()
{
    MenuBienvenida menuBienvenida;
    MenuIniciarSesion menuIniciarSesion;
    MenuRegistrarse menuRegistrarse;

    menuBienvenida.mostrar();
    switch (menuBienvenida.getOpcion())
    {
    case 1:
        menuIniciarSesion.mostrar();

        break;
    
    case 2:
        menuRegistrarse.mostrar();

        break;

    case 3:
        cout << "Hasta luego!" << endl;
        break;

    default:
         menuBienvenida.mostrar();
    }

    return 0;
}