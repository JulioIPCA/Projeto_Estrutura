/*****************************************************************//**
 * \file   Source.c
 * \brief  Ficheiro com as funções do programa
 * 
 * \author Júlio Faria
 * \date   March 2024
 *********************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Header.h" 


 /**
 * @brief Inicializa a estrutura de dados.
 *
 * @param ed Apontador para a estrutura de dados.
 *
 * Esta função inicializa a estrutura de dados, definindo o apontador para a primeira casa como NULL e o número de linhas e colunas como 0.
 */
int inicializar(ED* ed) {
    ed->head = NULL;
    ed->linhas = 0;
    ed->colunas = 0;
    
    return 0;
}

/**
 * @brief Adiciona um elemento na estrutura de dados.
 *
 * @param ed Apontador para a estrutura de dados.
 * @param armaz Valor a ser armazenado na casa.
 *
 * Esta função guarda memória para uma nova casa, define o valor armaz e o apontador para a próxima casa como NULL.
 * Em seguida, verifica se a lista está vazia e adiciona uma nova casa ao final da lista.
 */
int adicionar(ED* ed, int armaz) {
    Node* novo = (Node*)malloc(sizeof(Node));
    if (novo == NULL) {
        return 101;
    }
    novo->armaz = armaz; // Define o valor armazenado na nova casa 
    novo->prox = NULL; // A nova casa será a última da lista 

    // Verifica se a lista está vazia
    if (ed->head == NULL) {
        ed->head = novo;    // Se a lista está vazia, a nova casa é a primeira da lista
    }
    else {
        // Encontra a ultima casa na lista
        Node* ultimo = ed->head;
        while (ultimo->prox != NULL) {
            ultimo = ultimo->prox; // Move para a próxima casa
        }
        // Adiciona uma nova casa no final da lista
        ultimo->prox = novo;
    }
    return 0;
}


/**
 * @brief Lê a matriz do arquivo.
 *
 * @param filename Nome do arquivo.
 * @param ed Apontador para a estrutura de dados.
 *
 * Esta função abre o arquivo no modo leitura e lê os valores inteiros, adicionando-os na estrutura de dados.
 * A função também verifica se o número de colunas é consistente em todas as linhas.
 */
int lerMatriz(char* filename, ED* ed) {
    // Abre o arquivo no modo de leitura
    FILE* file = fopen(filename, "r");

    // Verifica se o arquivo foi aberto corretamente
    if (file == NULL) {
    return 101;
    }

    // Inicializa a estrutura de dados ed
    inicializar(ed);

    // Declaração de variáveis para armazenar o valor lido, o caractere lido e o número de colunas
    int valor;
    char c;
    int colunas = 0;

    // Lê os valores do arquivo até o final 
    while (fscanf_s(file, "%d", &valor) == 1) {
        // Adiciona o valor lido à estrutura de dados
        adicionar(ed, valor);

        // Incrementa o contador de colunas
        colunas++;

        // Lê o próximo caractere e verifica se esta no final da linha
        if (fscanf_s(file, "%c", &c, 1) != 1 || c == '\n') {
            // Se é a primeira linha, define o número de colunas
            if (ed->colunas == 0) {
                ed->colunas = colunas;
            }
            // Se o número de colunas é diferente do número de colunas da primeira linha, imprime uma mensagem de erro
            else if (colunas != ed->colunas) {
                // Imprime uma mensagem de erro 
                return 101;
            }

            // Incrementa o número de linhas ao encontrar o final da linha
            ed->linhas++;

            // Reinicia a variavel que conta o numero de colunas
            colunas = 0;
        }
    }

    // Fecha o arquivo
    fclose(file);
    return 0;
}


