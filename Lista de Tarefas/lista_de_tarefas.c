/*
 * Nome do arquivo: lista_de_tarefas.c
 * Descrição: Aplicação de lista de tarefas, onde o usuário consegue inserir, excluir, editar, visualização e concluir tarefas.
 * Autor: Igor França
 * Data de criação: 08 de setembro de 2023. 
 * 
 * Itens:
 * 01. Travar para não inserir letras ao invés de índices. 
 * 02. Criar a função de excluir tarefa. 
 * 03. Melhorar layout.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct tipo_tarefa{
    char descricao[50]; //Descrição geral da tarefa
    int situacao; //[1] Pendente; [2] Concluído
};

typedef struct tipo_tarefa tipo_tarefa;

void cabecalho();
void menu_inicial();
void menu_interno();
void visualizar_tarefas (tipo_tarefa tarefas[100], int*);
void incluir_tarefa(tipo_tarefa tarefas[100], int*);
void editar_tarefa(tipo_tarefa tarefas[100], int*);
void concluir_tarefa(tipo_tarefa tarefas[100], int*);
void excluir_tarefa(tipo_tarefa tarefas[100], int*);
int seleciona_opcao(int);

int main (){
    tipo_tarefa tarefas[100];
    int opcao;
    int contador_tarefas = 0;

    do{
        system ("cls");
        cabecalho();
        menu_inicial();
        opcao = seleciona_opcao(opcao);
        switch (opcao){
            case 1: //Visualizar tarefas
                visualizar_tarefas(tarefas, &contador_tarefas);
                //Novas opções de manipulação
                if (contador_tarefas == 0){
                    break;
                }
                else {//Incluir, editar, concluir, excluir, atualizar listagem
                    menu_interno();
                    opcao = seleciona_opcao(opcao);
                    switch (opcao){
                        case 1: //incluir tarefa
                            incluir_tarefa(tarefas, &contador_tarefas);
                            break;
                        case 2: //Editar tarefa
                            editar_tarefa(tarefas, &contador_tarefas);
                            break;
                        case 3: //Concluir tarefa
                            concluir_tarefa(tarefas, &contador_tarefas);
                            break;
                        case 4: //Excluir tarefa
                            excluir_tarefa(tarefas, &contador_tarefas);
                            break;
                        case 9: //Voltar para o menu inicial
                            break;
                        default:
                            printf("Opcao nao encontrada!\n");
                            break;
                    }
                    break;
                }
            case 2: //Inserir novas tarefas
                incluir_tarefa(tarefas, &contador_tarefas);
                break;
            case 0: //Encerrar programa 
                break;
        }
    } while (opcao != 0);
    system ("pause");
    return 0;
}

void cabecalho(){
    puts("=====================================================");
    puts("");
    puts("                       ~ # ~");
    puts("               ~ LISTA DE TAREFAS ~");
    puts("                       ~ # ~");
    puts("");
    puts("=====================================================");
}

void menu_inicial(){
    puts("");
    puts(" [1] Visualizar tarefas");
    puts(" [2] Inserir");
    puts(" [0] Encerrar programa");
    puts("");
    puts("=====================================================");
}

void menu_interno(){
    puts("=====================================================");
    puts("");
    puts(" [1] Inserir nova");
    puts(" [2] Editar");
    puts(" [3] Concluir");
    puts(" [4] Excluir");
    puts(" [9] Voltar");
    puts("");
    puts("=====================================================");
}

int seleciona_opcao(int opcao){
    printf("Informe a opcao: ");
    scanf("%i", &opcao);
    return opcao;
}

void visualizar_tarefas(tipo_tarefa tarefas[100], int *contador_tarefas){
    int i; 
    if (*contador_tarefas == 0){
        printf("\n               ~ # ~          \n");
        printf("   Nao ha tarefas armazenadas\n");
        printf("               ~ # ~          \n\n");
        system("pause");
        return;
    }
    else{
        for (i=0; i<*contador_tarefas; i++){
            printf("Tarefa %i:\n", i+1);
            printf("Descricao: %s", tarefas[i+1].descricao);
            printf("Situacao: %i", tarefas[i+1].situacao);
            if (tarefas[i+1].situacao == 1)
                printf(": Pendente\n\n");
            else
                printf(": Concluido\n\n");
        }
        system ("pause");
    }
}

void incluir_tarefa(tipo_tarefa tarefas[100], int *contador_tarefas){
    char resp = 'n', descricao[50];
    do{
        system("cls");
        cabecalho();
        printf("            VAMOS INCLUIR UMA NOVA TAREFA        \n\n");
        printf("Informe a descricao: ");
        fflush (stdin);
        fgets(descricao, 50, stdin);
        fflush (stdin);
        printf("\n");
        printf("Confirma a inclusao da tarefa? [s/n] ");
        scanf(" %c", &resp);
        resp = tolower(resp);
    } while (resp != 's');
    if (resp == 's'){
        strcpy(tarefas[*contador_tarefas+1].descricao, descricao);
        tarefas[*contador_tarefas+1].situacao = 1;
        *contador_tarefas = *contador_tarefas + 1;
    }
}

void editar_tarefa(tipo_tarefa tarefas[100], int *contador_tarefas){
    int i, verificacao = 0, indice;
    char resp = 's', descricao[50];
    do{
        printf("Informe o indice da tarefa que deseja alterar: ");
        scanf("%i", &indice);
        printf("\n");
        for (i=1; i<=*contador_tarefas; i++){
            if (i == indice)
                verificacao = 1;
        }
        if (verificacao == 1){
            printf("Descricao atual: %s", tarefas[indice].descricao);
            printf("Informe a nova descricao: ");
            fflush (stdin);
            fgets(descricao, 50, stdin);
            fflush (stdin);
        }
        else{
            printf("Tarefa nao encontrada!\n");
            system("pause");
        }
        printf("\n");
        printf("Confirma a edicao da tarefa? [s/n] ");
        scanf(" %c", &resp);
        resp = tolower(resp);
        if (resp == 's'){
            strcpy(tarefas[indice].descricao, descricao);
        }
    } while (resp != 's');
}

void concluir_tarefa(tipo_tarefa tarefas[100], int *contador_tarefas){
    int i, verificacao = 0, indice, situacao;
    char resp;
    do{
        system ("cls");
        cabecalho();
        visualizar_tarefas(tarefas, contador_tarefas);
        printf("\n----------------------------------------------\n");
        printf("\nInforme o indice da tarefa que deseja concluir\n");
        printf("ou informe 0 [zero] para cancelar: ");
        scanf("%i", &indice);
        printf("\n");
        if (indice != 0){
            for (i=0; i<=*contador_tarefas; i++){
                if (i == indice)
                    verificacao = 1;
            }
            if (verificacao == 1){
                if (tarefas[indice].situacao == 1){
                    printf("                 ~#~              \n");
                    printf("Situacao atual: Pendente          \n");
                    printf("Situacao alterada para: Concluido.\n");
                    printf("                 ~#~              \n");
                    situacao = 2;
                    printf("\n");
                    printf("Confirma a conclusao da tarefa? [s/n] ");
                    scanf(" %c", &resp);
                    resp = tolower(resp);
                    if (resp == 's')
                        tarefas[indice].situacao = situacao;
                }
                else{
                    printf("A tarefa ja esta marcada como concluida.\n");
                    system ("pause");
                }
            }
            else{
                printf("Tarefa nao encontrada!\n");
                system ("pause");
            }
        }
        else {
            break;
        }
    } while (resp != 's');
}

void excluir_tarefa(tipo_tarefa tarefas[100], int *contador_tarefas){
}