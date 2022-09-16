#ifndef ALUNO_H_
#define ALUNO_H_

#include "Pessoa.h"

class Aluno: public Pessoa{
private:
    int RA;

public:
    Aluno ();
    Aluno (int dia, int mes, int ano, const char* nomenclatura);
    ~Aluno ();
    void setRA(int registro);
    int getRA();
};
#endif // ALUNO_H_
