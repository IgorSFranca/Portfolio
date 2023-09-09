/*
 * Nome do arquivo: jogo-da-velha.c
 * Descrição: Jogo infanto-juvenil chamado Jogo da velha. O objetivo do jogo é marcar três quadrados consecutivos na horizontal, vertical ou
 * transversal, antes que o jogador adversário faça o mesmo. 
 * Autor: Igor França
 * Data de criação: 31 de outubro 
 * 
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

void header();
void header_options();
void header_menu();
void select_option(int*);
void create_players(char player1[], char player2[]);
void inicial_animation();
void game_animation(char game[3][3]);
void gameplay(char player1[], char player2[], char game[3][3], char winner[]);
void print_players(char player1[], char player2[]);
void end_game_verification(char game[][3], char player1[], char player2[], char winner[]);
void end_game_animation(char winner[]);
void clean_game(char game[3][3], char winner[]);

int main (){
    int option;
    char player1[] = {"Player 1"};
    char player2[] = {"Player 2"};
    char winner[] = {"roling"};
    char game[3][3] = {
        {' ',' ',' '},
        {' ',' ',' '},
        {' ',' ',' '}
    }; //Preenche o jogo de acordo com os movimentos

    do{
        system ("cls");
        header();
        header_menu();
        select_option(&option);
        switch (option){
            case 1:
                inicial_animation();
                gameplay(player1, player2, game, winner);
                end_game_animation(winner);
                break;
            case 2:
                system ("cls");
                header();
                header_options();
                select_option(&option);
                switch (option){
                    case 1: 
                        create_players(player1, player2);
                        break;
                    case 2: 
                        clean_game(game, winner); 
                        break;
                    case 3: 
                        break;
                }
                break;
            case 0:
                break;
        }
    } while (option != 0);
    return 0;
}

void header(){
    printf("=================================\n");
    printf("              ~#~                \n");
    printf("            ~ HASH ~             \n");
    printf("              ~#~                \n");
    printf("=================================\n");
}

void header_options(){
    printf("                                 \n");
    printf("           ~ OPTIONS ~           \n");
    printf("                                 \n");
    printf(" [1] Create players              \n");
    printf(" [2] Clean Game                  \n");
    printf(" [3] Return                      \n");
    printf("                                 \n");
    printf("=================================\n");
}

void header_menu(){
    printf("                                 \n");
    printf("            ~ MENU ~             \n");
    printf("                                 \n");
    printf(" [1] Start                       \n");
    printf(" [2] Options                     \n");
    printf(" [0] Exit                        \n");
    printf("                                 \n");
    printf("=================================\n");
}

void select_option(int *option){
    int temp;
    do{
        printf("Insert option: ");
        scanf(" %i", &temp);
        if (temp != 1 && temp != 2 && temp != 3 && temp != 0){
            printf("Invalid option!\n");
            while(getchar() != '\n'){} //limpa o buffer caso seja inserido uma letra ao invés de numero
        }
    } while (temp != 1 && temp != 2 && temp != 3 && temp != 0);
    *option = temp;
}

void create_players(char player1[], char player2[]){
    char resp;
    do{
        system("cls");
        header();
        printf("                                 \n");
        printf("          INSERT PLAYERS         \n");
        printf("First Player name: ");
        scanf(" %s", player1);
        printf("Confirm [y/n]: ");
        scanf(" %c", &resp);
    } while (resp != 'y');
    do{
        system("cls");
        header();
        printf("                                 \n");
        printf("          INSERT PLAYERS         \n");
        printf("First Player: Concluded          \n");
        printf("\nSecond Player name: ");
        scanf(" %s", player2);
        printf("Confirm [y/n]: ");
        scanf(" %c", &resp);
    } while (resp != 'y');
}

void inicial_animation(){
    Sleep(100); system("cls");
    printf("=================================\n");
    printf("              ~#~                \n");
    printf("        ~                        \n");
    printf("              ~#~                \n");
    printf("=================================\n");
    Sleep(100); system("cls");
    printf("=================================\n");
    printf("              ~#~                \n");
    printf("        ~                        \n");
    printf("              ~#~                \n");
    printf("=================================\n");
    Sleep(100); system("cls");
    printf("=================================\n");
    printf("              ~#~                \n");
    printf("        ~ J                      \n");
    printf("              ~#~                \n");
    printf("=================================\n");
    Sleep(100); system("cls");
    printf("=================================\n");
    printf("              ~#~                \n");
    printf("        ~ JO                     \n");
    printf("              ~#~                \n");
    printf("=================================\n");
    Sleep(100); system("cls");
    printf("=================================\n");
    printf("              ~#~                \n");
    printf("        ~ JOG                    \n");
    printf("              ~#~                \n");
    printf("=================================\n");
    Sleep(100); system("cls");
    printf("=================================\n");
    printf("              ~#~                \n");
    printf("        ~ JOGO                   \n");
    printf("              ~#~                \n");
    printf("=================================\n");
    Sleep(100); system("cls");
    printf("=================================\n");
    printf("              ~#~                \n");
    printf("        ~ JOGO                   \n");
    printf("              ~#~                \n");
    printf("=================================\n");
    Sleep(100); system("cls");
    printf("=================================\n");
    printf("              ~#~                \n");
    printf("        ~ JOGO D                 \n");
    printf("              ~#~                \n");
    printf("=================================\n");
    Sleep(100); system("cls");
    printf("=================================\n");
    printf("              ~#~                \n");
    printf("        ~ JOGO DA                \n");
    printf("              ~#~                \n");
    printf("=================================\n");
    Sleep(100); system("cls");
    printf("=================================\n");
    printf("              ~#~                \n");
    printf("        ~ JOGO DA                \n");
    printf("              ~#~                \n");
    printf("=================================\n");
    Sleep(100); system("cls");
    printf("=================================\n");
    printf("              ~#~                \n");
    printf("        ~ JOGO DA V              \n");
    printf("              ~#~                \n");
    printf("=================================\n");
    Sleep(100); system("cls");
    printf("=================================\n");
    printf("              ~#~                \n");
    printf("        ~ JOGO DA VE             \n");
    printf("              ~#~                \n");
    printf("=================================\n");
    Sleep(100); system("cls");
    printf("=================================\n");
    printf("              ~#~                \n");
    printf("        ~ JOGO DA VEL            \n");
    printf("              ~#~                \n");
    printf("=================================\n");
    Sleep(100); system("cls");
    printf("=================================\n");
    printf("              ~#~                \n");
    printf("        ~ JOGO DA VELH           \n");
    printf("              ~#~                \n");
    printf("=================================\n");
    Sleep(100); system("cls");
    printf("=================================\n");
    printf("              ~#~                \n");
    printf("        ~ JOGO DA VELHA          \n");
    printf("              ~#~                \n");
    printf("=================================\n");
    Sleep(100); system("cls");
    printf("=================================\n");
    printf("              ~#~                \n");
    printf("        ~ JOGO DA VELHA ~        \n");
    printf("              ~#~                \n");
    printf("=================================\n");
    Sleep(100);

}

void print_players(char player1[], char player2[]){
    printf("                                 \n");
    printf(" Player one: %s\n", player1);
    printf(" Player two: %s\n", player2);
    printf("                                 \n");
    printf("=================================\n");
}

void game_animation(char game[3][3]){
    printf("\n          |           |          \n");
    printf("     %c    |     %c     |     %c   \n", game[0][0], game[0][1], game[0][2]);
    printf("    1 1   |    1 2    |     1 3  \n");
    printf("__________|___________|__________\n");
    printf("          |           |          \n");
    printf("     %c    |     %c     |     %c   \n", game[1][0], game[1][1], game[1][2]);
    printf("    2 1   |    2 2    |     2 3  \n");
    printf("__________|___________|__________\n");
    printf("          |           |          \n");
    printf("     %c    |     %c     |     %c   \n", game[2][0], game[2][1], game[2][2]);
    printf("    3 1   |    3 2    |     3 3  \n");
    printf("          |           |         \n\n");
}

void gameplay(char player1[], char player2[], char game[3][3], char winner[]){
    int round;
    int l, c;

    for (round=0; round<5; round++){//iteração das rodadas
        int ok = 0;
        system("cls");
        header();
        print_players(player1, player2);
        game_animation(game);

        //Jogada do PLAYER 1
        printf("                ~~~           \n");
        printf("             Round %i\n", round+1);
        printf("            %s \n", player1);
        do{

            do{ //Laço que verifica se o usuário inseriu números, e não letras
                printf("Line: ");
                scanf("%i", &l);
                if (l != 1 && l != 2 && l != 3){
                    printf("Invalid line\n");
                    while (getchar() != '\n'){} //Limpando buffer
                }
            } while (l != 1 && l != 2 && l != 3);

            do{ //Laço que verifica se o usuário inseriu números, e não letras
                printf("Column: ");
                scanf("%i", &c);
                if (c != 1 && c != 2 && c != 3){
                    printf("Invalid Column\n");
                    while (getchar() != '\n'){} //Limpando buffer
                }
            } while (c != 1 && c != 2 && c != 3);

            if (game[l-1][c-1] == ' '){                
                game[l-1][c-1] = 'X';
                ok = 1;
            }
            else{
                printf("Game not allowed\n");
            }
        } while (ok != 1);

        //Verificação de vencedor
        end_game_verification(game, player1, player2, winner);
        if (strcmp(winner, "roling") != 0){
            break;
        }

        ok = 0;
        system("cls");
        header();
        print_players(player1, player2);
        game_animation(game);

        //Jogada do PLAYER 2
        printf("                ~~~           \n");
        printf("             Round %i\n", round+1);
        printf("            %s \n", player2);
        do{
            do{ //Laço que verifica se o usuário inseriu números, e não letras
                printf("Line: ");
                if (scanf("%i", &l) != 1 || (l != 1 && l != 2 && l != 3)){
                    while (getchar() != '\n'){} //Limpando buffer
                    printf("Invalid line\n");
                }
            } while (l != 1 && l != 2 && l != 3);

            do{ //Laço que verifica se o usuário inseriu números, e não letras
                printf("Column: ");
                if (scanf("%i", &c) != 1 || (c != 1 && c != 2 && c != 3)){
                    while (getchar() != '\n'){} //Limpando buffer
                    printf("Invalid Column\n");
                }
            } while (c != 1 && c != 2 && c != 3);

            if (game[l-1][c-1] == ' '){
                game[l-1][c-1] = 'O';
                ok = 1;
            }
            else{
                printf("Game not allowed\n");
            }
        } while (ok != 1);

        //Verificação de vencedor
        end_game_verification(game, player1, player2, winner);
        if (strcmp(winner, "roling") != 0){
            break;
        }
    }
}

void end_game_verification(char game[3][3], char player1[], char player2[], char winner[]){
    int l, c;

    //Verificando a vitória do Player 1
    for (l=0; l<3; l++){
        if (game[l][0] == 'X' && game[l][1] == 'X' && game[l][2] == 'X'){
            strcpy(winner, player1);
            return;
        }
    }
    for (c=0; c<3; c++){
        if (game[0][c] == 'X' && game[1][c] == 'X' && game[2][c] == 'X'){
            strcpy(winner, player1);
            return;
        }
    }
    if (game[0][0] == 'X' && game[1][1] == 'X' && game[2][2] == 'X'){
        strcpy(winner, player1);
        return;
    }
    if (game[0][2] == 'X' && game[1][1] == 'X' && game[2][0] == 'X'){
        strcpy(winner, player1);
        return;
    }

    //Verificando a vitória do Player 2
     for (l=0; l<3; l++){
        if (game[l][0] == 'O' && game[l][1] == 'O' && game[l][2] == 'O'){
            strcpy(winner, player2);
            return;
        }
    }
    for (c=0; c<3; c++){
        if (game[0][c] == 'O' && game[1][c] == 'O' && game[2][c] == 'O'){
            strcpy(winner, player2);
            return;
        }
    }
    if (game[0][0] == 'O' && game[1][1] == 'O' && game[2][2] == 'O'){
        strcpy(winner, player2);
        return;
    }
    if (game[0][2] == 'O' && game[1][1] == 'O' && game[2][0] == 'O'){
        strcpy(winner, player2);
        return;
    }
}

void end_game_animation(char winner[]){
    system("cls");
    header();
    printf("\n");
    printf("              ~ # ~              \n");
    printf("         CONGRATULATIONS         \n");
    printf("            %s\n", winner);
    printf("           ~ YOU WON ~           \n");
    printf("              ~ # ~              \n");
    printf("\n");
    system("pause");
}

void clean_game(char game[3][3], char winner []){
    int i, j;
    for (i=0; i<3; i++){
        for (j=0; j<3; j++){
            game[i][j] = ' ';
        }
    }
    strcpy(winner, "roling");
    printf("Game cleaned!\n");
    printf("Returning...");
    Sleep(2000);
}