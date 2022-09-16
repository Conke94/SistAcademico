#ifndef PROFESSOR_H_
#define PROFESSOR_H_

#include "Pessoa.h"


class Professor: public Pessoa{
private:
    Departamento* dptFiliado;
    Universidade* uniFiliado;

public:
    Professor();
    Professor(int dia, int mes, int ano, const char* nomenclatura);
    ~Professor();

    void setProfDpt (Departamento* dep);
    void setProfUni (Universidade* uni);
    void dptTrabalhado ();
    void uniTrabalhado ();
};
#endif // PROFESSOR_H_
