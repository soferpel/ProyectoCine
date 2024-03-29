#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "baseDeDatos.h"
int programaOperando = 1;
int main(void)
{
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
                    if (hayQueModificarDatos == 1)
                    {
                        hayQueModificarDatos = 0;
                        switch (opcionIntModificar)
                        {
                        case 1:
                            //USUARIO
                            break;
                        case 2:
                            //CINE
                            break;
                        case 3:
                            //ACTOR
                            break;
                        case 4:
                            //ASIENTO
                            break;
                        case 5:
                            menuModificarPelicula();
                            break;
                        case 6:
                            //SALA
                            break;
                        case 7:
                            printf("\nAdios!\n");
                            programaOperando = 0;
                            break;
                        }
                    }
                    break;
                case 2:
                    menuBorrarDatos();
                    break;
        
                case 3:
                    menuAnadirDatos();
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