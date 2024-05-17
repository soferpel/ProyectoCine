#include "cine.h"

Cine::Cine(char* nombreCine, char* direccionCine, char* ciudadCine)
{
    this->nombreCine = new char[strlen(nombreCine) + 1];
    strcpy(this->nombreCine, nombreCine);
    this->direccionCine = new char[strlen(direccionCine) + 1];
    strcpy(this->direccionCine, direccionCine);
    this->ciudadCine = new char[strlen(ciudadCine) + 1];
    strcpy(this->ciudadCine, ciudadCine);
}

Cine::~Cine()
{
    delete[] nombreCine;
    delete[] direccionCine;
    delete[] ciudadCine;
}

void Cine::setNombreCine(char* nombreCine)
{
    strcpy(this->nombreCine, nombreCine);
}

void Cine::setDireccionCine(char* direccionCine)
{
    strcpy(this->direccionCine, direccionCine);
}

void Cine::setCiudadCine(char* ciudadCine)
{
    strcpy(this->ciudadCine, ciudadCine);
}

int Cine::getIdCine()
{
    return idCine;
}

char* Cine::getNombreCine()
{
    return nombreCine;
}

char* Cine::getDireccionCine()
{
    return direccionCine;
}

char* Cine::getCiudadCine()
{
    return ciudadCine;
}


