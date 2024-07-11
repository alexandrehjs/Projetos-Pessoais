#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//função para preencher o vetor com números aleatórios;
void preencherVetor(int vetor[], int tamanho) {
    int i;
    srand(time(NULL)); // mais uma vez faremos o uso do "srand" para gerar os números aleátorios;
    for (i = 0; i < tamanho; i++) {
        vetor[i] = rand(); //limitando entre 1 e 10; 
    }
}

//função para imprimir o vetor;
void imprimirVetor(int vetor[], int tamanho) {
    int i;
    for (i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

//aqui fazemos uso primeiramente do "bubble sort" para ordenar os elementos em ordem crescente ou decrescente;
//esse método funciona comparando cada elemento da lista com o próximo, trocando de posição caso esteja fora de ordem;
void bubbleSort(int vetor[], int tamanho) {
    int i, j, temp;
    for (i = 0; i < tamanho-1; i++) {
        for (j = 0; j < tamanho-i-1; j++) {
            if (vetor[j] > vetor[j+1]) {
                temp = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = temp;
            }
        }
    }
}

//assim como o "bubble sorte", o Selection sort é também uma função usada para ordenar um vetor ou elementos;
//ele funciona selecionando repetidamente o menor (ou maior, dependendo da ordem desejada) elemento da lista e movendo-o para a posição correta;
void selectionSort(int vetor[], int tamanho) {
    int i, j, minIndex, temp;
    for (i = 0; i < tamanho-1; i++) {
        minIndex = i;
        for (j = i+1; j < tamanho; j++) {
            if (vetor[j] < vetor[minIndex]) {
                minIndex = j;
            }
        }
        temp = vetor[i];
        vetor[i] = vetor[minIndex];
        vetor[minIndex] = temp;
    }
}

//aqui temos a implementação do "Insertion sort", que acaba por ser o modo de ordenação mais eficiente, por sua praticidade em comparar um elemento com todos os demais já vistos e o insere no local devido (em resumo); 
void insertionSort(int vetor[], int tamanho) {
    int i, j, chave;
    for (i = 1; i < tamanho; i++) {
        chave = vetor[i];
        j = i - 1;
        while (j >= 0 && vetor[j] > chave) {
            vetor[j+1] = vetor[j];
            j = j - 1;
        }
        vetor[j+1] = chave;
    }
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
    int tamanho, i;
    int op;

    printf("Digite a opção desejada:\n 1 - booble sort\n 2 - selection sort\n 3 - insertion sort:\n 4 - quick sort\n");
    scanf("%d", &op);
    printf("Digite o tamanho desejado do vetor: ");
    scanf("%d", &tamanho);
    int vetor[tamanho];
    
    srand(time(NULL));

    preencherVetor(vetor, tamanho);
    printf("Vetor original: ");
    imprimirVetor(vetor, tamanho);

    switch (op)
    {
    case 1:
    //imprimindo usando da função "Bubble sort";
    bubbleSort(vetor, tamanho);
    printf("Vetor ordenado com Bubble Sort: ");
    imprimirVetor(vetor, tamanho);
    break;

    case 2:
    //imprimindo usando o "Selection sort";
    selectionSort(vetor, tamanho);
    printf("Vetor ordenado com Selection Sort: ");
    imprimirVetor(vetor, tamanho);
    break;

    case 3:
    //e por ultimo temos imprimindo com o "Insertion sort";
    insertionSort(vetor, tamanho);
    printf("Vetor ordenado com Insertion Sort: ");
    imprimirVetor(vetor, tamanho);
    break;

    case 4:
    quickSort(vetor, 0 , tamanho - 1);
    printf("Vetor ordenado com quick sort: ");
    imprimirVetor(vetor, tamanho);

    default: 
        printf("Operação inválida");
        break;
    }
    return 0;
}
