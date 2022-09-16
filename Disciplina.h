#ifndef DISCIPLINA_H_
#define DISCIPLINA_H_

#include "Departamento.h"
#include "ListaAlunos.h"
#include <string.h>

class Disciplina {
private:
    char nome [50];
    int ID;

    ListaAlunos turma;
    Departamento* dptPertencido;

public:
    Disciplina();
    Disciplina(const char* nomenclatura, int codigo, int maximo=45);
    void inicializar(const char* nomenclatura, int codigo);
    ~Disciplina();
    void setDptPertencido(Departamento* dpt);
    Departamento* getDptPertencido();
    
    char* getName();
    void setName (const char* nomenclatura);

    void listeAlunos ();
    void includeAluno (Aluno* serzinho);
    void removeAluno(Aluno* serzinho);
    void setNotas (float notaP1, float notaP2, int faltas, Aluno* requerido);
};
#endif // DISCIPLINA