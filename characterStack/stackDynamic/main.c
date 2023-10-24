#include "character_stack.h"
#include <stdio.h>
#include <stdlib.h>

void main() {
    //char *expressao = "";
    char expressao[50];

    printf("Digite uma expressão para verificar o balanceamento: ");
    fgets(expressao, sizeof(expressao), stdin);

    int resul = estaBalanceada(expressao);
    if (resul) {
        printf("A expressão está balanceada.\n");
    } else {
        printf("A expressão não está balanceada.\n");
    }
}
