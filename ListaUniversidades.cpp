#include "ListaUniversidades.h"
#include "UniversidadeLista.h"
#include <string.h>

ListaUniversidades::ListaUniversidades(){
    firstUni=NULL;
    currentUni=NULL;
}

ListaUniversidades::~ListaUniversidades(){
    firstUni=NULL;
    currentUni=NULL;
}

void ListaUniversidades::includeUniversidade(Universidade* desejada){
    UniversidadeLista* proxima;
    proxima= new UniversidadeLista();
    proxima->setUniversidadeCorrespondente(desejada);

    if (firstUni==NULL)
        firstUni=proxima;
    else{
        proxima->setBackUni(currentUni);
        currentUni->setNextUni(proxima);
    }

    currentUni=proxima;
}
    
void ListaUniversidades::removeUniversidade (Universidade* desejada){
    UniversidadeLista* auxiliar;
    auxiliar=firstUni;
    
    if (auxiliar==NULL)
        std::cout<<"Nao ha Universidades"<<std::endl;
    
    else{
        while (auxiliar->getUniversidadeCorrespondente()!=desejada)
            auxiliar=auxiliar->getNextUni();
        

        if (auxiliar==firstUni){
            auxiliar->getNextUni()->setBackUni(NULL);
            delete(firstUni);
            firstUni=auxiliar->getNextUni();
        }
        else if (auxiliar==currentUni){
          currentUni->getBackUni()->setNextUni(NULL);
             currentUni=auxiliar->getBackUni();
          delete(auxiliar);
        }
        else{
            auxiliar->getBackUni()->setNextUni(auxiliar->getNextUni());
             auxiliar->getNextUni()->setBackUni(auxiliar->getBackUni());
             delete(auxiliar);
        }
    }
}
    
void ListaUniversidades::listeUniversidades(){
    UniversidadeLista* auxiliar;
    auxiliar=firstUni;
    
    if (auxiliar!=NULL){
         std::cout<<"Universidades:"<<std::endl;

        do{
           if (auxiliar==NULL)
                  break;
             std::cout<<"-"<<auxiliar->getUniversidadeCorrespondente()->getNome()<<std::endl;
             auxiliar=auxiliar->getNextUni();
        }while (auxiliar!=NULL);
    }
}

void ListaUniversidades::inicializar (const char* nomenclatura){
    strcpy(nome, nomenclatura);
}

UniversidadeLista* ListaUniversidades::getFirstUniversidade(){
    return firstUni;
}