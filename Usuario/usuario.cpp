#include "usuario.h"

Usuario::Usuario(char nombre[16], char respuesta[20], char correo[30], char contrasena[16], int idUsuario)
{
    this->nombre = new char[16];
    strcpy(this->nombre, nombre);
    this->respuesta = new char[20];
    strcpy(this->respuesta, respuesta);
    this->correo = new char[30];
    strcpy(this->correo, correo);
    this->contrasena = new char[16];
    strcpy(this->contrasena, contrasena);
    this->idUsuario = idUsuario;
}

Usuario::~Usuario()
{
    delete[] this->nombre;
    delete[] this->respuesta;
    delete[] this->correo;
    delete[] this->contrasena;
}

void Usuario::setNombre(char nombre[16])
{
    strcpy(this->nombre, nombre);
}

void Usuario::setRespuesta(char respuesta[20])
{
    strcpy(this->respuesta, respuesta);
}

void Usuario::setCorreo(char correo[30])
{
    strcpy(this->correo, correo);
}

void Usuario::setContrasena(char contrasena[16])
{
    strcpy(this->contrasena, contrasena);
}

void Usuario::setIdUsuario(int idUsuario)
{
    this->idUsuario = idUsuario;
}

char* Usuario::getNombre()
{
    return this->nombre;
}

char* Usuario::getRespuesta()
{
    return this->respuesta;
}

char* Usuario::getCorreo()
{
    return this->correo;
}

char* Usuario::getContrasena()
{
    return this->contrasena;
}

int Usuario::getIdUsuario()
{
    return this->idUsuario;
}
