
#include <stdio.h>

#include <stdlib.h>

#include <time.h>

#define Dim 10



char  posL, posC;

int l, c, plac, cont, acertos;

l = 0;

c = 0;

plac = 25;

cont = 0;

acertos = 0;

char tabuleiro[Dim][Dim];



void gerarTabuleiro(){

    for(int i = 0; i < Dim; i++){

        for(int j = 0; j < Dim; j++){

            tabuleiro[i][j] = ' ';

        }

    }

}



void imprimirTabuleiro(){

    int letra = 65;

    system("cls"); // Faz o 'Refresh' do tabuleiro

    printf("\t\t\t\t\tBATALHA NAVAL\t\t\t\t");

    printf("Chances: %d\n\n", plac - cont);

    printf("\t\tA\tB\tC\tD\tE\tF\tG\tH\tI\tJ\n\n");

    for(int i = 0; i < Dim; i++){

        printf("\t%c", letra);

        for(int j = 0; j < Dim; j++){

            if(tabuleiro[i][j] == ' ' || tabuleiro[i][j] == 'W'){

                printf("\t#");

            }

            if(tabuleiro[i][j] == '0'){

                printf("\tO");

            }

            if(tabuleiro[i][j] == '1'){

                printf("\tX");

            }

        }

        printf("\n\n");

        letra++;

    }

}



void posicionarNavios(){

    int x, y, z;

    x = 0;

    y = 0;

    z = 0;

    srand(time(NULL));

    // Gera os navios de uma posição

    while(x < 5){

        y = rand()%9;

        z = rand()%9;

        if(tabuleiro[y][z] == ' '){

            tabuleiro[y][z] = 'W';

            x++;

        }

    }

    x = 0;

    // Gera o navio de duas posições

    while(x != -1){

        y = rand()%9;

        z = rand()%8;

        if(tabuleiro[y][z] == ' ' && tabuleiro[y][z+1] == ' '){

            tabuleiro[y][z] = 'W';

            tabuleiro[y][z+1] = 'W';

            x = -1;

        }

    }

    x = 0;

    // Gera os navios de três posições

    while(x < 2){

        y = rand()%9;

        z = rand()%7;

        if(tabuleiro[y][z] == ' ' && tabuleiro[y][z+1] == ' ' && tabuleiro[y][z+2] == ' '){

            tabuleiro[y][z] = 'W';

            tabuleiro[y][z+1] = 'W';

            tabuleiro[y][z+2] = 'W';

            x++;

        }

    }

    x = 0;

    // Gera o navio de quatro posições

    while(x != -1){

        y = 1+(rand()%9);

        z = rand()%8;

        if(tabuleiro[y][z] == ' ' && tabuleiro[y][z+1] == ' ' && tabuleiro[y-1][z] == ' ' && tabuleiro[y-1][z+1] == ' '){

            tabuleiro[y][z] = 'W';

            tabuleiro[y][z+1] = 'W';

            tabuleiro[y-1][z] = 'W';

            tabuleiro[y-1][z+1] = 'W';

            x = -1;

        }

    }

}



void posicaoLinha(){

    printf("Insira a posicao da linha: ");

    scanf("%c", &posL);

    fflush(stdin);

    posL = toupper(posL); // Transforma as letras em maiúsculas

    switch(posL){

        case('A'):

            l = 0;

            posicaoColuna();

            break;

        case('B'):

            l = 1;

            posicaoColuna();

            break;

        case('C'):

            l = 2;

            posicaoColuna();

            break;

        case('D'):

            l = 3;

            posicaoColuna();

            break;

        case('E'):

            l = 4;

            posicaoColuna();

            break;

        case('F'):

            l = 5;

            posicaoColuna();

            break;

        case('G'):

            l = 6;

            posicaoColuna();

            break;

        case('H'):

            l = 7;

            posicaoColuna();

            break;

        case('I'):

            l = 8;

            posicaoColuna();

            break;

        case('J'):

            l = 9;

            posicaoColuna();

            break;

        default:

            printf("Essa posicao nao existe! Digite uma posicao valida!\n");

            posicaoLinha();

            break;

    }

}



void posicaoColuna(){

    printf("Insira a posicao da coluna: ");

    scanf("%c", &posC);

    fflush(stdin);

    posC = toupper(posC); // Transforma as letras em maiúsculas

    switch(posC){

        case('A'):

            c = 0;

            break;

        case('B'):

            c = 1;

            break;

        case('C'):

            c = 2;

            break;

        case('D'):

            c = 3;

            break;

        case('E'):

            c = 4;

            break;

        case('F'):

            c = 5;

            break;

        case('G'):

            c = 6;

            break;

        case('H'):

            c = 7;

            break;

        case('I'):

            c = 8;

            break;

        case('J'):

            c = 9;

            break;

        default:

            printf("Essa posicao nao existe! Digite uma posicao valida!\n");

            posicaoColuna();

            break;

    }

}



int verificarJogada(){

    int resul = 0;

    if(tabuleiro[l][c] == 'W'){

        tabuleiro[l][c] = '1';

        resul = 1;

        acertos++;

    }else{

        tabuleiro[l][c] = '0';

        resul = 0;

    }

    return resul;

}



int main()

{

    char continuar = 'c';

    gerarTabuleiro();

    posicionarNavios();

    do{

        system("cls"); // Faz o 'Refresh' da tela

        if(continuar == 'C' || continuar == 'c'){

            imprimirTabuleiro();

            posicaoLinha();

            cont++;



            if(verificarJogada() == 1){

                imprimirTabuleiro();

                printf("Voce acertou um navio nas coodernadas (%d,%d)!\n", l, c);

                printf("Digite 'c' para continuar ou outra tecla para sair: ");

                scanf("%c", &continuar);

                fflush(stdin);

            }else{

                imprimirTabuleiro();

                printf("Tiro na agua!\nDigite 'c' para continuar ou outra tecla para sair: ");

                scanf("%c", &continuar);

                fflush(stdin);

            }

            if(acertos == 17){

                printf("Parabens!!! Voce acertou todos os navios!");

                continuar = '0';

            }

            if(cont == 26){

                printf("Voce atingiu o numero maximo de jogadas!");

            }

        }else{

            printf("Jogo interrompido!");

            cont = 26;

        }

    }while(cont <= 25);

    return 0;

}
