# Jogo da Velha

## Introdução

O programa "Jogo da Velha" é uma implementação do clássico jogo de tabuleiro para dois jogadores. O objetivo do jogo é marcar três quadrados consecutivos na horizontal, vertical ou diagonal antes que o jogador adversário faça o mesmo.

## Funcionalidades

O programa oferece as seguintes funcionalidades:

1. **Menu Principal**
   - Opção 1: Iniciar Jogo
   - Opção 2: Opções
   - Opção 0: Sair

2. **Opções**
   - Opção 1: Criar Jogadores
   - Opção 2: Limpar Jogo Atual
   - Opção 3: Voltar ao Menu Principal

## Estrutura do Código

### Bibliotecas Utilizadas

- `stdio.h`: Biblioteca padrão de entrada e saída.
- `stdlib.h`: Biblioteca padrão do sistema.
- `string.h`: Biblioteca para manipulação de strings.
- `windows.h`: Biblioteca para funções relacionadas ao sistema Windows.

### Funções Principais

1. **`header()`:** Função que imprime o cabeçalho do jogo.
2. **`header_options()`:** Função que imprime as opções do menu "Opções".
3. **`header_menu()`:** Função que imprime as opções do menu principal.
4. **`select_option(int*)`:** Função que lê e valida a opção escolhida pelo usuário.
5. **`create_players(char player1[], char player2[])`:** Função para criar os jogadores.
6. **`inicial_animation()`:** Animação inicial do jogo.
7. **`print_players(char player1[], char player2[])`:** Função que imprime os nomes dos jogadores.
8. **`game_animation(char game[3][3])`:** Função que imprime o estado atual do jogo.
9. **`gameplay(char player1[], char player2[], char game[3][3], char winner[])`:** Função que gerencia a jogabilidade.
10. **`end_game_verification(char game[3][3], char player1[], char player2[], char winner[])`:** Função que verifica se houve um vencedor.
11. **`end_game_animation(char winner[])`:** Animação de fim de jogo com o vencedor.
12. **`clean_game(char game[3][3], char winner[])`:** Função para limpar o tabuleiro.

## Fluxo do Jogo

1. O programa exibe um menu principal.
2. O usuário pode escolher entre iniciar o jogo, acessar as opções ou sair do programa.
3. Ao iniciar o jogo, os jogadores são criados com nomes padrão ou personalizados pelo usuário.
4. Durante o jogo, os jogadores alternam entre si fazendo suas jogadas.
5. O programa verifica se houve um vencedor após cada jogada.
6. Ao final do jogo, exibe uma mensagem de vitória para o jogador vencedor.
7. O usuário pode optar por voltar ao menu principal ou sair do programa.

## Considerações Finais

O programa "Jogo da Velha" oferece uma implementação interativa e funcional do jogo clássico para dois jogadores. Ele conta com um menu intuitivo e animações para tornar a experiência mais agradável. As funcionalidades de criação de jogadores e limpeza do jogo proporcionam flexibilidade ao usuário.

Por favor, sinta-se à vontade para entrar em contato caso necessite de alguma modificação ou esclarecimento adicional sobre o programa.
