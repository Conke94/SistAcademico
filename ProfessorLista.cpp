#include "ProfessorLista.h"

ProfessorLista::ProfessorLista (){
    nextProfessor=NULL;
    backProfessor=NULL;
    ProfessorCorrespondente=NULL;
}
    
ProfessorLista::~ProfessorLista(){
}

void ProfessorLista::setNextProfessor(ProfessorLista* serzinho){
    nextProfessor=serzinho;
}

ProfessorLista* ProfessorLista::getNextProfessor(){
    return (nextProfessor);
}
    
void ProfessorLista::setBackProfessor(ProfessorLista* serzinho){
    backProfessor=serzinho;
}

ProfessorLista* ProfessorLista::getBackProfessor(){
    return backProfessor;
}

Professor* ProfessorLista::getProfessor (){
    return ProfessorCorrespondente;
}
    
char* ProfessorLista::getProfessorName (){
    return ProfessorCorrespondente->getNome();
}

void ProfessorLista::setProfessorCorrespondente (Professor* serzinho){
    ProfessorCorrespondente=serzinho;
}