#ifndef SYSTEMACTIONS_H
#define SYSTEMACTIONS_H

/*Sempre checar se o arquivo .c está na pasta .vscode > task.json > "args" (já adicionei)*/

/*NÃO É RECOMENDADO INCLUIR BIBLIOTECAS NATIVAS DA LINGUAGEM EM NENHUM CASO*/
/*USAR DIRETIVAS DE PRÉ-PROCESSAMENTO (ifndef, define e endif)*/

/*ERRO NA DECLARAÇÃO, NÃO PODE DECLARAR VALORES NO .H, E FALTOU O EXTERN*/
extern int TAMANHO;

extern int minhaVariavelExterna;

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

/*NOVA FORMA DE ABRIR */
typedef struct file file;

/* Rotula as linhas no arquivo*/
int contarLinhasCSV(char fileName[50]);

/* Fecha o arquivo */
void closeFile(FILE *file);

/* Menu do sistema */
int menu();

/* Recebe os dados de um novo funcionario */
void inputEmployeeData(Funcionario *funcionario);

/* Crea um novo funcionario */
void createEmployee(Funcionario *funcionarios[10], int idx);


/* Busca e retorna um ponteiro para os dados dos funcionarios */
Funcionario *buscarFuncionarios(char fileName[50]);

/* Busca e retorna dos dados do funcionario */
Funcionario buscarFuncionario(char fileName[50], int cpf);

/* Atulaiza os dados de um funcionario existente */
void updateEmployee(char fileName[10], int cpf);


/* Deleta os dados de um funcionario existente */
void deleteEmployee(char fileName[10], int cpf);

/* Ler e escreve os dados no arquivo*/
void writeFile(Funcionario *funcionarios[10], char nome[50], int idx);

/* EScreve os dados do arquivo para o array */
void writeFileArray(Funcionario funcionarios[10], char nome[50], int idx);

/* Emprime os dados dos funcionarios */
void printEmployee(Funcionario funcionario);

#endif