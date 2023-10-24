typedef struct pilha Pilha;

Pilha *criarPilha();
int estaVazia(Pilha *pilha);
int estaCheia(Pilha *pilha);
void push(Pilha *pilha, char valor);
char pop(Pilha *pilha);
int estaBalanceada(char *expressao);
