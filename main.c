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

void main() {
    int acao;

    while (1) {
        printf(" --------- Sistema de Funcionarios ---------- \n\n");
        printf("\t---------- Menu ----------- \n");
        printf("\t01. Cadastrar...\n");
        printf("\t02. Atualizar...\n");
        printf("\t03. Buscar...\n");
        printf("\t04. Ler...\n");
        printf("\t05. Remover...\n");
        printf("\t06. Encerrar sessão...\n\n");

        printf(" Por favor digite o indice da operação que deseja realizar: ");
        scanf("%d", &acao);
        if (acao == 01 || acao == 1) {
            printf("\n---------- Ação de Cadastro! ----------\n");
        }
        else if (acao == 02 || acao == 2) {
           printf("\n---------- Ação de Atualização! ----------\n");
        }
        else if (acao == 03 || acao == 3) {
            printf("\n---------- Ação de Busca! ----------\n");
        }
        else if (acao == 04 || acao == 4) {
            printf("\n---------- Ação de Leitura! ----------\n");
        }
        else if (acao == 05 || acao == 5) {
            printf("\n---------- Ação de Remoção! ----------\n");
        }
        else if (acao == 06 || acao == 6) {
            break;
        }
        else {
            printf("\nInforme uma ação valida!\n\n");
        }
    }
    printf("\nsistem log: Sistema Encerrado! \n");
}
