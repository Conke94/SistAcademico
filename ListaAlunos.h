#pragma once
#include "AlunoLista.h"
#include "Aluno.h"
#include <iostream>
#include <string.h>

class ListaAlunos{
private:
    char nome [50];
    AlunoLista* alunoPrim;
    AlunoLista* alunoAtual;
    int nAlunos;
    int maxAlunos;

public:
    ListaAlunos();
    ~ListaAlunos();
    AlunoLista* getAlunoPrim ();
    AlunoLista* getAlunoAtual ();
    void includeAluno(Aluno* serzinho);
    void listeAlunos ();
    void removeAluno(Aluno* serzinho);
    void setNotas (float notaP1, float notaP2, int faltas, Aluno* requerido);
    void inicializar(int maximo, const char* nomenclatura);
};