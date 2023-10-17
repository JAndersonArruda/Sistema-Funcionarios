#ifndef OPERANDOCSV_H
#define OPERANDOCSV_H

/*Criando meu documento no inicio da execução*/
typedef struct File File;

/*Abrindo um arquivo de texto para adicionar os funcionarios*/
File *operarDocumento(char nome[30], char modo[3]);

/*Procedimento que atualiza uma lista de texto*/
void atualizarListaTxt(Lista *lista);

#endif
