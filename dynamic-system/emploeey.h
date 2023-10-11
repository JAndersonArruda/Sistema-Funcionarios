/* TAD: Estrutura funcionrio dinamico */


/* Estrutura Funcionario */
typedef struct funcionario Funcionario;


/* Função criarFuncionario - Cria um novo funcionario */
Funcionario *createFuncionario(char name[30], int age);

/* Procedimento freeFuncionario - Apaga um funcionario */
void freeFuncionario(Funcionario *emploeey);

/* Procedimento printFuncionario - Imprime um funcionario */
void printFuncionario(char name[30]);

/* Procedimento updateNameFuncioanrio - Atulaiza o nome do funcionario */
void updateNameFuncionario(char name[30]);

/* Procedimento updateAgeFuncionario - Atualiza a idade do funcionario */
void updateAgeFuncionario(char name[30]);
