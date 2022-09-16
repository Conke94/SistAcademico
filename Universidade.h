#ifndef UNIVERSIDADE_H_
#define UNIVERSIDADE_H_

#include <string.h>
#include "Departamento.h"
#include "ListaDepartamentos.h"

class Departamento;
class ListaDepartamentos;

class Universidade{
private:
    char nome[50];
    ListaDepartamentos* dptPossuintes;

public:
    Universidade();
    Universidade(const char* letras);
    ~Universidade();
    void inicializar(const char* letras);
    void setNome(const char* nomenclatura);
    char* getNome();
    void removeDepartamento (Departamento* novo);
    void includeDepartamento (Departamento* novo);
    void imprimeDepartamentos();
};
#endif // UNIVERSIDADE_H_
