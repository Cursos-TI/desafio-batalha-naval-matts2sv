#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    int tabuleiro[10][10] = {0}; // 0 representa a agua

    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    int posNavioV[3] = {3, 3, 3};
    int posNavioH[3] = {3, 3, 3};

    // Navio Horizontal

    int linhaH = 2, colunaH = 4;
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaH][colunaH + i] = posNavioH[i];
    }

    // Navio Vertical

    int linhaV = 5, colunaV = 7;
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaV + i][colunaV] = posNavioV[i];
    }
    printf("\n\n### Desafio Batalha Naval em C ###\n\n");

    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    printf("\nCoordenadas do Navio Horizontal:\n\n");
    for (int i = 0; i < 3; i++) {
        printf("Linha %d, Coluna %d\n", linhaH, colunaH + i); 
    }
    
    printf("\n\n##################################\n\n");

       printf("\n\nCoordenadas do Navio Vertical:\n\n");
    for (int i = 0; i < 3; i++) {
        printf("Linha %d, Coluna %d\n", linhaV, colunaV + i); 
    }

    printf("\n\n##################################\n\n");

    //Tabuleiro completo:

    printf("\n\n ### Tabuleiro de batalha naval ###\n\n");
    for (int y = 0; y < 10; y++) {
        for (int z = 0; z < 10; z++) {
            printf("%d ", tabuleiro[y][z]);
        }
        printf("\n");
    }

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
