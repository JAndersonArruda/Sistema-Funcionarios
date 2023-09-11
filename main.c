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

//obs: colocar pausa de segurança no fim de cada ação para que o ususario veja as informações, antes de iniciar novamente o menu.

#include <stdio.h>

void main() {
    int acao;

    while (1) {
        printf("\n ---------- Sistema de Funcionarios ---------- \n\n");

        printf("\n\t------------ Menu ------------- \n\n");
        printf("\t   01. Cadastrar...\n");
        printf("\t   02. Atualizar...\n");
        printf("\t   03. Buscar...\n");
        printf("\t   04. Ler...\n");
        printf("\t   05. Remover...\n");
        printf("\t   06. Encerrar sessão...\n\n");
        printf("\t------------------------------- \n\n");

        printf("system log: Por favor digite o indice da operação que deseja realizar: ");
        scanf("%d", &acao);

        if (acao == 01 || acao == 1) {
            printf("\n---------- Ação de Cadastro! ----------\n");
            printf("system log: preencha os campos necessarios para o cadastro...\n");
            //chamar procedimento createEmployee();
        }
        else if (acao == 02 || acao == 2) {
            printf("\n---------- Ação de Atualização! ----------\n");
            printf("system log: preencha os campos necessarios para a atualização dos dados do funcionario...\n");
            //chamar procedimento udateEmployee();
        }
        else if (acao == 03 || acao == 3) {
            printf("\n---------- Ação de Busca! ----------\n");
            printf("system log: preencha os campos necessarios para a busca de funcionarios...\n");
            //chamar procedimento fetchEmployee();
        }
        else if (acao == 04 || acao == 4) {
            printf("\n---------- Ação de Leitura! ----------\n\n");
            //chamar procedimento readEmployee();
            printf("system log: leitura completa.\n");
        }
        else if (acao == 05 || acao == 5) {
            printf("\n---------- Ação de Remoção! ----------\n");
            printf("system log: preencha os campos necessarios para a remoção...\n");
            //chamar procedimento deleteEmployee();
        }
        else if (acao == 06 || acao == 6) {
            break;
        }
        else {
            printf("\nsystem log: Informe uma ação valida!\n\n");
        }
    }
    printf("\nsystem log: Sistema Encerrado! \n");
}
