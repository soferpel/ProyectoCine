#include "usuario.h"
#include <string.h>

Usuario::Usuario(char* nombre, char* respuesta, char* correo, char* contrasena)
{
    this->nombre = new char[strlen(nombre) + 1];
    strcpy(this->nombre, nombre);
    this->respuesta = new char[strlen(respuesta) + 1];
    strcpy(this->respuesta, respuesta);
    this->correo = new char[strlen(correo) + 1];
    strcpy(this->correo, correo);
    this->contrasena = new char[strlen(contrasena) + 1];
    strcpy(this->contrasena, contrasena);
}

Usuario::Usuario()
{
    this->nombre = new char[strlen(nombre) + 1];
    this->respuesta = new char[strlen(respuesta) + 1];
    this->correo = new char[strlen(correo) + 1];
    this->contrasena = new char[strlen(contrasena) + 1];
}

Usuario::~Usuario()
{
    delete[] this->nombre;
    delete[] this->respuesta;
    delete[] this->correo;
    delete[] this->contrasena;
}

void Usuario::setNombre(char* nombre)
{
    strcpy(this->nombre, nombre);
}

void Usuario::setRespuesta(char* respuesta)
{
    strcpy(this->respuesta, respuesta);
}

void Usuario::setCorreo(char* correo)
{
    strcpy(this->correo, correo);
}

void Usuario::setContrasena(char* contrasena)
{
    strcpy(this->contrasena, contrasena);
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