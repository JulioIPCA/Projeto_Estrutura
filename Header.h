/*****************************************************************//**
 * \file   Header.h
 * \brief  Ficheiro de cabe�alho do programa - Cont�m as estruturas usadas no programa
 * 
 * 
 * \author J�lio Faria
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
 * @brief Estrutura para representar a lista ligada e as respetivas dimens�es.
 *
 * @var ED::head
 * Ponteiro para a primeira casa da lista ligada.
 * @var ED::linhas
 * N�mero de linhas na matriz.
 * @var ED::colunas
 * N�mero de colunas na matriz.    
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
 * Esta fun��o inicializa a estrutura de dados, definindo o ponteiro para a primeira casa como NULL e o n�mero de linhas e colunas como 0.
 */
int inicializar(ED* ed);

/**
 * @brief Adiciona um elemento na estrutura de dados.
 *
 * @param ed Ponteiro para a estrutura de dados.
 * @param armaz Valor a ser armazenado na casa.
 *
 * Esta fun��o guarda mem�ria para uma nova casa, define o valor armaz e o ponteiro para a pr�xima casa como NULL.
 * Em seguida, verifica se a lista est� vazia e adiciona uma nova casa ao final da lista.
 */
int adicionar(ED* ed, int armaz);

/**
 * @brief L� a matriz do arquivo.
 *
 * @param filename Nome do arquivo.
 * @param ed Ponteiro para a estrutura de dados.
 *
 * Esta fun��o abre o arquivo no modo leitura e l� os valores inteiros, adicionando-os na estrutura de dados.
 * A fun��o tamb�m verifica se o n�mero de colunas � consistente em todas as linhas.
 */
int lerMatriz(char* filename, ED* ed);

/**
* @brief Imprime a matriz.
*
* @param ed Ponteiro para a estrutura de dados.
*
* Esta fun��o percorre a lista ligada e imprime os valores das casas, formatando a sa�da para que a matriz seja exibida corretamente.
*/
int imprimirMatriz(ED* ed);

/**
 * @brief Modifica o valor de um elemento na matriz.
 *
 * @param ed Ponteiro para a estrutura de dados.
 * @param linha �ndice da linha do elemento a ser modificado.
 * @param coluna �ndice da coluna do elemento a ser modificado.
 * @param novoValor Novo valor a ser atribu�do ao elemento.
 *
 * Esta fun��oo modifica o valor de um elemento na matriz representada pela estrutura de dados.
 * Verifica se os �ndices de linha e coluna s�o v�lidos e, em seguida, percorre a lista ligada at� encontrar o elemento desejado.
 * Se o elemento for encontrado, o valor � atualizado com o novoValor. Caso contr�rio, uma mensagem de erro � exibida.
 */
int modificarValor(ED* ed, int linha, int coluna, int novoValor);

/**
 * @brief Atualiza o arquivo com a matriz modificada.
 *
 * @param filename Nome do arquivo.
 * @param ed Ponteiro para a estrutura de dados.
 *
 * Esta fun��o abre o arquivo no modo escrita e atualiza o conte�do do arquivo com a matriz modificada representada pela estrutura de dados.
 * A fun��o percorre a lista ligada e escreve os valores das respetivas casas no arquivo, formatando a sa�da para que a matriz seja armazenada corretamente.
 * Cada valor � separado por ponto e v�rgula e cada linha � finalizada com um paragrafo.
 */
int atualizarArquivo(char* filename, ED* ed);

/**
 * @brief Adiciona uma nova linha � matriz.
 *
 * @param ed Ponteiro para a estrutura de dados.
 * @param posicao Posi��o da nova linha a ser adicionada.
 *
 * Esta fun��o adiciona uma nova linha � matriz representada pela estrutura de dados. Verifica se a posi��o � v�lida e, em seguida,
 *  calcula o �ndice do primeiro elemento da nova linha. Em seguida, percorre a lista ligada at� � posi��o desejada e adiciona as novas casas na posi��o correta.
 * Cada nova casa tem o valor inicializado como 0. O n�mero de linhas � incrementado ap�s a adi��o da nova linha.
 */
int adicionarLinha(ED* ed, int posicao);

/**
 * @brief Adiciona uma nova coluna � matriz.
 *
 * @param ed Ponteiro para a estrutura de dados.
 * @param posicao Posi��o da nova coluna a ser adicionada.
 *
 * Esta fun��o adiciona uma nova coluna � matriz representada pela estrutura de dados. Ela verifica se a posi��o � v�lida e, em seguida,
 * calcula o �ndice do primeiro elemento da nova coluna. Em seguida, percorre a lista ligada at� � posi��o desejada e adiciona as novas casas na posi��o correta.
 * Cada nova casa tem o valor inicializado como 0. O n�mero de colunas � incrementado ap�s a adi��o da nova coluna.
 */
int adicionarColuna(ED* ed, int posicao);

/**
 * @brief Elimina uma linha da matriz.
 *
 * @param ed Ponteiro para a estrutura de dados.
 * @param posicao Posi��o da linha a ser eliminada.
 *
 * Esta fun��o elimina uma linha da matriz representada pela estrutura de dados.
 * Verifica se a posi��o � v�lida e, em seguida, calcula o �ndice do primeiro elemento da linha a ser eliminada.
 * Em seguida, percorre a lista ligada at� � posi��o desejada e remove as casas da respetiva linha.
 * O n�mero de linhas � decrementado ap� a remo��o da linha.
 */
int eliminarLinha(ED* ed, int posicao);

/**
 * @brief Elimina uma coluna da matriz.
 *
 * @param ed Ponteiro para a estrutura de dados.
 * @param posicao Posi��o da coluna a ser eliminada.
 *
 * Esta fun��o elimina uma coluna da matriz representada pela estrutura de dados. Ela verifica se a posi��o � v�lida e, em seguida, calcula o
 *  �ndice do primeiro elemento da coluna a ser eliminada. Em seguida, percorre a lista ligada at� a posi��o desejada e remove as casas da coluna.
 * O n�mero de colunas � decrementado ap�s a remo��o da coluna.
 */
int eliminarColuna(ED* ed, int posicao);

/**
 * @brief Calcula a soma m�xima poss�vel dos inteiros selecionados na matriz.
 *
 * @param ed Ponteiro para a estrutura de dados.
 * @return A soma m�xima poss�vel dos inteiros selecionados.
 *
 * Esta fun��o calcula a soma m�xima poss�vel dos inteiros selecionados na matriz representada pela estrutura de dados.
 * Converte a lista ligada numa matriz bidimensional e encontra o valor m�ximo na matriz.
 * Em seguida, converte a matriz numa matriz de custo, onde cada valor � a diferen�a entre o valor m�ximo e o valor original.
 * A fun��o utiliza o algoritmo de atribui�ao de custo m�nimo(algoritmo Hungaro) para encontrar a combina��o de inteiros que maximiza a soma.
 * Por fim, retorna a soma m�xima poss�vel dos inteiros selecionados.
 */

int calcularSomaMaxima(ED* ed);

