# Get Next Line (get_next_line)

`get_next_line` é um projeto da 42 que consiste em programar uma função que retorna uma linha lida de um descritor de arquivo (file descriptor).

## 📜 Descrição

O objetivo deste projeto é criar uma função chamada `get_next_line` que, quando chamada em um loop, lê o conteúdo de um arquivo de texto uma linha de cada vez. Esta função é essencial para muitos programas que precisam processar arquivos linha por linha, sendo um ótimo exercício para entender o gerenciamento de memória estática e alocação dinâmica em C.

## ✨ Funcionalidades

- **Leitura Linha por Linha**: Lê um arquivo de texto linha por linha, incluindo a quebra de linha (`\n`).
- **Gerenciamento de Múltiplos Arquivos**: A versão bônus do projeto permite gerenciar múltiplos descritores de arquivo simultaneamente.
- **Buffer Configurável**: O tamanho do buffer de leitura pode ser facilmente ajustado através da flag de compilação `-D BUFFER_SIZE=n`.
- **Funções Auxiliares**: Inclui um conjunto de funções utilitárias para manipulação de strings e gerenciamento de memória.

## 🚀 Como Usar

Para utilizar a função `get_next_line` em seu projeto, siga os passos abaixo:

1.  **Inclua o header**: Adicione `#include "get_next_line.h"` no seu arquivo `.c`.
2.  **Compile os arquivos**: Compile os arquivos `get_next_line.c` e `get_next_line_utils.c` juntamente com o seu projeto.
    ```bash
    cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c seu_programa.c -o seu_executavel
    ```
3.  **Exemplo de uso**:
    ```c
    #include "get_next_line.h"
    #include <fcntl.h>
    #include <stdio.h>

    int main(void)
    {
        int     fd;
        char    *line;

        fd = open("seu_arquivo.txt", O_RDONLY);
        if (fd == -1)
        {
            printf("Erro ao abrir o arquivo.");
            return (1);
        }
        while ((line = get_next_line(fd)))
        {
            printf("%s", line);
            free(line);
        }
        close(fd);
        return (0);
    }
    ```

## 🎁 Bônus

A parte bônus do projeto estende a funcionalidade do `get_next_line` para gerenciar múltiplos descritores de arquivo ao mesmo tempo. Isso significa que você pode ler de diferentes arquivos de forma intercalada sem perder o rastro da posição de leitura de cada um.

Para compilar a versão bônus, utilize os arquivos `_bonus`:
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c seu_programa_bonus.c -o seu_executavel_bonus
