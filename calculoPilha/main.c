#include <stdio.h>
#include <string.h>

#include "estruturaPilha.h"

int main()
{
    Pilha *pilha = criarPilha();

    char expressao[50];
    gets(expressao);

    int Deus = calcularExpressao(expressao, pilha);
    printf ("%d", Deus);

    return 0;
}