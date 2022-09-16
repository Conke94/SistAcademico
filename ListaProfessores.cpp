#include "ListaProfessores.h"

ListaProfessores::ListaProfessores(){
    ProfessorPrim=NULL;
    ProfessorAtual=NULL;
}

ListaProfessores::~ListaProfessores(){
    ProfessorLista* currentProfessor=ProfessorPrim;
    ProfessorLista* auxiliar=NULL;

    while (currentProfessor!=NULL){
        auxiliar=currentProfessor->getNextProfessor();
        delete (currentProfessor);
        currentProfessor=auxiliar;
    }
    
    ProfessorPrim=NULL;
    ProfessorAtual=NULL;
}

ProfessorLista* ListaProfessores::getProfessorPrim (){
    return ProfessorPrim;
}

ProfessorLista* ListaProfessores::getProfessorAtual (){
    return (ProfessorAtual);
}

void ListaProfessores::includeProfessor(Professor* serzinho){
    ProfessorLista* novo;
    novo=new ProfessorLista();
    novo->setProfessorCorrespondente(serzinho);
    novo->setNextProfessor(NULL);
    novo->setBackProfessor(NULL);

    if (ProfessorAtual==NULL){
        ProfessorPrim=novo;
        ProfessorAtual=novo;
    }

    else{
         ProfessorAtual->setNextProfessor(novo);
        novo->setBackProfessor(ProfessorAtual);
        ProfessorAtual=novo;
    }
}

void ListaProfessores::listeProfessores (){
    ProfessorLista* auxiliar=NULL;
    auxiliar=ProfessorPrim;
    std::cout<<"Professores:"<<std::endl;

    do{
        if (auxiliar==NULL)
            break;
        std::cout<<"-"<<auxiliar->getProfessor()->getNome()<<std::endl;
        auxiliar=auxiliar->getNextProfessor();
    }while(auxiliar!=NULL);
}

void ListaProfessores::removeProfessor(Professor* serzinho){
    ProfessorLista* currentProfessor = ProfessorPrim;
    while (currentProfessor!=NULL){
        if (currentProfessor->getProfessor() == serzinho && serzinho!=ProfessorPrim->getProfessor() && serzinho!=ProfessorAtual->getProfessor()){
            currentProfessor->getNextProfessor()->setBackProfessor(currentProfessor->getBackProfessor());
            currentProfessor->getBackProfessor()->setNextProfessor(currentProfessor->getNextProfessor());
        }
        else if (serzinho==ProfessorPrim->getProfessor() || serzinho==ProfessorAtual->getProfessor())
            break;
        currentProfessor=currentProfessor->getNextProfessor();
    }

    if (serzinho==ProfessorPrim->getProfessor() && serzinho!=ProfessorAtual->getProfessor()){
        ProfessorPrim=ProfessorPrim->getNextProfessor();
        ProfessorPrim->getBackProfessor()->setNextProfessor(NULL);
        ProfessorPrim->setBackProfessor(NULL);
    }

    else if (serzinho==ProfessorAtual->getProfessor() && serzinho!=ProfessorPrim->getProfessor()){
        ProfessorAtual=currentProfessor->getBackProfessor();
        currentProfessor->getBackProfessor()->setNextProfessor(NULL);
        currentProfessor->setBackProfessor(NULL);
    }

    else if (serzinho==ProfessorPrim->getProfessor() && serzinho==ProfessorAtual->getProfessor()){
        ProfessorAtual=NULL;
        ProfessorPrim=NULL;
    }
}

void ListaProfessores::inicializar(const char* nomenclatura){
    strcpy(nome, nomenclatura);
}