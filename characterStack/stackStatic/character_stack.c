#include "character_stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_MAXIMO 100

typedef struct pilha {
    char simbolos[TAMANHO_MAXIMO];
    int topo;
} Pilha;
