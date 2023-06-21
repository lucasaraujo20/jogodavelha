#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h> //sleep
#define ANSI_COLOR_RED     "\x1b[31m"//coloca cor nos textos
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m" //cor padrao
#define MAX_PLAYERS 100
#define max_nome 50
#define RANKING_FILE "ranking.txt"

//Esboço do designe do jogo da velha (menu)

typedef struct {
    char name[max_nome];
    int wins;
    int loss;
} Player;

char quadrado[3][3]; 
void zera();
void desenho1();
int condicaovitoria(char jogador);
void ia();
int Ramo();
int Empate();
void imprimemenu1();
void imprimeconfig();
void imprimemenudif();
void imprimesobre();
void imprimemenujogador();
void imprimecarregando();
void imprimecreditos();
void imprimesaindo();
void imprimelento(char *p,int N);//imprime o texto lento
void imprimecolorido(char *p,int N);//imprime o texto colorido
void saveRanking(Player players[], int numPlayers);//salva o rank
void loadRanking(Player players[], int *numPlayers);//carrega ordem do rank
void addPlayer(Player players[], int *numPlayers, char *name);//adc um novo player ao arquivo
void updateWins(Player players[], int numPlayers, char *name);//atualiza vitoria
void updateloss(Player players[], int numPlayers, char *name);//atualiza derrota
void printRanking();//imprime o rank
void desenho( char quadrado[3][3] ); // printa do designe do jogo da velha com os valores da matriz

