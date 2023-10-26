/* TAD: Matriz com vetor */

/* Funções exportadas */
/* Função dimensionarMatriz - Retorna o o tamanho do vetor correspondente a as dimenções da matriz */
int dimensionarMatriz(int m, int n);

/* Procedimento zerarMatriz - Preenche a matriz com o número 0 */
void zerarMatriz(int vet[], int tamanho);

/* Função indice - Retorna um indice para a matriz */
int indice(int linha, int coluna, int numColunas);

/* Função buscaElemento - Retorna um elemento de uma matriz */
int buscaElemento(int mat[], int linha, int coluna, int numColunas);

/* Procedimento adicionarElemento - Adiciona um elemento na matriz*/
void adicionarElemento(int vet[], int numColunas, int valor, int linha, int coluna);

/* Procedimento printarMatriz - Imprime uma matriz */
void printarMatriz(int vet[], int linhas, int colunas);

/* Procedimento preencher - Preenche uma matriz com valores aleatorios */
void preencher(int mat[], int linhas, int colunas);

/* Procedimento produtoMatriz - Calcula o produto de duas matrizes e amrmazena em uma matriz resposta */
void produtoMatriz(int mat1[], int mat2[], int numLinhasMat1, int numColunasMat1, int numLinhasMat2, int numColunasMat2, int matrizResposta[]);

/* Procedimento printarTransposta - Imprime a matriz transposta */
void printarTransposta(int mat[], int linhas, int colunas);

/* Procedimento somarMatrizes - Soma duas matrizes e imprime a soma */
void somarMatrizes (int mat1[], int mat2[], int linhas, int colunas, int matrizSoma[]);

/* Função ehIdentidade - Retorna 1, se a matriz B é identidade da matriz A, ou 0, se a matriz B não for identidade da matriz A */
int ehIdentidade(int mat[], int linhas, int colunas);

/* Função ehInversa - Retorna 1, se a matriz B for inversa da matriz A, ou 0, se a matriz B não for a inversa da matriz A */
int ehInversa (int mat1[], int mat2[], int numLinhasMat1, int numColunasMat1, int numLinhasMat2, int numColunasMat2);