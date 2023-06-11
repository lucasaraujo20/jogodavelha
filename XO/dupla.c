#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ANSI_COLOR_BLUE    "\x1b[34m"

void desenho( char quadrado[3][3] ); // printa do designe do jogo da velha com os valores da matriz

int main(){

    int cont, l,q, v = 0, i, j ; // cont = qauntidade de jogadas, l = linha , q  = quadrado , v = vez do jogador
    char res; // resposta do usuário de S ou N
    char quadrado[3][3] = {{' ', ' ', ' ',}
    ,{ ' ', ' ', ' '},
    { ' ', ' ', ' '},};

    do{
        cont = 1; // toda vez que o loop de dentro acontecer + 1 

        for( i = 0; i <=2 ; i++){ // adciona ' ';
            for( j = 0; j <=2 ; j++){
                
                quadrado[i][j] = ' ';
            }
        }

        do{
            desenho(quadrado);

            if( v%2 == 0){ // Vez de qual jogador, par X e impar O 
                printf(" Vez do X \n"); 
            }else {
                printf(" Vez do O \n");
            }

            printf(" Digite a linha: ");
            scanf("%d", &l);
            printf(" Digite o quadrado : ");
            scanf("%d", &q);

            if(  l < 1 || l > 3 || q < 1 || q > 3 ){ // jogada invalida pois não existe as posições // considerando posição inicial = 1

                l = 0;
                q = 0; 
            } else if ( quadrado[l-1][q-1] != ' '){// jogada invalida pois as posições estão  ocupadas // [l-1] pois meu l = 0

                l = 0;
                q = 0; 

            }else{ // quando der certo:
                if( v%2 == 0){
                    quadrado[l-1][q-1] = 'X';// num par
                }else {
                     quadrado[l-1][q-1] = 'O';
                }

                v++;
                cont++;
            }

        }while( cont <= 9);

        desenho(quadrado);

        printf("Jogar novamente ? S ou N\n "); 
        scanf("%s", &res);

    }while( res == 's' || res == 'S');

}

void desenho( char quadrado[3][3] ){

    system("cls"); // limpa a tela
    printf(ANSI_COLOR_BLUE); 
    printf("\n");
    printf("\t %c | %c | %c \n", quadrado[0][0], quadrado[0][1],quadrado[0][2]);/*/t = tabulação,  
    é utilizado para criar colunas em uma string*/ 
    printf("\t-----------\n" );
    printf("\t %c | %c | %c \n", quadrado[1][0], quadrado[1][1],quadrado[1][2]);
    printf("\t-----------\n" );
    printf("\t %c | %c | %c \n", quadrado[2][0], quadrado[2][1],quadrado[2][2]);
    printf("\n");

}