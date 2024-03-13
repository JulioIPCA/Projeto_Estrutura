/*****************************************************************//**
 * \file   Header.h
 * \brief  
 * 
 * 
 * \author Júlio Faria
 * \date   March 2024
 *********************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



/**
 * @struct Node
 * @brief Estrutura para representar um nó na lista encadeada.
 *
 * @var Node::armaz
 * Armazena um valor inteiro.
 * @var Node::linha
 * Armazena a linha do nó na matriz.
 * @var Node::prox
 * Ponteiro para o próximo nó na lista.
 */
typedef struct Node {
    int armaz;
    int linha;
    struct Node* prox;
} Node;

/**
 * @struct ED
 * @brief Estrutura para representar a lista encadeada e suas dimensões.
 *
 * @var ED::head
 * Ponteiro para o primeiro nó na lista encadeada.
 * @var ED::linhas
 * Número de linhas na matriz.
 * @var ED::colunas
 * Número de colunas na matriz.
 */
typedef struct {
    Node* head;
    int linhas;
    int colunas;
} ED;

