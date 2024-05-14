#ifndef MENUS_H
#define MENUS_H
#include <string>

using namespace std;

namespace menus
{
    class MenuBienvenida
    {
        private:
            int opcion;

        public:
            MenuBienvenida();
            ~MenuBienvenida();

            void mostrar();
            int getOpcion();
    };

    class MenuPrincipal
    {
        private:
            int opcion;
        public:
            MenuPrincipal();
            ~MenuPrincipal();

            void mostrar();
            int getOpcion();
    };

    class MenuIniciarSesion
    {
        private:
            char correoUsuario[30];
            char contrasena[16];
        public:
            MenuIniciarSesion();
            ~MenuIniciarSesion();

            void mostrar();
            char* getCorreoUsuario();
            char* getContrasena();
    };

    class MenuRegistrarse
    {
        private:
            char nombreUsuario[16];
            char correoElectronico[30];
            char contrasena[16];
            char respuestaSeguridad;
        public:
            MenuRegistrarse();
            ~MenuRegistrarse();

            void mostrar();
            char* getNombreUsuario();
            char* getCorreoElectronico();
            char* getContrasena();
            char* getRespuestaSeguridad();
    };

    class MenuComprarEntradas
    {
        private:
            char ciudadCine[20];
            int opcionCine;
            int opcionPelicula;
            char confirmarCompra;
            char fecha;
            int opcionHorario;
            int numEntradas;
        public:
            MenuComprarEntradas();
            ~MenuComprarEntradas();

            void mostrar();
            string getCiudadCine();
            int getOpcionCine();
            int getOpcionPelicula();
            string getConfirmarCompra();
            string getFecha();

    };

    class MenuCatalogoPeliculas
    {
        private:
            char ciudadCine[20];
            int opcionCine;
            int opcionPelicula;
            int confirmarCompra;
            string fecha;
        public:
            MenuCatalogoPeliculas();
            ~MenuCatalogoPeliculas();

            void mostrar();
            string getCiudadCine();
            int getOpcionCine();
            int getOpcionPelicula();
            int getConfirmarCompra();
            string getFecha();
    };
}

#endif