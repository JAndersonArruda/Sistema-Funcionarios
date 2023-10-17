#ifndef LISTAFUNCIONARIOS_H
#define LISTAFUNCIONARIOS_H

//------- DEFINIÇÃO ESTRUTURA NO CABECALHO FICA MAIS FACIL O ACESSO
//typedef strut Nodo Nodo ---- PROBLEMA DE ACESSO EM OUTROS ARQUIVOS .C      Consultar André

#include "funcionario.h"

/* Estrutura de uma lista */
typedef struct Lista
{
    Nodo *inico;
} Lista;

/* Função que cria a minha lista */
Lista *criarLista();

/* Procedimento que adiciona um novo funcionário na lista */
void adicionarFuncionario(Lista *lista, char nome[], char idade[], char cpf[]);

/* Procedimento que imprime toda a lista */
void imprimirLista(Lista *lista);

/*Procedimento que encontra um funcionário pelo nome dele*/
Nodo * buscarFuncionario(Lista *lista, char nome[]);

/*Procedimento que exibe apenas um úbico nome (usado em casos especiíficos)*/
void exibirUmFuncionario(Nodo *nodo);

/*Procedimento que deleta um funionário da lsita*/
void excluirFuncionario(Lista *lista, char nome[]);

/*Procedimento que edita um funcionário*/
void editarFuncionario(Lista *lista, char nome[30]);

#endif
