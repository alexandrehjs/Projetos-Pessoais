#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int vet[], int left, int middle, int right) {
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int temp[right - left + 1]; //vetor auxiliar para mesclar;

    i = left; //índice inicial do primeiro subvetor;
    j = middle + 1; //índice inicial do segundo subvetor;
    k = 0; //índice inicial do vetor temporário;

    //aqui queremos mesclar os elementos dos subvetores esquerdo e direito em ordem crescente;
    while (i <= middle && j <= right) {
        if (vet[i] <= vet[j]) {
            temp[k++] = vet[i++];
        } else {
            temp[k++] = vet[j++];
        }
    }

    while (i <= middle)
        temp[k++] = vet[i++];

    while (j <= right)
        temp[k++] = vet[j++];

    //aqui copiamos os elementos do vetor temporário de volta para o vetor original;
    for (i = left, k = 0; i <= right; i++, k++)
        vet[i] = temp[k];
}

void mergeSort(int vet[], int left, int right) {
    if (left < right) {
        //aqui verificamos se há mais de um elemento no intervalo a ser ordenado,se sim, dividimos o intervalo ao meio e chamamos recursivamente a função mergeSort para ordenar os subintervalos da esquerda e da direita;
        int middle = left + (right - left) / 2;

        mergeSort(vet, left, middle);
        mergeSort(vet, middle + 1, right);

        merge(vet, left, middle, right);
    }
}

void preencherVetor(int vet[], int tamanho) {
    srand(time(NULL));
    for (int i = 0; i < tamanho; i++) {
        vet[i] = rand() % 100;
    }
}

void imprimirVetor(int vet[], int tamanho) {
   
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");
}

int main() {
    int tamanho;
    
    printf("Qual o tamanho do vetor desejado: ");
    scanf("%d ", &tamanho);
    int vet[tamanho];

    preencherVetor(vet, tamanho);
    printf("Vetor original: ");
    imprimirVetor(vet, tamanho);

    mergeSort(vet, 0, tamanho - 1);

    printf("Vetor ordenado: ");
    imprimirVetor(vet, tamanho);

    return 0;
}
