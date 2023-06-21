#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define ANSI_COLOR_BLUE    "\x1b[34m"

void desenho( char quadrado[3][3] ); // printa do designe do jogo da velha com os valores da matriz



int main(){

    int cont, l,q, v = 1, i, j, r, r1 ; // cont = qauntidade de jogadas, l = linha , q  = quadrado , v = vez do jogador
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

            if( v%2 == 0 || v%2 == 1){ // Vez de qual jogador
                printf(" Vez do X \n"); 
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
                if( v == 1 ){
                    
                    quadrado[l-1][q-1] = 'X';

                    v++;

                }
            }

            //bot aleatorio em baixo

            
            srand(time(NULL)); // inicializa a randomização de numeros

                if ( v == 2) {
    
                do{


                    r = rand() % 3; // 0 a 2
                    r1 = rand() % 3;             

                }while ( quadrado[r][r1] != ' ');

                quadrado[r][r1] = 'O'; 


                v--; // volta v == 1


            }

            cont++;
        

            //O

            if( quadrado[0][0] == 'O' && quadrado[0][1] == 'O' && quadrado[0][2] == 'O'){ cont = 7; printf("\tRobo Venceu!!\n");};
            if( quadrado[1][0] == 'O' && quadrado[1][1] == 'O' && quadrado[1][2] == 'O'){ cont = 7; printf("\tRobo Venceu!!\n");};
            if( quadrado[2][0] == 'O' && quadrado[2][1] == 'O' && quadrado[2][2] == 'O'){ cont = 7; printf("\tRobo Venceu!!");};

            // Condção de vitoria 2. vertical 

            if( quadrado[0][0] == 'O' && quadrado[1][0] == 'O' && quadrado[2][0] == 'O'){ cont = 7; printf("\tRobo Venceu!!\n");};
            if( quadrado[0][2] == 'O' && quadrado[1][2] == 'O' && quadrado[2][2] == 'O'){ cont = 7; printf("\tRobo Venceu!!\n");};
            if( quadrado[0][1] == 'O' && quadrado[1][1] == 'O' && quadrado[2][1] == 'O'){ cont = 7; printf("\tRobo Venceu!!\n");};

            // Condição de vitoria 3, Diagonal direita

           if( quadrado[0][0] == 'O' && quadrado[1][1] == 'O' && quadrado[2][2] == 'O'){ cont = 7; printf("\tRobo Venceu!!\n");};
           if( quadrado[0][2] == 'O' && quadrado[1][1] == 'O' && quadrado[2][0] == 'O'){ cont = 7; printf("\tRobo Venceu!!\n");};

            //X

            // Condção de vitoria 1. horizontal
            if( quadrado[0][0] == 'X' && quadrado[0][1] == 'X' && quadrado[0][2] == 'X'){ cont = 7; printf("\tJogador Venceu!!\n");}
            if( quadrado[1][0] == 'X' && quadrado[1][1] == 'X' && quadrado[1][2] == 'X'){ cont = 7; printf("\tJogador Venceu!!\n");}
            if( quadrado[2][0] == 'X' && quadrado[2][1] == 'X' && quadrado[2][2] == 'X'){ cont = 7; printf("\tJogador Venceu!!");};

            // Condção de vitoria 2. vertical 

            if( quadrado[0][0] == 'X' && quadrado[1][0] == 'X' && quadrado[2][0] == 'X'){ cont = 7; printf("\tJogador Venceu!!\n");}
            if( quadrado[0][2] == 'X' && quadrado[1][2] == 'X' && quadrado[2][2] == 'X'){ cont = 7; printf("\tJogador Venceu!!\n");}
            if( quadrado[0][1] == 'X' && quadrado[1][1] == 'X' && quadrado[2][1] == 'X'){ cont = 7; printf("\tJogador Venceu!!\n");}

            // Condição de vitoria 3, Diagonal direita

           if( quadrado[0][0] == 'X' && quadrado[1][1] == 'X' && quadrado[2][2] == 'X'){ cont = 7; printf("\tJogador Venceu!!\n");};
           if( quadrado[0][2] == 'X' && quadrado[1][1] == 'X' && quadrado[2][0] == 'X'){ cont = 7; printf("\tJogador Venceu!!\n");};                


        }while( cont <= 5);

        desenho(quadrado);

        if( cont == 6){

            printf("\tEmpate\n");
        }

        printf("Jogar novamente ? S ou N\n "); 
        scanf("%s", &res);

    }while( res == 's' || res == 'S');

}


void desenho( char quadrado[3][3] ){

    //system("cls"); // limpa a tela
    printf(ANSI_COLOR_BLUE); 
    printf("\n");
    printf("\t   1   2   3 \n");
    printf("\t1  %c | %c | %c \n", quadrado[0][0], quadrado[0][1],quadrado[0][2]);/*/t = tabulação,  
    é utilizado para dar tab na string*/ 
    printf("\t   --------- \n" );
    printf("\t2  %c | %c | %c \n", quadrado[1][0], quadrado[1][1],quadrado[1][2]);
    printf("\t   --------- \n" );
    printf("\t3  %c | %c | %c \n", quadrado[2][0], quadrado[2][1],quadrado[2][2]);
    printf("\n");

}



