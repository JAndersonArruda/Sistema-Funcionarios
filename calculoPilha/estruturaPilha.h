#ifndef ESTRUTURAPILHA_H
#define ESTRUTURAPILHA_H

/*Estrutura da pilha*/
typedef struct Nodo
{
    struct Nodo *proximo;
    char caractere[10];
}Nodo;

/*Estrutura da minha pilha*/
typedef struct Pilha
{
    Nodo *topo;
}Pilha;

/*Função que retorna um ponteiro para uma pilha*/
Pilha *criarPilha();

/*Procedimento que adiciona um elemento na pilha*/
void push(char caractere[10], Pilha *pilha);

/*Remover um item da pilha*/
char *pop(Pilha *pilha);

/*Decompondo uma string e organizando na pilha*/
int calcularExpressao(char expressao[50], Pilha *pilha);

/*Desimpilhar toda a pilha*/
void desimpilharTudo(Pilha *pilha);

/*Procedimento que diexa uma string nula*/
void deixarNula(char expressao[10]);

/*Funcao para auxiliar nas operações*/
int realizarOperacao(Pilha *pilha, char sinal);

/*"Atualizar expressão"*/
void retornarSemDes(Pilha *pilha, char[50]);

#endif