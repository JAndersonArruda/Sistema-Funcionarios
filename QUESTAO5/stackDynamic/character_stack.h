typedef struct nodo Nodo;
typedef struct pilha Pilha;

Pilha *criarPilha();
int estaVazia(Pilha *pilha);
void push(Pilha *pilha, char valor);
int pop(Pilha *pilha);
void liberarPilha(Pilha *pilha);
int estaBalanceada(char *expressao);
