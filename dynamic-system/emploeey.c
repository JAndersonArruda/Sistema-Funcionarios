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