/**
* @brief Imprime a matriz.
*
* @param ed Apontador para a estrutura de dados.
*
* Esta função percorre a lista ligada e imprime os valores das casas, formatando a saída para que a matriz seja exibida corretamente.
*/
int imprimirMatriz(ED* ed) {
    Node* atual = ed->head;

    // Percorre cada linha
    for (int i = 0; i < ed->linhas; i++) {
        // Percorre cada coluna
        for (int j = 0; j < ed->colunas; j++) {
            // Verifica se a casa atual é nula (o final da lista foi alcançado)
            if (atual != NULL) {
                // Imprime o valor da casa atual
                printf("| %d\t |", atual->armaz);
                // Move para a próxima casa na mesma linha
                atual = atual->prox;
            }
            else {
                // Se a casa atual for nula, imprime um espaço vazio
                printf("|      |");
            }
        }
        // Imprime uma nova linha após cada linha da matriz
        printf("\n");
    }
        return 0;
}



/**
 * @brief Modifica o valor de um elemento na matriz.
 *
 * @param ed Apontador para a estrutura de dados.
 * @param linha índice da linha do elemento a ser modificado.
 * @param coluna índice da coluna do elemento a ser modificado.
 * @param novoValor Novo valor a ser atribuído ao elemento.
 *
 * Esta funçãoo modifica o valor de um elemento na matriz representada pela estrutura de dados.
 * Verifica se os índices de linha e coluna são válidos e, em seguida, percorre a lista ligada até encontrar o elemento desejado.
 * Se o elemento for encontrado, o valor é atualizado com o novoValor. Caso contrário, uma mensagem de erro é exibida.
 */

int modificarValor(ED* ed, int linha, int coluna, int novoValor) {
    linha--; // Subtrai 1 da linha
    coluna--; // Subtrai 1 da coluna
    // Verifica se os índices de linha e coluna são válidos
    if (linha < 0 || linha >= ed->linhas || coluna < 0 || coluna >= ed->colunas) {
        return 201;
    }

    Node* atual = ed->head; // Inicializa o apontador atual com a primeira casa lista
    int index = linha * ed->colunas + coluna; // Calcula o valor do elemento a ser modificado
    for (int i = 0; i < index; i++) {  // Percorre a lista até o valor desejado

        if (atual == NULL) {    // Se o final da lista for alcançado antes de atingir o valor desejado, exibe uma mensagem de erro
            return 201;
        }
        atual = atual->prox;    // Move para a próxima casa
    }
    // Atualiza o valor do elemento se ele for encontrado
    if (atual != NULL) {
        atual->armaz = novoValor; 
    }
    // Se o elemento não for encontrado, mostra uma mensagem de erro
    else { 
        return 201;
    }
    return 0;
}



/**
 * @brief Atualiza o arquivo com a matriz modificada.
 *
 * @param filename Nome do arquivo.
 * @param ed Apontador para a estrutura de dados.
 *
 * Esta função abre o arquivo no modo escrita e atualiza o conteúdo do arquivo com a matriz modificada representada pela estrutura de dados.
 * A função percorre a lista ligada e escreve os valores das respetivas casas no arquivo, formatando a saída para que a matriz seja armazenada corretamente.
 * Cada valor é separado por ponto e vírgula e cada linha é finalizada com um paragrafo.
 */
int atualizarArquivo(char* filename, ED* ed) {
    FILE* file = fopen(filename, "w");  // Abre o arquivo no modo de escrita
    // Verifica se o arquivo foi aberto corretamente
    if (file == NULL) {
        return 301;
    }

    // Percorre a lista ligada e escreve os valores das casas no arquivo
    Node* atual = ed->head;              // Inicializa o apontador atual com a primeira casa da lista

    for (int i = 0; i < ed->linhas; i++) {   // Percorre cada linha

        for (int j = 0; j < ed->colunas; j++) {  // Percorre cada coluna
            fprintf(file, "%d", atual->armaz);    
            atual = atual->prox;           // Move para a próxima casa
            if (j < ed->colunas - 1) {
                fprintf(file, ";"); // Adiciona ponto e vírgula entre os valores
            }
        }
        fprintf(file, "\n"); // Adiciona nova linha após cada linha da matriz
    }

    fclose(file);     // Fecha o arquivo

    return 0;
}



