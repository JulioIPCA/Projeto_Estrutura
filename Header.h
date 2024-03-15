/*****************************************************************//**
 * \file   Header.h
 * \brief  Ficheiro de cabeçalho do programa - Contém as estruturas usadas no programa
 * 
 * 
 * \author Júlio Faria
 * \date   March 2024
 *********************************************************************/


/**
 * @struct Node
 * @brief Estrutura para representar uma casa da lista ligada.
 *
 * @var Node::armaz
 * Armazena um valor inteiro.
 * @var Node::linha
 * Armazena a linha da casa na matriz.
 * @var Node::prox
 * Ponteiro para a proxima casa da lista.
 */
typedef struct Node {
    int armaz;
    int linha;
    struct Node* prox;
} Node;

/**
 * @struct ED
 * @brief Estrutura para representar a lista ligada e as respetivas dimensões.
 *
 * @var ED::head
 * Ponteiro para a primeira casa da lista ligada.
 * @var ED::linhas
 * Número de linhas na matriz.
 * @var ED::colunas
 * Número de colunas na matriz.    
 * 
 */
typedef struct {
    Node* head;
    int linhas;
    int colunas;
} ED;

/**
 * @brief Inicializa a estrutura de dados.
 *
 * @param ed Ponteiro para a estrutura de dados.
 *
 * Esta função inicializa a estrutura de dados, definindo o ponteiro para a primeira casa como NULL e o número de linhas e colunas como 0.
 */
int inicializar(ED* ed);

/**
 * @brief Adiciona um elemento na estrutura de dados.
 *
 * @param ed Ponteiro para a estrutura de dados.
 * @param armaz Valor a ser armazenado na casa.
 *
 * Esta função guarda memória para uma nova casa, define o valor armaz e o ponteiro para a próxima casa como NULL.
 * Em seguida, verifica se a lista está vazia e adiciona uma nova casa ao final da lista.
 */
int adicionar(ED* ed, int armaz);

/**
 * @brief Lê a matriz do arquivo.
 *
 * @param filename Nome do arquivo.
 * @param ed Ponteiro para a estrutura de dados.
 *
 * Esta função abre o arquivo no modo leitura e lê os valores inteiros, adicionando-os na estrutura de dados.
 * A função também verifica se o número de colunas é consistente em todas as linhas.
 */
int lerMatriz(char* filename, ED* ed);

/**
* @brief Imprime a matriz.
*
* @param ed Ponteiro para a estrutura de dados.
*
* Esta função percorre a lista ligada e imprime os valores das casas, formatando a saída para que a matriz seja exibida corretamente.
*/
int imprimirMatriz(ED* ed);

/**
 * @brief Modifica o valor de um elemento na matriz.
 *
 * @param ed Ponteiro para a estrutura de dados.
 * @param linha índice da linha do elemento a ser modificado.
 * @param coluna índice da coluna do elemento a ser modificado.
 * @param novoValor Novo valor a ser atribuído ao elemento.
 *
 * Esta funçãoo modifica o valor de um elemento na matriz representada pela estrutura de dados.
 * Verifica se os índices de linha e coluna são válidos e, em seguida, percorre a lista ligada até encontrar o elemento desejado.
 * Se o elemento for encontrado, o valor é atualizado com o novoValor. Caso contrário, uma mensagem de erro é exibida.
 */
int modificarValor(ED* ed, int linha, int coluna, int novoValor);

/**
 * @brief Atualiza o arquivo com a matriz modificada.
 *
 * @param filename Nome do arquivo.
 * @param ed Ponteiro para a estrutura de dados.
 *
 * Esta função abre o arquivo no modo escrita e atualiza o conteúdo do arquivo com a matriz modificada representada pela estrutura de dados.
 * A função percorre a lista ligada e escreve os valores das respetivas casas no arquivo, formatando a saída para que a matriz seja armazenada corretamente.
 * Cada valor é separado por ponto e vírgula e cada linha é finalizada com um paragrafo.
 */
int atualizarArquivo(char* filename, ED* ed);

/**
 * @brief Adiciona uma nova linha à matriz.
 *
 * @param ed Ponteiro para a estrutura de dados.
 * @param posicao Posição da nova linha a ser adicionada.
 *
 * Esta função adiciona uma nova linha à matriz representada pela estrutura de dados. Verifica se a posição é válida e, em seguida,
 *  calcula o índice do primeiro elemento da nova linha. Em seguida, percorre a lista ligada até à posição desejada e adiciona as novas casas na posição correta.
 * Cada nova casa tem o valor inicializado como 0. O número de linhas é incrementado após a adição da nova linha.
 */
int adicionarLinha(ED* ed, int posicao);

/**
 * @brief Adiciona uma nova coluna à matriz.
 *
 * @param ed Ponteiro para a estrutura de dados.
 * @param posicao Posição da nova coluna a ser adicionada.
 *
 * Esta função adiciona uma nova coluna à matriz representada pela estrutura de dados. Ela verifica se a posição é válida e, em seguida,
 * calcula o índice do primeiro elemento da nova coluna. Em seguida, percorre a lista ligada até à posição desejada e adiciona as novas casas na posição correta.
 * Cada nova casa tem o valor inicializado como 0. O número de colunas é incrementado após a adição da nova coluna.
 */
int adicionarColuna(ED* ed, int posicao);

/**
 * @brief Elimina uma linha da matriz.
 *
 * @param ed Ponteiro para a estrutura de dados.
 * @param posicao Posição da linha a ser eliminada.
 *
 * Esta função elimina uma linha da matriz representada pela estrutura de dados.
 * Verifica se a posição é válida e, em seguida, calcula o índice do primeiro elemento da linha a ser eliminada.
 * Em seguida, percorre a lista ligada até à posição desejada e remove as casas da respetiva linha.
 * O número de linhas é decrementado apó a remoção da linha.
 */
int eliminarLinha(ED* ed, int posicao);

/**
 * @brief Elimina uma coluna da matriz.
 *
 * @param ed Ponteiro para a estrutura de dados.
 * @param posicao Posição da coluna a ser eliminada.
 *
 * Esta função elimina uma coluna da matriz representada pela estrutura de dados. Ela verifica se a posição é válida e, em seguida, calcula o
 *  índice do primeiro elemento da coluna a ser eliminada. Em seguida, percorre a lista ligada até a posição desejada e remove as casas da coluna.
 * O número de colunas é decrementado após a remoção da coluna.
 */
int eliminarColuna(ED* ed, int posicao);

/**
 * @brief Calcula a soma máxima possível dos inteiros selecionados na matriz.
 *
 * @param ed Ponteiro para a estrutura de dados.
 * @return A soma máxima possível dos inteiros selecionados.
 *
 * Esta função calcula a soma máxima possível dos inteiros selecionados na matriz representada pela estrutura de dados.
 * Converte a lista ligada numa matriz bidimensional e encontra o valor máximo na matriz.
 * Em seguida, converte a matriz numa matriz de custo, onde cada valor é a diferença entre o valor máximo e o valor original.
 * A função utiliza o algoritmo de atribuiçao de custo mínimo(algoritmo Hungaro) para encontrar a combinação de inteiros que maximiza a soma.
 * Por fim, retorna a soma máxima possível dos inteiros selecionados.
 */

int calcularSomaMaxima(ED* ed);

