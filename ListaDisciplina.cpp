#include "ListaDisciplinas.h"
#include "DisciplinaLista.h"
#include <string.h>

ListaDisciplinas::ListaDisciplinas(){
    firstDiscipl=NULL;
    currentDiscipl=NULL;
}

ListaDisciplinas::~ListaDisciplinas(){
    firstDiscipl=NULL;
    currentDiscipl=NULL;
}

void ListaDisciplinas::includeDisciplina(Disciplina* desejada){
    DisciplinaLista* proxima;
    proxima= new DisciplinaLista();
    proxima->setDisciplinaCorrespondente(desejada);

    if (firstDiscipl==NULL)
        firstDiscipl=proxima;
    else{
        proxima->setBackDiscipl(currentDiscipl);
        currentDiscipl->setNextDiscipl(proxima);
    }

    currentDiscipl=proxima;
}
    
void ListaDisciplinas::removeDisciplina (Disciplina* desejada){
    DisciplinaLista* auxiliar;
    auxiliar=firstDiscipl;
    
    if (auxiliar==NULL)
        std::cout<<"Nao ha disciplinas"<<std::endl;
    
    else{
        while (auxiliar->getDisciplinaCorrespondente()!=desejada)
            auxiliar=auxiliar->getNextDiscipl();
        

        if (auxiliar==firstDiscipl){
            auxiliar->getNextDiscipl()->setBackDiscipl(NULL);
            delete(firstDiscipl);
            firstDiscipl=auxiliar->getNextDiscipl();
        }
        else if (auxiliar==currentDiscipl){
          currentDiscipl->getBackDiscipl()->setNextDiscipl(NULL);
             currentDiscipl=auxiliar->getBackDiscipl();
          delete(auxiliar);
        }
        else{
            auxiliar->getBackDiscipl()->setNextDiscipl(auxiliar->getNextDiscipl());
             auxiliar->getNextDiscipl()->setBackDiscipl(auxiliar->getBackDiscipl());
             delete(auxiliar);
        }
    }
}
    
void ListaDisciplinas::listeDisciplinas(){
    DisciplinaLista* auxiliar;
    auxiliar=firstDiscipl;
    
    if (auxiliar!=NULL){
        do{
           if (auxiliar==NULL)
                  break;
             std::cout<<"-"<<auxiliar->getDisciplinaCorrespondente()->getName()<<" da "<<auxiliar->getDisciplinaCorrespondente()->getDptPertencido()->getParteUni()->getNome()<<std::endl;
             auxiliar=auxiliar->getNextDiscipl();
        }while (auxiliar!=NULL);
    }
}

void ListaDisciplinas::inicializar (const char* nomenclatura){
    strcpy(nome, nomenclatura);
}

DisciplinaLista* ListaDisciplinas::getFirstDisciplina(){
    return firstDiscipl;
}