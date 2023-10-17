#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

/* Estrutura do meu funcionário */
typedef struct Funcionario
{
    char nome[30];
    char idade[8];
    char cpf[23];
} Funcionario;

/* Estrutura do meu nodo */
typedef struct Nodo
{
    Funcionario *meuFuncionario;
    struct Nodo *proximo;
    struct Nodo *anterior;
} Nodo;

/*Definindo a estrutura lista*/
typedef struct Lista Lista;

/*Menu gráfico que para o usuário interagir*/
void menu(Lista *lista);

#endif