/**
 * @brief Adiciona uma nova linha à matriz.
 *
 * @param ed Apontador para a estrutura de dados.
 * @param posicao Posição da nova linha a ser adicionada.
 *
 * Esta função adiciona uma nova linha à matriz representada pela estrutura de dados. Verifica se a posição é válida e, em seguida,
 * Calcula o índice do primeiro elemento da nova linha. Em seguida, percorre a lista ligada até à posição desejada e adiciona as novas casas na posição correta.
 * Cada nova casa tem o valor inicializado como 0. O número de linhas é incrementado após a adição da nova linha.
 */
int adicionarLinha(ED* ed, int posicao) {
    posicao--; // Subtrai 1 da posição

    // Verifica se a posição é válida
    if (posicao < 0 || posicao > ed->linhas) {
        return 401;
    }

    int index = posicao * ed->colunas; // Calcula o índice do primeiro elemento da nova linha
    Node* anterior = NULL;        // Inicializa o apontador anterior com NULL
    Node* atual = ed->head;         // Inicializa o apontador atual com a primeira casa da lista

    // Percorre a lista até à posição desejada
    for (int i = 0; i < index; i++) {
        if (atual == NULL) {
            return 401;
        }
        anterior = atual;    
        atual = atual->prox;   // Move para a próxima casa
    }

    // Adiciona a novas casas na posição desejada
    for (int i = 0; i < ed->colunas; i++) {
        Node* novo = (Node*)malloc(sizeof(Node));    // guarda memória para uma nova casa
        if (novo == NULL) {
            return 401;
        }
        novo->armaz = 0; // O valor da nova casa é 0
        novo->prox = atual; // A nova casa aponta para a casa atual

        if (anterior == NULL) {
            // Se não há casa anterior, a nova casa é a primeira da lista
            ed->head = novo;
        }
        else {
            // Caso contrário, a casa anterior aponta para a nova casa
            anterior->prox = novo;
        }

        // A nova casa torna-se na casa anterior para a próxima iteração
        anterior = novo;
    }

    ed->linhas++; // Incrementa o número de linhas
    return 0;
}

/**
 * @brief Adiciona uma nova coluna à matriz.
 *
 * @param ed Apontador para a estrutura de dados.
 * @param posicao Posição da nova coluna a ser adicionada.
 *
 * Esta função adiciona uma nova coluna à matriz representada pela estrutura de dados. Ela verifica se a posição é válida e, em seguida,
 * Calcula o índice do primeiro elemento da nova coluna. Em seguida, percorre a lista ligada até à posição desejada e adiciona as novas casas na posição correta.
 * Cada nova casa tem o valor inicializado como 0. O número de colunas é incrementado após a adição da nova coluna.
 */
int adicionarColuna(ED* ed, int posicao) {
    posicao--; // Subtrai 1 da posição 

    // Verifica se a posição é válida
    if (posicao < 0 || posicao > ed->colunas) {
        return 501;
    }

    Node* anterior = NULL;    // Inicializa o aontador anterior com NULL
    Node* atual = ed->head;   // Inicializa o apontador atual com a primeira casa da lista
    Node* novo = NULL;      // Inicializa o apontador novo com NULL

    // Adiciona as novas casas na posição desejada inserida pelo utilizador
    for (int i = 0; i < ed->linhas; i++) {

        // Percorre a lista até a posição desejada na linha atual
        int index = i * (ed->colunas + 1) + posicao; // Calcula o valor da nova coluna
        anterior = NULL;
        atual = ed->head; 
        // Percorre a lista até a posição desejada na linha atual
        for (int j = 0; j < index; j++) {   
            if (atual == NULL) {
                return 501;
            }
            anterior = atual;     // A casa anterior torna-se na casa atual
            atual = atual->prox;   // Move para a próxima casa
        }

        novo = (Node*)malloc(sizeof(Node));   // Guarda a memória para uma nova casa
        if (novo == NULL) {
            return 501;
        }
        novo->armaz = 0; // O valor da nova casa é 0
        novo->prox = atual; // A nova casa aponta para a casa atual

        if (anterior == NULL) {
            // Se não há casa anterior, a nova casa é a primeiro da lista
            ed->head = novo;
        }
        else {
            // Caso contrário,a casa anterior aponta para a nova casa
            anterior->prox = novo;
        }
    }

    ed->colunas++; // Incrementa o número de colunas
    return 0;
}


