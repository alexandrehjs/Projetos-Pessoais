#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencherVetor(int vetor[], int tamanho) {
    int i;
    srand(time(NULL)); // novamente faremos o uso do "srand" para gerar os números aleátorios para teste do nosso método;
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 50;  
    }
}

void imprimirVetor(int vetor[], int tamanho) {
    int i;
    for (i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int particionarVetor(int *vet, int start, int end) {
    int pivot = (vet[start] + vet[end] + (vet[start] + vet[end]) / 2) / 3;//fazemos uma função para encontrar o pivo do vetor de modo que pegamos a soma do inico, fim e meio do vetor e os divide por tres; 

    while (start < end) {//aqui partiremos com um while com a condição de que se o inicio for menor que o fim, prosseguir com a verificação;
        while (start < end && vet[start] <= pivot) {//muito importante essa condição, pois ela fará a verificação que se o inicio continuar sendo menor que o pivo, fara a incrementação para o próximo indice, seguindo assim a verificação do vetor;
            start = start + 1;
        }
        while (start < end && vet[end] > pivot) {//nesta condição se fará a verificação de que se o fim for maior do que o pivo, irá ter uma decrementação no indice de verificação; 
            end = end - 1;
        }
        //criamos uma variavel auxiliar para receber o valor do inicio, que por sua vez receba o fim para fazer a troca, ao final o nosso fim receberá o auxiliar que foi trocado; 
        int aux = vet[start];
        vet[start] = vet[end];
        vet[end] = aux;
    }  
    return start;  
}

void quickSort(int *vet, int start, int end) {
    if (start < end) {
        int pos = particionarVetor(vet, start, end);
        //o quickSort é implementado duas vezes para fazer a ordenação dos vetores que foram separados;
        //de forma recursiva iremos classificar os subvetores à esquerda e à direita do pivô, até que todo o vetor esteja ordenado;
        quickSort(vet, start, pos - 1); //vetor a direita;
        quickSort(vet, pos, end); //vetor a esquerda;
    }
}

int main() {
    int tamanho;

    printf("Qual o tamanho do vetor desejado: ");
    scanf("%d", &tamanho);
    int vetor[tamanho];

    preencherVetor(vetor, tamanho);
    printf("Vetor original: ");
    imprimirVetor(vetor, tamanho);

    quickSort(vetor, 0, tamanho - 1); 
    printf("Vetor ordenado: ");
    imprimirVetor(vetor, tamanho);

    return 0;
}
