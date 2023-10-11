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
    Lista *new = (Lista *)malloc(sizeof(Lista));
    new ->start == NULL;
    return new;
}

void addFuncionario(Lista *list, char name[30], int age) {
    Nodo *new = (Nodo *)malloc(sizeof(Nodo));

    if (list ->start == NULL) {
        new ->emploeey = createFuncionario(name, age);
        new ->next = NULL;
        list ->start = new ->emploeey;
    }
    else {

    }
}