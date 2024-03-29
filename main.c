#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "baseDeDatos.h"
int programaOperando = 1;
int main(void)
{
    borrarTablas();
    crearTabla();
    autenticacionExitosa = 0;
    while (programaOperando == 1)
    {
        hayQueAnadirDatos = 0;
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
                    if (hayQueAnadirDatos == 1)
                    {
                        hayQueAnadirDatos = 0;
                        switch (opcionIntAD)
                        {
                        case 1:
                            menuRegistro();
                            break;
                        case 2:
                            menuAnadirAsiento();
                            break;
                        case 3:
                            menuAnadirPelicula();
                            break;
                        case 4:
                            menuAnadirActor();
                            break;
                        case 5:
                            menuAnadirCine();
                            break;
                        case 6:
                            menuAnadirSala();
                            break;
                        case 7:
                            printf("\nAdios!\n");
                            programaOperando = 0;
                            break;
                        }
                    }
                    break;
                case 4:
                    printf("\nAdios!\n");
                    programaOperando = 0;
                    break;
            }   
        }  
        else
        {
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
        }
    }

    return 0;
}