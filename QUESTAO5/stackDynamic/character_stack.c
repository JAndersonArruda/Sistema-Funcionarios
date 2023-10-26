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

void liberarPilha(Pilha *pilha) {
    Nodo *atual = pilha->topo;
    while (atual != NULL) {
        Nodo *aux = atual;
        atual = atual->prox;
        free(aux);
    }
    free(pilha);
}

/*
int estaBalanceada(char *expressao, char *charAbertura, char *charFechamento) {
    Pilha *pilha = criarPilha();
    int i = 0;

    while (expressao[i] != '\0') {
        int c;
        int ehAbertura = 0;

        for (c = 0; charAbertura[c] != '\0'; c++) {
            if (expressao[i] == charAbertura[c]) {
                push(pilha, expressao[i]);
                ehAbertura = 1;
                break;
            }
        }

        if (!ehAbertura) {
            for (c = 0; charFechamento[c] != '\0'; c++) {
                if (expressao[i] == charFechamento[c]) {
                    if (estaVazia(pilha)) {
                        return 0;
                    }
                    pop(pilha);
                    break;
                }
            }
        }

        i++;
    }

    return estaVazia(pilha);
}
*/

// Simplificação com o strchr -> realiza comparações, semelhante ao utilizado acima.
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
                liberarPilha(pilha);
                return 0;
            }
            char topo = pop(pilha);
            if ((c == ')' && topo != '(') || (c == ']' && topo != '[') || (c == '}' && topo != '{')) {
                liberarPilha(pilha);
                return 0;
            }
        }
        i++;
    }

    int resultado = estaVazia(pilha);
    liberarPilha(pilha);
    return resultado;
}

