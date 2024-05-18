#ifndef USUARIO_H
#define USUARIO_H

class Usuario
{
    private:
        char* nombre;  
        char* respuesta;
        char* correo;
        char* contrasena;
    public:
        Usuario(char* nombre, char* respuesta, char* correo, char* contrasena);
        ~Usuario();

        void setNombre(char* nombre);
        void setRespuesta(char* respuesta);
        void setCorreo(char* correo);
        void setContrasena(char* contrasena);
        char* getNombre();
        char* getRespuesta();
        char* getCorreo();
        char* getContrasena();
};

#endif