int main() {
    char mat[3][3];
    char nick[30];
    Player players[MAX_PLAYERS];
    int numPlayers = 0;
    char digi[] = "Digite uma OPCAO:";
    char invalida[] = "OPCAO INVALIDA";
    char voltarmn[] = "2 - VOLTAR AO MENU INICIAL";
    char salvo[] = "SALVANDO...";
    char nome[] = "Digite o nome:";
    char nomerk[] = " --- RANKING ---";
    char jogarnv[] = "1 - JOGAR NOVAMENTE";
    int opcao,opcao2,opcao3,opcao4,opcao5,dificuldade = 1;
    int vez = 1;
    int cont, l,q, v = 1, i, j, r, r1 ; // cont = qauntidade de jogadas, l = linha , q  = quadrado , v = vez do jogador
    char res; // resposta do usuário de S ou N
    char quadrado[3][3] = {{' ', ' ', ' ',}
    ,{ ' ', ' ', ' '},
    { ' ', ' ', ' '},};
    loadRanking(players, &numPlayers);
    do{//MENU
        opcao = 0;
        imprimemenu1();
        imprimelento(digi,30);
        setbuf(stdin,NULL);
        scanf("%d",&opcao);
        if(opcao == 1){//jogar
            do{
                imprimemenujogador();
                setbuf(stdin,NULL);
                scanf("%d",&opcao2);
                if(opcao2==1){//jogar 
                    printf("\n");
                    imprimelento(nome,20);
                    setbuf(stdin,NULL);
                    fgets(nick,30,stdin);
                    addPlayer(players,&numPlayers,nick);
                    saveRanking(players, numPlayers);
                    printf("\n");
                    printf(ANSI_COLOR_YELLOW);
                    imprimelento(salvo,250);
                    printf(ANSI_COLOR_RESET);
                    printf("\n\n");
                    do{
                        printf("  ");
                        imprimelento(jogarnv,20);
                        printf("\n");
                        printf("  ");
                        imprimelento(voltarmn,20);
                        printf("\n\n");
                        imprimelento(digi,20);
                        setbuf(stdin,NULL);
                        scanf("%d",&opcao5);
                        if(opcao5 == 1){//jogar novamente
                            if(dificuldade == 1){
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
                                desenho(quadrado);
                                    //O
                                printf(ANSI_COLOR_RED);
                                    if( quadrado[0][0] == 'O' && quadrado[0][1] == 'O' && quadrado[0][2] == 'O'){ cont = 7; printf("\t\nRobo Venceu!\n\n"); updateloss(players, numPlayers, nick); saveRanking(players, numPlayers);};
                                    if( quadrado[1][0] == 'O' && quadrado[1][1] == 'O' && quadrado[1][2] == 'O'){ cont = 7; printf("\t\nRobo Venceu!\n\n"); updateloss(players, numPlayers, nick); saveRanking(players, numPlayers);};
                                    if( quadrado[2][0] == 'O' && quadrado[2][1] == 'O' && quadrado[2][2] == 'O'){ cont = 7; printf("\t\nRobo Venceu!\n\n"); updateloss(players, numPlayers, nick); saveRanking(players, numPlayers);};

                                    // Condção de vitoria 2. vertical 

                                    if( quadrado[0][0] == 'O' && quadrado[1][0] == 'O' && quadrado[2][0] == 'O'){ cont = 7; printf("\t\nRobo Venceu!\n\n"); updateloss(players, numPlayers, nick); saveRanking(players, numPlayers);};
                                    if( quadrado[0][2] == 'O' && quadrado[1][2] == 'O' && quadrado[2][2] == 'O'){ cont = 7; printf("\t\nRobo Venceu!\n\n"); updateloss(players, numPlayers, nick); saveRanking(players, numPlayers);};
                                    if( quadrado[0][1] == 'O' && quadrado[1][1] == 'O' && quadrado[2][1] == 'O'){ cont = 7; printf("\t\nRobo Venceu!\n\n"); updateloss(players, numPlayers, nick); saveRanking(players, numPlayers);};

                                    // Condição de vitoria 3, Diagonal direita

                                if( quadrado[0][0] == 'O' && quadrado[1][1] == 'O' && quadrado[2][2] == 'O'){ cont = 7; printf("\t\nRobo Venceu!\n\n"); updateloss(players, numPlayers, nick); saveRanking(players, numPlayers);};
                                if( quadrado[0][2] == 'O' && quadrado[1][1] == 'O' && quadrado[2][0] == 'O'){ cont = 7; printf("\t\nRobo Venceu!\n\n"); updateloss(players, numPlayers, nick); saveRanking(players, numPlayers);};

                                    //X
                                printf(ANSI_COLOR_GREEN);
                                    // Condção de vitoria 1. horizontal
                                    if( quadrado[0][0] == 'X' && quadrado[0][1] == 'X' && quadrado[0][2] == 'X'){ cont = 7; printf("\t\nJogador Venceu!\n\n");updateWins(players, numPlayers, nick); saveRanking(players, numPlayers);}
                                    if( quadrado[1][0] == 'X' && quadrado[1][1] == 'X' && quadrado[1][2] == 'X'){ cont = 7; printf("\t\nJogador Venceu!\n\n");updateWins(players, numPlayers, nick); saveRanking(players, numPlayers);}
                                    if( quadrado[2][0] == 'X' && quadrado[2][1] == 'X' && quadrado[2][2] == 'X'){ cont = 7; printf("\t\nJogador Venceu!\n\n");updateWins(players, numPlayers, nick); saveRanking(players, numPlayers);};

                                    // Condção de vitoria 2. vertical 

                                    if( quadrado[0][0] == 'X' && quadrado[1][0] == 'X' && quadrado[2][0] == 'X'){ cont = 7; printf("\t\nJogador Venceu!\n\n");updateWins(players, numPlayers, nick); saveRanking(players, numPlayers);}
                                    if( quadrado[0][2] == 'X' && quadrado[1][2] == 'X' && quadrado[2][2] == 'X'){ cont = 7; printf("\t\nJogador Venceu!\n\n");updateWins(players, numPlayers, nick); saveRanking(players, numPlayers);}
                                    if( quadrado[0][1] == 'X' && quadrado[1][1] == 'X' && quadrado[2][1] == 'X'){ cont = 7; printf("\t\nJogador Venceu!\n\n");updateWins(players, numPlayers, nick); saveRanking(players, numPlayers);}

                                    // Condição de vitoria 3, Diagonal direita

                                if( quadrado[0][0] == 'X' && quadrado[1][1] == 'X' && quadrado[2][2] == 'X'){ cont = 7; printf("\t\nJogador Venceu!\n\n");updateWins(players, numPlayers, nick); saveRanking(players, numPlayers);};
                                if( quadrado[0][2] == 'X' && quadrado[1][1] == 'X' && quadrado[2][0] == 'X'){ cont = 7; printf("\t\nJogador Venceu!\n\n");updateWins(players, numPlayers, nick); saveRanking(players, numPlayers);};                
                                printf(ANSI_COLOR_RESET);

                                }while( cont <= 5);
                                if( cont == 6){
                                    printf(ANSI_COLOR_YELLOW);
                                    printf("\t\nEmpate!\n\n");
                                    printf(ANSI_COLOR_RESET);
                                }
                            else if(dificuldade == 2){
                                zera();
                                desenho1();
                                while (!condicaovitoria('X') && !condicaovitoria('O') && !Empate()) {
                                    if (vez) {
                                    printf(" Digite a linha: ");
                                    scanf("%d", &l);
                                    printf(" Digite o quadrado : ");
                                    scanf("%d", &q);
                                    if (quadrado[l - 1][q - 1] != ' ' ) {
                                    printf("Posicao ocupada. Tente novamente.\n");
                                    continue;
                                    }
                                    } else {
                                    quadrado[l - 1][q - 1] = 'X';
                                        ia();
                                    }
                                    vez = !vez;
                                    desenho1();
                                }
                                desenho1();
                                printf("\tFim do jogo!\n");
                                if (Empate()) {
                                    printf(ANSI_COLOR_YELLOW);
                                    printf("\t\nEmpate!\n\n");
                                    printf(ANSI_COLOR_RESET);
                                } else if (vez) {
                                    printf(ANSI_COLOR_RED);
                                    printf("\tRobo ganhou!\n\n");
                                    printf(ANSI_COLOR_RESET);
                                    updateloss(players, numPlayers, nick); 
                                    saveRanking(players, numPlayers);
                                } else {
                                    printf(ANSI_COLOR_GREEN);
                                    printf("\tJogador ganhou!\n\n");
                                    printf(ANSI_COLOR_RESET);
                                    updateWins(players, numPlayers, nick); 
                                    saveRanking(players, numPlayers);
                                }
                            }
                            opcao5 = 0;
                            }
                        }else if(opcao5 == 2){//voltar o menu
                            printf("\n");
                            printf(ANSI_COLOR_YELLOW);
                            imprimelento(salvo,250);
                            printf(ANSI_COLOR_RESET);
                            printf("\n\n");
                            opcao5 = 1;
                            opcao2 = 1;
                            opcao = 0;
                            break;
                        }else{//invalido
                            printf("\n");
                            printf(ANSI_COLOR_RED);
                            imprimelento(invalida,20);
                            printf(ANSI_COLOR_RESET);
                            printf("\n");
                            opcao5 = 0;
                        }
                    }while(opcao5 == 0);
                }else if(opcao2 == 2){//voltar
                    opcao = 0;
                    opcao2 = 1;
                }else{//invalido
                    printf("\n");
                    printf(ANSI_COLOR_RED);
                    imprimelento(invalida,20);
                    printf(ANSI_COLOR_RESET);
                    printf("\n");
                    opcao2 = 0;
                }
                }while(opcao2 == 0);
        }else if(opcao == 2){//ranking
            imprimecarregando();
            printf("\n");
            imprimecolorido(nomerk,40);
            printf("\n\n");
            printRanking();
            opcao = 0;
        }else if(opcao == 3){//config
            do{
                imprimeconfig();
                setbuf(stdin,NULL);
                scanf("%d",&opcao2);
                if(opcao2 == 1){//dificuldade
                    do{
                        opcao3 = 0;
                        imprimemenudif();
                        setbuf(stdin,NULL);
                        scanf("%d",&opcao4);
                        switch (opcao4)
                        {
                        case 1:
                            dificuldade = 1;
                            printf("\n");
                            printf(ANSI_COLOR_YELLOW);
                            imprimelento(salvo,500);
                            printf(ANSI_COLOR_RESET);
                            printf("\n");
                            opcao3 = 1;
                            break;
                        case 2:
                            dificuldade = 2;
                            printf("\n");
                            printf(ANSI_COLOR_YELLOW);
                            imprimelento(salvo,500);
                            printf(ANSI_COLOR_RESET);
                            printf("\n");
                            opcao3 = 1;
                            break;
                        default:
                            printf("\n");
                            printf(ANSI_COLOR_RED);
                            imprimelento(invalida,30);
                            printf(ANSI_COLOR_RESET);
                            printf("\n");
                            opcao3 = 0;
                            break;  
                        }   
                    }while(opcao3 == 0);
                    opcao2 = 0;
                }else if(opcao2 == 2){//creditos
                    imprimecreditos();
                    opcao2 = 0;
                }else if(opcao2 == 3){//sobre
                    imprimesobre();
                    opcao2 = 0;
                }else if(opcao2 == 4){//voltar
                    opcao2 = 1;
                }else{
                    printf("\n");
                    printf(ANSI_COLOR_RED);
                    imprimelento(invalida,30);
                    printf(ANSI_COLOR_RESET);
                    printf("\n");
                    opcao2 = 0;
                }
            }while(opcao2 == 0);
            opcao = 0;
        }else if(opcao == 4){//sair
            imprimesaindo();
            opcao == 1;
        }else{//invalido
            printf("\n");
            printf(ANSI_COLOR_RED);
            imprimelento(invalida,20);
            printf(ANSI_COLOR_RESET);
            printf("\n");
            opcao = 0;
        }
    }while(opcao == 0);
    return 0;
}

