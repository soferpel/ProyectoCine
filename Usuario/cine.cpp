#include "cine.h"

Cine::Cine(char nombreCine[20], char direccionCine[20], char ciudadCine[20])
{
    this->nombreCine = new char[20];
    strcpy(this->nombreCine, nombreCine);
    this->direccionCine = new char[20];
    strcpy(this->direccionCine, direccionCine);
    this->ciudadCine = new char[20];
    strcpy(this->ciudadCine, ciudadCine);
}

Cine::~Cine()
{
    delete[] nombreCine;
    delete[] direccionCine;
    delete[] ciudadCine;
}

void Cine::setNombreCine(char nombreCine[20])
{
    strcpy(this->nombreCine, nombreCine);
}

void Cine::setDireccionCine(char direccionCine[20])
{
    strcpy(this->direccionCine, direccionCine);
}

void Cine::setCiudadCine(char ciudadCine[20])
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


