#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char nome[60];
    char idade[5];
    char cpf[15];
    char endereco[100];
    char salario[15];
} Funcionario;

FILE *openFIle(char nome[25], char mode[5]) {
    FILE * file;
    file = fopen(nome, mode);

    return file;
}

void closeFile(FILE *file) {
    fclose(file);
}

int menu() {
    int acao;
    
    //Nova opcao de criar arquivo adicionada
    printf("\n\t------------ Menu ------------- \n\n");
    printf("\t   [1] Criar novo arquivo\n");
    printf("\t   [2] Cadastrar Funcionario (em arquivo existente)\n");
    printf("\t   [3] Atualizar Dados\n");
    printf("\t   [4] Buscar Funcionario\n");
    printf("\t   [5] Ler\n");
    printf("\t   [6] Remover Funcionario\n");
    printf("\t   [7] Encerrar sessão\n\n");
    printf("\t------------------------------- \n\n");

	scanf ("%d", &acao);

    printf("system log: Por favor digite o indice da operação que deseja realizar: ");
    

    return acao;
}


void createEmployee(Funcionario funcionarios[3], int idx, char name[50], char age[5], char cpf[25], char address[100], char salary[15], char fileName[25]) {
	//Seguest�o de mudan�a ---
    Funcionario *funcionario = (Funcionario *)malloc(sizeof(Funcionario));
    
    FILE * myFile = openFIle(fileName, "a");
    
    if (myFile == NULL) {
    	printf ("Arquivo nao encotrado\n");
	}
	else{
		
	//Adicionado o funcion�rio em um documento
    strcpy(funcionario->nome, name);
    fputs(funcionario -> nome, myFile);
    
    strcpy(funcionario->idade, age);
    fputs(funcionario -> idade, myFile);
    
    strcpy(funcionario->cpf, cpf);
    fputs(funcionario -> cpf, myFile);
    
    strcpy(funcionario->endereco, address);
    fputs(funcionario -> endereco, myFile);
    
    strcpy(funcionario->salario, salary);
    fputs(funcionario -> salario, myFile);


    printf("Index: %d", idx);
    funcionarios[idx] = *funcionario;
		
	}
	
	fclose(myFile);
    
}

//Recebe o nome do arquivo desejado (caso esteja em pasta diferente, enviar o caminho do arquivo), imprime todo o arquivo
void readEmployee(char fileName[50]){
	
	//Vetor de strings para melhor compreencao na exibicao do arquivo
	
	char titles[5][10];
	strcpy(titles[0], "Nome: ");
	strcpy(titles[1], "Idade: ");
	strcpy(titles[2], "CPF: ");
	strcpy(titles[3], "Endereco : ");
	strcpy(titles[4], "Salario : ");

	
	FILE * file = fopen(fileName, "r");
	if (!file){
		printf ("Imposs�vel abrir arquivo");
	}
	
	char buffer[1000];
	int control = 0;
	
	//Melhoria no printf
	while (fgets(buffer, sizeof(buffer), file) != NULL) {
		
		char * token = strtok(buffer, ",");
		
		while (token != NULL) {
			printf ("%s", titles[control]);
			control++;
			printf ("%s\n", token);
			token = strtok(NULL, ",");
		}
		printf("\n\n");
		fclose(file);
	}	
}

void writeFile(Funcionario funcionarios[3] , char nome[25]) {
	
    FILE * file = openFIle(nome, "r");
	
	//Ajuste devido a minha versao do C
	int c;

    for (c = 0; c < 3; c++){
        fprintf(file, "%s, %d, %s, %s, %.2f\n",
                funcionarios[c].nome,
                funcionarios[c].idade,
                funcionarios[c].cpf,
                funcionarios[c].endereco,
                funcionarios[c].salario);
    }

    closeFile(file);
}
