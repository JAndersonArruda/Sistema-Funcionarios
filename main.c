#include <stdio.h>
#include <stdlib.h>
#include "system-actions.h"

void main() {
    Funcionario funcionarios[3];

    int idxFuncionario = 0;
    int acao;

    printf("\n ---------- Sistema de Funcionarios ---------- \n\n");
    do {
        acao = menu();

        switch (acao) {
            case 1:
                printf("\n---------- Cadastre-se! ----------\n");
                printf("system log: preencha os campos necessarios para o cadastro...\n");

                char nome[50], cpf[15], endereco[100];
                int idade;
                float salario;

                fflush(stdin);
                printf("Nome: ");
                scanf("%s", &nome);
                fflush(stdin);
                printf("Idade: ");
                scanf("%d", &idade);
                fflush(stdin);
                printf("CPF: ");
                scanf("%s", &cpf);
                fflush(stdin);
                printf("Endereço: ");
                scanf("%s", &endereco);
                fflush(stdin);
                printf("Salário: ");
                scanf("%f", &salario);
                fflush(stdin);

                if (idxFuncionario < 3) {
                    createEmployee(&funcionarios, idxFuncionario, nome, idade, cpf, endereco, salario);
                    
                    if (idxFuncionario == 2) {
                    writeFile(funcionarios, "funcionarios.csv");
                    }

                    idxFuncionario++;
                }
                break;
            case 2:
                printf("\n---------- Ação de Atualização! ----------\n");
                printf("system log: preencha os campos necessarios para a atualização dos dados do funcionario...\n");
                //chamar procedimento udateEmployee();
                getchar();
                break;
            case 3:
                printf("\n---------- Ação de Busca! ----------\n");
                printf("system log: preencha os campos necessarios para a busca de funcionarios...\n");
                //chamar procedimento fetchEmployee();
                getchar();
                break;
            case 4:
                printf("\n---------- Ação de Leitura! ----------\n\n");
                //chamar procedimento readEmployee();
                printf("system log: leitura completa.\n");
                getchar();
                break;
            case 5:
                printf("\n---------- Ação de Remoção! ----------\n");
                printf("system log: preencha os campos necessarios para a remoção...\n");
                //chamar procedimento deleteEmployee();
                getchar();
                break;
            case 6:
                continue;
            default:
                printf("\nsystem log: Informe uma ação valida!\n\n");
                getchar();
                break;
        }
    } while (acao != 6);
    
    printf("\nsystem log: Sistema Encerrado! \n");
    getchar();
}
