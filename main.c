#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "baseDeDatos.h"

int main(void)
{
    autenticacionExitosa = 0;
    menuBienvenida();
    switch (opcionIntBvda)
    {
    case 1:
        menuInicioSesion();
        if (autenticacionExitosa == 1)
        {
            menuAdministrador();
            switch (opcionIntAd)
            {
            case 1:
                menuModificarDatos();
                printf("Modificar datos\n"); //Son textos informativos temporales hasta que se implementen las funciones
                break;
            case 2:
                menuBorrarDatos();
                printf("Borrar datos\n"); //Son textos informativos temporales hasta que se implementen las funciones
                break;
        
            case 3:
                menuAnadirDatos();
                printf("Anadir datos\n"); //Son textos informativos temporales hasta que se implementen las funciones
                switch (opcionIntAD)
                {
                case 1:
                    menuRegistro();
                    break;
                case 2:
                    //menu añadir asiento
                    break;
                case 3:
                    break;
                case 4:
                    break;
                case 5:
                    break;
                case 6:
                    break;
                case 7:
                    printf("\nAdios!\n");
                    break;
                }
                break;

            case 4:
                printf("\nAdios!\n");
                break;
            }
        }
        else
        {
            printf("Error de autentificacion");
        }
            break;
        case 2:
            menuRegistro();
            if (autenticacionExitosa == 1)
            {
            menuAdministrador();
            switch (opcionIntAd)
            {
            case 1:
                menuModificarDatos();
                printf("Modificar datos\n"); //Son textos informativos temporales hasta que se implementen las funciones
                break;
            case 2:
                menuBorrarDatos();
                printf("Borrar datos\n"); //Son textos informativos temporales hasta que se implementen las funciones
                break;
        
            case 3:
                menuAnadirDatos();
                printf("Anadir datos\n"); //Son textos informativos temporales hasta que se implementen las funciones
                switch (opcionIntAD)
                {
                case 1:
                    menuRegistro();
                    break;
                case 2:
                    //menu añadir asiento
                    break;
                case 3:
                    break;
                case 4:
                    break;
                case 5:
                    break;
                case 6:
                    break;
                case 7:
                    printf("\nAdios!\n");
                    break;
                }
                break;

            case 4:
                printf("\nAdios!\n");
                break;
            }
            }
            else
            {
                printf("Error de autentificacion");
            }
                //TODO si el proceso ha ido bien, mostrar menuPrincipal
                break;
        case 3:
            printf("\nAdios!\n");
            break;
        }

    

    //menuPrincipal();
    return 0;
}