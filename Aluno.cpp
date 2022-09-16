#include "Aluno.h"

Aluno::Aluno():
Pessoa (0, 0, 0, " "){
    RA=0;
}

Aluno::Aluno (int dia, int mes, int ano, const char* nomenclatura):
Pessoa (dia, mes, ano, nomenclatura){
    RA=0;
}

Aluno::~Aluno (){
}

void Aluno::setRA(int registro){
    RA=registro;
}

int Aluno::getRA (){
    return (RA);
}

