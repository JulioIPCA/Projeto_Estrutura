/*****************************************************************//**
 * \file   main.c
 * \brief  Ficheiro principal do programa
 *
 * \author Júlio Faria
 * \date   Março 2024
 *********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "Header.h"

/**
 * \brief Função principal do programa
 * \return 0 se o programa terminar com sucesso
 */
int main() {

    /**
    * .declaração de variáveis
    *
    * \return
    */

    ED ed;
    int n = 1;

    int posicao;

    int linha, coluna, novoValor;

    /**
	 * \brief Chama a função lerMatriz
	 * 
	 */
    lerMatriz("matriz.txt", &ed);

    /**
	 * \brief leitura de um valor inteiro de 1 a 7 para escolher a opção
	 */
    scanf_s("%d", &n);

    switch (n) {

    case 1:
        /**
         * \brief Chama a funçãoimprimirMatriz
         */
        imprimirMatriz(&ed);    
        break;

    case 2:
        imprimirMatriz(&ed);
        /**
         * \brief Chama a função modificarValor
         */
        printf("\nDigite a linha, a coluna e o novo valor (separados por espaço): ");
        scanf_s("%d %d %d", &linha, &coluna, &novoValor);
        modificarValor(&ed, linha, coluna, novoValor); 
        printf("\nMatriz após a modificação:\n");
        imprimirMatriz(&ed);
        atualizarArquivo("matriz.txt", &ed);

        break;

    case 3:
        /**
         * \brief Chama a função adicionarLinha
         */
        printf("Número da posição onde quer adicionar a linha: ");
        scanf_s("%d", &posicao);
        adicionarLinha(&ed, posicao);
        imprimirMatriz(&ed);
        atualizarArquivo("matriz.txt", &ed);
        break;

    case 4:
        /**
        * \brief Chama a função adicionarColuna
        */
        printf("Número da posição onde quer adicionar a Coluna: ");
        scanf_s("%d", &posicao);
        adicionarColuna(&ed, posicao);
        imprimirMatriz(&ed);
        atualizarArquivo("matriz.txt", &ed);
        break;

    case 5:
        /**
        * \brief Chama a função EliminarLinha
        */
        imprimirMatriz(&ed);
        printf("Número da posição onde quer eliminar a linha: ");
        scanf_s("%d", &posicao);
        eliminarLinha(&ed, posicao);
        imprimirMatriz(&ed);
        atualizarArquivo("matriz.txt", &ed);
        break;

    case 6:
        /**
        * \brief Chama a função EliminarColuna
        */
        imprimirMatriz(&ed);
        printf("Número da posição onde quer eliminar a Coluna: ");
        scanf_s("%d", &posicao);
        eliminarColuna(&ed, posicao);
        imprimirMatriz(&ed);
        atualizarArquivo("matriz.txt", &ed);
        break;

    case 7:
        /**
        * \brief Chama a função calcularSomaMaxima
        */
        imprimirMatriz(&ed);
        printf("A soma máxima da matriz e: %d", calcularSomaMaxima(&ed));
    }
    return 0;
}