#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "estruturaPilha.h"

/*Funcção que cria um ponteiro para uma pilha*/
Pilha *criarPilha()
{
    Pilha *pilha = (Pilha *)malloc(sizeof(Pilha));
    pilha->topo = NULL;
    return pilha;
}

/*Adicionando itens na pilha*/
void push(char caractere[10], Pilha *pilha)
{
    Nodo *novo = (Nodo *)malloc(sizeof(Nodo));

    strcpy(novo->caractere, caractere);
    novo->proximo = pilha->topo;
    pilha->topo = novo;
}

/*Removendo um item da pilha*/
char *pop(Pilha *pilha)
{
    Nodo *aux = pilha->topo;
    char *caractere = malloc(strlen(aux->caractere) + 1);

    strcpy(caractere, aux->caractere);
    pilha->topo = aux->proximo;
    free(aux);

    return caractere;
}

/*Funcao para auxiliar nas operações*/
int realizarOperacao(Pilha *pilha, char sinal)
{

    int valor1 = 0, valor2 = 0, resultado = 0;
    if (sinal == '+')
    {
        // atoi = ascii to inteiro, atof adcii para float...
        valor1 = atoi(pop(pilha));
        valor2 = atoi(pop(pilha));

        resultado = valor1 + valor2;
    }
    else if (sinal == '-')
    {
        valor1 = atoi(pop(pilha));
        valor2 = atoi(pop(pilha));

        resultado = valor2 - valor1;
    }
    return resultado;
}

/*Deixar string nula*/
void deixarNula(char expressao[50])
{
    for (int controle = 0; controle < strlen(expressao); controle++)
    {
        expressao[controle] = '\0';
    }
}

void retornarSemDes(Pilha *pilha, char expressao[50])
{
    deixarNula(expressao);
    Nodo *aux = pilha->topo;
    while(aux != NULL)
    {
        strcat(expressao, aux->caractere);
        aux = aux->proximo;
    }
    printf ("--- %s ---\n", expressao);
}

/*Decompondo uma strig e empilha seus valores na estrutura*/
int calcularExpressao(char expressao[50], Pilha *pilha)
{
    char auxStr[10], auxExpressao[50];
    deixarNula(auxStr);
    int resultado = 0, sinal = 0, tamanho = strlen(expressao), auxControle, controle = 0;
    strcpy(auxExpressao, expressao);

    char *token = strtok(expressao, "+");

    while (token != NULL)
    {
        // Retorna o determinado sinal
        controle += strlen(token);
        if (auxExpressao[controle] == '+' || auxExpressao[controle] == '\0') // Pega o ultimo caractere(não possui mais sinais)
        {
            if (!sinal)
            {
                push(token, pilha);
                sinal++;
            }
            else
            {
                push(token, pilha);
                resultado += realizarOperacao(pilha, '+');
                sprintf(auxStr, "%d", resultado);
                push(auxStr, pilha);

                retornarSemDes(pilha, expressao);
                token = strtok(expressao, "+");

                sinal = 0;
            }
        }
        token = strtok(NULL, "+ ");
        controle++; // Ignorando os sinais (+, -, (, ), /, *);
    }

    return resultado;
}

/*Desimpilhar tudo*/
void desimpilharTudo(Pilha *pilha)
{
    while (pilha->topo != NULL)
    {
        printf("%s\n", pop(pilha));
    }
}
