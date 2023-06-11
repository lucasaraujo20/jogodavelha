#include<stdio.h>
#include<string.h>
#include<windows.h> //sleep
#define ANSI_COLOR_RED     "\x1b[31m"//coloca cor nos textos
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m" //cor padrao

//Esboço do designe do jogo da velha (menu)

struct dados{
    char nome[30];
    char senha[10];
    int vitoria;
    int derrota;
    int pontuacao;
};

void imprimemenu1();
void imprimeconfig();
void imprimerank(struct dados *p,int n);
void imprimemenudif();
void imprimesobre();
void imprimemenujogador();
void imprimecarregando();
void imprimecreditos();
void imprimesaindo();
void imprimelento(char *p,int N);
void imprimecolorido(char *p,int N);

int main() {
    char mat[3][3];
    char cac1,cac2;
    int compara1,compara2;
    struct dados usuario[20] = {
        {"Jorginho\n","0000\n",15,9,36},
        {"GiuseppeKadura\n","1234\n",20,10,50},
        {"Lucas1\n","2345\n",8,10,14}
        };
    char erro[] = "Nome ou senha invalidos!\nDigite novamente!";
    char erro2[] = "Nome ja existente no banco de dados!\nDigite novamente!";
    char digi[] = "Digite uma OPCAO:";
    char invalida[] = "OPCAO INVALIDA";
    char salvo[] = "SALVANDO...";
    char nome[] = "Digite o nome:";
    char nomerk[] = " --- RANKING ---";
    char senha[] = "Digite a senha:";
    int i,j = 3,opcao,opcao2,opcao3,opcao4,dificulade = 1;
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
                if(opcao2==1){
                    do{
                        printf("\n");
                        imprimelento(nome,20);
                        setbuf(stdin,NULL);
                        fgets(usuario[j].nome,30,stdin);
                        imprimelento(senha,20);
                        setbuf(stdin,NULL);
                        fgets(usuario[j].senha,10,stdin);
                        printf(ANSI_COLOR_YELLOW);
                        imprimecarregando();
                        printf(ANSI_COLOR_RESET);
                        for(i = 0;i < j; i++){
                            if(strcmp(usuario[j].nome,usuario[i].nome) == 0){
                                printf(ANSI_COLOR_RED);
                                imprimelento(erro2,20);
                                printf(ANSI_COLOR_RESET);
                                compara1 = 0;
                                break;
                            }else{
                                j++;
                                compara1 = 1;
                                break;
                            }
                        }
                    }while(compara1 == 0);
                }else if(opcao2 == 2){
                    do{
                        printf("\n");
                        imprimelento(nome,20);
                        setbuf(stdin,NULL);
                        fgets(usuario[j].nome,30,stdin);
                        imprimelento(senha,20);
                        setbuf(stdin,NULL);
                        fgets(usuario[j].senha,10,stdin);
                        printf(ANSI_COLOR_YELLOW);
                        imprimecarregando();
                        printf(ANSI_COLOR_RESET);
                        for(i = 0;i < j; i++){
                            if(strcmp(usuario[j].nome,usuario[i].nome) == 0 && strcmp(usuario[j].senha,usuario[i].senha) == 0){
                                //funcionamento do jogo
                                j++;
                                break;
                                exit(1);
                            }else{
                                printf(ANSI_COLOR_RED);
                                imprimelento(erro,20);
                                printf(ANSI_COLOR_RESET);
                                break;
                            }
                        }
                    }while(compara2 != 0 && compara2 != 0);
                }else if(opcao2==3){
                    opcao = 0;
                    opcao2 = 1;
                }else{
                    printf("\n");
                    printf(ANSI_COLOR_RED);
                    imprimelento(invalida,20);
                    printf(ANSI_COLOR_RESET);
                    printf("\n");
                    opcao2 = 0;
                }
                }while(opcao2==0);
        }else if(opcao == 2){//ranking
            imprimecarregando();
            imprimecolorido(nomerk,40);
            printf("\n\n");
            imprimerank(usuario,j);
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
                            dificulade = 1;
                            printf("\n");
                            printf(ANSI_COLOR_YELLOW);
                            imprimelento(salvo,500);
                            printf(ANSI_COLOR_RESET);
                            printf("\n");
                            opcao3 = 1;
                            break;
                        case 2:
                            dificulade = 2;
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
            opcao == 0;
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
    printf("\n");
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
    printf("\n\n");
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
    char cria[] = "1 - CRIAR CONTA";
    char entrar[] = "2 - ENTRAR EM UMA CONTA";
    char voltar[] = "3 - VOLTAR";
    char slc[] = "Digite uma OPCAO:";
    printf("\n");
    imprimecolorido(nome,40);
    printf("\n\n");
    printf("  ");
    imprimelento(cria,20);
    printf("\n");
    printf("  ");
    imprimelento(entrar,20);
    printf("\n");
    printf("  ");
    imprimelento(voltar,20);
    printf("\n\n");
    imprimelento(slc,20);
}

void imprimesobre(){
    char sobre[] = " --- SOBRE ---";
    char nome[] = "Nome do Progama: ";
    char versao[] = "Versao: 0.6";
    char autores[] = "Autores: Lucas Martins, Lucas Araujo, Douglas Miguel";
    char descricao[] = "Descricao:";
    char data[] = "Data de Lancamento:";
    char req[] = "Requisitos de sistema:";
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

void imprimerank(struct dados *p,int n){
    char ponto[] = "PONTUACAO:";
    char win[] = "VITORIAS:";
    char lose[] = "DERROTAS:";
    for(int i = 0;i < n;i++){
        imprimelento(p[i].nome,20);
        printf(ANSI_COLOR_YELLOW);
        imprimelento(ponto,20);
        printf(ANSI_COLOR_RESET);
        printf("%d\n",p[i].pontuacao,20);
        printf(ANSI_COLOR_GREEN);
        imprimelento(win,20);
        printf(ANSI_COLOR_RESET);
        printf("%d\n",p[i].vitoria,20);
        printf(ANSI_COLOR_RED);
        imprimelento(lose,20);
        printf(ANSI_COLOR_RESET);
        printf("%d",p[i].derrota,20);
        printf(ANSI_COLOR_RESET);
        printf("\n\n");
    }  
}
