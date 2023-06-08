//Esboço do designe do jogo da velha

#include <stdio.h>

int main() {
    char mat[3][3] = {' '}; // se quiser colocar "x" ou "o" para testar como fica
    int i, j, linha, coluna, player;


    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            mat[i][j] = ' '; // se quiser colocar "x" ou "o" para testar como fica
        }
    }

    printf("\n");

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

    printf("\n");


  /*  do{
        printf("Digite a linha e dois a coluna: ");
        scanf("%d \n %d",&linha, &coluna);

    }while(  linha < 0 || linha > 2 || coluna < 0 || coluna > 2 != ' '); /* Lendo os valores, caso seja != 0, 
    o jogador ja jogou naquela posicao*/

/*
    if ( player == 1){

        mat[linha][coluna] = '0';
        player++;
    }else{
        mat[linha][coluna] = 'X';
        player = 1; 
        
      }        
*/ 

    printf("\n");

    for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
        printf("%c", mat[i][j]);
        if ( j < 2 ) {
            printf("_|");
            if( j < 2 ) {
                printf("_"); 
                
            }
             
        }
        
    }

        printf("\n");
    }

    printf("\n");

    return 0;
}
