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
            string correoUsuario;
            string contrasena;
        public:
            MenuIniciarSesion();
            ~MenuIniciarSesion();

            void mostrar();
            string getCorreoUsuario();
            string getContrasena();
    };

    class MenuRegistrarse
    {
        private:
            string nombreUsuario;
            string correoElectronico;
            string contrasena;
            string respuestaSeguridad;
        public:
            MenuRegistrarse();
            ~MenuRegistrarse();

            void mostrar();
            string getNombreUsuario();
            string getCorreoElectronico();
            string getContrasena();
            string getRespuestaSeguridad();
    };

    class MenuComprarEntradas
    {
        private:
            string ciudadCine;
            int opcionCine;
            int opcionPelicula;
            string confirmarCompra;
            string fecha;
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
            string ciudadCine;
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