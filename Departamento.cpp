#include "Departamento.h"
#include "Disciplina.h"
#include <stdio.h>
#include "DisciplinaLista.h"
#include "ListaDisciplinas.h"

Departamento::Departamento(){
    disciplExistentes=new(ListaDisciplinas);
    inicializar (" ");
    parteUni=NULL;
    disciplExistentes->inicializar(nome);
}

Departamento::Departamento(const char* letras){
    disciplExistentes=new(ListaDisciplinas);
    inicializar (letras);
    disciplExistentes->inicializar(nome);
}

void Departamento::inicializar (const char* letras){
    strcpy(nome, letras);
    disciplExistentes->inicializar(nome);
}

Departamento::~Departamento (){
    DisciplinaLista* auxiliar=disciplExistentes->getFirstDisciplina();
    DisciplinaLista* auxiliar2=NULL;

    while (auxiliar!=NULL){
        auxiliar2=auxiliar->getNextDiscipl();
        delete (auxiliar);
        auxiliar=auxiliar2;
    }

    delete(disciplExistentes);
    parteUni=NULL;
}

void Departamento::setNome (const char* letras){
    strcpy (nome, letras);
    disciplExistentes->inicializar(letras);
}

char* Departamento::getNome(){
    return (nome);
}

void Departamento::setParteUni(Universidade* endereco){
    parteUni=endereco;
}

void Departamento::includeDisciplina (Disciplina* nova){
    disciplExistentes->includeDisciplina(nova);
}

void Departamento::removeDisciplina (Disciplina* desejada){
    disciplExistentes->removeDisciplina(desejada);
}

void Departamento::listeDisciplinas (){
    disciplExistentes->listeDisciplinas();
}

Universidade* Departamento::getParteUni(){
    return parteUni;
}


