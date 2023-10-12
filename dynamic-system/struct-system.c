#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct-system.h"

int menu() {
    int acao;
    
    //Nova opcao de criar arquivo adicionada
    printf("\n\t------------ Menu ------------- \n\n");
    printf("\t   [1] Criar novo arquivo\n");
    printf("\t   [2] Cadastrar Funcionario (em arquivo existente)\n");
    printf("\t   [3] Atualizar Dados\n");
    printf("\t   [4] Buscar Funcionario\n");
    printf("\t   [5] Ler\n");
    printf("\t   [6] Remover Funcionario\n");
    printf("\t   [7] Encerrar sessão\n\n");
    printf("\t------------------------------- \n\n");

	scanf ("%d", &acao);

    printf("system log: Por favor digite o indice da operação que deseja realizar: ");
    
    return acao;
}