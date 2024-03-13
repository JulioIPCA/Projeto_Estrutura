/*****************************************************************//**
 * \file   Header.h
 * \brief  
 * 
 * 
 * \author J�lio Faria
 * \date   March 2024
 *********************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



/**
 * @struct Node
 * @brief Estrutura para representar um n� na lista encadeada.
 *
 * @var Node::armaz
 * Armazena um valor inteiro.
 * @var Node::linha
 * Armazena a linha do n� na matriz.
 * @var Node::prox
 * Ponteiro para o pr�ximo n� na lista.
 */
typedef struct Node {
    int armaz;
    int linha;
    struct Node* prox;
} Node;

/**
 * @struct ED
 * @brief Estrutura para representar a lista encadeada e suas dimens�es.
 *
 * @var ED::head
 * Ponteiro para o primeiro n� na lista encadeada.
 * @var ED::linhas
 * N�mero de linhas na matriz.
 * @var ED::colunas
 * N�mero de colunas na matriz.
 */
typedef struct {
    Node* head;
    int linhas;
    int colunas;
} ED;

