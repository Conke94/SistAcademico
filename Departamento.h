#ifndef DEPARTAMENTO_H_
#define DEPARTAMENTO_H_

class Universidade;
class Disciplina;
class ListaDisciplinas;

class Departamento{
private:
    char nome [50];
    Universidade* parteUni;
    ListaDisciplinas* disciplExistentes;

public:
    Departamento();
    Departamento(const char* letras);
    void inicializar (const char* letras);
    ~Departamento ();
    void setNome (const char* letras);
    char* getNome ();
    void setParteUni(Universidade* endereco);
    void includeDisciplina (Disciplina* discipl);
    void listeDisciplinas ();
    void removeDisciplina (Disciplina* desejada);
    Universidade* getParteUni();
};
#endif // DEPARTAMENTO_H
