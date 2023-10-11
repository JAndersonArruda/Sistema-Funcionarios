#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    int numero;
    char rua[30];
    char bairro[20]; //lote
    char cidade[20];
    char estado[3]; //sigla
} Endereco;

typedef struct {
    char nome[50];
    char rg[10];
    char cargo[15];
    Endereco *residencia; 
} Funcionario;

typedef struct nodo {
    Funcionario *dados;
    struct nodo *proximo;
} Nodo;

typedef struct {
    Nodo *inicio;
} Lista;


Lista *createList() {
    Lista *list = (Lista *)malloc(sizeof(Lista));

    if (list != NULL) {
        list->inicio = NULL;
        return list;
    }
    printf("Espaco de memoria insufiencte");
}

void addEmployee(Lista *list, char name[50], char rg[10], char office[15], int numHouse, char road[30], char batch[20], char city[20], char state[3]) {
    Nodo *newEmployee = (Nodo *)malloc(sizeof(Nodo));

    if (newEmployee == NULL) {
        printf("Espaco de memoria insufiencte");
    }
    else {
        newEmployee->proximo = NULL;
        strcpy(newEmployee->dados->nome, name);
        strcpy(newEmployee->dados->rg, rg);
        strcpy(newEmployee->dados->cargo, office);
        newEmployee->dados->residencia->numero = numHouse;
        strcpy(newEmployee->dados->residencia->rua, road);
        strcpy(newEmployee->dados->residencia->bairro, batch);
        strcpy(newEmployee->dados->residencia->cidade, city);
        strcpy(newEmployee->dados->residencia->estado, state);

        if (list->inicio == NULL) {
            list->inicio = newEmployee;
        }
        else {
            //emplementar posteriormente;
        }
    }
    
}
