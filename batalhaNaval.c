#include <stdio.h>

#define TAM 10
#define SKILL 5

int main() {

    int tabuleiro[TAM][TAM];
    int cone[SKILL][SKILL];
    int cruz[SKILL][SKILL];
    int octa[SKILL][SKILL];

    int i, j;
    int centro = SKILL / 2;

    
    //  Inicializa tabuleiro com água (0)
   
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

   
    //  Define  navios  
    
    tabuleiro[2][4] = 3;
    tabuleiro[2][5] = 3;
    tabuleiro[2][6] = 3;

    tabuleiro[5][2] = 3;
    tabuleiro[6][2] = 3;
    tabuleiro[7][2] = 3;

    
    
    

    // CONE  
    for (i = 0; i < SKILL; i++) {
        for (j = 0; j < SKILL; j++) {
            int dist = j - centro;
            if (dist < 0) dist = -dist;

            if (i <= centro && dist <= i) {
                cone[i][j] = 1;
            } else {
                cone[i][j] = 0;
            }
        }
    }

    //  CRUZ  
    for (i = 0; i < SKILL; i++) {
        for (j = 0; j < SKILL; j++) {
            if (i == centro || j == centro) {
                cruz[i][j] = 1;
            } else {
                cruz[i][j] = 0;
            }
        }
    }

    // OCTAEDRO 
    for (i = 0; i < SKILL; i++) {
        for (j = 0; j < SKILL; j++) {
            int dl = i - centro;
            int dc = j - centro;
            if (dl < 0) dl = -dl;
            if (dc < 0) dc = -dc;

            if (dl + dc <= centro) {
                octa[i][j] = 1;
            } else {
                octa[i][j] = 0;
            }
        }
    }

    
    //  Aplicação das habilidades no TABULEIRO (valor 5)
   
    

    int origemConeL = 2, origemConeC = 3;
    int origemCruzL = 5, origemCruzC = 5;
    int origemOctaL = 8, origemOctaC = 5;

    //  Aplicar Cone 
    for (i = 0; i < SKILL; i++) {
        for (j = 0; j < SKILL; j++) {
            if (cone[i][j] == 1) {
                int L = origemConeL + (i - centro);
                int C = origemConeC + (j - centro);

                if (L >= 0 && L < TAM && C >= 0 && C < TAM) {
                    if (tabuleiro[L][C] == 0) {
                        tabuleiro[L][C] = 5;
                    }
                }
            }
        }
    }

    //  Aplicar Cruz 
    for (i = 0; i < SKILL; i++) {
        for (j = 0; j < SKILL; j++) {
            if (cruz[i][j] == 1) {
                int L = origemCruzL + (i - centro);
                int C = origemCruzC + (j - centro);

                if (L >= 0 && L < TAM && C >= 0 && C < TAM) {
                    if (tabuleiro[L][C] == 0) {
                        tabuleiro[L][C] = 5;
                    }
                }
            }
        }
    }

    //  Aplicar Octaedro 
    for (i = 0; i < SKILL; i++) {
        for (j = 0; j < SKILL; j++) {
            if (octa[i][j] == 1) {
                int L = origemOctaL + (i - centro);
                int C = origemOctaC + (j - centro);

                if (L >= 0 && L < TAM && C >= 0 && C < TAM) {
                    if (tabuleiro[L][C] == 0) {
                        tabuleiro[L][C] = 5;
                    }
                }
            }
        }
    }

   
    //   Final do Tabuleiro
   
    printf("   A B C D E F G H I J\n");
    for (i = 0; i < TAM; i++) {
        printf("%2d ", i + 1);
        for (j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
