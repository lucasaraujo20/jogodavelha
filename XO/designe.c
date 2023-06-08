//Esboço do designe do jogo da velha

#include <stdio.h>

int main() {
    char mat[3][3] = {' '}; // se quiser colocar "x" ou "o" para testar como fica
    int i, j;


    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            mat[i][j] = ' '; // se quiser colocar "x" ou "o" para testar como fica
        }
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%c", mat[i][j]);

            if (j < 2) {
                printf("_|"); // j percorre e printa posição 0 e 1

                if( j < 3) {

                    printf("_"); // printa dois "-" no lado direito de cada "_|"
                }
            }
        }
        printf("\n");
    }

    return 0;
}
