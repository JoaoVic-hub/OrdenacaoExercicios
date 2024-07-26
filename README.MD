# Algoritmos de Ordenação

Este projeto implementa dois algoritmos clássicos de ordenação: **Selection Sort** e **Insertion Sort**. O objetivo é comparar o desempenho dos dois algoritmos em termos de tempo de execução, usando dados de entrada fornecidos em arquivos de texto.

## Estrutura do Projeto

- **Algoritmos_Ordenacao.c**: Arquivo principal contendo a implementação dos algoritmos de ordenação e a lógica do programa.
- **Makefile**: Arquivo de automação para compilar o programa.
- **Arquivos de Teste**: Arquivos de texto contendo os dados a serem ordenados (ex.: `num.1000.4.in`).

## Algoritmos Implementados

### 1. Selection Sort

O **Selection Sort** é um algoritmo de ordenação simples que divide o array em duas partes: a parte ordenada à esquerda e a parte não ordenada à direita. Ele repete o seguinte processo:

1. Encontra o menor elemento na parte não ordenada.
2. Troca esse elemento com o primeiro elemento não ordenado.
3. Move o limite entre as partes ordenada e não ordenada para a direita.

### 2. Insertion Sort

O **Insertion Sort** constrói a matriz final uma peça de cada vez, percorrendo da esquerda para a direita e inserindo cada elemento na sua posição correta na parte já ordenada.

## Uso

### Compilação

Para compilar o programa, você pode usar o `Makefile` fornecido. Execute o seguinte comando no terminal:

```bash
make
