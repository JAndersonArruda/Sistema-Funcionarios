#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "systemActions.h"

/*VARIÁVEL EXTERNA TEM QUE SER DECLARADA NO .C QUE SERÁ UTILIZADA*/
int TAMANHO = 10;

int fun; 

/*Não é possível declara o FILE diretamente no arquivo .h, então criei a seguinte solção:
------------*/


/*O ponteiro meuArquivo substitui o arquivo direto, E RETORNA O MESMO, UM PONTEIRO PARA FILE*/
FILE *openFile(char nome[50], char mode[5]) {
    file *file;
    file->meuArquivo = fopen(nome, mode);
    if (!file) {
        printf("Impossível abrir arquivo\n");
        return NULL;
    }

    return file->meuArquivo;
}

int contarLinhasCSV(char fileName[50]) {
    int linhas = 0;
    char linha[1024];

    FILE *file = openFile(fileName, "r");
	if (!file){
		return 0;
	}
    
    while (fgets(linha, sizeof(linha), file) != NULL) {
        linhas++;
    }

    fclose(file);
    return linhas;
}

void closeFile(FILE *file) {
    fclose(file);
}

int menu() {
    int acao;
    
    printf("\n\t------------ Menu ------------- \n\n");
    printf("\t   [1] Cadastrar Funcionario\n");
    printf("\t   [2] Atualizar Dados\n");
    printf("\t   [3] Buscar Funcionario\n");
    printf("\t   [4] Ler\n");
    printf("\t   [5] Remover Funcionario\n");
    printf("\t   [6] Encerrar sessão\n\n");
    printf("\t------------------------------- \n\n");

    printf("system log: Por favor digite o indice da operação que deseja realizar: ");
    scanf("%d", &acao);

    return acao;
}

void inputEmployeeData(Funcionario *funcionario) {
    fflush(stdin);
    printf("Nome: ");
    scanf("%s", &funcionario->nome);
    fflush(stdin);
    printf("Idade: ");
    scanf("%d", &funcionario->idade);
    fflush(stdin);
    printf("CPF: ");
    scanf("%d", &funcionario->cpf);
    fflush(stdin);
    printf("Endereço: ");
    scanf("%s", &funcionario->endereco);
    fflush(stdin);
    printf("Salário: ");
    scanf("%f", &funcionario->salario);
    fflush(stdin);
}

void createEmployee(Funcionario *funcionarios[TAMANHO], int idx) {
    Funcionario *funcionario = (Funcionario *)malloc(sizeof(Funcionario));

    printf("\n---------- Cadastre-se! ----------\n");
    printf("system log: preencha os campos necessarios para o cadastro...\n");

    inputEmployeeData(funcionario);

    funcionarios[idx] = funcionario;
}

Funcionario *buscarFuncionarios(char fileName[50]) {
    FILE *file = openFile(fileName, "r");

    if (!file) {
        return NULL;
    }

    int numFuncionarios = contarLinhasCSV(fileName);
    
    Funcionario *funcionarios = (Funcionario*)malloc(numFuncionarios * sizeof(Funcionario));

    char linha[1024];
    char* token;
    int idx = 0;


    while (fgets(linha, sizeof(linha), file) != NULL && idx < numFuncionarios) {
        Funcionario *funcionario = (Funcionario*)malloc(sizeof(Funcionario)); 
       
        token = strtok(linha, ",");
        int campo = 0;

        while (token != NULL && campo < 5) {
            switch (campo) {
                case 0:
                    strncpy(funcionario->nome, token, sizeof(funcionario->nome));
                    break;
                case 1:
                    funcionario->idade = atoi(token);
                    break;
                case 2:
                    funcionario->cpf = atoi(token);
                    break;
                case 3:
                    strncpy(funcionario->endereco, token, sizeof(funcionario->endereco));
                    break;
                case 4:
                    funcionario->salario = atof(token);
                    break;
            }

            token = strtok(NULL, ",");
            campo++;
        }
        funcionarios[idx] = *funcionario;
        idx++;
    }

    
    return funcionarios;
}

Funcionario buscarFuncionario(char fileName[50], int cpf) {
    int numFuncionarios = contarLinhasCSV(fileName);
    Funcionario *funcionarios = buscarFuncionarios(fileName);
    for (fun = 0; fun < numFuncionarios; fun++){
        if (funcionarios[fun].cpf == cpf){
            return(funcionarios[fun]);
        }
    }

}

void updateEmployee(char fileName[50], int cpf) {
    printf("\n---------- Atualize-se! ----------\n");
    printf("system log: preencha os campos necessarios para a atualização...\n");

    Funcionario funcionario = buscarFuncionario(fileName, cpf);
    inputEmployeeData(&funcionario);
    
    int encontrou = 0;
    
    int numFuncionarios = contarLinhasCSV("funcionarios.csv");
    Funcionario *funcionarios = buscarFuncionarios("funcionarios.csv");
    for (fun = 0; fun < numFuncionarios; fun++){
        if (funcionarios[fun].cpf == cpf){
            funcionarios[fun] = funcionario;
            encontrou = 1;
        }
    }

    if (encontrou) {
        writeFileArray(funcionarios, "funcionarios.csv", numFuncionarios);
        printf("Funcionário com CPF %d atualizado com sucesso!\n", cpf);
    } else {
        printf("Funcionário não encontrado!\n");
    }
}

void deleteEmployee(char fileName[50], int cpf) {
    int numFuncionarios = contarLinhasCSV(fileName);
    Funcionario *funcionarios = buscarFuncionarios(fileName);

    int encontrou = 0;

    FILE *file = openFile(fileName, "w");

    if (file != NULL) {
        for (fun = 0; fun < numFuncionarios; fun++) {
            if (funcionarios[fun].cpf == cpf) {
                encontrou = 1; 
            } else {
                fprintf(file, "%s, %d, %d, %s, %.2f\n",
                        funcionarios[fun].nome,
                        funcionarios[fun].idade,
                        funcionarios[fun].cpf,
                        funcionarios[fun].endereco,
                        funcionarios[fun].salario);
            }
        }

        if (encontrou) {
            printf("Funcionário com CPF %d removido com sucesso!\n", cpf);
        } else {
            printf("Funcionário não encontrado!\n");
        }

        closeFile(file);
    } else {
        printf("Erro ao abrir o arquivo para remoção.\n");
    }
}

void writeFile(Funcionario *funcionarios[TAMANHO], char nome[50], int idx) {
    printf("%d", idx);
    FILE *file = openFile(nome, "a");

    fprintf(file, "%s, %d, %d, %s, %.2f\n",
            funcionarios[idx]->nome,
            funcionarios[idx]->idade,
            funcionarios[idx]->cpf,
            funcionarios[idx]->endereco,
            funcionarios[idx]->salario);

    closeFile(file);
}

void writeFileArray(Funcionario funcionarios[TAMANHO], char nome[50], int idx) {
    FILE *file = openFile(nome, "w");

    for (fun = 0; fun < idx; fun++){
        fprintf(file, "%s, %d, %d, %s, %.2f\n",
            funcionarios[fun].nome,
            funcionarios[fun].idade,
            funcionarios[fun].cpf,
            funcionarios[fun].endereco,
            funcionarios[fun].salario);
    }

    closeFile(file);
}

void printEmployee(Funcionario funcionario) {
    printf("======================================\n");
    printf("Nome: %s\n", funcionario.nome);
    printf("Idade: %d\n", funcionario.idade);
    printf("CPF: %d\n", funcionario.cpf);
    printf("Endereço: %s\n", funcionario.endereco);
    printf("Salário: %.2f\n", funcionario.salario);
}
