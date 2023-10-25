#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listaFuncionarios.h"
#include "funcionario.h"
#include "operandoCsv.h"

//Estrutura para um arquivo
typedef struct File
{
    FILE *documento;
} File;

//Operando o documento e realizando testes
File *operarDocumento(char nome[30], char modo[3])
{
    File *arquivo = (File *)malloc(sizeof(File));
    //Verificando se o arquivo existe
    if (arquivo != NULL)
    {
        //Verificando se o ponteiro não é nulo
        arquivo->documento = fopen(nome, modo);
        if (arquivo->documento != NULL)
        {
            return arquivo;
        }
    }
 return NULL;
}

//Atualizando arquivos de texto para o documento listaFun.txt
void atualizarListaTxt(Lista *lista)
{
    File *arquivo = operarDocumento("listaFun.txt", "w+");
    Nodo *aux = lista->inico;
    while (aux != NULL)
    {
        fputs(aux->meuFuncionario->nome, arquivo->documento);
        fputs(aux->meuFuncionario->idade, arquivo->documento);
        fputs(aux->meuFuncionario->cpf, arquivo->documento);
        fputs(aux->meuFuncionario->matricula, arquivo->documento);

        aux = aux->proximo;
    }
    fclose(arquivo->documento);
}