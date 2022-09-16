#include "ListaAlunos.h"

ListaAlunos::ListaAlunos(){
    alunoPrim=NULL;
    alunoAtual=NULL;
    nAlunos=0;
}

ListaAlunos::~ListaAlunos(){
    AlunoLista* currentAluno=alunoPrim;
    AlunoLista* auxiliar=NULL;

    while (currentAluno!=NULL){
        auxiliar=currentAluno->getNextAluno();
        delete (currentAluno);
        currentAluno=auxiliar;
    }
    
    alunoPrim=NULL;
    alunoAtual=NULL;
}

AlunoLista* ListaAlunos::getAlunoPrim (){
    return alunoPrim;
}

AlunoLista* ListaAlunos::getAlunoAtual (){
    return (alunoAtual);
}

void ListaAlunos::includeAluno(Aluno* serzinho){
    AlunoLista* novo;
    novo=new AlunoLista();
    novo->setAlunoCorrespondente(serzinho);
    novo->setNextAluno(NULL);
    novo->setBackAluno(NULL);

    if (nAlunos<maxAlunos){
        if (alunoAtual==NULL){
            alunoPrim=novo;
            alunoAtual=novo;
        }

        else{
            alunoAtual->setNextAluno(novo);
            novo->setBackAluno(alunoAtual);
            alunoAtual=novo;
        }
        nAlunos++;
    }
    else
        std::cout<<"Turma cheia!"<<std::endl;
}

void ListaAlunos::listeAlunos (){
    AlunoLista* auxiliar=NULL;
    auxiliar=alunoPrim;
    std::cout<<"Alunos:"<<std::endl;

    do{
        if (auxiliar==NULL)
            break;
        std::cout<<"-"<<auxiliar->getAluno()->getNome()<<std::endl;
        auxiliar=auxiliar->getNextAluno();
    }while(auxiliar!=NULL);
}

void ListaAlunos::removeAluno(Aluno* serzinho){
    AlunoLista* currentAluno = alunoPrim;
    while (currentAluno!=NULL){
        if (currentAluno->getAluno() == serzinho && serzinho!=alunoPrim->getAluno() && serzinho!=alunoAtual->getAluno()){
            currentAluno->getNextAluno()->setBackAluno(currentAluno->getBackAluno());
            currentAluno->getBackAluno()->setNextAluno(currentAluno->getNextAluno());
        }
        else if (serzinho==alunoPrim->getAluno() || serzinho==alunoAtual->getAluno())
            break;
        currentAluno=currentAluno->getNextAluno();
    }

    if (serzinho==alunoPrim->getAluno() && serzinho!=alunoAtual->getAluno()){
        alunoPrim=alunoPrim->getNextAluno();
        alunoPrim->getBackAluno()->setNextAluno(NULL);
        alunoPrim->setBackAluno(NULL);
    }

    else if (serzinho==alunoAtual->getAluno() && serzinho!=alunoPrim->getAluno()){
        alunoAtual=currentAluno->getBackAluno();
        currentAluno->getBackAluno()->setNextAluno(NULL);
        currentAluno->setBackAluno(NULL);
    }

    else if (serzinho==alunoPrim->getAluno() && serzinho==alunoAtual->getAluno()){
        alunoAtual=NULL;
        alunoPrim=NULL;
    }
}

void ListaAlunos::setNotas (float notaP1, float notaP2, int faltas, Aluno* requerido){
    AlunoLista* auxiliar=alunoPrim;

    while (auxiliar!=NULL && auxiliar->getAluno()!=requerido)
        auxiliar=auxiliar->getNextAluno();
    
    auxiliar->setNota1(notaP1);
    auxiliar->setNota2(notaP2);
    auxiliar->setFaltas(faltas);
}

void ListaAlunos::inicializar(int maximo, const char* nomenclatura){
    strcpy(nome, nomenclatura);
    maxAlunos=maximo;
}


