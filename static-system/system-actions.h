#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Tamanho padrão */
int TAMANHO;

/* COnstrução da estrutura */
typedef struct funcionario{
    char nome[50];
    int idade;
    int cpf;
    char endereco[100];
    float salario;
} Funcionario;

/* Definindo estrutura funcionario */
typedef struct funcionario Funcionario;

/* Abrir o Arquivo */
FILE *openFile(char nome[50], char mode[5]);

/* Rotula as linhas no arquivo*/
int contarLinhasCSV(char fileName[50]);

/* Fecha o arquivo */
void closeFile(FILE *file);

/* Menu do sistema */
int menu();

/* Recebe os dados de um novo funcionario */
void inputEmployeeData(Funcionario *funcionario);

/* Crea um novo funcionario */
void createEmployee(Funcionario *funcionarios[TAMANHO], int idx);


/* Busca e retorna um ponteiro para os dados dos funcionarios */
Funcionario *buscarFuncionarios(char fileName[50]);

/* Busca e retorna dos dados do funcionario */
Funcionario buscarFuncionario(char fileName[50], int cpf);

/* Atulaiza os dados de um funcionario existente */
void updateEmployee(char fileName[50], int cpf);


/* Deleta os dados de um funcionario existente */
void deleteEmployee(char fileName[50], int cpf);

/* Ler e escreve os dados no arquivo*/
void writeFile(Funcionario *funcionarios[TAMANHO], char nome[50], int idx);

/* EScreve os dados do arquivo para o array */
void writeFileArray(Funcionario funcionarios[TAMANHO], char nome[50], int idx);

/* Emprime os dados dos funcionarios */
void printEmployee(Funcionario funcionario);