void imprimemenu1(){
    char nome[] = " --- JOGO DA VELHA --- ";
    char start[] = "1 - JOGAR";
    char Ranking[] = "2 - RANKING";
    char config[] = "3 - CONFIGURACOES";
    char Exit[] = "4 - SAIR";
        imprimecolorido(nome,40);
        printf("\n\n");
        printf("     ");
        imprimelento(start,40);
        printf("\n");
        printf("     ");
        imprimelento(Ranking,40);
        printf("\n");
        printf("     ");
        imprimelento(config,40);
        printf("\n");
        printf("     ");
        imprimelento(Exit,40);
        printf("\n\n");
}

void imprimecreditos(){
    char creditos2[] = " --- CREDITOS ---";
    char agrad[] = "Agradecimentos Especiais:\nProf. Me. Claudiney R. Tinoco \ne Prof. Dra. Amanda C. Davi Resende";
    char desenvolvimento[] = "Desenvolvimento:\nLucas Martins:Programador\nLucas Araujo:Programador\nDouglas Miguel:Programador";
    printf("\n");
    imprimecolorido(creditos2,40);
    printf("\n\n");
    imprimelento(desenvolvimento,20);
    printf("\n");
    imprimelento(agrad,20);
    printf("\n");    
}

void imprimecarregando(){
    char carregando[] = "...";
    char carregando2[] = "CARREGANDO";
    printf(ANSI_COLOR_YELLOW);
    printf("\n");
    imprimelento(carregando2,250);
    imprimelento(carregando,500);
    printf(ANSI_COLOR_RESET);
    printf("\n");
}

