#include <stdio.h>
#include <stdlib.h> 
#include <locale.h>
#include <time.h>

void inicializarTabuleiroJ(char tabuleiro[10][10]){
    int i, j;

    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            tabuleiro[i][j]= ' ';
        }
    }
}

void inicializarTabuleiroC(char tabuleiro[10][10]){
    int i, j;

    for (i=0;i<10;i++){
        for(j=0;j<10;j++){
            tabuleiro[i][j]= ' ';
        }
    }
}

void inicializarTabuleiroAlvoJ(char tabuleiro[10][10]){
    int i, j;

    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            tabuleiro[i][j]= ' ';
        }
    }
}

void inicializarTabuleiroAlvoC( char tabuleiro[10][10]){
    int i, j;

    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            tabuleiro[i][j]= ' ';
        }
    }
}

void imprimirTabuleiro(char tabuleiro[10][10]){
    int i, j;

    printf("\n");
    printf("   1   2   3   4   5   6   7   8   9   10\n");

    for(i=0;i<10;i++){
        printf("%d   ", i+1);
        for(j=0;j<10;j++){
            printf("%c", tabuleiro[i][j]);
            if(j<9){
                printf(" | ");
            }
        }
        printf("  ---+---+---+---+---+---+---+---+---+---\n");
    }
    printf("\n");
}

void escolherLocusNavio (char tabuleiro[10][10], int tamanhoNavio, char simboloNavio){

}

void selecionarCampoInimigo(char tabuleiro[10][10], int *linha, int *coluna){
    printf("Digite a linha e a coluna que deseja bombardear! (1-10): ");
    scanf("%d %d", linha, coluna);
    (*linha)--;
    (*coluna)--;
    if(*linha<0 || *linha>9 || *coluna<0 || *coluna>9){
        printf("Posição inválida! Digite novamente!\n");
        return selecionarCampoInimigo(tabuleiro, linha, coluna);
    }
}

void selecionarCampoJogador (char tabuleiro[10][10], int *linha, int *coluna){
    *linha = rand()%10;
    *coluna = rand()%10;
    if(*linha<0 || *linha>9 || *coluna<0 || *coluna>9){
        return selecionarCampoJogador(tabuleiro, linha, coluna);
    }
}

int main(){

    setlocale(LC_ALL, "pt_BR.UTF-8");
    srand(time(NULL));

    char tabuleiroJ[10][10], tabuleiroC[10][10], tabuleiroAlvoJ[10][10], tabuleiroAlvoC[10][10];
    int linha, coluna;
    int jogarNovamente, jogoTerminou;

    printf("--------------------------------------------------\n");
    printf("         Bem-vindo ao jogo Batalha Naval!         \n");
    printf("--------------------------------------------------\n");
    printf("Nessa versão de batalha naval, você jogará contra o computador, que terá um navio de 3 posições e outro de 2 posições.\n");

    do{
        inicializarTabuleiroJ(tabuleiroJ);
        inicializarTabuleiroC(tabuleiroC);
        inicializarTabuleiroAlvoJ(tabuleiroAlvoJ);
        inicializarTabuleiroAlvoC(tabuleiroAlvoC);

    }while(jogarNovamente==1);
}