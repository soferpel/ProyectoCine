#ifndef ASIENTO_H
#define ASIENTO_H

class Asiento
{
    private:
        int idSala;
        int idAsiento;
        int filaAsiento;
        int numeroAsiento;
        char fechaAsiento[11];

    public:
        Asiento(int filaAsientoInt, int numeroAsientoInt, char fechaAsiento[11]);
        ~Asiento();

        void setFilaAsiento(int filaAsiento);
        void setNumeroAsiento(int numeroAsiento);
        void setFechaAsiento(char fechaAsiento[11]);
        void setIdSala(int idSala);
        int getIdAsiento();
        int getFilaAsiento();
        int getNumeroAsiento();
        char* getFechaAsiento();
        int getIdSala();

};

#endif