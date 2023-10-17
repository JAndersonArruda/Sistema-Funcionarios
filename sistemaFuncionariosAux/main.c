#include <stdio.h>

#include "listaFuncionarios.h"
#include "funcionario.h"

int main()
{
    Lista * lista = criarLista();

    menu(lista);

    printf ("\nATENCAO! um arquivo de texto foi criado chamado listaFun.txt, certifique-se de salva-lo antes de executar o programa novmente\n");

    return 0;
}


//exit (num);