#ifndef CINE_H
#define CINE_H

class Cine
{
    private:
        int idCine;
        char nombreCine[20];
        char direccionCine[20];
        char ciudadCine[20];
    public:
        Cine(char nombreCine[20], char direccionCine[20], char ciudadCine[20]);
        ~Cine();
        
        void setNombreCine(char nombreCine[20]);
        void setDireccionCine(char direccionCine[20]);
        void setCiudadCine(char ciudadCine[20]);
        int getIdCine();
        char* getNombreCine();
        char* getDireccionCine();
        char* getCiudadCine();
};

#endif