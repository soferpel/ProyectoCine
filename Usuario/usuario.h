#ifndef USUARIO_H
#define USUARIO_H

class Usuario
{
    private:
        char nombre[16];  
        char respuesta[20];
        char correo[30];
        char contrasena[16];
        int idUsuario;
    public:
        Usuario(char nombre[16], char respuesta[20], char correo[30], char contrasena[16], int idUsuario);
        ~Usuario();

        void setNombre(char nombre[16]);
        void setRespuesta(char respuesta[20]);
        void setCorreo(char correo[30]);
        void setContrasena(char contrasena[16]);
        void setIdUsuario(int idUsuario);
        char* getNombre();
        char* getRespuesta();
        char* getCorreo();
        char* getContrasena();
        int getIdUsuario();
};

#endif