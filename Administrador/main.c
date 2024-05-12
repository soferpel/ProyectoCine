#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "baseDeDatos.h"
#include "configuracion.h"
#include <windows.h>

int programaOperando = 1;

int main(void)
{
    PathDB rutaDB = leerConfiguracion("configuracion.txt");
    crearTabla(rutaDB);
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
                            menuModificarUsuario();
                            modificarUsuario(rutaDB);
                            validacionUsuario = 0;
                            hayQueModificarDatos = 0;
                            break;
                        case 2:
                            menuModificarCine();
                            modificarCine(rutaDB);
                            validacionCine = 0;
                            hayQueModificarDatos = 0;
                            break;
                        case 3:
                            menuModificarActor();
                            modificarActor(rutaDB);
                            validacionActor = 0;
                            hayQueModificarDatos = 0;
                            break;
                        case 4:
                            menuModificarAsiento();
                            modificarAsiento(rutaDB);
                            validacionAsiento = 0;
                            hayQueModificarDatos = 0;
                            break;
                        case 5:
                            menuModificarPelicula();
                            modificarPelicula(rutaDB);
                            validacionPelicula = 0;
                            hayQueModificarDatos = 0;
                            break;
                        case 6:
                            menuModificarSala();
                            modificarSala(rutaDB);
                            validacionSala = 0;
                            hayQueModificarDatos = 0;
                            break;
                        case 7:
                            printf("\nAdios!\n");
                            programaOperando = 0;
                            free(rutaDB.ruta);
                            break;
                        
                        default:
                            menuModificarDatos();
                        }
                    }
                    break;
                case 2:
                    menuBorrarDatos();
                    eliminarFila(rutaDB);
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
                            guardarUsuario(rutaDB);
                            break;
                        case 2:
                            menuAnadirAsiento();
                            anadirAsiento(rutaDB);
                            validacionSala = 0;
                            hayQueAnadirDatos = 0;
                            break;
                        case 3:
                            menuAnadirPelicula();
                            anadirPelicula(rutaDB);
                            validacionSala = 0;
                            hayQueAnadirDatos = 0;
                            break;
                        case 4:
                            menuAnadirActor();
                            anadirActor(rutaDB);
                            validacionPelicula = 0;
                            hayQueAnadirDatos = 0;
                            break;
                        case 5:
                            menuAnadirCine();
                            anadirCine(rutaDB);
                            hayQueAnadirDatos = 0;
                            break;
                        case 6:
                            menuAnadirSala();
                            anadirSala(rutaDB);
                            validacionCine = 0;
                            hayQueAnadirDatos = 0;
                            break;
                        case 7:
                            printf("\nAdios!\n");
                            programaOperando = 0;
                            free(rutaDB.ruta);
                            break;
                        
                        default:
                            menuAnadirDatos();
                        }
                    }
                    break;
                case 4:
                    printf("\nAdios!\n");
                    programaOperando = 0;
                    free(rutaDB.ruta);
                    break;
                
                default:
                    menuAdministrador();
            }   
        }  
        else
        {
            menuBienvenida();
            switch (opcionIntBvda)
            {
                case 1:
                    menuInicioSesion();
                    validarUsuario(rutaDB);
                    break;
                 case 2:
                    menuRegistro();
                    guardarUsuario(rutaDB);
                    break;
                case 3:
                    printf("\nAdios!\n");
                    programaOperando = 0;
                    free(rutaDB.ruta);
                    break;
                
                default:
                    menuBienvenida();
                    break;

            }
        }
    }


    return 0;
}