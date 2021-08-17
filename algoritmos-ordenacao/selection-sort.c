#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>

void inserir(int *vet, int tam){
	int i = 0;
	
	for(i;i < tam; i++){
		//printf("\nDigite o %do número:", i+1);
		//scanf("%d", &vet[i]);
		vet[i] = rand() % 100 + 1;
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

void selectionSort(int *vet, int tam){
	int aux = 0, i = 0, j = 0, indice_menor = 0;
	
	for (; i < tam-1; i++) {
		indice_menor = i;
		for(j = i+1; j < tam; j++){
			if(vet[j] < vet[indice_menor]) {
				indice_menor = j;
			}
		}
		if(indice_menor != i) {
			aux = vet[i]; ;
			vet[i] = vet[indice_menor];
			vet[indice_menor] = aux;			
		}
		mostrar(vet, tam);
	}
 }

int main() {
	setlocale(LC_ALL, "");
	
	int *vet, tam;
	
	printf("\n\nDigite o tamanho do vetor: ");
	scanf("%d", &tam);
	
	vet = (int *) malloc(sizeof(int));
		
	inserir(vet, tam);
	
	printf("\n\nVetor original:");
	mostrar(vet, tam);
	
	selectionSort(vet, tam);
	
	printf("\n\nVetor ordenado:");
	mostrar(vet, tam);
	
	return 0;
}
