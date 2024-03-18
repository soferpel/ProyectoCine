#include <stdio.h>
#include <stdlib.h>
#include "menus.h"

int main(void)
{

    menuBienvenida();
    switch (opcionBienvenida)
    {
    case 1:
        menuInicioSesion();
        //TODO si el usuario es correcto, mostrar menuPrincipal
        //menuPrincipal();
        break;
    case 2:
        menuRegistro();
        //TODO si el proceso ha ido bien, mostrar menuPrincipal
        //menuPrincipal();
        break;
    case 3:
        printf("\nAdios!\n");
        break;
    }

    //menuPrincipal();
    return 0;
}