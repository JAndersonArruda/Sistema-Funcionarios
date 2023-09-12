#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char nome[50];
    int idade;
    char cpf[15];
    char endereco[100];
    float salario;
} Funcionario;

FILE *openFIle(char nome[25], char mode[5]) {
    FILE *file;
    file = fopen(nome, mode);

    return file;
}

int menu() {
    int acao;
    
    printf("\n\t------------ Menu ------------ \n\n");
    printf("\t   [1] Cadastrar...\n");
    printf("\t   [2] Atualizar...\n");
    printf("\t   [3] Buscar...\n");
    printf("\t   [4] Ler...\n");
    printf("\t   [5] Remover...\n");
    printf("\t   [6] Encerrar sessão...\n\n");
    printf("\t------------------------------- \n\n");

    printf("system log: Por favor digite o indice da operação que deseja realizar: ");
    scanf("%d", &acao);

    return acao;
}

Funcionario createEmployee(char nome[50], int idade, char cpf[15], char endereco[100], float salario) {
	//Seguest�o de mudan�a ---
    Funcionario *funcionario = (Funcionario *)malloc(sizeof(Funcionario));
    funcionario->id = 1;
    strcpy(funcionario->nome, nome);
    funcionario->idade = idade;
    strcpy(funcionario->cpf, cpf);
    strcpy(funcionario->endereco, endereco);
    funcionario->salario = salario;

    return *funcionario;
}

//Recebe o nome do arquivo desejado (caso esteja em pasta diferente, enviar o caminho do arquivo)
void readEmployee(char fileName[50]){
	
	FILE* file = fopen(fileName, "r");
	if (!file){
		printf ("Imposs�vel abrir arquivo");
	}
	else{
		//String respons�vel por armazenar os valores do documento
		char buffer[1024];	
		//Enquanto o documento n�o estiver nulo
		while(fgets(buffer, 1024, file)){

			//Definindo a separa��o quando uma v�rgula for identificada
			char * value = strtok(buffer, ", ");			
			//Enquanto aquela linha n�o for nula, percorra
			while(value){
				printf("%s  ", value);
                value = strtok(NULL, ", ");
			}	
			//Qubrando entre uma linha e outra
			printf("\n");
		}
		//Encerrando execu��o do arquivo
		fclose(file);
	}	
}
