#include "cine.h"
#include <string.h>

Cine::Cine(char* nombreCine, char* direccionCine, char* ciudadCine)
{
    strcpy(this->nombreCine, nombreCine);
    strcpy(this->direccionCine, direccionCine);
    strcpy(this->ciudadCine, ciudadCine);
}

Cine::Cine()
{
   
}

Cine::~Cine()
{

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

char* Cine::getIdCine()
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


