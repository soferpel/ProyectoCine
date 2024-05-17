#include "actor.h"
#include <string.h>

Actor::Actor(char* nombreActor, char* idPelicula)
{
    this->nombreActor = new char[strlen(nombreActor) + 1];
    strcpy(this->nombreActor, nombreActor);
    this->idPelicula = new char[strlen(idPelicula) + 1];
    strcpy(this->idPelicula, idPelicula);
}

Actor::~Actor()
{
    delete[] this->nombreActor;
    delete[] this->idPelicula;
}

void Actor::setNombreActor(char* nombreActor)
{
    strcpy(this->nombreActor, nombreActor);
}

void Actor::setIdPelicula(char* idPelicula)
{
    this->idPelicula = idPelicula;
}

char* Actor::getIdActor()
{
    return this->idActor;
}

char* Actor::getNombreActor()
{
    return this->nombreActor;
}

char* Actor::getIdPelicula()
{
    return this->idPelicula;
}
