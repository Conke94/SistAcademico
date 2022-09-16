#include "Principal.h"
#include <stdio.h>
#include <iostream>

Principal::Principal(){
    menu();
}

Universidade* Principal::localizarUniversidade(const char* nameUni){
    UniversidadeLista* currentUni=NULL;
    currentUni=UniversidadesList.getFirstUniversidade();
    int i=0;
    char nomeVindo[50];

    while (currentUni!=NULL){
        while (nameUni[i]!='\0'){
            strcpy(nomeVindo, currentUni->getUniversidadeNome());
            if (nomeVindo[i]!=nameUni[i]){
                currentUni=currentUni->getNextUni();
                break;
            }
            else
                i++;
        }
        if (nameUni[i]=='\0')
            return (currentUni->getUniversidadeCorrespondente());
        else
            i=0;
    }
    return NULL;
}

Departamento* Principal::localizarDepartamento(const char* nameDpt){
    DepartamentoLista* currentDpt=NULL;
    currentDpt=DepartamentosList.getFirstDepartamento();
    int i=0;
    char nomeVindo[50];

    while (currentDpt!=NULL){
        while (nameDpt[i]!='\0'){
            strcpy(nomeVindo, currentDpt->getDptCorrespondente()->getNome());
            if (nomeVindo[i]!=nameDpt[i]){
                currentDpt=currentDpt->getNextDepartamento();
                break;
            }
            else
                i++;
        }
        if (nameDpt[i]=='\0')
            return (currentDpt->getDptCorrespondente());
        else
            i=0;
    }
    return NULL;
}

Disciplina* Principal::localizarDisciplina(const char* nomeDiscipl){
    DisciplinaLista* currentDiscipl=NULL;
    currentDiscipl=DisciplinasList.getFirstDisciplina();
    int i=0;
    char nomeVindo[50];

    while (currentDiscipl!=NULL){
        while (nomeDiscipl[i]!='\0'){
            strcpy(nomeVindo, currentDiscipl->getDisciplinaCorrespondente()->getName());
            if (nomeVindo[i]!=nomeDiscipl[i]){
                currentDiscipl=currentDiscipl->getNextDiscipl();
                break;
            }
            else
                i++;
        }
        if (nomeDiscipl[i]=='\0')
            return (currentDiscipl->getDisciplinaCorrespondente());
        else
            i=0;
    }
    return NULL;
}

Principal::~Principal(){
}

void Principal::menu(){
    int op=0;
    while (op!=3){
        system("cls");
        std::cout<<"Insira o desejado:"<<std::endl;
        std::cout<<"1- Cadastrar"<<std::endl;
        std::cout<<"2- Executar"<<std::endl;
        std::cout<<"3- Sair"<<std::endl;
        std::cin>>op;

        switch (op)
        {
        case 1:{
            iniciarCadastro();
        }break;
        case 2:{
            iniciarExecucao();
        }break;
        case 3:{
            std::cout<<"Programa finalizado com sucesso!";
        }break;
    
        default:{
            std::cout<<"Comando nao encontrado"<<std::endl;
            system("pause");
        }
        }
    }
}

void Principal::iniciarCadastro(){
    int op=0;
    while (op!=6){
        system("cls");
        std::cout<<"Insira o desejado:"<<std::endl;
        std::cout<<"1- Inserir universidade"<<std::endl;
        std::cout<<"2- Inserir departamento"<<std::endl;
        std::cout<<"3- Inserir disciplina"<<std::endl;
        std::cout<<"4- Inserir pessoa"<<std::endl;
        std::cout<<"5- Sair"<<std::endl;
        std::cin>>op;
        system("cls");
    
        switch (op){
            case 1:{
                cadUniversidade();
            }break;
            case 2:{
                cadDepartamento();
            }break;
            case 3:{
                cadDisciplina();
            }break;
            case 4:{
                cadPessoa();
            }break;
            case 5:{
                menu();
            }break;
            default:{
                std::cout<<"Comando nao encontrado"<<std::endl;
                system("pause");
            }break;
        }
    }
}

void Principal::iniciarExecucao(){
    int op=0;
    while (op!=6){
        system("cls");
        std::cout<<"Insira o desejado:"<<std::endl;
        std::cout<<"1- Listar universidades"<<std::endl;
        std::cout<<"2- Listar departamentos"<<std::endl;
        std::cout<<"3- Listar disciplinas"<<std::endl;
        std::cout<<"4- Listar professores"<<std::endl;
        std::cout<<"5- Listar alunos"<<std::endl;
        std::cout<<"6- Sair"<<std::endl;
        std::cin>>op;
        system("cls");

        switch (op){
        case 1:{
            UniversidadesList.listeUniversidades();
            fflush(stdin);
            getchar();
        }break;
        case 2:{
            DepartamentosList.listeDepartamentos();
            fflush(stdin);
            getchar();
        }break;
        case 3:{
            DisciplinasList.listeDisciplinas();
            fflush(stdin);
            getchar();
        }break;
        case 4:{
            ProfessoresList.listeProfessores();
            fflush(stdin);
            getchar();
        }break;
        case 5:{
            AlunosList.listeAlunos();
            fflush(stdin);
            getchar();
        }break;
        case 6:{
            menu();
        }
        default:{
            std::cout<<"Comando nao encontrado"<<std::endl;
            system("pause");
        }break;
        }
    }
}