/**
 * @brief Elimina uma linha da matriz.
 *
 * @param ed Apontador para a estrutura de dados.
 * @param posicao Posição da linha a ser eliminada.
 *
 * Esta função elimina uma linha da matriz representada pela estrutura de dados.
 * Verifica se a posição é válida e, em seguida, calcula o índice do primeiro elemento da linha a ser eliminada.
 * Em seguida, percorre a lista ligada até à posição desejada e remove as casas da respetiva linha.
 * O número de linhas é decrementado apó a remoção da linha.
 */

int eliminarLinha(ED* ed, int posicao) {
    posicao--; // Subtrai 1 da posição 

    // Verifica se a posição é válida
    if (posicao < 0 || posicao >= ed->linhas) {
        return 601;
    }

    int index = posicao * ed->colunas; // Calcula o índice do primeiro elemento da linha a ser eliminada
    Node* anterior = NULL;      // Inicializa o apontador anterior com NULL
    Node* atual = ed->head;    // Inicializa o apontador atual com a primeira casa da lista

    // Percorre a lista até a posição desejada
    for (int i = 0; i < index; i++) {   
        if (atual == NULL) {
            return 601;
        }
        anterior = atual;      // A casa anterior torna-se na casa atual
        atual = atual->prox;     // Move para a próxima casa
    }

    // Remove as casas da linha desejada
    for (int i = 0; i < ed->colunas; i++) {
        Node* temp = atual;      // Armazena o apontador atual numa variável temporária
        atual = atual->prox;    // Move para a próxima casa
        free(temp);           // Liberta a memória guardada para a casa atual
    }

    if (anterior == NULL) {
        // Se não há casa anterior, a primeira casa da lista é a casa atual
        ed->head = atual;
    }
    else {
        // Caso contrário, a casa anterior aponta para a casa atual
        anterior->prox = atual;
    }

    ed->linhas--; // Decrementa o número de linhas
    return 0;
}


/**
 * @brief Elimina uma coluna da matriz.
 *
 * @param ed Apontador para a estrutura de dados.
 * @param posicao Posição da coluna a ser eliminada.
 *
 * Esta função elimina uma coluna da matriz representada pela estrutura de dados. Verifica se a posição é válida e, em seguida, calcula o
 *  índice do primeiro elemento da coluna a ser eliminada. Em seguida, percorre a lista ligada até a posição desejada e remove as casas da coluna.
 * O número de colunas é decrementado após a remoção da coluna.
 */
