#ifndef FILACIRCULAR_H
#define FILACIRCULAR_H

/*Menu de interação com o usuário*/
void menu();

/*Estrutura de um nodo de impressão*/
typedef struct funcionario{
    char nome[10];
    int prioridade;
}funcionario;

/*Estrutura que simula um funcionário que solicitou a impressora*/
void destruirFilaCircular(funcionario *fila);

/*Funcçao que retorna uma fila*/
funcionario *criarFilaCircular();

/*Procedimento que insere um elemento*/
void inserirElemento(funcionario *fila, char nome[10], int prioridade);

/*Desinfileirar um elemento*/
void desinfileirarElemento(funcionario *fila);

/*Verifica se uma fila está ou não cheia*/
int checarFilaCheia();

/*Quando um valor entra no meio da fila devido a preferencia, a funcao é chamada*/
int menorQue(funcionario *fila, int elemento, int reserva);

/*Realzia a troca de valores em uma fila*/
void permutarValores(funcionario * fila, int p1, int p2);

/*Mecanismo que define a posição de cada impressão com base na orde de preferência */
int controlarEntrada(funcionario *fila, int element);

/*Exibir estado atual*/
void exibirEstado(int *fila);

void exibir();

#endif