*Este projeto foi criado como parte do currículo da 42 por jaalves-*

# Libft

## Descrição

Libft é uma biblioteca em C que reimplementa funções da libc padrão e adiciona funções utilitárias para manipulação de strings, gerenciamento de memória e operações com listas ligadas. O objetivo é construir uma biblioteca pessoal que servirá como base para os projetos futuros da 42.

A biblioteca é dividida em três partes:

- **Parte 1 — Funções da Libc**: Reimplementação de 23 funções da biblioteca C padrão (ctype, string, memória e stdlib) com o prefixo `ft_`.
- **Parte 2 — Funções adicionais**: 11 funções utilitárias não presentes na libc ou existentes em formato diferente (extração de substring, concatenação/trim/split de strings, conversão inteiro→string, mapeamento de caracteres, saída para file descriptor).
- **Parte 3 — Lista ligada**: 9 funções para criar e manipular listas simplesmente ligadas usando a estrutura `t_list`.

## Instruções

### Compilação

```bash
make
```

Compila todos os arquivos fonte e gera `libft.a` na raiz do repositório.

### Regras disponíveis

| Regra    | Descrição                               |
|----------|-----------------------------------------|
| `all`    | Compila a biblioteca (`libft.a`)        |
| `clean`  | Remove os arquivos objeto               |
| `fclean` | Remove os arquivos objeto e `libft.a`   |
| `re`     | Recompila a biblioteca do zero          |

### Uso

Inclua o header nos seus arquivos C e link a biblioteca:

```c
#include "libft.h"
```

```bash
cc -Wall -Wextra -Werror seu_programa.c -L. -lft -o seu_programa
```

## Funções

### Parte 1 — Funções da Libc

| Função        | Descrição                                              |
|---------------|--------------------------------------------------------|
| `ft_isalpha`  | Verifica se o caractere é alfabético                  |
| `ft_isdigit`  | Verifica se o caractere é um dígito (0-9)              |
| `ft_isalnum`  | Verifica se o caractere é alfanumérico                 |
| `ft_isascii`  | Verifica se o caractere pertence à tabela ASCII        |
| `ft_isprint`  | Verifica se o caractere é imprimível                   |
| `ft_strlen`   | Calcula o comprimento de uma string                    |
| `ft_memset`   | Preenche uma área de memória com um byte constante     |
| `ft_bzero`    | Zera uma área de memória                               |
| `ft_memcpy`   | Copia uma área de memória                              |
| `ft_memmove`  | Copia uma área de memória (lidando com sobreposição)   |
| `ft_strlcpy`  | Cópia de string com limite de tamanho                  |
| `ft_strlcat`  | Concatenação de string com limite de tamanho           |
| `ft_toupper`  | Converte um caractere para maiúsculo                   |
| `ft_tolower`  | Converte um caractere para minúsculo                   |
| `ft_strchr`   | Localiza a primeira ocorrência de um caractere         |
| `ft_strrchr`  | Localiza a última ocorrência de um caractere           |
| `ft_strncmp`  | Compara duas strings até n caracteres                  |
| `ft_memchr`   | Busca um caractere em uma área de memória              |
| `ft_memcmp`   | Compara duas áreas de memória                          |
| `ft_strnstr`  | Localiza uma substring em uma string (com limite)      |
| `ft_atoi`     | Converte uma string para inteiro                       |
| `ft_calloc`   | Aloca memória inicializada com zero                    |
| `ft_strdup`   | Duplica uma string                                     |

### Parte 2 — Funções adicionais

| Função          | Descrição                                                    |
|-----------------|--------------------------------------------------------------|
| `ft_substr`     | Extrai uma substring de uma string                           |
| `ft_strjoin`    | Concatena duas strings em uma nova                           |
| `ft_strtrim`    | Remove caracteres do início e do fim de uma string           |
| `ft_split`      | Divide uma string por um delimitador em um array             |
| `ft_itoa`       | Converte um inteiro para string                              |
| `ft_strmapi`    | Aplica uma função a cada caractere (com índice)              |
| `ft_striteri`   | Itera e modifica cada caractere (com índice)                 |
| `ft_putchar_fd` | Escreve um caractere em um file descriptor                   |
| `ft_putstr_fd`  | Escreve uma string em um file descriptor                     |
| `ft_putendl_fd` | Escreve uma string + newline em um file descriptor           |
| `ft_putnbr_fd`  | Escreve um inteiro em um file descriptor                     |

### Parte 3 — Funções de lista ligada

| Função           | Descrição                                                     |
|------------------|---------------------------------------------------------------|
| `ft_lstnew`      | Cria um novo nó de lista                                      |
| `ft_lstadd_front`| Adiciona um nó no início da lista                              |
| `ft_lstsize`     | Conta o número de nós na lista                                 |
| `ft_lstlast`     | Retorna o último nó da lista                                   |
| `ft_lstadd_back` | Adiciona um nó no final da lista                               |
| `ft_lstdelone`   | Libera o conteúdo de um nó e o próprio nó                      |
| `ft_lstclear`    | Libera uma lista inteira                                       |
| `ft_lstiter`     | Aplica uma função ao conteúdo de cada nó                       |
| `ft_lstmap`      | Cria uma nova lista aplicando uma função a cada nó             |

## Recursos

- [Norma da 42](https://github.com/42School/norminette)
- [Páginas do man (seção 3)](https://man7.org/linux/man-pages/dir_section_3.html)
- [Referência da Biblioteca C Padrão](https://en.cppreference.com/w/c)
- Ferramentas de IA foram utilizadas para revisão de código e auxílio na depuração durante o desenvolvimento deste projeto.
