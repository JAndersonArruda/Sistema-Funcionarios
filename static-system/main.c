/*
-- Criar um sistema de funcionarios em que as informações sejam amrazenadas em um arquivo .csv
-- Cada dado deve ser armazenado de formma organizada, cada coluna deve conter um unico tipo de informação
-- Os referentes dados são:
    -->CPF(id);
    -->Nome;
    -->Endereço;
    -->Idade;
    -->Cargo;

-- Criar um sistema continuo.
*/


#include <stdio.h>
#include "system-actions.h"

void main() {
    int acao;

    while (1) {
        printf("\n ---------- Sistema de Funcionarios ---------- \n\n");

        int acao = menu();
        // printf("\n\t------------ Menu ------------- \n\n");
        // printf("\t   01. Cadastrar...\n");
        // printf("\t   02. Atualizar...\n");
        // printf("\t   03. Buscar...\n");
        // printf("\t   04. Ler...\n");
        // printf("\t   05. Remover...\n");
        // printf("\t   06. Encerrar sessão...\n\n");
        // printf("\t------------------------------- \n\n");
        // printf("system log: Por favor digite o indice da operação que deseja realizar: ");
        // scanf("%d", &acao);
        getchar();

        if (acao == 1) {
            printf("\n---------- Ação de Cadastro! ----------\n");
            printf("system log: preencha os campos necessarios para o cadastro...\n");
            //chamar procedimento createEmployee();
            getchar();
        }
        else if (acao == 2) {
            printf("\n---------- Ação de Atualização! ----------\n");
            printf("system log: preencha os campos necessarios para a atualização dos dados do funcionario...\n");
            //chamar procedimento udateEmployee();
            getchar();
        }
        else if (acao == 3) {
            printf("\n---------- Ação de Busca! ----------\n");
            printf("system log: preencha os campos necessarios para a busca de funcionarios...\n");
            //chamar procedimento fetchEmployee();
            getchar();
        }
        else if (acao == 4) {
            printf("\n---------- Ação de Leitura! ----------\n\n");
            //chamar procedimento readEmployee();
            printf("system log: leitura completa.\n");
            getchar();
        }
        else if (acao == 5) {
            printf("\n---------- Ação de Remoção! ----------\n");
            printf("system log: preencha os campos necessarios para a remoção...\n");
            //chamar procedimento deleteEmployee();
            getchar();
        }
        else if (acao == 6) {
            break;
        }
        else {
            printf("\nsystem log: Informe uma ação valida!\n\n");
            getchar();
        }
    }
    printf("\nsystem log: Sistema Encerrado! \n");
    getchar();
}
