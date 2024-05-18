#ifndef SALA_H
#define SALA_H

class Sala{
    
    private:
        char* idCine;
        char* numeroSala;
        char* nColumnasSala;
        char* nFilasSala;
    public:
        Sala(char* numeroSala, char* nColumnasSala, char* nFilasSala, char* idCine);
        Sala();
        ~Sala();

        void setNumeroSala(char* numeroSala);
        void setIdCine(char* idCine);
        void setNColumnasSala(char* nColumnasSala);
        void setNFilasSala(char* nFilasSala);
        char* getIdSala();
        char* getIdCine();
        char* getNumeroSala();
        char* getNColumnasSala();
        char* getNFilasSala();

};

#endif