#include <stdio.h>

#define TABULEIRO 10
#define NAVIO 3
#define AGUA 0

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {

    int tabuleiro[TABULEIRO][TABULEIRO] = {0}; // 0 representa a agua

    // Posições dos navios no tabuleiro (vertical, horizontal e diagonal)
    int posNavioV[3] = {NAVIO, NAVIO, NAVIO};
    int posNavioH[3] = {NAVIO, NAVIO, NAVIO};
    int posNavioD1[3] = {NAVIO, NAVIO, NAVIO};
    int posNavioD2[3] = {NAVIO, NAVIO, NAVIO};

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

    // Navio Diagonal 1

    int linhaD1 = 1, colunaD1 = 1;
    for (int d = 0; d < 3; d++) {
        if (linhaD1 + d < TABULEIRO && colunaD1 + d < TABULEIRO && tabuleiro[linhaD1 + d][colunaD1 + d] == AGUA) {
            tabuleiro[linhaD1 + d][colunaD1 + d] = posNavioD1[d];
        }
    }

    // Navio Diagonal 2

    int linhaD2 = 1, colunaD2 = 8;
    for (int d = 0; d < 3; d++) {
        if (linhaD2 + d < TABULEIRO && colunaD2 - d >= 0 && tabuleiro[linhaD2 + d][colunaD2 - d] == AGUA) {
            tabuleiro[linhaD2 + d][colunaD2 - d] = posNavioD2[d];
        }
    }

    // Exibição da posição dos navios

    printf("\nCoordenadas do Navio Horizontal:\n\n");
    for (int i = 0; i < 3; i++) {
        printf("Linha %d, Coluna %d\n", linhaH, colunaH + i); 
    }
    
    printf("\n\n##################################\n\n");

    printf("\n\nCoordenadas do Navio Vertical:\n\n");
    for (int i = 0; i < 3; i++) {
        printf("Linha %d, Coluna %d\n", linhaV + i, colunaV); 
    }

    printf("\n\n##################################\n\n");

    printf("\nCoordenadas do Navio Diagonal 1:\n\n");
    for (int i = 0; i < 3; i++) {
        printf("Linha %d, Coluna %d\n", linhaD1 + i, colunaD1 + i);
    }

    printf("\n\n##################################\n\n");

    printf("Coordenadas do Navio Diagonal 2:\n\n");
    for (int i = 0; i < 3; i++) {
        printf("Linha %d, Coluna %d\n", linhaD2 + i, colunaD2 - i);
    }

    printf("\n\n##################################\n\n");

    //Tabuleiro completo:

    printf("\n\n ### Tabuleiro de batalha naval ###\n\n");
    for (int y = 0; y < TABULEIRO; y++) {
        for (int z = 0; z < TABULEIRO; z++) {
            printf("%2d ", tabuleiro[y][z]);
        }
        printf("\n");
    }

    return 0;
}
