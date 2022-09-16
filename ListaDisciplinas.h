#ifndef LISTADISCIPLINAS_H_
#define LISTADISCIPLINAS_H_
#include "DisciplinaLista.h"
#include <string.h>

class ListaDisciplinas{
private:
    DisciplinaLista* firstDiscipl;
    DisciplinaLista* currentDiscipl;

    char nome [50];

public:
    ListaDisciplinas();
    ~ListaDisciplinas();
    void includeDisciplina(Disciplina* desejada);
    void removeDisciplina (Disciplina* desejada);
    void listeDisciplinas();
    void inicializar (const char* nomenclatura);
    DisciplinaLista* getFirstDisciplina();
};
#endif