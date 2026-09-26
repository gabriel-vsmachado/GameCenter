#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*A função inicializarMatriz simplesmente cria a matriz 3x3 e a preenche com '-' para identificar os espaços do jogo que não foram escolhidos por nenhum jogador.
Além disso, a fução não retorna nenhum valor, por isso void.*/
void inicializarMatriz(char matriz[3][3]){

    int i, j;

    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            matriz[i][j]='-';
        }
    }
}

/*A função imprimirMatriz, quando chamada, irá imprimir a matriz salva a partir das escolhas dos jogadores, exibindo a formatação correta dela, com linhas, colunas e a grade do jogo.
Além disso, a função não retorna nenhum valor, por isso void.*/
void imprimirMatriz(char matriz[3][3]){

    int i, j;

    printf("\n");
    printf("   1   2   3\n");

    for(i=0;i<3;i++){
        printf("%d  ", i+1);
        for(j=0;j<3;j++){
            printf("%c", matriz[i][j]);
            if(j<2){
                printf(" | ");
            }
        }
        printf("\n");
        if(i<2){
            printf("  ---+---+---\n");
        }
    }
    printf("\n");
}

/*A função verificarVencedor, quando chamada, utiliza de condições e estruturas de decisão para poder comparar as entradas da matriz, linha por linha, coluna por coluna, diagonal principal
e secundária para verificar se os valores se adequam a alguma condição de vitória. A função é char, pois retorna '-' caso ninguem tenha ganhado ou retorna o caractere X ou O correspondente
ao jogador que obteve a condição de vitória.*/
char verificarVencedor(char matriz[3][3]){

    int i, j;

    for(i=0;i<3;i++){
        if(matriz[i][0]==matriz[i][1]&&matriz[i][1]==matriz[i][2]&&matriz[i][0]!='-'){
        return matriz[i][0];
    }

    for(j=0;j<3;j++){
        if(matriz[0][j]==matriz[1][j]&&matriz[1][j]==matriz[2][j]&&matriz[0][j]!='-'){
            return matriz[0][j];
        }
    }

    if(matriz[0][0]==matriz[1][1]&&matriz[1][1]==matriz[2][2]&&matriz[0][0]!='-'){
        return matriz[0][0];
    }

    if(matriz[0][2]==matriz[1][1]&&matriz[1][1]==matriz[2][0]&&matriz[0][2]!='-'){
        return matriz[0][2];
    }

    return '-';
    }
}

/*A função verificarEmpate, quando chamada, verifica se o tabuleiro do jogo está preenchido e ninguém atende à condição de vitória. A fun��o � int, pois
retorna um valor numérico (1 para empate e 0 para não empate).*/
int verificarEmpate(char matriz[3][3]){

    int i, j;

    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(matriz[i][j]=='-'){
                return 0;
            }
        }
    }

    return 1;
}

int main(){

    setlocale (LC_ALL,"pt_BR.UTF-8");

    char matriz[3][3];
    char jogador, vencedor;
    int linha, coluna;
    int jogoTerminou, jogarNovamente;

    printf("------------------------------------------\n");
    printf("         BEM-VINDOS AO JOGO DA VELHA!     \n");
    printf("------------------------------------------\n");
    printf("Especificações: \n");
    printf("1- Definam previamente antes de cada rodada quem será o jogador X e quem será o jogador O.\n");
    printf("2- O jogador X sempre começará a partida.\n\n");

    do{
        inicializarMatriz(matriz);
        jogador = 'X';
        jogoTerminou = 0;

        while(jogoTerminou==0){
            imprimirMatriz(matriz);

            printf("Vez do jogador %c!\n", jogador);

            do{
                printf("Escolha uma linha de 1 a 3: ");
                scanf("%d", &linha);
                printf("Escolha uma coluna de 1 a 3: ");
                scanf("%d", &coluna);
                linha--;
                coluna--;

                if(linha<0||linha>2||coluna<0||coluna>2){
                    printf("\nEssa escolha é inválida!! Escolha apenas posições de 1 a 3!\n\n");
                }
                else if(matriz[linha][coluna]!='-'){
                    printf("\nEssa posição já está ocupada!!\n\n");
                }
            }while(linha<0||linha>2||coluna<0||coluna>2||matriz[linha][coluna]!='-');

            matriz[linha][coluna] = jogador;
            vencedor = verificarVencedor(matriz);

            if(vencedor!='-'){
                imprimirMatriz(matriz);

                printf("------------------------------------------\n");
                printf("      O JOGADOR %c VENCEU!! PARABÉNS!!    \n", jogador);
                printf("------------------------------------------\n");

                jogoTerminou = 1;
            }
            else if(verificarEmpate(matriz)==1){
                    imprimirMatriz(matriz);

                    printf("------------------------------------------\n");
                    printf("              DEU VELHA!!!!!!!            \n");
                    printf("------------------------------------------\n");

                    jogoTerminou = 1;
            }
            else{
                if(jogador=='X'){
                    jogador = 'O';
                }
                else{
                    jogador = 'X';
                }
            }
        }
        do{
            printf("\nDeseja jogar novamente?\n");
            printf("1- Jogar novamente\n");
            printf("2- Sair\n");
            printf("Escolha uma opção: ");
            scanf("%d", &jogarNovamente);

            if(jogarNovamente!=1&&jogarNovamente!=2){
                printf("\nEssa opção é inválida! Por favor, escolha 1 ou 2.");
            }
        }while(jogarNovamente!=1&&jogarNovamente!=2);
    }while(jogarNovamente==1);

    return 0;
}