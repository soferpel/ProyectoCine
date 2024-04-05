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
    printf("%s\n", rutaDB.ruta);

    crearTabla(rutaDB);
    autenticacionExitosa = 0;
    while (programaOperando == 1)
    {
        hayQueAnadirDatos = 0;
        if (autenticacionExitosa == 1)
        {
                menuAdministrador(rutaDB);
                switch (opcionIntAd)
                {
                case 1:
                    menuModificarDatos(rutaDB);
                    if (hayQueModificarDatos == 1)
                    {
                        hayQueModificarDatos = 0;
                        switch (opcionIntModificar)
                        {
                        case 1:
                            menuModificarUsuario(rutaDB);
                            modificarUsuario(rutaDB);
                            validacionUsuario = 0;
                            hayQueModificarDatos = 0;
                            break;
                        case 2:
                            menuModificarCine(rutaDB);
                            modificarCine(rutaDB);
                            validacionCine = 0;
                            hayQueModificarDatos = 0;
                            break;
                        case 3:
                            menuModificarActor(rutaDB);
                            modificarActor(rutaDB);
                            validacionActor = 0;
                            hayQueModificarDatos = 0;
                            break;
                        case 4:
                            //ASIENTO
                            break;
                        case 5:
                            menuModificarPelicula(rutaDB);
                            modificarPelicula(rutaDB);
                            validacionPelicula = 0;
                            hayQueModificarDatos = 0;
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
                    menuBorrarDatos(rutaDB);
                    eliminarFila(rutaDB);
                    break;
        
                case 3:
                    menuAnadirDatos(rutaDB);
                    if (hayQueAnadirDatos == 1)
                    {
                        hayQueAnadirDatos = 0;
                        switch (opcionIntAD)
                        {
                        case 1:
                            menuRegistro(rutaDB);
                            guardarUsuario(rutaDB);
                            break;
                        case 2:
                            menuAnadirAsiento(rutaDB);
                            anadirAsiento(rutaDB);
                            validacionSala = 0;
                            hayQueAnadirDatos = 0;
                            break;
                        case 3:
                            menuAnadirPelicula(rutaDB);
                            anadirPelicula(rutaDB);
                            validacionSala = 0;
                            hayQueAnadirDatos = 0;
                            break;
                        case 4:
                            menuAnadirActor(rutaDB);
                            anadirActor(rutaDB);
                            validacionPelicula = 0;
                            hayQueAnadirDatos = 0;
                            break;
                        case 5:
                            menuAnadirCine(rutaDB);
                            anadirCine(rutaDB);
                            hayQueAnadirDatos = 0;
                            break;
                        case 6:
                            menuAnadirSala(rutaDB);
                            anadirSala(rutaDB);
                            validacionCine = 0;
                            hayQueAnadirDatos = 0;
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
            menuBienvenida(rutaDB);
            switch (opcionIntBvda)
            {
                case 1:
                    menuInicioSesion(rutaDB);
                    validarUsuario(rutaDB);
                    break;
                 case 2:
                    menuRegistro(rutaDB);
                    guardarUsuario(rutaDB);
                    break;
                case 3:
                    printf("\nAdios!\n");
                    programaOperando = 0;
                    break;
                
                default:
                    menuBienvenida(rutaDB);

            }
        }
    }


    return 0;
}