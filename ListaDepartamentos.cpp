#include "ListaDepartamentos.h"

ListaDepartamentos::ListaDepartamentos(){
    firstDepartamento=NULL;
    currentDepartamento=NULL;
}
    
ListaDepartamentos::~ListaDepartamentos(){
    firstDepartamento=NULL;
    currentDepartamento=NULL;
}

void ListaDepartamentos::inicializar (const char* nomenclatura){
    strcpy(nome, nomenclatura);
}
    
void ListaDepartamentos::includeDepartamento (Departamento* desejado){
    DepartamentoLista *novo=new DepartamentoLista();
    novo->setDptCorrespondente(desejado);
    novo->setNextDepartamento(NULL);
    novo->setBackDepartamento(currentDepartamento);

    if (currentDepartamento==NULL){
        firstDepartamento=novo;
        currentDepartamento=novo;
    }

    else{
        currentDepartamento->setNextDepartamento(novo);
        novo->setBackDepartamento(currentDepartamento);
        currentDepartamento=novo;
    }
}

void ListaDepartamentos::removeDepartamento (Departamento* desejado){
    DepartamentoLista* auxiliar=firstDepartamento;
    
    while (auxiliar->getDptCorrespondente()!=desejado)
        auxiliar=auxiliar->getNextDepartamento();
    
    if (auxiliar==firstDepartamento)
        delete(auxiliar);
    else if (auxiliar==currentDepartamento){
        currentDepartamento->getBackDepartamento()->setNextDepartamento(NULL);
        currentDepartamento=auxiliar->getBackDepartamento();
        delete(auxiliar);
    }
    else{
        auxiliar->getBackDepartamento()->setNextDepartamento(auxiliar->getNextDepartamento());
        auxiliar->getNextDepartamento()->setBackDepartamento(auxiliar->getBackDepartamento());
        delete(auxiliar);
    }

}
    
void ListaDepartamentos::listeDepartamentos (){
    DepartamentoLista* auxiliar;
    auxiliar=firstDepartamento;
    
    if (auxiliar!=NULL){
        do{
           if (auxiliar==NULL)
                  break;
             std::cout<<"-"<<auxiliar->getDptCorrespondente()->getNome()<<" da "<<auxiliar->getDptCorrespondente()->getParteUni()->getNome()<<std::endl;
             auxiliar=auxiliar->getNextDepartamento();
        }while (auxiliar!=NULL);
    }
}

DepartamentoLista* ListaDepartamentos::getFirstDepartamento(){
    return firstDepartamento;
}
