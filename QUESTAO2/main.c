#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "struct-matrix-vector.h"


void main() {
	
	srand(time(NULL));
	

	// TESTE QUEST�O 01 =====
	int mat1[6],  mat2[6], matProduto[9];
	
	preencher(mat1, 3, 2);
	
	preencher(mat2, 2, 3);
	 
	printarMatriz(mat1, 3, 2);
	printf ("\n");
	printarMatriz(mat2, 2, 3);
	printf ("\n");
	
	produtoMatriz(mat1, mat2, 3, 2, 2, 3, matProduto);
	
	printf("\n PRODUTO\n");
	printarMatriz(matProduto, 3, 3);
	printf ("\n");
	
	
	// TESTE QUEST�O 02 =====
	//Para que a soma exista, as matrizes devem ter a mesma dimens�o, se preferirem, podem adicionar um teste de condi��o
	
	int mat3[9], mat4[9], matSoma[9];
	
	preencher(mat3, 3, 3);
	preencher(mat4, 3, 3);
	
	printf ("SOMA\n\n");
	printarMatriz(mat3, 3, 3);
	printf("\n");
	printarMatriz(mat4, 3, 3);
	printf("\n");
	somarMatrizes(mat3, mat4, 3, 3, matSoma); //O prcedimento ja printa;
	printf ("\n\n");
	
	// TESTE QUEST�O 03 =====
	
	//A matriz deve ser quadrada, se preferirem, podem adicionar um teste de condi��o
	int mat5[9];
	
	//Mat, n� de colunas, valor, linhas e coluna
	//PODEM ALTERAR OS VALORES, JA FOI TESTADO E ELA FUNCIONA
	
	adicionarElemento(mat5, 3, 1, 1, 1);
	adicionarElemento(mat5, 3, 0, 1, 2);
	adicionarElemento(mat5, 3, 0, 1, 3);
	adicionarElemento(mat5, 3, 0, 2, 1);
	adicionarElemento(mat5, 3, 1, 2, 2);
	adicionarElemento(mat5, 3, 0, 2, 3);
	adicionarElemento(mat5, 3, 0, 3, 1);
	adicionarElemento(mat5, 3, 0, 3, 2);
	adicionarElemento(mat5, 3, 1, 3, 3);
	
	printf ("\nMATRIZ IDENTIDADE \n\n");
	printarMatriz(mat5, 3, 3);
	
	if (ehIdentidade(mat5, 3, 3)){
		printf ("E identidade");
	}
	else{
		printf ("Nao eh identidade");
	}

	printf("\n\n\n");
	
	//TESTE QUEST�O 04 =====
	
	// ao multiplicar a matriz A por B, se B for inversa de A, = a uma matriz identidade
	printf ("\nMATRIZ INVERSA \n\n");

	int mat6[6], mat7[6];

	preencher(mat6, 3, 2);
	preencher(mat7, 2, 3);


	printarMatriz(mat6, 3, 2);
	printf("\n");
	printarMatriz(mat7, 2, 3);
	printf("\n");

	if (ehInversa(mat6, mat7, 3, 2, 2, 3) == 1) {
		printf("A matriz B é a inversa de A \n");
	}
	else {
		printf("A matriz B não é a inversa de A \n");
	} 
    
    /*
	// matriz invera real
	int mat8[6], mat9[6];

	adicionarElemento(mat8, 2, 1, 1, 1);
	adicionarElemento(mat8, 2, 0, 1, 2);
	adicionarElemento(mat8, 2, 0, 2, 1);
	adicionarElemento(mat8, 2, 1, 2, 2);
	adicionarElemento(mat8, 2, 0, 3, 1);
	adicionarElemento(mat8, 2, 0, 3, 2);

	adicionarElemento(mat9, 3, 1, 1, 1);
	adicionarElemento(mat9, 3, 0, 1, 2);
	adicionarElemento(mat9, 3, 0, 1, 3);
	adicionarElemento(mat9, 3, 0, 2, 1);
	adicionarElemento(mat9, 3, 1, 2, 2);
	adicionarElemento(mat9, 3, 0, 2, 3);

	printarMatriz(mat6, 3, 2);
	printf("\n");
	printarMatriz(mat7, 2, 3);
	printf("\n");

	if (ehInversa(mat6, mat7, 3, 2, 2, 3) == 1) {
		printf("A matriz B é a inversa de A");
	}
	else {
		printf("A matriz B não é a inversa de A");
	} 
    */
	
}
