#include "DisciplinaLista.h"

DisciplinaLista::DisciplinaLista(){
    nextDiscipl=NULL;
    backDiscipl=NULL; 
}

DisciplinaLista::~DisciplinaLista(){
}

DisciplinaLista* DisciplinaLista::getNextDiscipl(){
    return (nextDiscipl);
}

DisciplinaLista* DisciplinaLista::getBackDiscipl(){
    return (backDiscipl);
}
    
void DisciplinaLista::setNextDiscipl (DisciplinaLista* proxima){
    nextDiscipl=proxima;
}

void DisciplinaLista::setBackDiscipl (DisciplinaLista* anterior){
    backDiscipl=anterior;
}

Disciplina* DisciplinaLista::getDisciplinaCorrespondente(){
    return (disciplCorrespondente);
}
    
char* DisciplinaLista::getDisciplinaNome(){
    return (disciplCorrespondente->getName());
}

void DisciplinaLista::setDisciplinaCorrespondente(Disciplina* correspondente){
    disciplCorrespondente=correspondente;
}



