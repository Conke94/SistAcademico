#include "AlunoLista.h"

AlunoLista::AlunoLista (){
    nextAluno=NULL;
    backAluno=NULL;
    AlunoCorrespondente=NULL;
}
    
AlunoLista::~AlunoLista(){
}

void AlunoLista::setNextAluno(AlunoLista* serzinho){
    nextAluno=serzinho;
}

AlunoLista* AlunoLista::getNextAluno(){
    return (nextAluno);
}
    
void AlunoLista::setBackAluno(AlunoLista* serzinho){
    backAluno=serzinho;
}

AlunoLista* AlunoLista::getBackAluno(){
    return backAluno;
}

Aluno* AlunoLista::getAluno (){
    return AlunoCorrespondente;
}
    
char* AlunoLista::getAlunoName (){
    return AlunoCorrespondente->getNome();
}

void AlunoLista::setAlunoCorrespondente (Aluno* serzinho){
    AlunoCorrespondente=serzinho;
}

void AlunoLista::setNota1(float nota){
    nota1=nota;
}

void AlunoLista::setNota2(float nota){
    nota2=nota;
}

void AlunoLista::setFaltas (int quantidade){
    nFaltas=quantidade;
}

float AlunoLista::getNota1 (){
    return nota1;
}

float AlunoLista::getNota2 (){
    return nota2;
}

int AlunoLista::getNumeroFaltas (){
    return nFaltas;
}