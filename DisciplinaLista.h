#ifndef DISCIPLINALISTA_H_
#define DISCIPLINALISTA_H_
#include "Disciplina.h"

class DisciplinaLista {
private:
    DisciplinaLista* nextDiscipl;
    DisciplinaLista* backDiscipl;

    Disciplina* disciplCorrespondente;

public:
    DisciplinaLista();
    ~DisciplinaLista();
    DisciplinaLista* getNextDiscipl();
    DisciplinaLista* getBackDiscipl();
    void setNextDiscipl (DisciplinaLista* proxima);
    void setBackDiscipl (DisciplinaLista* anterior);
    Disciplina* getDisciplinaCorrespondente();
    char* getDisciplinaNome();
    void setDisciplinaCorrespondente(Disciplina* correspondente);
};
#endif