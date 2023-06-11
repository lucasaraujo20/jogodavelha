#include <stdio.h>
#define ANSI_COLOR_BLUE    "\x1b[34m"

void desenho( char quadrado[3][3] ); // printa do designe do jogo da velha com os valores da matriz


int main(){

    char quadrado[3][3] = {{' ', ' ', ' ',}
    ,{ ' ', ' ', ' '},
    { ' ', ' ', ' '},};

    desenho(quadrado);


}

void desenho( char quadrado[3][3] ){

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