#include <stdio.h>

#define TABULEIRO 10
#define NAVIO 3
#define AGUA 0
#define HABILIDADE 5  // valor para marcar área afetada
#define TAM_HAB 5     // tamanho das matrizes das habilidades

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

    // Matrizes de Habilidades

    int cone[TAM_HAB][TAM_HAB] = {0};
    int cruz[TAM_HAB][TAM_HAB] = {0};
    int octaedro[TAM_HAB][TAM_HAB] = {0};

    int centro = TAM_HAB / 2; // centro das matrizes

    // Cone — área expandindo para baixo
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            int limite = i; 
            if (j >= centro - limite && j <= centro + limite) {
                cone[i][j] = 1;
            }
        }
    }

    // Cruz — linhas central e vertical
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i == centro || j == centro) {
                cruz[i][j] = 1;
            }
        }
    }

    // Octaedro — forma de losango
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (abs(i - centro) + abs(j - centro) <= centro) {
                octaedro[i][j] = 1;
            }
        }
    }

    // Sobreposição no Tabuleiro


    int origemConeLin = 6, origemConeCol = 2;
    int origemCruzLin = 4, origemCruzCol = 4;
    int origemOctLin  = 7, origemOctCol = 7;

    // Cone
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {

            int tabLin = origemConeLin + i - centro;
            int tabCol = origemConeCol + j - centro;

            if (cone[i][j] == 1 &&
                tabLin >= 0 && tabLin < TABULEIRO &&
                tabCol >= 0 && tabCol < TABULEIRO &&
                tabuleiro[tabLin][tabCol] == AGUA) {

                tabuleiro[tabLin][tabCol] = HABILIDADE;
            }
        }
    }

    // Cruz
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {

            int tabLin = origemCruzLin + i - centro;
            int tabCol = origemCruzCol + j - centro;

            if (cruz[i][j] == 1 &&
                tabLin >= 0 && tabLin < TABULEIRO &&
                tabCol >= 0 && tabCol < TABULEIRO &&
                tabuleiro[tabLin][tabCol] == AGUA) {

                tabuleiro[tabLin][tabCol] = HABILIDADE;
            }
        }
    }

    // Octaedro
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {

            int tabLin = origemOctLin + i - centro;
            int tabCol = origemOctCol + j - centro;

            if (octaedro[i][j] == 1 &&
                tabLin >= 0 && tabLin < TABULEIRO &&
                tabCol >= 0 && tabCol < TABULEIRO &&
                tabuleiro[tabLin][tabCol] == AGUA) {

                tabuleiro[tabLin][tabCol] = HABILIDADE;
            }
        }
    }

    //Tabuleiro completo:

    printf("\n\n ### Tabuleiro de batalha naval ###\n\n");
    for (int y = 0; y < TABULEIRO; y++) {
        for (int z = 0; z < TABULEIRO; z++) {

            if (tabuleiro[y][z] == AGUA) {
                printf(" . ");   // Água (0)
            }
            else if (tabuleiro[y][z] == NAVIO) {
                printf(" N ");   // Navio (3)
            }
            else if (tabuleiro[y][z] == HABILIDADE) {
                printf(" * ");   // Área de habilidade (5)
            }
            else {
                printf("%2d ", tabuleiro[y][z]);
            }
        }
        printf("\n");
    }

    printf("\nLegenda:\n. = Água\nN = Navio\n* = Área da habilidade\n\n");

    return 0;
}
