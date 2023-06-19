#include <stdio.h>
#include <stdlib.h> // system("cls"); 

char quadrado[3][3]; 
void zera();
void desenho();
int condicaovitoria(char jogador);
void ia();
int Ramo();
int Empate();




int main() {
    int vez = 1; 
    int l, q;

    zera();
    desenho();

    while (!condicaovitoria('X') && !condicaovitoria('O') && !Empate()) {

        if (vez) {

        printf(" Digite a linha: ");
        scanf("%d", &l);
        printf(" Digite o quadrado : ");
        scanf("%d", &q);


        if (quadrado[l - 1][q - 1] != ' ' ) {
        printf("Ocupado. Tente novamente\n");
        continue;

        }

        } else {

        quadrado[l - 1][q - 1] = 'X';

            ia();
        }

        vez = !vez;
        desenho();
    }

    desenho();

    printf("Fim do jogo!\n");


    if (Empate()) {
        printf("Empate\n");
    } else if (vez) {
        printf("Robo ganhou\n");
    } else {
        printf("Jogador ganhou\n");
    }


    return 0;
}














void zera() {
    for (int i = 0; i < 3; i++) { // reseta e adciona ' ';
        for (int j = 0; j < 3; j++) {
            quadrado[i][j] = ' ';
        }
    }
}

void desenho() {

    //system("cls"); // limpa a tela
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



int condicaovitoria(char pl) { // pl = player

    for (int i = 0; i < 3; i++) {
        if (quadrado[i][0] == pl && quadrado[i][1] == pl && quadrado[i][2] == pl && pl != ' ') {
            return 1; // Vencedor
        }
    }


    for (int i = 0; i < 3; i++) {
        if (quadrado[0][i] == pl && quadrado[1][i] == pl && quadrado[2][i] == pl && pl != ' ') {
            return 1; 
        }
    }


    if (quadrado[0][0] == pl && quadrado[1][1] == pl && quadrado[2][2] == pl && pl != ' ') {
        return 1; 
    }

    if (quadrado[0][2] == pl && quadrado[1][1] == pl && quadrado[2][0] == pl && pl != ' ') {
        return 1;
    }

    return 0; 
}





void ia() {

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (quadrado[i][j] == ' ') {
                quadrado[i][j] = 'O';
                if (condicaovitoria('O')) {
                    return;
                } else {
                    quadrado[i][j] = ' ';
                }
            }
        }
    }


 
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (quadrado[i][j] == ' ') {
                quadrado[i][j] = 'X';
                if (condicaovitoria('X')) {
                    quadrado[i][j] = 'O';
                    return;
                } else {
                    quadrado[i][j] = ' ';
                }
            }
        }
    }


    if (quadrado[1][1] == ' ') { // se o usuário não jogar no centro
        quadrado[1][1] = 'O';
        return;
    }


    if (Ramo()) {
        return;
    }


    if (quadrado[0][0] == ' ') { // fazer jogada em ' '
        quadrado[0][0] = 'O';
        return;
    }
    if (quadrado[0][2] == ' ') {
        quadrado[0][2] = 'O';
        return;
    }
    if (quadrado[2][0] == ' ') {
        quadrado[2][0] = 'O';
        return;
    }
    if (quadrado[2][2] == ' ') {
        quadrado[2][2] = 'O';
        return;
    }


    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (quadrado[i][j] == ' ') {
                quadrado[i][j] = 'O';
                return;
            }
        }
    }
}




int Ramo() {

    for (int i = 0; i < 3; i++) {
        if (quadrado[i][0] == 'O' && quadrado[i][2] == 'O' && quadrado[i][1] == ' ') {
            quadrado[i][1] = 'O';
            return 1;
        }
    }


    for (int i = 0; i < 3; i++) {
        if (quadrado[0][i] == 'O' && quadrado[2][i] == 'O' && quadrado[1][i] == ' ') {
            quadrado[1][i] = 'O';
            return 1;
        }
    }

  
    if (quadrado[0][0] == 'O' && quadrado[2][2] == 'O' && quadrado[1][1] == ' ') {
        quadrado[1][1] = 'O';
        return 1;
    }

  
    if (quadrado[0][2] == 'O' && quadrado[2][0] == 'O' && quadrado[1][1] == ' ') {
        quadrado[1][1] = 'O';
        return 1;
    }

    return 0;
}


int Empate() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (quadrado[i][j] == ' ') {
                return 0; // Se tiver posições ' ' não é empate
            }
        }
    }
    return 1; // Todas com posições com X ou O
}
