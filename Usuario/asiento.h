#ifndef ASIENTO_H
#define ASIENTO_H

class Asiento
{
    private:
        char* idSala;
        char* idAsiento;
        char* filaAsiento;
        char* numeroAsiento;
        char* fechaAsiento;

    public:
        Asiento(char* filaAsientoInt, char* numeroAsientoInt, char* fechaAsiento, char* idSala);
        ~Asiento();

        void setFilaAsiento(int filaAsiento);
        void setNumeroAsiento(int numeroAsiento);
        void setFechaAsiento(char* fechaAsiento);
        void setIdSala(int idSala);
        char* getIdAsiento();
        char* getFilaAsiento();
        char* getNumeroAsiento();
        char* getFechaAsiento();
        char* getIdSala();

};

#endif