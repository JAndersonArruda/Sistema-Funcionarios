#include "system-actions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *openFile(char *nome, char *mode) {
    FILE *file;
    file = fopen(nome, mode);
    if (!file) {
        printf("Impossível abrir arquivo\n");
        return NULL;
    }

    return file;
}

int contarLinhasCSV(char *fileName) {
    int linhas = 0;
    char linha[1024];

    FILE* file = fopen(fileName, "r");
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
    scanf("%s", funcionario->nome);
    fflush(stdin);
    printf("Idade: ");
    scanf("%d", &funcionario->idade);
    fflush(stdin);
    printf("CPF: ");
    scanf("%d", &funcionario->cpf);
    fflush(stdin);
    printf("Endereço: ");
    scanf("%s", funcionario->endereco);
    fflush(stdin);
    printf("Salário: ");
    scanf("%f", &funcionario->salario);
    fflush(stdin);

    printf("\n%s\n%d\n%d\n%s\n%f\n", funcionario->nome, funcionario->idade, funcionario->cpf, funcionario->endereco, funcionario->salario);
}

void createEmployee(Funcionario *funcionarios[TAMANHO], int idx) {
    Funcionario *funcionario = (Funcionario *)malloc(sizeof(Funcionario));

    printf("\n---------- Cadastre-se! ----------\n");
    printf("system log: preencha os campos necessarios para o cadastro...\n");

    inputEmployeeData(funcionario);

    funcionarios[idx] = funcionario;
}

Funcionario *buscarFuncionarios(char *fileName) {
    FILE *file = openFile(fileName, "r");

    if (!file) {
        return NULL;
    }

    int numFuncionarios = contarLinhasCSV(fileName);
    
    Funcionario *funcionarios = (Funcionario*)malloc(numFuncionarios * sizeof(Funcionario));

    char linha[1024];
    char* token;
    int idx = 0;

    // Leia cada linha do arquivo
    while (fgets(linha, sizeof(linha), file) != NULL && idx < numFuncionarios) {
        Funcionario *funcionario = (Funcionario*)malloc(sizeof(Funcionario)); // Crie uma variável Funcionario para armazenar os dados

        // Use strtok para dividir a linha em tokens separados por vírgulas
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

    // Feche o arquivo
    return funcionarios;
}

Funcionario buscarFuncionario(char fileName[50], int cpf) {
    int numFuncionarios = contarLinhasCSV(fileName);
    Funcionario *funcionarios = buscarFuncionarios(fileName);
    for (int fun = 0; fun < numFuncionarios; fun++){
        if (funcionarios[fun].cpf == cpf){
            return(funcionarios[fun]);
        }
    }

    Funcionario notFound;
    notFound.cpf = -1;
    return notFound;
}

void updateEmployee(char *fileName, int cpf) {
    printf("\n---------- Atualize-se! ----------\n");
    printf("system log: preencha os campos necessarios para a atualização...\n");

    Funcionario funcionario = buscarFuncionario(fileName, cpf);
    if (funcionario.cpf != -1) {
        inputEmployeeData(&funcionario);
        
        int encontrou = 0;
        
        int numFuncionarios = contarLinhasCSV("funcionarios.csv");
        Funcionario *funcionarios = buscarFuncionarios("funcionarios.csv");
        for (int fun = 0; fun < numFuncionarios; fun++){
            if (funcionarios[fun].cpf == cpf){
                funcionarios[fun] = funcionario;
                encontrou = 1;
            }
        }

        if (encontrou) {
            writeFileArray(funcionarios, "funcionarios.csv", numFuncionarios);
            printf("Funcionário com CPF %d atualizado com sucesso!\n", cpf);
        }
    } else {
        printf("Funcionário não encontrado!\n");
    }
}

void deleteEmployee(char *fileName, int cpf) {
    int numFuncionarios = contarLinhasCSV(fileName);
    Funcionario *funcionarios = buscarFuncionarios(fileName);

    int encontrou = 0;

    FILE *file = openFile(fileName, "w");

    if (file != NULL) {
        for (int fun = 0; fun < numFuncionarios; fun++) {
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

void writeFile(Funcionario *funcionarios[TAMANHO], char *nome, int idx) {
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

void writeFileArray(Funcionario funcionarios[TAMANHO], char *nome, int idx) {
    FILE *file = openFile(nome, "w");

    for (int fun = 0; fun < idx; fun++){
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