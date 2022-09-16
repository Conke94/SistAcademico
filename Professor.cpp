#include "Professor.h"

Professor::Professor():
Pessoa(0, 0, 0, " "){
    dptFiliado=NULL;
    uniFiliado=NULL;
}

Professor::Professor(int dia, int mes, int ano, const char* nomenclatura):
Pessoa(dia, mes, ano, nomenclatura){
    dptFiliado=NULL;
    uniFiliado=NULL;
}

Professor::~Professor(){
}

void Professor::setProfDpt (Departamento* dep){
    dptFiliado=dep;
}

void Professor::setProfUni (Universidade* uni){
    uniFiliado=uni;
}

void Professor::dptTrabalhado (){
    std::cout<<nome<<" trabalha para o "<<dptFiliado->getNome()<<std::endl;
}

void Professor::uniTrabalhado (){
    std::cout<<nome<<" trabalha para a "<<uniFiliado->getNome()<<std::endl;
}
