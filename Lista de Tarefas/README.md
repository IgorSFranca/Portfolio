## Lista de Tarefas (em desenvolvimento)

### Descrição

O programa `lista_de_tarefas.c` implementa uma aplicação de lista de tarefas que oferece funcionalidades para o gerenciamento de tarefas, incluindo inserção, edição, visualização, conclusão e exclusão.

### Compilação e Execução

Para compilar e executar o programa, utilize um compilador C compatível com a sua plataforma. Por exemplo, no Linux, utilize o seguinte comando no terminal:

```bash
gcc lista_de_tarefas.c -o lista_de_tarefas
./lista_de_tarefas
```

### Uso

Ao ser executado, o programa exibe um menu inicial com opções para interagir com a lista de tarefas. A partir do menu inicial, o usuário pode visualizar tarefas existentes, inserir novas tarefas, editar tarefas existentes, marcar tarefas como concluídas ou excluí-las.

### Funcionalidades Implementadas

- **Visualizar Tarefas**

    Ao selecionar a opção "Visualizar tarefas" no menu inicial, o programa exibe a lista de tarefas existentes, apresentando a descrição e o status de cada uma.

    Exemplo de tela de execução:
    ```
    =====================================
                    ~ # ~
            ~ LISTA DE TAREFAS ~
                    ~ # ~
    =====================================

     [1] Visualizar tarefas
     [2] Inserir
     [0] Encerrar programa

    =====================================
    Informe a opcao: 1

    =====================================
                        ~ # ~
                ~ LISTA DE TAREFAS ~
                        ~ # ~
    =====================================

    Tarefa 1:
    Descricao: Tarefa de exemplo
    Situacao: Pendente

    ```

- **Inserir Nova Tarefa**

    A opção "Inserir" no menu inicial permite ao usuário adicionar uma nova tarefa à lista. É solicitada uma descrição para a nova tarefa, e a inclusão só é confirmada após a confirmação do usuário.

    Exemplo de tela de execução:
    ```
    =====================================
                    ~ # ~
            ~ LISTA DE TAREFAS ~
                    ~ # ~
    =====================================

     [1] Visualizar tarefas
     [2] Inserir
     [0] Encerrar programa

    =====================================
    Informe a opcao: 2

    VAMOS INCLUIR UMA NOVA TAREFA

    Informe a descricao: Tarefa de exemplo

    Confirma a inclusao da tarefa? [s/n] s

    Tarefa adicionada com sucesso!
    ```

- **Editar Tarefa**

    A opção "Editar" no menu interno permite ao usuário editar a descrição de uma tarefa existente. O usuário seleciona o índice da tarefa a ser editada, informa a nova descrição e a edição é confirmada após a confirmação do usuário.

    Exemplo de tela de execução:
    ```
    =====================================
                        ~ # ~
                ~ LISTA DE TAREFAS ~
                        ~ # ~
    =====================================

     [1] Inserir nova
     [2] Editar
     [3] Concluir
     [4] Excluir
     [9] Voltar

    =====================================
    Informe a opcao: 2

    Informe o indice da tarefa que deseja alterar: 1

    Descricao atual: Tarefa de exemplo
    Informe a nova descricao: Nova descricao para a tarefa de exemplo

    Confirma a edicao da tarefa? [s/n] s

    Tarefa editada com sucesso!
    ```

- **Concluir Tarefa**

    A opção "Concluir" no menu interno permite ao usuário marcar uma tarefa como concluída. O usuário seleciona o índice da tarefa a ser concluída, e a conclusão é confirmada após a confirmação do usuário.

    Exemplo de tela de execução:
    ```
    =====================================
                        ~ # ~
                ~ LISTA DE TAREFAS ~
                        ~ # ~
    =====================================

     [1] Inserir nova
     [2] Editar
     [3] Concluir
     [4] Excluir
     [9] Voltar

    =====================================
    Informe a opcao: 3

    =====================================
                        ~ # ~
                ~ LISTA DE TAREFAS ~
                        ~ # ~
    =====================================

    Tarefa 1:
    Descricao: Nova descricao para a tarefa de exemplo
    Situacao: Pendente

    ----------------------------------------------

    Informe o indice da tarefa que deseja concluir
    ou informe 0 [zero] para cancelar: 1

                     ~#~
    Situacao atual: Pendente
    Situacao alterada para: Concluido.
                     ~#~

    Confirma a conclusao da tarefa? [s/n] s

    Tarefa concluida com sucesso!
    ```

### Funcionalidades Pendentes

1. **Travar Inserção de Letras ao Invés de Índices**

   Atualmente, o programa ainda permite a inserção de letras ao invés de índices, o que resulta em comportamento inesperado.

2. **Excluir Tarefa**

   A funcionalidade para excluir uma tarefa ainda não foi implementada.

3. **Melhoria de Layout**

   O layout atual é funcional, mas pode ser aprimorado para proporcionar uma experiência mais agradável ao usuário.
