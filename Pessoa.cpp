#include "Pessoa.h"
#include <iostream>

void Pessoa::calculaIdade(int diaAtual, int mesAtual, int anoAtual){
    if (mesAtual>mesNascimento)
        idade=anoAtual-anoNascimento;
    else if (mesAtual<mesNascimento)
        idade=anoAtual-anoNascimento-1;
    else{
        if (diaAtual>=diaNascimento)
            idade=anoAtual-anoNascimento;
        else
            idade=anoAtual-anoNascimento-1;
    }
}

void Pessoa::getIdade(){
    std::cout<<"A idade de "<<nome<< " eh: "<<idade<<std::endl;
}

void Pessoa::inicializar (int dia, int mes, int ano, const char* nomenclatura){
    strcpy(nome, nomenclatura);
    diaNascimento=dia;
    mesNascimento=mes;
    anoNascimento=ano;
    idade=0;
}

Pessoa::Pessoa(int dia, int mes, int ano, const char* nomenclatura){
    inicializar (dia, mes, ano, nomenclatura);
}

Pessoa::Pessoa(){
    inicializar (0, 0, 0, "");
}

Pessoa::~Pessoa(){

}

void Pessoa::setUniversidadeFiliacao(Universidade* nomeU){
    parteUni=nomeU;
}

void Pessoa::qualUniFazParte(){
    std::cout<<nome<<" esta associado a "<<parteUni->getNome()<<std::endl;
}

void Pessoa::setParteDpt (Departamento* depart){
    parteDpt=depart;
}

void Pessoa::qualDptFazParte (){
    std::cout<<nome<<" faz parte do departamento de "<<parteDpt->getNome()<<" da "<<parteUni->getNome()<<std::endl;
}

char* Pessoa::getNome(){
    return nome;
}
