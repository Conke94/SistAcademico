#include "Professor.h"
#pragma once

class ProfessorLista{
private:
    ProfessorLista* nextProfessor;
    ProfessorLista* backProfessor;

    Professor* ProfessorCorrespondente;

public:
    ProfessorLista ();
    ~ProfessorLista();
    void setNextProfessor(ProfessorLista* serzinho);
    ProfessorLista* getNextProfessor();
    void setBackProfessor(ProfessorLista* serzinho);
    ProfessorLista* getBackProfessor();
    Professor* getProfessor ();
    char* getProfessorName ();
    void setProfessorCorrespondente (Professor* serzinho);
};