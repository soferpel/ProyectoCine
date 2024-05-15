#ifndef MENUS_H
#define MENUS_H
#include <string>

using namespace std;

namespace menus
{
    class MenuEleccionModo
    {
        private:
            int opcion;
        public:
            MenuEleccionModo();
            ~MenuEleccionModo();

            void mostrar();
            int getOpcion();
    };

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

    class MenuPrincipalCliente
    {
        private:
            int opcion;
        public:
            MenuPrincipalCliente();
            ~MenuPrincipalCliente();

            void mostrar();
            int getOpcion();
    };

    class MenuPrincipalAdministrador
    {
        private:
            int opcion;
        public:
            MenuPrincipalAdministrador();
            ~MenuPrincipalAdministrador();

            void mostrar();
            int getOpcion();
    };

    class MenuIniciarSesion
    {
        private:
            char correo[30];
            char contrasena[16];
        public:
            MenuIniciarSesion();
            ~MenuIniciarSesion();

            void mostrar();
            char* getCorreo();
            char* getContrasena();
    };

    class MenuRegistrarse
    {
        private:
            char nombre[16];
            char correo[30];
            char contrasena[16];
            char respuestaSeguridad[20];
        public:
            MenuRegistrarse();
            ~MenuRegistrarse();

            void mostrar();
            char* getNombre();
            char* getCorreo();
            char* getContrasena();
            char* getRespuestaSeguridad();
    };

    class MenuModificarDatos
    {
        private:
            int opcion;
        public:
            MenuModificarDatos();
            ~MenuModificarDatos();

            void mostrar();
            int getOpcion();
    };
    
    class MenuModificarPelicula
    {
        private:
            int idAModificar;
            int idSala;
            char titulo[20];
            char sinopsis[200];
            char horario[6];
        public:
            MenuModificarPelicula();
            ~MenuModificarPelicula();

            void mostrar();
            int getIdAModificar();
            int getIdSala();
            char* getTitulo();
            char* getSinopsis();
            char* getHorario();
    };

    class MenuModificarUsuario
    {
        private:
            char correo[30];
            char contrasena[16];
            char nombre[16];
            char respuestaSeguridad[20];
        public:
            MenuModificarUsuario();
            ~MenuModificarUsuario();

            void mostrar();
            char* getCorreo();
            char* getContrasena();
            char* getNombre();
            char* getRespuestaSeguridad();
    };

    class MenuModificarCine
    {
        private:
            int idAModificar;
            char nombre[20];
            char direccion[40];
            char ciudad[20];
        public:
            MenuModificarCine();
            ~MenuModificarCine();

            void mostrar();
            int getIdAModificar();
            char* getNombre();
            char* getDireccion();
            char* getCiudad();
    };

    class MenuModificarActor
    {
        private:
            int idAModificar;
            char nombre[20];
            int idPelicula;
        public:
            MenuModificarActor();
            ~MenuModificarActor();

            void mostrar();
            int getIdAModificar();
            char* getNombre();
            int getIdPelicula();
    };

    class MenuModificarAsiento
    {
        private:
            int idAModificar;
            int fila;
            int numero;
            char fecha[11];
            int idSala;
        public:
            MenuModificarAsiento();
            ~MenuModificarAsiento();

            void mostrar();
            int getIdAModificar();
            int getFila();
            int getNumero();
            char* getFecha();
    };

    class MenuModificarSala
    {
        private:
            int idAModificar;
            int numero;
            int nColumnas;
            int nFilas;
            int idCine;
        public:
            MenuModificarSala();
            ~MenuModificarSala();

            void mostrar();
            int getIdAModificar();
            int getNumero();
            int getNColumnas();
            int getNFilas();
            int getIdCine();
            
    };

}

#endif