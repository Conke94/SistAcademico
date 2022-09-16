#ifndef DEPARTAMENTOLISTA_H_
#define DEPARTAMENTOLISTA_H_

#include <iostream>

class Departamento;

class DepartamentoLista{
private:
    DepartamentoLista* nextDepartamento;
    DepartamentoLista* backDepartamento;

    Departamento* dptCorrespondente;

public:
    DepartamentoLista();
    ~DepartamentoLista();
    void setNextDepartamento (DepartamentoLista* proximo);
    void setBackDepartamento (DepartamentoLista* anterior);
    DepartamentoLista* getNextDepartamento ();
    DepartamentoLista* getBackDepartamento ();
    void setDptCorrespondente (Departamento* pertencido);
    Departamento* getDptCorrespondente ();
};
#endif