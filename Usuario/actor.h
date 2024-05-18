#ifndef ACTOR_H
#define ACTOR_H

class Actor
{
    private:
        char* idActor;
        char* nombreActor;
        char* idPelicula;
    public:
        Actor(char* nombreActor, char* idPelicula);
        Actor();
        ~Actor();

        void setNombreActor(char* nombreActor);
        void setIdPelicula(char* idPelicula);
        char* getIdActor();
        char* getNombreActor();
        char* getIdPelicula();
};

#endif