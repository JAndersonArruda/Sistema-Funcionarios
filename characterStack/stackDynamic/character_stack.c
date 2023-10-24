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
