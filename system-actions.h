#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    int id;
    char nome[50];
    int idade;
    char cpf[15];
    char endereco[100];
    float salario;
} Funcionario;


int menu() {
    int acao;
    
    printf("\n\t------------ Menu ------------- \n\n");
    printf("\t   [1] Cadastrar...\n");
    printf("\t   [2] Atualizar...\n");
    printf("\t   [3] Buscar...\n");
    printf("\t   [4] Ler...\n");
    printf("\t   [5] Remover...\n");
    printf("\t   [6] Encerrar sessão...\n\n");
    printf("\t------------------------------- \n\n");

    printf("system log: Por favor digite o indice da operação que deseja realizar: ");
    scanf("%d", &acao);

    return acao;
}
