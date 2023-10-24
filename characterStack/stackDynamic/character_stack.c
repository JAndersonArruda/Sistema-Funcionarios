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


