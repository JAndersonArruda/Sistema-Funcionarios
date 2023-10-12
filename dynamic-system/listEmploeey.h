/* TAD: Estrutura lista de funcionarios dinamico */


/* Estrutura Nodo - Armazena os dados do funcionario */
typedef struct nodo Nodo;

/* Estrutura Lista de Funcionarios */
typedef struct lista Lista;


/* Função criarLista - criar uma lista de funcionarios vazia */
Lista *criarLista();

/* Procedimento addFuncionario - Adiciona um funcionario a lista de forma ordenada crescente por nome */
void addFuncionario(Lista *list, char name[30], int age);

/* Função voidLista - Retorna 0, para lsita vazia, ou 1, para lista não vazia */
int voidLista(Lista *list);

/* Função freeLista - Apaga a lista */
void freeLista(Lista *list);

/* Procedimento printLista - Imprime a lista de funcionario */
void printLista(Lista *list);

/* Procedimento fetchFuncionario - Busca e impreme o funcionario */
void fecthFuncionario(Lista *list, char name[30]);

/* Procedimento updataFuncionario - atualiza os dados do funcionario */
void updateFuncionario(Lista *list, char name[30]);

