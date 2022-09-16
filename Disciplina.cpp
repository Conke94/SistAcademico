#include "Disciplina.h"
#include "AlunoLista.h"
#include <stdio.h>
#include <string.h>

Disciplina::Disciplina():
turma()
{
    dptPertencido=NULL;
    inicializar(" ", 0);
    turma.inicializar(45, " ");
}

Disciplina::Disciplina(const char* nomenclatura, int codigo, int maximo):
turma()
{
    dptPertencido=NULL;
    inicializar(nomenclatura, codigo);
    turma.inicializar(45, nomenclatura);
}

Disciplina::~Disciplina(){
    dptPertencido=NULL;
}

void Disciplina::setDptPertencido(Departamento* dpt){
    dptPertencido=dpt;
    dpt->includeDisciplina(this);
}

Departamento* Disciplina::getDptPertencido(){
    return dptPertencido;
}

char* Disciplina::getName (){
    return nome;
}

void Disciplina::inicializar(const char* nomenclatura, int codigo){
    strcpy(nome, nomenclatura);
    ID=codigo;
    turma.inicializar(45, nomenclatura);
}

void Disciplina::listeAlunos(){
    turma.listeAlunos();
}

void Disciplina::includeAluno (Aluno* serzinho){
    turma.includeAluno(serzinho);
}

void Disciplina::removeAluno(Aluno* serzinho){
    turma.removeAluno(serzinho);
}

void Disciplina::setNotas (float notaP1, float notaP2, int faltas, Aluno* requerido){
    turma.setNotas(notaP1, notaP2, faltas, requerido);
}

void Disciplina::setName (const char* nomenclatura){
    strcpy(nome, nomenclatura);
}





