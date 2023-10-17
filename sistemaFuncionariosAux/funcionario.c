#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "listaFuncionarios.h"
#include "funcionario.h"

/*Menu de interação para o usuário*/
void menu(Lista *lista)
{
    int opcao;
    char nome[30], idade[8], cpf[23];

    do
    {
        printf("Informe a operacao desejada: \n\n");
        printf("1 - Adicionar um funcionario;\n");
        printf("2 - Pesquisar funcionario;\n");
        printf("3 - Editar funcionario;\n");
        printf("4 - Deletar funcionario;\n");
        printf("5 - Exibir lista de funcionarios;\n");
        printf("6 - Encerrar programa (ou qualquer outra tecla)\n\n");
        scanf("%d", &opcao);
        fflush(stdin);

        switch (opcao)
        {
        case 1:
            printf("Operacao solicitada: Adicionar funcionario\n\n");

            printf("Informe o nome: \n");
            gets(nome);
            fflush(stdin);
            strcat(nome, ", ");

            printf("Informe a idade: \n");
            gets(idade);
            fflush(stdin);
            strcat(idade, ", ");
            fflush(stdin);

            printf("Informe o cpf: \n");
            gets(cpf);
            fflush(stdin);
            strcat(cpf, ", ");
            fflush(stdin);

            adicionarFuncionario(lista, nome, idade, cpf);
            printf("\nOperacao realizada com sucesso!\n");

            break;

        case 2:
            printf("Operacao solicitada: Pesquisar um funcionario\n\n");
            printf("Informe o nome do funcionario que voce deseja pesquisar: \n");
            gets(nome);
            fflush(stdin);
            strcat(nome, ", ");

            Nodo *nodo = buscarFuncionario(lista, nome);
            exibirUmFuncionario(nodo);

            break;

        case 3:
            printf("Operacao solicitada: Editar um funcinario\n\n");
            printf("Informe o nome do funcinario para ser editado: \n");
            gets(nome);
            strcat(nome, ", ");
            fflush(stdin);
            editarFuncionario(lista, nome);

            break;

        case 4:
            printf("Operacao solicitada: Remover funcionario\n\n");

            printf("Informe o nome do funcionario a ser excluido: \n");
            gets(nome);
            fflush(stdin);
            strcat(nome, ", ");

            excluirFuncionario(lista, nome);

            break;

        case 5:
            printf("Operacao solicitada: Exibir toda a lista\n\n");
            imprimirLista(lista);

            break;

        default:
            printf("Operacao invalida!\n");
            break;
        }
    } while (opcao > 0 && opcao <= 5);
}