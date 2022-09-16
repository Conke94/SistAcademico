#include "Aluno.h"
#pragma once

class AlunoLista{
private:
    AlunoLista* nextAluno;
    AlunoLista* backAluno;

    float nota1;
    float nota2;
    int nFaltas;
    

    Aluno* AlunoCorrespondente;

public:
    AlunoLista ();
    ~AlunoLista();
    void setNextAluno(AlunoLista* serzinho);
    AlunoLista* getNextAluno();
    void setBackAluno(AlunoLista* serzinho);
    AlunoLista* getBackAluno();
    Aluno* getAluno ();
    char* getAlunoName ();
    void setAlunoCorrespondente (Aluno* serzinho);

    void setNota1(float nota);
    void setNota2(float nota);
    void setFaltas (int quantidade);

    float getNota1 ();
    float getNota2 ();
    int getNumeroFaltas ();
};