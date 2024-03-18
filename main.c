#include <stdio.h>
#include <stdlib.h>
#include "menus.h"

int main(void)
{

    menuBienvenida();
    switch (opcionInt)
    {
    case 1:
        menuInicioSesion();
        //TODO si el usuario es correcto, mostrar menuPrincipal
        menuPrincipal();
        switch (opcionInt)
        {
        case 1:
            //menuCatalogo();
            printf("Catalogo\n"); //Son textos informativos temporales hasta que se implementen las funciones
            break;
        case 2:
            //menuComprarEntradas();
            printf("Comprar entradas\n"); //Son textos informativos temporales hasta que se implementen las funciones
            break;
        
        case 3:
            //menuMisEntradas();
            printf("Mis entradas\n"); //Son textos informativos temporales hasta que se implementen las funciones
            break;

        case 4:
            //menuModificarUsuario();
            printf("Modificar usuario\n"); //Son textos informativos temporales hasta que se implementen las funciones
            break;

        case 5:
            printf("\nAdios!\n");
            break;
        }
        break;
    case 2:
        menuRegistro();
        //TODO si el proceso ha ido bien, mostrar menuPrincipal
        menuPrincipal();
        break;
    case 3:
        printf("\nAdios!\n");
        break;
    }

    //menuPrincipal();
    return 0;
}