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

int estaBalanceada(char *expressao) {
    Pilha *pilha = criarPilha();
    int i = 0;
    char *charAbertura = "({[";
    char *charFechamento = ")}]";

    while (expressao[i] != '\0') {
        char c = expressao[i];

        if (strchr(charAbertura, expressao[i])) {
            push(pilha, expressao[i]);
        } else if (strchr(charFechamento, expressao[i])) {
            if (estaVazia(pilha)) {
                return 0;
            }
            char topo = pop(pilha);
            if ((c == ')' && topo != '(') || (c == ']' && topo != '[') || (c == '}' && topo != '{')) {
                return 0;
            }
        }
        i++;
    }

    return estaVazia(pilha);
}