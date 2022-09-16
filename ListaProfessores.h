#pragma once
#include "ProfessorLista.h"
#include <iostream>
#include <string.h>

class ListaProfessores{
private:
    char nome [50];
    ProfessorLista* ProfessorPrim;
    ProfessorLista* ProfessorAtual;

public:
    ListaProfessores();
    ~ListaProfessores();
    ProfessorLista* getProfessorPrim ();
    ProfessorLista* getProfessorAtual ();
    void includeProfessor(Professor* serzinho);
    void removeProfessor(Professor* serzinho);
    void inicializar(const char* nomenclatura);
    void listeProfessores ();
};

