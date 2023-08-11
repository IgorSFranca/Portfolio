/*
 * Nome do arquivo: jogo_da_forca.c
 * Descrição: Jogo info-juvenil da foca, onde o usuário tenta adivinhar a palavra escondida. A cada tentativa errada, o usuário 
 * perde um ponto de vida.
 * Autor: Igor França
 * Datas:
 *      Criação: 22 de julho de 2023; 
 *      Modularização: 11/08/2023
 */

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <ctype.h> 

//protótipos
void cabecalho();
void imprimir_certas(char letras_certas[], int max);
void imprimir_tentativas(char letras_tentadas[], int tentativas);
void verifica_fim(int vitoria, int max);
char capta_letra(int max, int tentativas, char letra[]);
int verifica_letra(int max, char palavra_misteriosa[], char letras_certas[], char letra[], int vitoria, int posicao, char letras_tentadas[]);

int main (){
    //declaração de variáveis
    char palavra_misteriosa[] = {"quadrilongo"};
    char letra[1];
    char letras_certas[sizeof(palavra_misteriosa)-1];
    char letras_tentadas[sizeof(palavra_misteriosa)-1] = {""};
    memset (letras_certas, '_', sizeof(palavra_misteriosa)-1); 
    int i;
    int max = sizeof(palavra_misteriosa)-1;
    int chances = sizeof(palavra_misteriosa)-1;
    int vitoria = 0;
    int posicao = 0;
    int tentativas = 0;

    //execução do jogo
    do{
        cabecalho();
        imprimir_certas(letras_certas, max);
        imprimir_tentativas(letras_tentadas, tentativas);
        letra[0] = capta_letra(max, tentativas, letra);
        system ("cls"); 
        vitoria = verifica_letra(max, palavra_misteriosa, letras_certas, letra, vitoria, posicao, letras_tentadas);
        posicao++; //Posicionamento da letra na exibição das tentativas
        tentativas++; //Contagem de tentativas
        if (vitoria == sizeof(palavra_misteriosa)-1) //Condição para dar um Break caso o usuário acerte a palavra antes de finalizar as tentativas
            break;
    } while (tentativas != sizeof(palavra_misteriosa)-1); 
    verifica_fim(vitoria, max);
    system ("pause");
    return 0;
}

//procedimentos e funções
void cabecalho(){
    printf("++++++++++++++++++++++++++++\n");
    printf("+          ~~*~~           +\n");
    printf("+   ~# JOGO DA FORCA #~    +\n");
    printf("+          ~~*~~           +\n");
    printf("++++++++++++++++++++++++++++\n\n");
    printf("  ==================\n");
    printf("  ||//             |\n");
    printf("  ||/              O\n");
    printf("  ||              /|\\ \n");
    printf("  ||              / \\ \n");
    printf("  ||\n");
    printf("  -------------------\n");
}

void imprimir_certas(char letras_certas[], int max){
    int i;
    printf("Palavra: "); 
    for (i=0; i<max; i++){
        printf("%c", letras_certas[i]);
    }
    printf("\n");
}

void imprimir_tentativas(char letras_tentadas[], int tentativas){
    int i;
    printf("Tentativas: ");
    for (i=0; i<tentativas; i++){
        printf("%c", letras_tentadas[i]);
    }
    printf("\n");
}

char capta_letra(int max, int tentativas, char letra[]){
    printf("Voce tem %i tentativas.\n", max-tentativas);
    printf("Informe uma letra: ");
    scanf(" %c", &letra[0]); 
    return (tolower(letra[0]));
}

int verifica_letra(int max, char palavra_misteriosa[], char letras_certas[], char letra[], int vitoria, int posicao, char letras_tentadas[]){
    int i;
    for (i=0; i<max; i++){ //Laço para verificar se a letra informada pelo jogador está na palavra
        if (letra[0] == palavra_misteriosa[i]){ 
            letras_certas[i] = letra[0];
            vitoria++; //Contador de acertos para verificar o fim do jogo
        }
    }
    for (i=posicao; i<max; i++){ // Arquivamento das tentativas
        letras_tentadas[i] = letra[0];
    }
    return vitoria;
}

void verifica_fim(int vitoria, int max){
    if (vitoria == max){// Condição de verificação do fim do jogo
        printf("Parabens voce acertou a palavra!\n");
        printf("Fim de jogo!\n");
    } 
    else{
        printf("Voce nao conseguiu acertar a palavra.\n");
        printf("Fim de jogo!\n");
    }
}