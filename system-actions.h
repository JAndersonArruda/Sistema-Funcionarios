#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    int id;
    char nome[50];
    int idade;
    char cpf[15];
    char endereco[100];
    float salario;
} Funcionario;


int menu() {
    int acao;
    
    printf("\n\t------------ Menu ------------- \n\n");
    printf("\t   [1] Cadastrar...\n");
    printf("\t   [2] Atualizar...\n");
    printf("\t   [3] Buscar...\n");
    printf("\t   [4] Ler...\n");
    printf("\t   [5] Remover...\n");
    printf("\t   [6] Encerrar sessÃ£o...\n\n");
    printf("\t------------------------------- \n\n");

    printf("system log: Por favor digite o indice da operaÃ§Ã£o que deseja realizar: ");
    scanf("%d", &acao);

    return acao;
}

Funcionario createEmployee(char nome[50], int idade, char cpf[15], char endereco[100], float salario) {
	//Seguestão de mudança ---
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
		printf ("Impossível abrir arquivo");
	}
	else{
		
		//String responsável por armazenar os valores do documento
		char buffer[1024];	
		
		//Enquanto o documento não estiver nulo
		while(fgets(buffer, 1024, file)){
			
			//Definindo a separação quando uma vírgula for identificads
			char * value = strtok(buffer, ", ");			
			//Enquanto aquela linha não for nula, percorra
			while(value){
				printf("%s  ", value);
                value = strtok(NULL, ", ");
			}	
			//Qubrando entre uma linha e outra
			printf("\n");
		}
		//Encerrando execução do arquivo
		fclose(file);
	}	
}
