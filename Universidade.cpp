#include "Universidade.h"
#include <iostream>

Universidade::Universidade(){
    dptPossuintes=new ListaDepartamentos();
    inicializar (" ");
    dptPossuintes->inicializar(nome);
}

Universidade::Universidade(const char* letras){
    dptPossuintes=new ListaDepartamentos();
    inicializar (letras);
    dptPossuintes->inicializar(nome);
}

Universidade::~Universidade(){
    DepartamentoLista* auxiliar=dptPossuintes->getFirstDepartamento();
    DepartamentoLista* auxiliar2=NULL;

    while (auxiliar!=NULL){
        auxiliar2=auxiliar->getNextDepartamento();
        delete (auxiliar);
        auxiliar=auxiliar2;
    }

    delete(dptPossuintes);  
}

void Universidade::inicializar (const char* letras){
    strcpy(nome, letras);
    dptPossuintes->inicializar(nome);
}

void Universidade::setNome(const char* nomenclatura){
    strcpy(nome, nomenclatura);
}

char* Universidade::getNome(){
    return (nome);
}

void Universidade::imprimeDepartamentos(){
    dptPossuintes->listeDepartamentos();
}

void Universidade::includeDepartamento (Departamento* novo){
    dptPossuintes->includeDepartamento (novo);
}

void Universidade::removeDepartamento (Departamento* novo){
    dptPossuintes->removeDepartamento (novo);
}
