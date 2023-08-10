/*
 * Nome do arquivo: task_list.c
 * Descrição: Lista de Tarefas: Uma aplicação de linha de comando (CLI) para gerenciar uma lista de tarefas. 
 * Os usuários podem adicionar, remover e listar tarefas.
 * Autor: Igor França
 * Data de criação: 10 de agosto de 2023
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

void cabecalho(), opcoes_princiais(), opcoes_secundarias(), encerramento();

int main(){
    int opcao;

    cabecalho();
    opcoes_princiais();
    do{
        printf("Informe a opcao desejada: ");
        scanf(" %i", &opcao);
        if (opcao == 0)
            opcoes_secundarias();
        if (opcao == 8)
            opcoes_princiais();
    } while (opcao < 0 || opcao > 8 || opcao == 0 || opcao == 8);
    switch(opcao){
        case 1: break;
        case 2: break;
        case 3: break;
        case 4: break;
        case 5: break;
        case 6: system ("cls"); break;
        case 7: encerramento(); break;
    }
    system ("pause");
    return 0;
}

void cabecalho(){
    printf("---------------------------------------\n");
    printf("|                 ~#~                 |\n");
    printf("|              TASK LIST              |\n");
    printf("|                 ~#~                 |\n");
    printf("---------------------------------------\n");
}

void opcoes_princiais(){
    printf("---------------------------------------\n");
    printf("|           Opcoes principais         |\n");
    printf("| [1] Visualizar lista de tarefas     |\n");
    printf("| [2] Criar tarefa                    |\n");
    printf("| [3] Editar tarefa                   |\n");
    printf("| [4] Excluir tarefa                  |\n");
    printf("| [5] Concluir tarefa                 |\n");
    printf("| [0] Mais opcoes                     |\n");
    printf("---------------------------------------\n");
}

void opcoes_secundarias(){
    printf("---------------------------------------\n");
    printf("|         ~  Outras Opcoes  ~         |\n");
    printf("| [6] Para limpar o visor             |\n");
    printf("| [7] Para encerrar a aplicacao       |\n");
    printf("| [8] Menu anterior                   |\n");
    printf("---------------------------------------\n");
}

void encerramento(){
    int i;
    printf("\nEncerrando Task List");
        for (i=0; i<3; i++){
            Sleep(600);
            printf(".");
        }
    printf("\nTask List encerrado!\n\n");
    }