#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para ordenar um array usando Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
}

// Função para ordenar um array usando Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Função para imprimir um array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(int argc, char *argv[]) {
    // Verifica se o nome do arquivo foi passado como argumento
    if (argc < 2) {
        printf("Uso: %s <arquivo_de_entrada>\n", argv[0]);
        return 1; // Retorna 1 indicando erro
    }

    // Abre o arquivo para leitura
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo"); // Exibe mensagem de erro se o arquivo não puder ser aberto
        return 1; // Retorna 1 indicando erro
    }

    int size;
    // Lê o tamanho do array
    fscanf(file, "%d", &size);
    // Aloca memória para o array
    int *arr = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        // Lê cada elemento do arquivo
        fscanf(file, "%d", &arr[i]);
    }
    fclose(file); // Fecha o arquivo

    printf("Array original: \n");
    printArray(arr, size); // Imprime o array original

    // Cria uma cópia do array para usar com o segundo algoritmo de ordenação
    int *arr_copy = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        arr_copy[i] = arr[i];
    }

    // Medição de tempo para Selection Sort
    clock_t start, end;
    start = clock(); // Marca o tempo de início
    selectionSort(arr, size);
    end = clock(); // Marca o tempo de fim
    double timeSelectionSort = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Array ordenado usando Selection Sort: \n");
    printArray(arr, size); // Imprime o array ordenado
    printf("Tempo gasto pelo Selection Sort: %f segundos\n", timeSelectionSort); // Calcula e imprime o tempo de execução

    // Reseta o array para o estado original usando a cópia
    for (int i = 0; i < size; i++) {
        arr[i] = arr_copy[i];
    }

    // Medição de tempo para Insertion Sort
    start = clock(); // Marca o tempo de início
    insertionSort(arr, size);
    end = clock(); // Marca o tempo de fim
    double timeInsertionSort = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Array ordenado usando Insertion Sort: \n");
    printArray(arr, size); // Imprime o array ordenado
    printf("Tempo gasto pelo Insertion Sort: %f segundos\n", timeInsertionSort); // Calcula e imprime o tempo de execução

    // Comparação dos tempos de execução
    if (timeSelectionSort < timeInsertionSort) {
        printf("Selection Sort foi mais rapido.\n");
    } else if (timeSelectionSort > timeInsertionSort) {
        printf("Insertion Sort foi mais rapido.\n");
    } else {
        printf("Ambos os algoritmos levaram o mesmo tempo.\n");
    }

    // Libera a memória alocada
    free(arr);
    free(arr_copy);

    return 0;
}