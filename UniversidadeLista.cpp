#include "UniversidadeLista.h"

UniversidadeLista::UniversidadeLista(){
    nextUni=NULL;
    backUni=NULL; 
}

UniversidadeLista::~UniversidadeLista(){
}

UniversidadeLista* UniversidadeLista::getNextUni(){
    return (nextUni);
}

UniversidadeLista* UniversidadeLista::getBackUni(){
    return (backUni);
}
    
void UniversidadeLista::setNextUni (UniversidadeLista* proxima){
    nextUni=proxima;
}

void UniversidadeLista::setBackUni (UniversidadeLista* anterior){
    backUni=anterior;
}

Universidade* UniversidadeLista::getUniversidadeCorrespondente(){
    return (universidadeCorrespondente);
}
    
char* UniversidadeLista::getUniversidadeNome(){
    return (universidadeCorrespondente->getNome());
}

void UniversidadeLista::setUniversidadeCorrespondente(Universidade* correspondente){
    universidadeCorrespondente=correspondente;
}
