#ifndef LISTAUNIVERSIDADE_H_
#define LISTAUNIVERSIDADE_H_
#include "UniversidadeLista.h"
#include <string.h>

class ListaUniversidades{
private:
    UniversidadeLista* firstUni;
    UniversidadeLista* currentUni;

    char nome [50];

public:
    ListaUniversidades();
    ~ListaUniversidades();
    void includeUniversidade(Universidade* desejada);
    void removeUniversidade (Universidade* desejada);
    void listeUniversidades();
    void inicializar (const char* nomenclatura);
    UniversidadeLista* getFirstUniversidade();
};
#endif