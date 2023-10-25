/*
– Criar uma fila circular vazia;
– Verificar se a fila circular está cheia e/ou vazia;
– Inserir um novo nodo no final da fila circular
(enfileirar);
– Excluir o nodo que está no início da fila circular
(desenfileirar);
– Consultar e/ou alterar o nodo que está no início
da fila circular ;
– Destruir a fila circular.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "filaCircular.h"

/*Variaveis de controle globais*/
const int MAX = 10;
int inicio = 0, fim = -1, quantidade = 0, aux = 0, repeticao = 0;
;

/*Procedimento que zera uma fila*/
void destruirFilaCircular(funcionario *fila)
{
    for (int controle = 0; controle < 10; controle++)
    {
        fila[controle].prioridade = 0;
        strcpy(fila[controle].nome, "S/N");
    }
}

/*Criando uma fila circular (um vetor de intiros com 10 posições)*/
funcionario *criarFilaCircular()
{
    funcionario *fila = (funcionario *)malloc(sizeof(funcionario) * 10);
    destruirFilaCircular(fila);
    return fila;
}

/*Desinfileirar um elemento*/
void desinfileirarElemento(funcionario *fila)
{
    printf("Elemento impresso -> %s\nPrioridade = %d\n\n", fila[inicio].nome, fila[inicio].prioridade);
    fila[inicio].prioridade = 0;
    strcpy(fila[inicio].nome, "S/N");

    inicio = inicio == 9 ? 0 : inicio + 1;

    quantidade--;
}

/*Verificando se a fila está cheia*/
int checarFilaCheia()
{
    return quantidade == MAX ? 1 : 0;
}

/*Procedimento que insere um elemento*/
void inserirElemento(funcionario *fila, char nome[10], int prioridade)
{
    if (checarFilaCheia())
    {
        fim = aux % 10 == 0 &&fim != 0 ? fim = 0 : fim;
        desinfileirarElemento(fila);
    }

    aux++;

    int indice = controlarEntrada(fila, prioridade);

    fila[indice].prioridade = prioridade;
    strcpy(fila[indice].nome, nome);
    quantidade++;
}

/*Retorna o indice da fuila que um valor deve entrar*/
int menorQue(funcionario *fila, int prioridade, int reserva)
{
    for (int controle = inicio; fila[controle].prioridade != 0; controle++)
    {

        controle = controle == 10 ? 0 : controle;

        if (fila[controle].prioridade == 1)
        {
            repeticao++;
        }

        if (prioridade >= fila[controle].prioridade && fila[controle + 1].prioridade != 1)
        {
            controle = controle == 0 ? MAX - 1 : controle - 1;

            return controle;
        }
    }
    return 0;
}

/*Permutar valores quando necessário (devido a ordem de preferencia)*/
void permutarValores(funcionario *fila, int posicao1, int posicao2)
{
    char auxStr[10];
    int auxpri = fila[posicao1].prioridade;
    strcpy(auxStr, fila[posicao1].nome);

    fila[posicao1].prioridade = fila[posicao2].prioridade;
    strcpy(fila[posicao1].nome, fila[posicao2].nome);

    fila[posicao2].prioridade = auxpri;
    strcpy(fila[posicao2].nome, auxStr);
}

/*Controlador de entrada na fila*/
/*
1 - Diretor
2 - Coordenado
3 - Funcionario
*/
int controlarEntrada(funcionario *fila, int prioridade)
{
    if (prioridade < fila[inicio].prioridade || prioridade == 1)
    {
        if (inicio == 0)
        {
            inicio = MAX - 1;
        }
        else
        {
            if (checarFilaCheia())
            {
                desinfileirarElemento(fila);
            }
            else
            {
                inicio--;
                return inicio;
            }
        }
    }
    else if (prioridade == 2)
    {
        int reserva = 0;
        int valor = menorQue(fila, prioridade, reserva);
        if (valor == 0)
        {
            if (checarFilaCheia())
            {
                desinfileirarElemento(fila);
            }
            else
            {
                fim++;
                return valor;
            }
        }
        else
        {
            if (repeticao > 0)
            {
                permutarValores(fila, inicio - 1, valor + 1);
                repeticao = 0;
            }
            inicio--;
        }
        return valor + 1;
    }
    else if (prioridade == 3)
    {
        fim++;
        return fim;
    }
}

/*Exibir estado atual*/
void exibirEstado(int *fila)
{
    printf("Sequencia da fila no termino da execucao: \n");
    for (int controle = 0; controle < MAX; controle++)
    {
        printf("%d \n", fila[controle]);
    }
}

void exibir()
{
    printf("Inicio atual da fila = %d\n", inicio);
    printf("Fim atual da fila = %d\n", fim);
    printf("Quantidade atual = %d\n", quantidade);
    printf("Impressoes totais = %d\n\n", aux);
}
