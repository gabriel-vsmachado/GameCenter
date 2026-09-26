#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

/* A função inicializarTabuleiro inicializa a matriz visível com '?' que serão substituídas pelos símbolos
da matriz oculta conforme a escolha do usuário.*/
void inicializarTabuleiro(char visivel[4][4]){

    int i, j;

    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            visivel[i][j]='?';
        }
    }
}

/* A função embaralharTabuleiro embaralha os símbolos que ficaram ocultos em uma outra matriz e que serão
revelados apenas após as escolhas do usuário.*/
void embaralharTabuleiro (char matriz[4][4], char simbolos[]){

    int i, j;
    int linha, coluna;

    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            matriz[i][j]=' ';
        }
    }

    for(i=0;i<8;i++){
        do{
            linha=rand() % 4;
            coluna=rand() % 4;
        }while(matriz[linha][coluna]!=' ');

        matriz[linha][coluna]=simbolos[i];

        do{
            linha=rand() % 4;
            coluna=rand() % 4;
        }while(matriz[linha][coluna]!=' ');

        matriz[linha][coluna]=simbolos[i];
    }
}

/* A função imprimirTabuleiro apenas imprime o tabuleiro visível que será alterado conforme as escolhas
do usuário e da análise de pares. Nessa função, o tabuleiro também é impresso formatado para simular uma
interface gráfica.*/
void imprimirTabuleiro (char visivel[4][4]){

    int i, j;

    printf("\n");
    printf("   1   2   3   4\n");

    for(i=0;i<4;i++){
        printf("%d  ", i+1);
        for(j=0;j<4;j++){
            printf("%c", visivel[i][j]);
            if(j<3){
                printf(" | ");
            }
        }
        printf("\n");
        if(i<3){
            printf(" ---+---+---+---\n");
        }
    }
    printf("\n");
}

/* Essa função permite que o usuário selecione a primeira carta que deseja e faz a verificação
da validade da escolha.Lembrete: deixar o código mais eficiente!!*/
char selecionarLocus1 (char visivel[4][4], char matriz[4][4]){

    int linha, coluna;
    int i, j;

    printf("Escolha a linha e a coluna da primeira carta (1-4): ");
    scanf("%d %d", &linha, &coluna);
    if(linha<1 || linha>4 || coluna<1 || coluna>4){
        printf("Posição inválida! Escolha novamente.\n");
        return selecionarLocus1(visivel, matriz);
    }
     if(visivel[linha-1][coluna-1] != '?'){
        printf("Essa carta já foi revelada! Escolha outra.\n");
        return selecionarLocus1(visivel, matriz);
    }
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(linha-1==i && coluna-1==j){
                if(visivel[i][j]=='?'){
                    visivel[i][j]=matriz[i][j];
                    return matriz[i][j];
                }
            }
        }
    }
}

/* Essa função permite que o usuário selecione a segunda carta que deseja e faz a verificação
da validade da escolha.Lembrete: deixar o código mais eficiente!!*/
char selecionarLocus2 (char visivel[4][4], char matriz[4][4]){

    int linha, coluna;
    int i, j;

    printf("Escolha a linha e a coluna da segunda carta (1-4): ");
    scanf("%d %d", &linha, &coluna);
    if(linha<1 || linha>4 || coluna<1 || coluna>4){
        printf("Posição inválida! Escolha novamente.\n");
        return selecionarLocus2(visivel, matriz);
    }
     if(visivel[linha-1][coluna-1] != '?'){
        printf("Essa carta já foi revelada! Escolha outra.\n");
        return selecionarLocus2(visivel, matriz);
    }
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(linha-1==i && coluna-1==j){
                if(visivel[i][j]=='?'){
                    visivel[i][j]=matriz[i][j];
                    return matriz[i][j];
                }
            }
        }
    }
    
}

/* Essa função verifica se as duas cartas selecionadas formam um par.*/
char verificarPar (char visivel[4][4], char matriz[4][4], char carta1, char carta2){

    int i, j;

    if(carta1==carta2){
        printf("Par encontrado!\n");
        return 1;
    }
    else{
        printf("Não é um par!\n");
        for(i=0;i<4;i++){
            for(j=0;j<4;j++){
                if(visivel[i][j]==carta1 || visivel[i][j]==carta2){
                    visivel[i][j]='?';
                }
            }
        }
        return 0;
    }
}

/* Essa função verifica se o jogador venceu o jogo, ou seja, se todas as cartas foram reveladas. */
int verificarVitoria (char visivel[4][4]){

    int i, j;

    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(visivel[i][j]=='?'){
                return 0;
            }
        }
    }
    return 1;
}

int main(){

    setlocale(LC_ALL, "pt_BR.UTF-8");
    srand(time(NULL));

    char visivel[4][4];
    char matriz[4][4];
    char simbolos[]={'!','@','#','$','%','&','*','G'};
    int jogadas;
    int linha, coluna;
    char carta1, carta2;
    int jogoTerminou;
    int jogarNovamente;

    printf("----------------------------------------\n");
    printf("      BEM-VINDO AO JOGO DA MEMÓRIA!!    \n");
    printf("----------------------------------------\n");

    do{
        jogadas=0;
        jogoTerminou=0;
        inicializarTabuleiro(visivel); 
        embaralharTabuleiro(matriz, simbolos);
        
        while(jogoTerminou==0){
            imprimirTabuleiro(visivel);
        
            carta1=selecionarLocus1(visivel, matriz);
            imprimirTabuleiro(visivel);
            carta2=selecionarLocus2(visivel, matriz);
            imprimirTabuleiro(visivel);
            verificarPar(visivel, matriz, carta1, carta2);
            jogoTerminou=verificarVitoria(visivel);
            jogadas++;
        }

        if(jogoTerminou==1){
            printf("\n--------------------------------------------------\n");
            printf("   Parabéns! Você concluiu o jogo em %d jogadas!\n", jogadas);
            printf("--------------------------------------------------\n");
        }

        do{
            printf("Deseja jogar novamente?\n");
            printf("1- Jogar novamente\n");
            printf("2- Sair\n");
            printf("Escolha uma opção: ");
            scanf("%d", &jogarNovamente);

            if(jogarNovamente != 1 && jogarNovamente != 2){
                printf("Opção inválida! Escolha 1 ou 2.\n");
            }

        }while(jogarNovamente!=1 && jogarNovamente!=2);

    }while(jogarNovamente==1);

    printf("\nObrigado por jogar! Até a próxima!\n");

    return 0;
}