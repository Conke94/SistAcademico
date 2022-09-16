#ifndef LISTADEPARTAMENTOS_H_
#define LISTADEPARTAMENTOS_H_
#include "DepartamentoLista.h"
#include "UniversidadeLista.h"
#include <string.h>
#include <iostream>
#include "Departamento.h"

class ListaDepartamentos{
private:
    DepartamentoLista* firstDepartamento;
    DepartamentoLista* currentDepartamento;

    Universidade* uniCorrespondente;

    char nome[50];
public:
    ListaDepartamentos();
    ~ListaDepartamentos();
    void inicializar (const char* nomenclatura);
    void includeDepartamento (Departamento* novo);
    void removeDepartamento (Departamento* desejado);
    void listeDepartamentos ();
    DepartamentoLista* getFirstDepartamento();
};
#endif