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
            string nombreUsuario;
            string contrasena;
        public:
            MenuIniciarSesion();
            ~MenuIniciarSesion();

            void mostrar();
            string getNombreUsuario();
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
}

#endif