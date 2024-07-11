#include <stdio.h>
#include <stdlib.h>

int buscaBinaria(int key,int *vet, int meio, int inicio, int fim){
    if(inicio <= fim){
       int meio = (inicio + fim) / 2;

        if(key == vet[meio]){
            return meio;
        }
        else if(key < vet[meio]){
                return buscaBinaria(key, vet, inicio , meio - 1);
            }
        else{
                return buscaBinaria(key, vet, meio + 1, fim);
        }
    } return -1;
}

int main(){
    int tam;
    int valor, op;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tam);
    int vet[tam];

    while (op != 0)
    {
        printf("Qual valor deseja buscar ?: ");
        scanf("%d", &valor);

        printf("Resultado: %d\n", buscaBinaria(vet, valor, tam));
        
        printf("\n0 - Sair.\n1 - Fazer outra busca\n");
        scanf("%d", &op);
    } while (op != 0);
    
    return 0;


}