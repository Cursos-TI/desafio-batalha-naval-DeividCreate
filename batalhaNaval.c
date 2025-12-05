#include <stdio.h>

int main() {

    int tabuleiro[10][10]; // criar tabuleiro 10x10
    int i, j;   // variaveis i serão linhas, j serão colunas

    // Preenche com 0
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Navio horizontal (3 posições)
    tabuleiro[2][4] = 3; // primeiro índici = i, segundo índici = j
    tabuleiro[2][5] = 3;
    tabuleiro[2][6] = 3;

    // Navio vertical (3 posições)
    tabuleiro[5][2] = 3;
    tabuleiro[6][2] = 3;
    tabuleiro[7][2] = 3;


    int linhaD1 = 1;
    int colunaD1 = 1;

    for (i = 0; i < 3; i++) {
        tabuleiro[linhaD1 + i][colunaD1 + i] = 3;
    }

    
    // Navio diagonal ↙ (linha + i, coluna - i)
   
    int linhaD2 = 4;
    int colunaD2 = 8;

    for (i = 0; i < 3; i++) {
        tabuleiro[linhaD2 + i][colunaD2 - i] = 3;
    }

     


    printf ("   A B C D E F G H I J\n");


   // --- Mostrar tabuleiro com números das linhas ---
    for (i = 0; i < 10; i++) {

        // imprime número da linha
        printf("%2d ", i + 1);

        // imprime o conteúdo da linha
        for (j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
        
    }

    printf("\n");
    printf("\n");
    printf("\n");
    return 0;
}