void imprimesaindo(){
    char Exit2[] = "SAINDO";
    char carregando[] = "...";
    printf("\n");
    printf(ANSI_COLOR_RED);
    imprimelento(Exit2,250);
    imprimelento(carregando,500);
    printf(ANSI_COLOR_RESET);
}

void imprimelento(char *p,int N){
    int i;
    for(i = 0;*(p+i)!='\0';i++){
        printf("%c",*(p+i));
        fflush(stdout);
        Sleep(N);
    }
}

void imprimecolorido(char *p,int N){
    int i;
    for (i = 0; *(p+i) != '\0'; i++){
        switch (i % 6){
        case 0:
            printf(ANSI_COLOR_RED);
            break;
        case 1:
            printf(ANSI_COLOR_GREEN);
            break;
        case 2:
            printf(ANSI_COLOR_YELLOW);
            break;
        case 3:
            printf(ANSI_COLOR_BLUE);
            break;
        case 4:
            printf(ANSI_COLOR_MAGENTA);
            break;
        case 5:
            printf(ANSI_COLOR_CYAN);
            break;
        }
        printf("%c", *(p+i));
        fflush(stdout);
        Sleep(N);
        printf(ANSI_COLOR_RESET);
    }
}

void imprimeconfig(){
    char config[] = " --- CONFIGURACOES ---";
    char dif[] = "1 - DIFICULDADE";
    char credito[] = "2 - CREDITOS";
    char sobre[] = "3 - SOBRE";   
    char voltar[] =  "4 - VOLTAR";
    char digi[] = "Digite uma OPCAO:";
    printf("\n");
    imprimecolorido(config,40);
    printf("\n\n");
    printf("   ");
    imprimelento(dif,20);
    printf("\n");
    printf("   ");
    imprimelento(credito,20);
    printf("\n");
    printf("   ");
    imprimelento(sobre,20);
    printf("\n");
    printf("   ");
    imprimelento(voltar,20);
    printf("\n\n");
    imprimelento(digi,20);
}

void imprimemenudif(){
    char dif[] = " --- DIFICULDADE ---";
    char dif1[] = "1 - FACIL";
    char dif2[] = "2 - NORMAL";
    char digi[] = "Digite uma OPCAO:";
    printf("\n");
    imprimecolorido(dif,40);
    printf("\n\n");
    printf("   ");
    imprimelento(dif1,20);
    printf("\n");
    printf("   ");
    imprimelento(dif2,20);
    printf("\n\n");
    imprimelento(digi,20);
}

