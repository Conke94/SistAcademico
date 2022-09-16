#ifndef UNIVERSIDADELISTA_H_
#define UNIVERSIDADELISTA_H_
#include "Universidade.h"

class UniversidadeLista {
private:
    UniversidadeLista* nextUni;
    UniversidadeLista* backUni;

    Universidade* universidadeCorrespondente;

public:
    UniversidadeLista();
    ~UniversidadeLista();
    UniversidadeLista* getNextUni();
    UniversidadeLista* getBackUni();
    void setNextUni (UniversidadeLista* proxima);
    void setBackUni (UniversidadeLista* anterior);
    Universidade* getUniversidadeCorrespondente();
    char* getUniversidadeNome();
    void setUniversidadeCorrespondente(Universidade* correspondente);
};
#endif