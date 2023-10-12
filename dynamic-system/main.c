#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "emploeey.h"
#include "listEmploeey.h"
#include "struct-system.h"


void main () {
    int action;

    printf("-------------------- Sistema de Funcionarios --------------------");
    do {
        action = menu();

    } while (action != 7);
}