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
 * declaração de variáveis
 */

ED ed;
int n = 1;

int posicao;

int linha, coluna, novoValor, armaz, result;

/**
 * \brief Função principal do programa
 * 
 */
int main() {

    lerMatriz("matriz.txt", &ed);
    
    /**
	 * leitura de um valor inteiro de 1 a 7 para escolher a opção
	 */
    scanf_s("%d", &n);

    switch (n) {

    case 1:

        /**
         * Chama a funçãoimprimirMatriz
         */

        imprimirMatriz(&ed);

        break;

    case 2:
        imprimirMatriz(&ed);
        /**
         * Chama a função modificarValor
         */
        printf("\nDigite a linha, a coluna e o novo valor (separados por espaco): ");
        scanf_s("%d %d %d", &linha, &coluna, &novoValor);
        modificarValor(&ed, linha, coluna, novoValor);
        result = modificarValor(&ed, linha, coluna, novoValor);
        if (result == 201) {
            printf("Erro na funcao");
        }
        else {
            printf("\nMatriz apos a modificacao:\n");
            imprimirMatriz(&ed);
            atualizarArquivo("matriz.txt", &ed);
        }


        break;

    case 3:

        /**
         * Chama a função adicionarLinha
         */
        imprimirMatriz(&ed);
        printf("Numero da posicao onde quer adicionar a linha: ");
        scanf_s("%d", &posicao);
        adicionarLinha(&ed, posicao);
        result = adicionarLinha(&ed, posicao);
        if (result == 401) {
            printf("Erro na funcao");
        }
        else {
            imprimirMatriz(&ed);
            atualizarArquivo("matriz.txt", &ed);
        }
        break;

    case 4:

        /**
        * Chama a função adicionarColuna
        */
        printf("Numero da posicao onde quer adicionar a Coluna: ");
        scanf_s("%d", &posicao);
        adicionarColuna(&ed, posicao);
        result = adicionarColuna(&ed, posicao);
        if (result == 501) {
            printf("Erro na funcao");
        }
        else {
            imprimirMatriz(&ed);
            atualizarArquivo("matriz.txt", &ed);
        }
        break;

    case 5:

        /**
        * Chama a função EliminarLinha
        */
        imprimirMatriz(&ed);
        printf("Numero da posicao onde quer eliminar a linha: ");
        scanf_s("%d", &posicao);
        eliminarLinha(&ed, posicao);
        result = eliminarLinha(&ed, posicao);
        if (result == 601) {
            printf("Erro na funcao");
        }
        else {
            imprimirMatriz(&ed);
            atualizarArquivo("matriz.txt", &ed);
        }
        break;

    case 6:

        /**
        * Chama a função EliminarColuna
        */
        imprimirMatriz(&ed);
        printf("Numero da posição onde quer eliminar a Coluna: ");
        scanf_s("%d", &posicao);
        result = eliminarColuna(&ed, posicao); // Chama a função e armazena o resultado
        if (result == 701) {
            printf("Erro na funcao");
        }
        else {
            imprimirMatriz(&ed);
            atualizarArquivo("matriz.txt", &ed);
        }
        break;

    case 7:


        /**
        * Chama a função calcularSomaMaxima
        */
        imprimirMatriz(&ed);
        result = calcularSomaMaxima(&ed);
        if (result == 801) {
            printf("Erro na funcao");
        }
        else {
            int somaMaxima = result; // Armazena o resultado da função
            printf("A soma maxima da matriz e: %d", somaMaxima); // Usa a variável para a impressão
        }
        break;
    }
    /**
    * 
    * \return 0 se o programa terminar com sucesso
    */
    return 0;
}