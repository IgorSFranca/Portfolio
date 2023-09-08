/*
 * Nome do arquivo: lista_de_tarefas.c
 * Descrição: Aplicação de lista de tarefas, onde o usuário consegue inserir, excluir, editar, visualização e concluir tarefas.
 * Autor: Igor França
 * Data de criação: 08 de setembro de 2023. 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cabecalho();
void menu_inicial();
void menu_interno();
void seleciona_opcao(int*);

struct tipo_tarefa{
    char tarefa[50];
    int situacao;
};

typedef struct tipo_tarefa tipo_tarefa;

int main (){
    tipo_tarefa tarefas[100];
    int opcao;

    cabecalho();
    menu_inicial();
    seleciona_opcao(&opcao);
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
    puts("");
    puts(" [1] Inserir nova");
    puts(" [2] Editar");
    puts(" [3] Concluir");
    puts(" [4] Excluir");
    puts(" [5] Atualizar listagem");
    puts(" [9] Voltar");
    puts("");
    puts("=====================================================");
}

void seleciona_opcao(int *opcao){
    printf("Informe a opcao: ");
    scanf("%i", *opcao);
}