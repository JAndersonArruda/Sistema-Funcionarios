#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "struct-matrix-vector.h"


int dimensionarMatriz(int m, int n) {
	int tamanho = m * n;
	return tamanho;
}

void zerarMatriz(int vet[], int tamanho) {
	int k;
	for (k = 0; k < tamanho; k++){
		vet[k] = 0;
	}
}

int indice(int linha, int coluna, int numColunas) {
	int k = (linha - 1) * numColunas + (coluna - 1);
	return k;
}

int buscaElemento(int mat[], int linha, int coluna, int numColunas) {
	int aux = mat[indice(linha, coluna, numColunas)];
}

void adicionarElemento(int vet[], int numColunas, int valor, int linha, int coluna) {
	int k = (linha - 1) * numColunas + (coluna - 1);
	vet[k] = valor;
}

void printarMatriz(int vet[], int linhas, int colunas) {
	int i, j;
	for (i = 0; i < linhas; i++){
		for (j = 0; j < colunas; j++){
			printf("%d  ", vet[i*colunas + j]);
		}
		printf ("\n");
	}
}

void preencher(int mat[], int linhas, int colunas) {
	int i, j;
	for (i = 0; i < linhas; i++){
		for (j = 0; j< colunas; j++){
			mat[indice(i+1, j+1, colunas)] = rand() % (0 - 4);
		}
	} 
}

void produtoMatriz(int mat1[], int mat2[], int numLinhasMat1, int numColunasMat1, int numLinhasMat2, int numColunasMat2, int matrizResposta[]) {
	if (numLinhasMat1 == numColunasMat2) {
		int i, j, x, mult = 0;
		for (i = 0; i < numLinhasMat1; i ++) {
			for (j = 0; j < numColunasMat2; j++) {
				for (x = 0; x < numColunasMat1; x++) {
					mult += mat1[indice(i +1, x +1, numColunasMat1)] * mat2[indice(x +1, j +1, numColunasMat2)];
				}
				matrizResposta[indice(i +1, j +1, numColunasMat2)] = mult;
				mult = 0;
			}
		}
	}
	else {
		printf("As matrizes são incompativeis");
	}

}

void printarTransposta(int mat[], int linhas, int colunas) {
	int i, j;
	for (i = 0; i < linhas; i++){
		for (j = 0; j < colunas; j++){
			printf ("%d  ", mat[indice(j+1, i+1, colunas)]);
		}
			printf("\n");
	}
}

void somarMatrizes (int mat1[], int mat2[], int linhas, int colunas, int matrizSoma[]) {	
	int i, j;
	for (i = 0; i < linhas; i++) {
		for (j = 0; j < colunas; j++) {
			matrizSoma[indice(i+1, j+1, colunas)] = mat1[indice(i+1, j+1, colunas)] + mat2[indice(i+1, j+1, colunas)];
			
		}
	}
	printf ("ANTES\n");
	printarMatriz(matrizSoma, linhas, colunas);
	printf ("DEPOIS\n");
	printarTransposta(matrizSoma, linhas, colunas);
}

int ehIdentidade(int mat[], int linhas, int colunas) {
	if (linhas == colunas) {
		int i, j;
		for (i = 0; i < linhas; i++) {
			for (j = 0; j < colunas; j++) {
				if (i == j){
					if (mat[indice(i+1, j+1, colunas)] == 1){
						continue;
					}
					else{
						return 0;
					}
				}
				else if (mat[indice(i+1, j+1, colunas)] == 0){
					continue;
				}
				else{
					return 0;
				}
			}
		}
		return 1;
	}
	else {
		return 0;
	}
}

int ehInversa (int mat1[], int mat2[], int numLinhasMat1, int numColunasMat1, int numLinhasMat2, int numColunasMat2) {
	
	int matResultante[dimensionarMatriz(numLinhasMat1, numColunasMat2)];
	
	produtoMatriz(mat1, mat2, numLinhasMat1, numColunasMat1, numLinhasMat2, numColunasMat2, matResultante);
	printarMatriz(matResultante, numLinhasMat1, numColunasMat2);
	printf("\n");

	if (ehIdentidade(matResultante, numLinhasMat1, numColunasMat2) == 1) {
		return 1;
	}
	return 0;
}