int eliminarColuna(ED* ed, int posicao) {
    posicao--; // Subtrai 1 da posição 

    // Verifica se a posição é válida
    if (posicao < 0 || posicao >= ed->colunas) {
        return 701;
    }

    Node* anterior = NULL;    // Inicializa o apontador anterior como NULL
    Node* atual = ed->head;   // Inicializa o apontador atual com a primeira casa da lista

    // Remove as casas da coluna desejada
    for (int i = 0; i < ed->linhas; i++) {
        // Percorre a lista até a posição desejada na linha atual
        int index = i * (ed->colunas - 1) + posicao;
        anterior = NULL;   
        atual = ed->head;    // Inicializa o apontador atual com a primeira casa da lista

        for (int j = 0; j < index; j++) { // Percorre a lista até a posição desejada na linha atual
            if (atual == NULL) {
                return 701;
            }
            anterior = atual;           // A casa anterior torna-se na casa atual
            atual = atual->prox;      // Move para a próxima casa
        }

        Node* temp = atual;    // Armazena o apontador atual numa variável temporária
        atual = atual->prox;    // Move para a próxima casa
        free(temp);

        if (anterior == NULL) {
            // Se não casa anterior, a primeira casa da lista é a casa atual
            ed->head = atual;
        }
        else {
            // Caso contrário, a casa anterior aponta para a casa atual
            anterior->prox = atual;
        }
    }

    ed->colunas--; // Decrementa o número de colunas
    return 0;
}

/**
 * @brief Calcula a soma máxima possível dos inteiros selecionados na matriz.
 *
 * @param ed Apontador para a estrutura de dados.
 * @return A soma máxima possível dos inteiros selecionados.
 *
 * Esta função calcula a soma máxima possível dos inteiros selecionados na matriz representada pela estrutura de dados.
 * Converte a lista ligada numa matriz bidimensional e encontra o valor máximo na matriz.
 * Em seguida, converte a matriz numa matriz de custo, onde cada valor é a diferença entre o valor máximo e o valor original.
 * A função utiliza o algoritmo de atribuiçao de custo mínimo(algoritmo Hungaro) para encontrar a combinação de inteiros que maximiza a soma.
 * Por fim, retorna a soma máxima possível dos inteiros selecionados.
 */
