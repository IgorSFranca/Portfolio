/*
 * Nome do arquivo: jogo_da_forca.c
 * Descrição: Jogo info-juvenil da foca, onde o usuário tenta adivinhar a palavra escondida. A cada tentativa errada, o usuário
 * perde um ponto de vida.
 * Autor: Igor França
 * Datas:
 *      Criação: 22 de julho de 2023;
 *      Modularização: 11 de agosto 2023;
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h> //Biblioteca para manipulação de strings
#include <ctype.h>  //Colocas as letras todas em minúsculas
#include <windows.h> //Utilização do sleep

// protótipos
void cabecalho();
void menu_inicial();
int opcao_inicial(int);
void animacao(int);
void musica_abertura();
void musica_vitoria();
void musica_perdedor();
void criar_palavra(char palavra_misteriosa[]);
void imprimir_certas(char letras_certas[], int);
void imprimir_tentativas(char letras_tentadas[], int);
void verifica_fim(int, int);
void capta_letra(char letra[]);
void verifica_letra(int *, int, char palavra_misteriosa[], char letras_certas[], char letra[], int *vitoria, int posicao, char letras_tentadas[]);
void imprime_tentativas_restantes(int);

int main()
{
    // declaração de variáveis
    char palavra_misteriosa[100] = {"camiseta"};
    char letra[1];
    char letras_certas[strlen(palavra_misteriosa)];
    char letras_tentadas[30];
    memset(letras_certas, '_', strlen(palavra_misteriosa));
    int max = strlen(palavra_misteriosa);
    int chances = 6;
    int vitoria = 0;
    int posicao = 0;
    int opcao;
    char resp;

    // execução do jogo
    menu_inicial();
    musica_abertura();
    system("cls");
    menu_inicial();
    opcao = opcao_inicial(opcao);
    system ("cls");
    switch (opcao){
        case 1:
            do
            {
                animacao(chances);
                imprime_tentativas_restantes(chances);
                imprimir_certas(letras_certas, max);
                imprimir_tentativas(letras_tentadas, posicao);
                capta_letra(letra);
                system("cls");
                verifica_letra(&chances, max, palavra_misteriosa, letras_certas, letra, &vitoria, posicao, letras_tentadas);
                posicao++; // Posicionamento da letra na exibição das tentativas
                if (vitoria+1 == max) // Condição para dar um Break caso o usuário acerte a palavra antes de finalizar as tentativas
                    break;
            } while (chances != 0);
            animacao(chances);
            verifica_fim(vitoria, max);
            break;
            case 2: break;
    }
    system("pause");
    return 0;
}

// procedimentos e funções
void cabecalho(){
    printf("============================\n");
    printf("           ~~*~~            \n");
    printf("    ~# JOGO DA FORCA #~     \n");
    printf("           ~~*~~            \n");
    printf("============================\n\n");
}

void menu_inicial(){
    cabecalho();
    printf(" [1] Start                  \n");
    printf(" [2] Exit                   \n");
    printf("                            \n");
    printf("============================\n\n");
}

int opcao_inicial(int opcao){
    printf("Choice: ");
    scanf("%i", &opcao);
    return opcao;
}

void animacao(int chances){
    int i;
    if (chances == 0){
        char corda[5] = {'|', '/', '|', '\\', '|'};
        char cabeca[5][5] = {" o", "o", " o", "  o", " o"};
        char tronco[5][6] = {" /|\\", "/|\\", " /|\\", "  /|\\", " /|\\"};
        char pernas[5][6] = {" / \\", "/ \\", " / \\", "  / \\", " / \\"};
        for (i=0; i<5; i++){
            cabecalho();
            printf("  ==================        \n");
            printf("  ||//             %c       \n", corda[i]);
            printf("  ||/             %s        \n", cabeca[i]);
            printf("  ||             %s         \n", tronco[i]);
            printf("  ||             %s         \n", pernas[i]);
            printf("  ||                        \n");
            printf("  -------------------       \n");
            Sleep(100);
            system ("cls");
        }
        cabecalho();
        printf("  ==================        \n");
        printf("  ||//             |        \n");
        printf("  ||/              o        \n");
        printf("  ||              /|\\      \n");
        printf("  ||              / \\      \n");
        printf("  ||                        \n");
        printf("  -------------------       \n");
    }
    if (chances == 1){
        char corda[5] = {'|', '/', '|', '\\', '|'};
        char cabeca[5][5] = {" o", "o", " o", "  o", " o"};
        char tronco[5][6] = {" /|\\", "/|\\", " /|\\", "  /|\\", " /|\\"};
        char pernas[5][6] = {" / ", "/ ", " / ", "  / ", " / "};
        for (i=0; i<5; i++){
            cabecalho();
            printf("  ==================        \n");
            printf("  ||//             %c       \n", corda[i]);
            printf("  ||/             %s        \n", cabeca[i]);
            printf("  ||             %s         \n", tronco[i]);
            printf("  ||             %s         \n", pernas[i]);
            printf("  ||                        \n");
            printf("  -------------------       \n");
            Sleep(100);
            system ("cls");
        }
        cabecalho();
        printf("  ==================        \n");
        printf("  ||//             |        \n");
        printf("  ||/              o        \n");
        printf("  ||              /|\\      \n");
        printf("  ||              /         \n");
        printf("  ||                        \n");
        printf("  -------------------       \n");
    }
    if (chances == 2){
        char corda[5] = {'|', '/', '|', '\\', '|'};
        char cabeca[5][5] = {" o", "o", " o", "  o", " o"};
        char tronco[5][6] = {" /|\\", "/|\\", " /|\\", "  /|\\", " /|\\"};
        for (i=0; i<5; i++){
            cabecalho();
            printf("  ==================        \n");
            printf("  ||//             %c       \n", corda[i]);
            printf("  ||/             %s        \n", cabeca[i]);
            printf("  ||             %s         \n", tronco[i]);
            printf("  ||                        \n");
            printf("  ||                        \n");
            printf("  -------------------       \n");
            Sleep(100);
            system ("cls");
        }
        cabecalho();
        printf("  ==================        \n");
        printf("  ||//             |        \n");
        printf("  ||/              o        \n");
        printf("  ||              /|\\      \n");
        printf("  ||                        \n");
        printf("  ||                        \n");
        printf("  -------------------       \n");
    }
    if (chances == 3){
        char corda[5] = {'|', '/', '|', '\\', '|'};
        char cabeca[5][5] = {" o", "o", " o", "  o", " o"};
        char tronco[5][6] = {" /|", "/|", " /|", "  /|", " /|"};
        for (i=0; i<5; i++){
            cabecalho();
            printf("  ==================        \n");
            printf("  ||//             %c       \n", corda[i]);
            printf("  ||/             %s        \n", cabeca[i]);
            printf("  ||             %s         \n", tronco[i]);
            printf("  ||                        \n");
            printf("  ||                        \n");
            printf("  -------------------       \n");
            Sleep(100);
            system ("cls");
        }
        cabecalho();
        printf("  ==================        \n");
        printf("  ||//             |        \n");
        printf("  ||/              o        \n");
        printf("  ||              /|        \n");
        printf("  ||                        \n");
        printf("  ||                        \n");
        printf("  -------------------       \n");
    }
    if (chances == 4){
        char corda[5] = {'|', '/', '|', '\\', '|'};
        char cabeca[5][5] = {" o", "o", " o", "  o", " o"};
        char tronco[5][6] = {" /", "/", " /", "  /", " /"};
        for (i=0; i<5; i++){
            cabecalho();
            printf("  ==================        \n");
            printf("  ||//             %c       \n", corda[i]);
            printf("  ||/             %s        \n", cabeca[i]);
            printf("  ||             %s         \n", tronco[i]);
            printf("  ||                        \n");
            printf("  ||                        \n");
            printf("  -------------------       \n");
            Sleep(100);
            system ("cls");
        }
        cabecalho();
        printf("  ==================        \n");
        printf("  ||//             |        \n");
        printf("  ||/              o        \n");
        printf("  ||              /         \n");
        printf("  ||                        \n");
        printf("  ||                        \n");
        printf("  -------------------       \n");
    }
    if (chances == 5){
        char corda[5] = {'|', '/', '|', '\\', '|'};
        char cabeca[5][5] = {" o", "o", " o", "  o", " o"};
        for (i=0; i<5; i++){
            cabecalho();
            printf("  ==================        \n");
            printf("  ||//             %c       \n", corda[i]);
            printf("  ||/             %s        \n", cabeca[i]);
            printf("  ||                        \n");
            printf("  ||                        \n");
            printf("  ||                        \n");
            printf("  -------------------       \n");
            Sleep(100);
            system ("cls");
        }
        cabecalho();
        printf("  ==================        \n");
        printf("  ||//             |        \n");
        printf("  ||/              o        \n");
        printf("  ||                        \n");
        printf("  ||                        \n");
        printf("  ||                        \n");
        printf("  -------------------       \n");
    }
    if (chances == 6){
            cabecalho();
            printf("  ==================        \n");
            printf("  ||//             |        \n");
            printf("  ||/                       \n");
            printf("  ||                        \n");
            printf("  ||                        \n");
            printf("  ||                        \n");
            printf("  -------------------       \n");
        }
    }

void musica_abertura(){
    int n1 = 528, t1 = 200; //Hz //milisegundos
    int n2 = 440, t2 = 200;
    int n3 = 334, t3 = 2000;
    int n4 = 440, t4 = 500;
    int n5 = 528, t5 = 500;
    int n6 = 593, t6 = 1000;
    int n7 = 440, t7 = 1500;
    int n8 = 528, t8 = 1500;
    int n9 = 498, t9 = 500; 
    int n10 = 528, t10 = 500; 
    int n11 = 593, t11 = 500; 
    int n12 = 392, t12 = 500; 
    int n13 = 670, t13 = 1500; 
    int n14 = 593, t14 = 1500;

    Beep(n1, t1);
    Beep(n2, t2);
    Beep(n3, t3);
    Sleep(400);
    Beep(n4, t4);
    Beep(n5, t5);
    Beep(n6, t6);
    Beep(n7, t7);
    Sleep(400);
    Beep(n8, t8);
    Beep(n9, t9);
    Beep(n10, t10);
    Beep(n11, t11);
    Beep(n12, t12);
    Beep(n13, t13);
    Beep(n14, t14);
}

void musica_vitoria(){
    int f1 = 800, d1 = 100; //Hz //milisegundos
    int f2 = 800, d2 = 50;
    int f3 = 800, d3 = 50;
    int f4 = 900, d4 = 600; 

    Beep(f1, d1);
    Sleep(400);
    Beep(f2, d2);
    Beep(f3, d3);
    Beep(f4, d4);
}

void musica_perdedor(){
    int f1 = 600, d1 = 600; //Hz //milisegundos
    int f2 = 500, d2 = 500;
    int f3 = 400, d3 = 900;

    Beep(f1, d1);
    Beep(f2, d2);
    Beep(f3, d3);
}

void criar_palavra(char palavra_misteriosa[]){
    printf("============================\n");
    printf("           ~~*~~            \n");
    printf("       ~# OPTIONS #~        \n");
    printf("           ~~*~~            \n");
    printf("                            \n");
    printf(" INFORMAR A PALAVRA SEGREDO \n");
    printf("============================\n");
    printf("Palavra: ");
    scanf(" %s", palavra_misteriosa);
}

void imprimir_certas(char letras_certas[], int max)
{
    int i;
    printf("\nPalavra: ");
    for (i = 0; i < max; i++)
    {
        printf("%c", letras_certas[i]);
    }
    printf("\n");
}

void imprimir_tentativas(char letras_tentadas[], int posicao)
{
    int i;
    printf("Tentativas: ");
    for (i = 0; i < posicao; i++)
    {
        printf("%c", letras_tentadas[i]);
    }
    printf("\n");
}

void capta_letra(char letra[]){
    printf("Informe uma letra: ");
    scanf(" %c", &letra[0]);
    letra[0] = tolower(letra[0]);
}

void verifica_letra(int *chances, int max, char palavra_misteriosa[], char letras_certas[], char letra[], int *vitoria, int posicao, char letras_tentadas[]){
    int i, deducao_chance = 0, cont_certas = 0;
    for (i = 0; i < max; i++){ // Laço para verificar se a letra informada pelo jogador está na palavra
        if (letra[0] == palavra_misteriosa[i]){
            if (letra[0] != letras_certas[i]){
                cont_certas++;
                if (cont_certas == 1){
                    *vitoria = *vitoria + 1; // Contador de acertos para verificar o fim do jogo
                }
            }
            letras_certas[i] = letra[0];
            deducao_chance++;
        }
    }
    if (deducao_chance == 0)
        *chances = *chances - 1;
    for (i = posicao; i < 30; i++){ // Arquivamento das tentativas
        letras_tentadas[i] = letra[0];
    }
}

void verifica_fim(int vitoria, int max){
    if (vitoria+1 == max){
        musica_vitoria();
    }
    else{
        musica_perdedor();
    }

    if (vitoria+1 == max){ // Condição de verificação do fim do jogo
        printf("=====================================================\n");
        printf("                         ~#~                         \n");
        printf("                       PARABENS!                     \n");
        printf("               Voce acertou a palavra!               \n");
        printf("                     Fim de jogo                     \n");
        printf("                         ~#~                         \n");
        printf("=====================================================\n");
    }
    else
    {
        printf("=====================================================\n");
        printf("                         ~#~                         \n");
        printf("                     FIM DE JOGO                     \n");
        printf("             Voce nao acertou a palavra!             \n");
        printf("                         ~#~                         \n");
        printf("=====================================================\n");
    }
}

void imprime_tentativas_restantes(int chances)
{
    printf(" Voce tem %i tentativas\n", chances);
}