void Principal::cadUniversidade(){
    Universidade* nova= new Universidade();
    char name [50];
    
    std::cout<<"Insira o nome da Universidade"<<std::endl;
    std::cin>>name;
    nova->setNome(name);

    UniversidadesList.includeUniversidade(nova);
    std::cout<<"Universidade cadastrada com sucesso!"<<std::endl;
    system("pause");
}

void Principal::cadDepartamento(){
    Departamento* novo= new Departamento();
    Universidade* ptc=NULL;
    char nameDpt [50];
    char nameUni [50];
    
    std::cout<<"Insira o nome do Departamento:"<<std::endl;
    std::cin>>nameDpt;
    novo->setNome(nameDpt);

    std::cout<<"Esse departamento pertence a qual Universidade?"<<std::endl;
    std::cin>>nameUni;

    ptc=localizarUniversidade(nameUni);
    if (ptc!=NULL){
        novo->setParteUni(ptc);
        DepartamentosList.includeDepartamento(novo);
        ptc->includeDepartamento(novo);
        std::cout<<"Departamento cadastrado com sucesso!"<<std::endl;
        system("pause");
    }
    else{
        std::cout<<"Essa universidade nao existe"<<std::endl;
        delete(novo);
        system("pause");
    }
}

void Principal::cadDisciplina(){
    Disciplina* nova=new Disciplina ();
    Departamento* ptc=NULL;
    char nameDisciplina [50];
    char nameDpt [50];

    std::cout<<"Insira o nome da disciplina"<<std::endl;
    std::cin>>nameDisciplina;
    nova->setName(nameDisciplina);

    std::cout<<"Insira o nome do departamento da disciplina"<<std::endl;
    std::cin>>nameDpt;

    ptc=localizarDepartamento (nameDpt);

    if (ptc!=NULL){
        nova->setDptPertencido(ptc);
        DisciplinasList.includeDisciplina(nova);
        ptc->includeDisciplina(nova);
        std::cout<<"Disciplina cadastrada com sucesso!"<<std::endl;
        system("pause");
    }
    else{
        std::cout<<"Esse departamento nao existe"<<std::endl;
        system("pause");
        delete(nova);
    }
}

void Principal::cadPessoa(){
    int opt=0;

    std::cout<<"Insira o desejado:"<<std::endl;
    std::cout<<"1- Inserir aluno"<<std::endl;
    std::cout<<"2- Inserir professor"<<std::endl;
    std::cin>>opt;
    switch (opt)
    {
    case 1:{
        cadAluno();
    }break;
    case 2:{
        cadProfessor();
    }break;
    default:
        std::cout<<"Comando nao encontrado";
        system("pause");
        break;
    }
}

void Principal::cadAluno(){
    char nomeAluno[50];
    char nomeDiscipl[50];
    int dia, mes, ano, op=-1;
    Disciplina* ptc=NULL;
    
    system("cls");
    std::cout<<"Insira o nome"<<std::endl;
    std::cin>>nomeAluno;
    std::cout<<"Insira a data de nascimento:"<<std::endl;
    std::cin>>dia;
    std::cin>>mes;
    std::cin>>ano;

    Aluno* novo= new Aluno();
    novo->inicializar(dia, mes, ano, nomeAluno);
    AlunosList.includeAluno(novo);
    std::cout<<"Aluno cadastrado com sucesso!"<<std::endl;
    system("pause");

    while (op!=0){
        std::cout<<"Insira a disciplina realizada pelo aluno:"<<std::endl;
        std::cin>>nomeDiscipl;

        ptc=localizarDisciplina(nomeDiscipl);
        ptc->includeAluno(novo);

        std::cout<<"Deseja cadastrar mais disciplinas? Digite 0 para encerrar"<<std::endl;
        std::cin>>op;
    }
    std::cout<<"Obrigado!"<<std::endl;
    system("pause");
}

void Principal::cadProfessor(){
    char nomeProfessor [50];
    char nomeDiscipl [50];
    int dia, mes, ano;

    system("cls");
    std::cout<<"Insira o nome do professor"<<std::endl;
    std::cin>>nomeProfessor;
    std::cout<<"Insira a data de nascimento do professor:"<<std::endl;
    std::cin>>dia;
    std::cin>>mes;
    std::cin>>ano;

    std::cout<<"Insira o nome da disciplina na qual ele trabalha"<<std::endl;
    std::cin>>nomeDiscipl;

    Disciplina* ptc=localizarDisciplina(nomeDiscipl);

    if (ptc!=NULL){
        Professor* novo=new Professor();
        novo->inicializar(dia, mes, ano, nomeProfessor);
        std::cout<<"Professor cadastrado com sucesso!"<<std::endl;
        ProfessoresList.includeProfessor(novo);
    }
    else
        std::cout<<"Disciplina nao encontrada"<<std::endl;
    system("pause");
}








