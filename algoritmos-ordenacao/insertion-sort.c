#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>

void inserir(int *vet, int tam){
	int i = 0;
	
	for(i;i < tam; i++){
		//printf("\nDigite o %do número:", i+1);
		//scanf("%d", &vet[i]);
		vet[i] = rand() % 100;
	}
}

void mostrar(int *vet, int tam){
	int i = 0;

	printf("\n[");
	for(i;i < tam; i++){
		if (i == tam-1) {
			printf("%d", vet[i]);
		} else {
			printf("%d ", vet[i]);
		}
	}
	printf("]");

	
}

void insertionSort(int *vet, int tam){
	int i = 1, j = 0, aux = 0;
	
	for (; i < tam; i++) {
		aux = vet[i];
		j = i - 1;
		while(j >= 0 && aux < vet[j]) {
			vet[j+1] = vet[j];
			j--;	
		}
		vet[j+1] = aux;
	}		
}

int main() {
	setlocale(LC_ALL, "");
	
	int *vet, tam;
	
	printf("\n\nDigite o tamanho do vetor:");
	scanf("%d", &tam);
	
	vet = (int *) malloc(sizeof(int));
		
	inserir(vet, tam);
	
	printf("\n\nVetor original:");
	mostrar(vet, tam);
	
	insertionSort(vet, tam);
	
	printf("\n\nVetor ordenado:");
	mostrar(vet, tam);
	
	return 0;
}