void imprimemenujogador(){
    char nome[] = " --- JOGAR ---";
    char jogar[] = "1 - JOGAR ";
    char voltar[] = "2 - VOLTAR";
    char slc[] = "Digite uma OPCAO:";
    printf("\n");
    imprimecolorido(nome,40);
    printf("\n\n");
    printf("  ");
    imprimelento(jogar,20);
    printf("\n");
    printf("  ");
    imprimelento(voltar,20);
    printf("\n\n");
    imprimelento(slc,20);
}

void imprimesobre(){
    char sobre[] = " --- SOBRE ---";
    char nome[] = "Nome do Progama: Game of Old Woman Premium Pro Max Plus";
    char versao[] = "Versao: 1.9";
    char autores[] = "Autores: Lucas Martins, Lucas Araujo, Douglas Miguel";
    char descricao[] = "Descricao:O Jogo da Velha eh um classico jogo de tabuleiro\nque foi desenvolvido por um grupo de alunos da Universidade Federal \nde Uberlandia como parte de um projeto de programacao em linguagem C.\nO objetivo do jogo eh preencher uma grade 3x3 com simbolos \"X\" e \"O\" \nde forma alternada, ate que um dos jogadores consiga formar uma linha reta,\nhorizontal, vertical ou diagonalmente.";
    char data[] = "Data de Lancamento:22/06/2023, 23:99";
    char req[] = "Requisitos de sistema:Ate microondas roda kkk";
    printf("\n");
    imprimecolorido(sobre,40);
    printf("\n\n");
    imprimelento(nome,20);
    printf("\n");
    imprimelento(versao,20);
    printf("\n");
    imprimelento(autores,20);
    printf("\n");
    imprimelento(descricao,20);
    printf("\n");
    imprimelento(data,20);
    printf("\n");
    imprimelento(req,20);
    printf("\n");
}

void saveRanking(Player players[], int numPlayers){
    FILE *file = fopen(RANKING_FILE, "w");
    if(file == NULL){
        printf("Erro ao criar o arquivo do ranking.\n");
        return;
    }
    for(int i = 0; i < numPlayers; i++){
        fprintf(file, "%s,%d,%d\n", players[i].name, players[i].wins, players[i].loss);
    }
    fclose(file);
}

void loadRanking(Player players[], int *numPlayers){
    FILE *file = fopen(RANKING_FILE, "r");
    if (file == NULL) {
        *numPlayers = 0;
        return;
    }
    *numPlayers = 0;
    char line[100];
    while(fgets(line, sizeof(line), file) != NULL){
        char *name = strtok(line, ",");
        int wins = atoi(strtok(NULL, ","));
        int loss = atoi(strtok(NULL, ","));
        strncpy(players[*numPlayers].name, name, max_nome);
        players[*numPlayers].wins = wins;
        players[*numPlayers].loss = loss;
        (*numPlayers)++;
    }
    fclose(file);
}

void printRanking(){
    FILE *file = fopen(RANKING_FILE, "r");
    char line[100];
    if(file == NULL){
        printf("O arquivo do ranking nao existe.\n");
        return;
    }
    while(fgets(line, sizeof(line), file) != NULL){
        char *name = strtok(line, ",");
        int wins = atoi(strtok(NULL, ","));
        int loss = atoi(strtok(NULL, ","));
        printf("Jogador: %s\n", name);
        printf("Vitorias: %d\n", wins);
        printf("Derrotas: %d\n", loss);
        printf("--------------------\n");
    }
    fclose(file);
}

void addPlayer(Player players[], int *numPlayers, char *name){
    if (*numPlayers >= MAX_PLAYERS) {
        printf("O limite de jogadores foi atingido.\n");
        return;
    }
    name[strcspn(name, "\n")] = '\0';
    strncpy(players[*numPlayers].name, name, max_nome);
    players[*numPlayers].wins = 0;
    players[*numPlayers].loss = 0;
    (*numPlayers)++;
}

void updateWins(Player players[], int numPlayers, char *name){
    for (int i = 0; i < numPlayers; i++) {
        if (strcmp(players[i].name, name) == 0) {
            players[i].wins++;
            break;
        }
    }
}

void updateloss(Player players[], int numPlayers, char *name){
    for (int i = 0; i < numPlayers; i++) {
        if (strcmp(players[i].name, name) == 0) {
            players[i].loss++;
            break;
        }
    }
}

void desenho( char quadrado[3][3] ){

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

void zera() {
    for (int i = 0; i < 3; i++) { // reseta e adciona ' ';
        for (int j = 0; j < 3; j++) {
            quadrado[i][j] = ' ';
        }
    }
}

void desenho1() {

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
