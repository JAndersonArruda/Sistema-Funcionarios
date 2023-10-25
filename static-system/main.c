#include <stdio.h>
#include <stdlib.h>

#include "systemActions.h"

int TAMANHO = 10;

int main() {
    int cpf;

    /*VARIÁVEL EXTERNA TEM QUE SER DECLARADA NO .C QUE SERÁ UTILIZADA*/

    Funcionario *funcionarios[TAMANHO];

    int idxFuncionario = 0; 
    int acao;

    printf("\n ---------- Sistema de Funcionarios ---------- \n\n");
    do {
        acao = menu();

        int numFuncionarios;

        switch (acao) {
            case 1:
                if (idxFuncionario <= TAMANHO) {
                    if(idxFuncionario == TAMANHO) {
                        idxFuncionario = 0;
                    }

                    createEmployee(funcionarios, idxFuncionario);
                    writeFile(funcionarios, "funcionarios.csv", idxFuncionario);

                    idxFuncionario++;
                }
                break;
            case 2:
                printf("CPF: ");
                scanf("%d", &cpf);
                updateEmployee("funcionarios.csv", cpf);
                break;
            case 3:
                printf("\n---------- Ação de Busca! ----------\n");
                printf("system log: preencha os campos necessarios para a busca de funcionarios...\n");
                printf("CPF: ");
                scanf("%d", &cpf);
                Funcionario funcionario = buscarFuncionario("funcionarios.csv", cpf);
                if (funcionario.cpf != -1){
                    printEmployee(funcionario);
                }
                break;
            case 4:
                numFuncionarios = contarLinhasCSV("funcionarios.csv");
                Funcionario *funcionarios = buscarFuncionarios("funcionarios.csv");
                int fun;
                for (fun = 0; fun < numFuncionarios; fun++){
                    printEmployee(funcionarios[fun]);
                }
                break;
            case 5:
                printf("\n---------- Ação de Remoção! ----------\n");
                printf("system log: preencha os campos necessarios para a remoção...\n");
                printf("CPF: ");
                scanf("%d", &cpf);
                deleteEmployee("funcionarios.csv", cpf);
                getchar();
                break;
            default:
                printf("\nsystem log: Informe uma ação valida!\n\n");
                getchar();
        }
    } while (acao != 6);
    
    printf("\nsystem log: Sistema Encerrado! \n");
    return 0;
}
