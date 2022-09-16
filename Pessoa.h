#ifndef PESSOA_H_
#define PESSOA_H_

#include <string.h>
#include <iostream>
#include "Departamento.h"
#include "Universidade.h"

class Pessoa{
protected:
    int diaNascimento;
    int mesNascimento;
    int anoNascimento;
    int idade;
    char nome [50];
    Universidade* parteUni;
    Departamento* parteDpt;

public:
    void calculaIdade(int diaAtual, int mesAtual, int anoAtual);
    void getIdade();
    Pessoa (int dia, int mes, int ano, const char* nomenclatura);
    Pessoa ();
    void inicializar(int dia, int mes, int ano, const char*nomenclatura);
    ~Pessoa();
    void setUniversidadeFiliacao(Universidade* nomeU);
    void qualUniFazParte();
    void setParteDpt (Departamento* depart);
    void qualDptFazParte ();
    char* getNome ();
};
#endif // PESSOA_H_
