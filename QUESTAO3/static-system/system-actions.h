#ifndef SYSTEM_ACTIONS_H
#define SYSTEM_ACTIONS_H
#include <stdio.h>


#define TAMANHO 15

typedef struct funcionario {
    char nome[50];
    int idade;
    int cpf;
    char endereco[100];
    float salario;
} Funcionario;

FILE *openFile(char *nome, char *mode);
int contarLinhasCSV(char *fileName);
void closeFile(FILE *file);
int menu();
void inputEmployeeData(Funcionario *funcionario);
void createEmployee(Funcionario *funcionarios[TAMANHO], int idx);
Funcionario *buscarFuncionarios(char *fileName);
Funcionario buscarFuncionario(char fileName[50], int cpf);
void updateEmployee(char *fileName, int cpf);
void deleteEmployee(char *fileName, int cpf);
void writeFile(Funcionario *funcionarios[TAMANHO], char *nome, int idx);
void writeFileArray(Funcionario funcionarios[TAMANHO], char *nome, int idx);
void printEmployee(Funcionario funcionario);

#endif