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

void createEmployee(Funcionario funcionarios[3], int idx, char name[50], int age, char cpf[15], char address[100], float salary) {
	//Seguest�o de mudan�a ---
    Funcionario *funcionario = (Funcionario *)malloc(sizeof(Funcionario));

    strcpy(funcionario->nome, name);
    funcionario->idade = age;
    strcpy(funcionario->cpf, cpf);
    strcpy(funcionario->endereco, address);
    funcionario->salario = salary;

    printf("Index: %d", idx);
    funcionarios[idx] = *funcionario;
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

void writeFile(Funcionario funcionarios[3] , char nome[25]) {
    FILE *file = openFIle(nome, "w");

    for (int c = 0; c < 3; c++){
        fprintf(file, "%s, %d, %s, %s, %.2f\n",
                funcionarios[c].nome,
                funcionarios[c].idade,
                funcionarios[c].cpf,
                funcionarios[c].endereco,
                funcionarios[c].salario);
    }

    closeFile(file);
}