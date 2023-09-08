/*
 * Nome do arquivo: task_list.c
 * Descrição: Aplicação de lista de tarefas, onde o usuário consegue inserir, excluir, editar, visualização e concluir tarefas.
 * Autor: Igor França
 * Data de criação: 08 de setembro de 2023. 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tipo_tarefa{
    char tarefa[50];
    int situacao;
};

typedef struct tipo_tarefa tipo_tarefa;

int main (){
    tipo_tarefa tarefas[100];

    return 0;
}