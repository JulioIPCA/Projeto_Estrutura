/*****************************************************************//**
 * \file   main.c
 * \brief
 *
 * \author J�lio Faria
 * \date   March 2024
 *********************************************************************/

 //relatorio:
 //prefacio ou resumo(tem de estar bem explicado-problema em questao - porque � importante resolver - como � que se consegui resolver)
 //introducao-tudo do trabalho, com algum detalhe, enquadramento do trbalho. Objetivos. metodologia do trabalho(git,visual, ajudas,busca internet)
 // //e o meu relatorio � organizado da seguinte forma(secc�es(tipo indice))
 // //estado da arte- background(falar linguagem c, estrutura de dados dinamica, algoritmo que existe)        -> nao � totalmente necessario
 // avaliacao do sistema(matriz)
 //Conclusao (perceber o trabalho todo)(resultados, dados, conclus�o do progrmama, uso de listas ligadas etc)
 //

#include <stdio.h>
#include <stdlib.h>
#include "Header.h"

int main() {
    ED ed;
    int n = 1;

    int posicao;

    int linha, coluna, novoValor;

    lerMatriz("matriz.txt", &ed);

    scanf_s("%d", &n);

    switch (n) {

    case 1:

        imprimirMatriz(&ed);    
        break;


    case 2:

        imprimirMatriz(&ed);

        // Exemplo de modifica��o de um valor na matriz (linha 2, coluna 3)
        int linha, coluna, novoValor;
        int linha_n, coluna_n;


        printf("\nDigite a linha, a coluna e o novo valor (separados por espaço): ");
        scanf_s("%d %d %d", &linha, &coluna, &novoValor);
        modificarValor(&ed, linha, coluna, novoValor); 

        // Exibir a matriz atualizada
        printf("\nMatriz apos a modificacao:\n");
        imprimirMatriz(&ed);

        // Atualiza o arquivo com a matriz modificada
        atualizarArquivo("matriz.txt", &ed);

        break;

    case 3:
        //chama a fun��o adicionar linha e pede a linha ao utilizador

        printf("Numero da posição aonde quer adicionar a linha: ");
        scanf_s("%d", &posicao);
        adicionarLinha(&ed, posicao);
        imprimirMatriz(&ed);
        atualizarArquivo("matriz.txt", &ed);
        break;

    case 4:
        printf("Numero da posição aonde quer adicionar a Coluna: ");
        scanf_s("%d", &posicao);
        adicionarColuna(&ed, posicao);
        imprimirMatriz(&ed);
        atualizarArquivo("matriz.txt", &ed);
        break;

    case 5:
        imprimirMatriz(&ed);
        printf("Numero da posição aonde quer eliminar a linha: ");
        scanf_s("%d", &posicao);
        eliminarLinha(&ed, posicao);
        imprimirMatriz(&ed);
        atualizarArquivo("matriz.txt", &ed);
        break;

    case 6:
        imprimirMatriz(&ed);
        printf("Numero da posição aonde quer eliminar a Coluna: ");
        scanf_s("%d", &posicao);
        eliminarColuna(&ed, posicao);
        imprimirMatriz(&ed);
        atualizarArquivo("matriz.txt", &ed);
        break;
    case 7:
        imprimirMatriz(&ed);
        //implementar a função calcularSomaMaxima
        printf("A soma maxima da matriz e: %d", calcularSomaMaxima(&ed));

        return 0;
    }
    return 0;
}