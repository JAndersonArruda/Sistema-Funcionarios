#include <stdio.h>
#include <stdlib.h>
#include "system-actions.h"

char fileName[50];

void main() {
    Funcionario funcionarios[3];

    int idxFuncionario = 0;
    int acao;


    printf("\n ---------- Sistema de Funcionarios ---------- \n\n");
    do {
        acao = menu();

        switch (acao) {
        	
        	case 1:
                printf("\n---------- A��o de criar um arquivo! ----------\n");
                printf("system log: Informe o nome do arquivo que ser� criado para realizar as devidas opera��es...\n");
                gets(fileName);
                //chamar fun��o createFile();
                //Declarando o arquivo aqui para utilizar apenas ele no decorrer da execu��o
                openFIle(fileName, "w");
                getchar();
                break;
        	
            case 2:
                printf("\n---------- Cadastre-se! ----------\n");
                printf("system log: preencha o nome do aruivo e os campos necessarios para o cadastro...\n");
                printf ("Nome do arquivo: \n");
                scanf ("%s", &fileName);

                char nome[50], cpf[15], endereco[100], idade[5], salario[15];


                fflush(stdin);
                printf("Nome: ");
                scanf("%s", &nome);
                fflush(stdin);
                printf("Idade: ");
                scanf("%s", &idade);
                fflush(stdin);
                printf("CPF: ");
                scanf("%s", &cpf);
                fflush(stdin);
                printf("Endereço: ");
                scanf("%s", &endereco);
                fflush(stdin);
                printf("Salário: ");
                scanf("%s", &salario);
                fflush(stdin);

                createEmployee(funcionarios, idxFuncionario, nome, idade, cpf, endereco, salario, fileName);

                idxFuncionario++;
                break;
            case 3:
                printf("\n---------- Ação de Atualização! ----------\n");
                printf("system log: preencha os campos necessarios para a atualização dos dados do funcionario...\n");
                //chamar procedimento udateEmployee();
                getchar();
                break;
            case 4:
                printf("\n---------- Ação de Busca! ----------\n");
                printf("system log: preencha os campos necessarios para a busca de funcionarios...\n");
                //chamar procedimento fetchEmployee();
                getchar();
                break;
            case 5:
                printf("\n---------- Ação de Leitura! ----------\n\n");
                //chamar procedimento readEmployee();
                printf ("Informe o nome do arquivo a ser lido: \n");
                scanf ("%s", &fileName);
                readEmployee(fileName);
                printf("system log: leitura completa.\n");
                getchar();
                break;
            case 6:
                printf("\n---------- Ação de Remoção! ----------\n");
                printf("system log: preencha os campos necessarios para a remoção...\n");
                //chamar procedimento deleteEmployee();
                getchar();
                break;
            case 7:
                continue;
            default:
                printf("\nsystem log: Informe uma ação valida!\n\n");
                getchar();
                break;
        }
    } while (acao != 7);
    
    printf("\nsystem log: Sistema Encerrado! \n");
    getchar();
}