int calcularSomaMaxima(ED* ed) {
    // Verifica se a matriz esta fazia
    if (ed->linhas == 0 || ed->colunas == 0) {
        return 801;
    }
    // Verifica se a matriz é quadrada
    if (ed->linhas != ed->colunas) {
        return 801;
    }
    // Converte a lista ligada numa matriz bidimensional
    int** matriz = (int**)malloc(ed->linhas * sizeof(int*)); // Guarda memória para a matriz
    Node* current = ed->head;     // Inicializa o ponteiro atual com a primeira casa da lista
    int maxVal = INT_MIN;     // Inicializa o valor máximo com o menor valor possível

    for (int i = 0; i < ed->linhas; i++) {       // Percorre cada linha
        matriz[i] = (int*)malloc(ed->colunas * sizeof(int));    // Guarda memória para cada linha da matrizw

        for (int j = 0; j < ed->colunas; j++) {        // Percorre cada coluna
            if (current != NULL) {        // Verifica se a casa atual não é nula
                matriz[i][j] = current->armaz;      // Adiciona o valor da casa atual à matriz

                if (current->armaz > maxVal) {       // Verifica se o valor da casa atual é maior que o valor máximo
                    maxVal = current->armaz; // Encontra o valor máximo na matriz
                }
                current = current->prox;     // Move para a próxima casa
            } 
                 // Se a casa atual for nula, o valor da matriz é 0
            else {
            return 801;
            }
        }
    }

    // Converte a matriz em uma matriz de custo
    for (int i = 0; i < ed->linhas; i++) {   // Percorre cada linha
        for (int j = 0; j < ed->colunas; j++) {    // Percorre cada coluna
            matriz[i][j] = maxVal - matriz[i][j];    // Calcula a diferença entre o valor máximo e o valor original
        }
    }    

    // Guarda memória para as estruturas de dados auxiliares
    int* u = (int*)calloc(ed->linhas + 1, sizeof(int));     // Guarda memória para o vetor u
    int* v = (int*)calloc(ed->colunas + 1, sizeof(int));    // Guarda memória para o vetor v
    int* p = (int*)calloc(ed->colunas + 1, sizeof(int));    // Guarda memória para o vetor p
    int* way = (int*)calloc(ed->colunas + 1, sizeof(int));     // Guarda memória para o vetor way

    // Verifica se a alocação de memória foi bem-sucedida
    if (u == NULL || v == NULL || p == NULL || way == NULL) {     
        return 801;
    }

    // Aplica o algoritmo de atribuiçao de custo mínimo (algoritmo Hungaro)
    for (int i = 1; i <= ed->linhas; i++) {   // Percorre cada linha
        p[0] = i;     // Define o valor de p[0] como i
        int j0 = 0;    // Inicializa j0 como 0  
        int* minv = (int*)malloc((ed->colunas + 1) * sizeof(int));    // Guarda memória para o vetor minv
        bool* used = (bool*)calloc(ed->colunas + 1, sizeof(bool));    // Guarda memória para o vetor used

        // Verifica se a alocação de memória foi bem-sucedida
        if (minv == NULL || used == NULL) {
            return 801;
        }

        for (int j = 0; j <= ed->colunas; j++) {     // Percorre cada coluna
            minv[j] = INT_MAX;      // Inicializa minv[j] com o maior valor possível
            used[j] = false;        // Inicializa used[j] como falso 
        }
        // Inicializa o ciclo do algoritmo de atribuiçao de custo mínimo
        do {
            used[j0] = true;     // Define used[j0] como verdadeiro
            int i0 = p[j0], delta = INT_MAX;    // Inicializa i0 e delta com o maior valor possível
            int j1 = 0; // Inicializa j1 
            for (int j = 1; j <= ed->colunas; j++) {    // Percorre cada coluna

                if (!used[j]) {    // Verifica se used[j] é falso
                    int cur = matriz[i0 - 1][j - 1] - u[i0] - v[j];     // Calcula o valor de cur
                    if (cur < minv[j]) {      // Verifica se cur é menor que minv[j]
                        minv[j] = cur;        // Define minv[j] como cur
                        way[j] = j0;          // Define way[j] como j0
                    }
                    if (minv[j] < delta) {     // Verifica se minv[j] é menor que delta
                        delta = minv[j];       // Define delta como minv[j] 
                        j1 = j;               // Define j1 como j
                    }
                }
            }

            for (int j = 0; j <= ed->colunas; j++) {    // Percorre cada coluna
                if (used[j]) {             // Verifica se used[j] é verdadeiro
                    u[p[j]] += delta;             // Adiciona delta a u[p[j]]
                    v[j] -= delta;            // Subtrai delta de v[j]
                }
                else {
                    minv[j] -= delta;            // Subtrai delta de minv[j]
                }
            }
            j0 = j1;                     // Define j0 como j1
        } while (p[j0] != 0);                  // O ciclo continua enquanto p[j0] for diferente de 0


        do {
            int j1 = way[j0];             // Define j1 como way[j0]
            p[j0] = p[j1];               // Define p[j0] como p[j1]
            j0 = j1;                      // Define j0 como j1
        } while (j0);                    // O ciclo continua enquanto j0 for verdadeiro

        // Liberta a memória guardada para minv e used
        free(minv);               
        free(used);               
    }

    // Calcula a soma máxima possível dos inteiros selecionados
    int sum = 0;
    //printf("Valores selecionados: ");
    for (int j = 1; j <= ed->colunas; j++) {
        printf("%d ", maxVal - matriz[p[j] - 1][j - 1]);        // Subtrai o valor da matriz de custo do valor máximo para obter o valor original
        sum += maxVal - matriz[p[j] - 1][j - 1];               // Adiciona o valor original à soma
    }
    //printf("\n");

    // Liberta a memória guardada
    for (int i = 0; i < ed->linhas; i++) {
        free(matriz[i]);      // Liberta a memória guardada para cada linha da matriz
    }
    // Liberta a memória guardada para as estruturas de dados auxiliares
    free(matriz);         
    free(u);
    free(v);
    free(p);
    free(way);

    return sum;
}





