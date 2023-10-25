#include <stdio.h>
#include <stdlib.h>

#include "filaCircular.h"

int main()
{
    // menu();
    funcionario *fila = criarFilaCircular();

    for (int k = 0; k < 10; k++)
    {
        printf("%d \n", k);
        printf("Nome = %s \n", fila[k].nome);
        printf("Prioridade = %d \n\n", fila[k].prioridade);
    }

    exibir();

    return 0;
}