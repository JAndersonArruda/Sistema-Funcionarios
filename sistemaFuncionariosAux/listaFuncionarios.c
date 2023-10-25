#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "listaFuncionarios.h"
#include "funcionario.h"
#include "operandoCsv.h"

/* Criando uma nova lista */
Lista *criarLista()

{
    Lista *lista = (Lista *)malloc(sizeof(Lista));
    lista->inico = NULL;
    return lista;
}

/* Procedimento que adiciona um novo funcionário à lista */
void adicionarFuncionario(Lista *lista, char nome[30], char idade[5], char cpf[15], char matricula[10])
{
    Nodo *novo = (Nodo *)malloc(sizeof(Nodo));
    novo->meuFuncionario = (Funcionario *)malloc(sizeof(Funcionario));

    strcpy(novo->meuFuncionario->nome, nome);
    strcpy(novo->meuFuncionario->idade, idade);
    strcpy(novo->meuFuncionario->cpf, cpf);
    strcpy(novo->meuFuncionario->matricula, matricula);

    novo->proximo = NULL;
    novo->anterior = NULL;

    if (lista->inico == NULL)
    {
        lista->inico = novo;
    }
    else
    {
        Nodo *aux = lista->inico;
        while (aux->proximo != NULL)
        {
            aux = aux->proximo;
        }
        novo->anterior = aux;
        aux->proximo = novo;
    }
    /*Adicionando no documento de texto*/
    atualizarListaTxt(lista);
}

/*Exibir apenas um funcionário (usado em situações mais específicas)*/
void exibirUmFuncionario(Nodo *nodo)
{
    printf("========================\n");
    printf("Nome: %s\n", nodo->meuFuncionario->nome);
    printf("Idade: %s\n", nodo->meuFuncionario->idade);
    printf("CPF: %s\n", nodo->meuFuncionario->cpf);
    printf("Matricula: %s", nodo->meuFuncionario->matricula);
    printf("========================\n\n");
}

/* Procedimento que imprime uma lista */
void imprimirLista(Lista *lista)
{
    Nodo *aux = lista->inico;
    while (aux != NULL)
    {
        exibirUmFuncionario(aux);
        aux = aux->proximo;
    }
}

/*Procedimento que busca um funcionário na lista pelo nome*/
Nodo *buscarFuncionario(Lista *lista, char nome[30])
{

    Nodo *aux = lista->inico;
    while (aux != NULL)
    {
        if (!strcmp(aux->meuFuncionario->nome, nome))
        {
            return aux;
        }
        aux = aux->proximo;
    }
    return NULL;
}

/*Procedimento que deleta um funcionário da lista*/
void excluirFuncionario(Lista *lista, char nome[30])
{

    Nodo *aux = buscarFuncionario(lista, nome);

    if (aux != NULL)
    {
        if (aux->proximo != NULL)
        {
            aux->proximo->anterior = aux->anterior;
        }
        if (aux->anterior != NULL)
        {
            aux->anterior->proximo = aux->proximo;
        }
        if (lista->inico == aux)
        {
            lista->inico = aux->proximo;
        }
        printf("Operacao realizada com sucesso!\n");
        /*Adicionando no documento de texto*/
        atualizarListaTxt(lista);
    }
    else
    {
        printf("Ocorreu um erro na execucao, tente novamente.\n");
    }
}

// ------ Procedimento que alteram cada campo do funcionário isoladamente ---------
/*Recebendo informações do nome*/
void alterarNome(Nodo *nodo)
{
    char nome[30];
    printf("Informe o novo nome: \n");
    gets(nome);
    strcat(nome, ", ");
    fflush(stdin);

    strcpy(nodo->meuFuncionario->nome, nome);
}

/*Recebendo informações do CPF*/
void alterarCpf(Nodo *nodo)
{
    char cpf[23];
    printf("Informe o novo numero do CPF: \n");
    gets(cpf);
    strcat(cpf, ", ");
    fflush(stdin);

    strcpy(nodo->meuFuncionario->cpf, cpf);
}

/*Recebendo informações da idade*/
void alterarIdade(Nodo *nodo)
{
    char idade[8];
    printf("Informe a nova idade: \n");
    gets(idade);
    strcat(idade, ", ");
    fflush(stdin);

    strcpy(nodo->meuFuncionario->idade, idade);
}

/*Procedimento que edita um funcionário*/
void editarFuncionario(Lista *lista, char nome[30])
{
    char editar[8];

    Nodo *aux = lista->inico;
    aux = buscarFuncionario(lista, nome);
    if (aux != NULL)
    {
        printf("O que deseja editar? (nome, idade ou cpf)\n");
        gets(editar);
        fflush(stdin);

        if (!strcmp(editar, "nome"))
        {
            alterarNome(aux);
        }
        else if (!strcmp(editar, "cpf"))
        {
            alterarCpf(aux);
        }
        else if (!strcmp(editar, "idade"))
        {
            alterarIdade(aux);
        }
        else
        {
            printf("Opcao de edicao invalida!\n");
        }
        atualizarListaTxt(lista);
    }
    else
    {
        printf("Funcinario informado nao existe na lista\n");
    }
}

/*Procedimento que gera um numero de matricula*/
void gerarMatricula(char matricula[10])
{
    srand(time(NULL));

    int novaMatricula = rand() % (9999)*rand()%(9999);
    /*Copiar um inteiro em uma string*/
    sprintf(matricula, "%d", novaMatricula);
    strcat(matricula, ",\n");
}