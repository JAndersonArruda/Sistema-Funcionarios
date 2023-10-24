#include "character_stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_MAXIMO 100

typedef struct pilha {
    char simbolos[TAMANHO_MAXIMO];
    int topo;
} Pilha;

Pilha *criarPilha() {
    Pilha *pilha = (Pilha *)malloc(sizeof(Pilha));
    if (pilha != NULL) {
        pilha->topo = -1;
    }
    return pilha;
}

int estaVazia(Pilha *pilha) {
    return pilha->topo == -1;
}

int estaCheia(Pilha *pilha) {
    return pilha->topo == TAMANHO_MAXIMO - 1;
}

void push(Pilha *pilha, char valor) {
    if (!estaCheia(pilha)) {
        pilha->topo++;
        pilha->simbolos[pilha->topo] = valor;
    } else {
        printf("Erro: A pilha está cheia.\n");
    }
}

char pop(Pilha *pilha) {
    if (!estaVazia(pilha)) {
        char valor = pilha->simbolos[pilha->topo];
        pilha->topo--;
        return valor;
    } else {
        printf("Erro: A pilha está vazia.\n");
        return '\0';
    }
}
