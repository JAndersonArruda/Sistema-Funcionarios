#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "emploeey.h"

struct funcionario {
    char nome[30];
    int idade;
};
typedef struct funcionario Funcionario;


Funcionario *createFuncionario(char name[30], int age) {
    Funcionario *new = (Funcionario *)malloc(sizeof(Funcionario));
    strcpy(new ->nome, name);
    new ->idade = age;
    return new;
}

void freeFuncionario(Funcionario *emploeey) {
    free(emploeey);
}

void printFuncionario(Funcionario *emploeey) {
    printf("-----------------------------------------------------\n");
    printf("Nome: %s\n Idade: %.02d\n", emploeey ->nome, emploeey ->idade);
}

void updateNameFuncionario(Funcionario *emploeey, char name[30]) {
    strcpy(emploeey ->nome, name);
}

void updateAgeFuncionario(Funcionario *emploeey, int age) {
    emploeey ->idade = age;
}
