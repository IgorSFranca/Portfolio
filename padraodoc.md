----------------------------------------------------------------------------------------------------------
* Comentários de cabeçalho:
No início de cada arquivo fonte (.c ou .h), inclua um comentário que descreva o propósito do arquivo, seu autor, data de criação e quaisquer outras informações relevantes. Isso ajudará outros desenvolvedores a entenderem a finalidade do arquivo sem precisar analisar o código.

/*
 * Nome do arquivo: meu_programa.c
 * Descrição: Programa para realizar uma determinada tarefa.
 * Autor: Seu Nome
 * Data: 
        Criação: 22 de julho de 2023
        Modularização: 

 */

----------------------------------------------------------------------------------------------------------
* Comentários de função:
Antes de cada função, inclua um comentário que explique o que a função faz, seus parâmetros de entrada, seu valor de retorno (se houver) e quaisquer exceções que possam ser lançadas. Esse comentário deve estar imediatamente acima da definição da função.

/*
 * Descrição: Calcula a soma de dois números inteiros.
 * Parâmetros:
 *     a - Primeiro número inteiro
 *     b - Segundo número inteiro
 * Retorno:
 *     A soma dos dois números.
 */
int soma(int a, int b) {
    return a + b;
}

----------------------------------------------------------------------------------------------------------
* Comentários em linha:
Utilize comentários em linha para explicar trechos de código mais complexos ou que não sejam autoexplicativos.

// Laço for para iterar sobre o vetor e encontrar o valor máximo
for (int i = 0; i < tamanho; i++) {
    if (vetor[i] > maximo) {
        maximo = vetor[i];
    }
}
----------------------------------------------------------------------------------------------------------
* Explicação de constantes e variáveis:
Quando você declara constantes ou variáveis importantes, adicione um comentário explicativo ao lado delas.

int velocidadeMaxima = 100; // Velocidade máxima permitida em km/h
const int diasSemana = 7;   // Número de dias em uma semana

----------------------------------------------------------------------------------------------------------
* Explicação de estruturas e tipos personalizados:
Se você definir estruturas (structs) ou tipos personalizados, forneça uma breve explicação dos campos e propriedades relevantes.

typedef struct {
    char nome[50];     // Nome do cliente
    int idade;         // Idade do cliente
    char endereco[100];// Endereço do cliente
} Cliente;

----------------------------------------------------------------------------------------------------------
* Comentários de bibliotecas e cabeçalhos de arquivos:
Quando incluir bibliotecas ou cabeçalhos de arquivos, adicione um breve comentário sobre o que essas bibliotecas fazem ou contêm.

#include <stdio.h>  // Biblioteca padrão de entrada/saída
#include "funcoes.h"// Cabeçalho com as declarações das funções

