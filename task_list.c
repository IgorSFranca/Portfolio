/*
 * Nome do arquivo: task_list.c
 * Descrição: Lista de Tarefas CLI: Crie uma aplicação de linha de comando (CLI) para gerenciar uma lista de tarefas. 
 * Os usuários podem adicionar, remover e listar tarefas.
 * Autor: Igor França
 * Data de criação: 10 de agosto de 2023
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void cabecalho();

int main(){
    cabecalho();

    system ("pause");
    return 0;
}

void cabecalho(){
    printf("---------------------------------------\n");
    printf("|                 ~#~                 |\n");
    printf("|              TASK LIST              |\n");
    printf("|                 ~#~                 |\n");
    printf("---------------------------------------\n\n");
}