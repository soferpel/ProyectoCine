#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "baseDeDatos.h"
int programaOperando = 1;
int main(void)
{
    while (programaOperando == 1)
    {
        autenticacionExitosa = 0;
        menuBienvenida();
        switch (opcionIntBvda)
        {
            case 1:
                menuInicioSesion();
                break;
             case 2:
                menuRegistro();
                    break;
            case 3:
                printf("\nAdios!\n");
                programaOperando = 0;
                break;
        }
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
                        programaOperando = 0;
                        break;
                    }
                    break;

                case 4:
                    printf("\nAdios!\n");
                    programaOperando = 0;
                    break;
            }   
        }   
    }

    return 0;
}