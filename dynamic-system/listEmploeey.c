#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "emploeey.h"
#include "listEmploeey.h"

struct nodo {
    Funcionario *emploeey;
    struct nodo *next;
};
typedef struct nodo Nodo;

struct lista {
    Nodo *start;
};
typedef struct lista Lista;


Lista *criarLista() {
    Lista *list = (Lista *)malloc(sizeof(Lista));
    list ->start == NULL;
    return list;
}

void addFuncionario(Lista *list, char name[30], int age) {
    Nodo *new = (Nodo *)malloc(sizeof(Nodo));
    new ->emploeey = createFuncionario(name, age);
    new ->next = NULL;

    if (list ->start == NULL) {
        list ->start = new;
    }
    else {
        Nodo *aux = list ->start;
        Nodo *temp = NULL;
        int comp = strcmp(name, new ->emploeey ->nome);

        while (comp > 0 && aux ->next != NULL) {
            temp = aux;
            aux = aux ->next;
            comp = strcmp(name, new ->emploeey ->nome);
        }

        if (comp > 0) {
            aux ->next = new;
        }
        else if (list ->start == aux) {
            new ->next = aux;
            list ->start = new;
        }
        else {
            new ->next = aux;
            temp ->next = new;
        }      
    }
}
