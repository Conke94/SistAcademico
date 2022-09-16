#include "DepartamentoLista.h"

DepartamentoLista::DepartamentoLista(){
    nextDepartamento=NULL;
    backDepartamento=NULL;
    dptCorrespondente=NULL;
}

DepartamentoLista::~DepartamentoLista(){
}

void DepartamentoLista::setNextDepartamento (DepartamentoLista* proximo){
    nextDepartamento=proximo;
}

void DepartamentoLista::setBackDepartamento (DepartamentoLista* anterior){
    backDepartamento=anterior;
}
    
DepartamentoLista* DepartamentoLista::getNextDepartamento (){
    return (nextDepartamento);
}
    
DepartamentoLista* DepartamentoLista::getBackDepartamento (){
    return (backDepartamento);
}

void DepartamentoLista::setDptCorrespondente (Departamento* pertencido){
    dptCorrespondente=pertencido;
}

Departamento* DepartamentoLista::getDptCorrespondente (){
    return dptCorrespondente;
}