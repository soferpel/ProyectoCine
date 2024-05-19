#ifndef CINE_H
#define CINE_H

class Cine
{
    private:
        char* idCine;
        char nombreCine[20];
        char direccionCine[20];
        char ciudadCine[20];
    public:
        Cine(char* nombreCine, char* direccionCine, char* ciudadCine);
        Cine();
        ~Cine();
        
        void setNombreCine(char* nombreCine);
        void setDireccionCine(char* direccionCine);
        void setCiudadCine(char* ciudadCine);
        char* getIdCine();
        char* getNombreCine();
        char* getDireccionCine();
        char* getCiudadCine();
};

#endif