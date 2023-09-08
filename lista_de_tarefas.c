/*
 * Nome do arquivo: lista_de_tarefas.c
 * Descrição: Aplicação de lista de tarefas, onde o usuário consegue inserir, excluir, editar, visualização e concluir tarefas.
 * Autor: Igor França
 * Data de criação: 08 de setembro de 2023. 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
                            break;
                        case 3: //Concluir tarefa
                            break;
                        case 4: //Excluir tarefa
                            break;
                        case 5: //Atualizar listagem de tarefas
                            break;
                        case 6: //Voltar para o menu inicial
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
    puts(" [5] Atualizar listagem");
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
        printf("Nao ha tarefas armazenadas.\n");
        system("pause");
        return;
    }
    else{
        for (i=0; i<*contador_tarefas; i++){
            printf("Tarefa %i:\n", i);
            printf("Descricao: %s\n", tarefas[i].descricao);
            printf("Situacao: %i\n", tarefas[i].situacao);
        }
    }
}

void incluir_tarefa(tipo_tarefa tarefas[100], int *contador_tarefas){
    system("cls");
    cabecalho();
    printf("VAMOS INCLUIR UMA NOVA TAREFA\n\n");
    printf("Informe a descricao: ");
    scanf("%s", &tarefas[*contador_tarefas+1].descricao);
    fflush;
    tarefas[*contador_tarefas+1].situacao = 1;
}