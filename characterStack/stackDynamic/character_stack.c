#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo {
    char simbolo;
    struct nodo *prox;
} Nodo;

typedef struct pilha {
    Nodo *topo;
} Pilha;

Pilha *criarPilha() {
    Pilha *pilha = (Pilha *)malloc(sizeof(Pilha));
    if (pilha != NULL) {
        pilha->topo = NULL;
    }
    return pilha;
}

int estaVazia(Pilha *pilha) {
    return pilha->topo == NULL;
}

void push(Pilha *pilha, char valor) {
    Nodo *novoNodo = (Nodo *)malloc(sizeof(Nodo));
    if (novoNodo != NULL) {
        novoNodo->simbolo = valor;
        novoNodo->prox = pilha->topo;
        pilha->topo = novoNodo;
    } else {
        printf("Erro: Falha na alocação de memória.\n");
    }
}

int pop(Pilha *pilha) {
    if (!estaVazia(pilha)) {
        Nodo *aux = pilha->topo;
        int value = aux->simbolo;
        pilha->topo = aux->prox;
        free(aux);
        return value;
    } else {
        printf("Erro: A pilha está vazia.\n");
        return -1;  // Valor de erro
    }
}
