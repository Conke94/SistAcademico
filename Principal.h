#ifndef PRINCIPAL_H_
#define PRINCIPAL_H_

#include "ListaAlunos.h"
#include "ListaProfessores.h"
#include "ListaDisciplinas.h"
#include "Windows.h"
#include "ListaUniversidades.h"

class Principal{
private:
    ListaDisciplinas DisciplinasList;
    ListaDepartamentos DepartamentosList;
    ListaUniversidades UniversidadesList;
    ListaAlunos AlunosList;
    ListaProfessores ProfessoresList;
    
public:
    Principal();
    void menu ();

    void iniciarCadastro();
    void iniciarExecucao();
    
    void cadUniversidade();
    void cadDepartamento();
    void cadDisciplina();
    void cadPessoa();
    void cadAluno();
    void cadProfessor();

    Universidade* localizarUniversidade(const char* nameUni);
    Departamento* localizarDepartamento(const char* nameDpt);
    Disciplina* localizarDisciplina(const char* nomeDiscipl);

    ~Principal();
};

#endif // PRINCIPAL_H
