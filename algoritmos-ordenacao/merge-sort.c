#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include<time.h>

void inserir(int *vet, int tam){
	int i = 0;

	srand(time(NULL));
	
	for(i;i < tam; i++){
		vet[i] = rand() % tam;
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

void merge (int *vet, int comeco, int meio, int fim) {
	int com1 = comeco, com2 = meio+1, com_aux = 0, tam = fim - comeco + 1;
	int *vet_aux = (int *) malloc(tam*sizeof(int));
	
	while(com1 <= meio && com2 <= fim) {
		if (vet[com1] < vet[com2]) {
			vet_aux[com_aux] = vet[com1];
			com1++;
		} else {
			vet_aux[com_aux] = vet[com2];
			com2++;
		}
		com_aux++;
	}
	
	while(com1 <= meio) {
		vet_aux[com_aux] = vet[com1];
		com_aux++;
		com1++;
	}
	
	while(com2 <= fim) {
		vet_aux[com_aux] = vet[com2];
		com_aux++;
		com2++;
	}

	for(com_aux = comeco; com_aux <= fim; com_aux++){
		vet[com_aux] = vet_aux[com_aux-comeco];
	}
	
	free(vet_aux);
}

void mergeSort(int *vet, int comeco, int fim) {
	if(comeco < fim){
		int meio = (comeco+fim)/2;
		mergeSort(vet, comeco, meio);
		mergeSort(vet, meio+1, fim);
		merge(vet, comeco, meio, fim);
	}	 
}

int main() {
	setlocale(LC_ALL, "");
	
	int *vet, tam;
	
	printf("\n\nDigite o tamanho do vetor: ");
	scanf("%d", &tam);
	
	vet = (int *) malloc(tam*sizeof(int));
		
	inserir(vet, tam);
	
	printf("\n\nVetor original:");
	mostrar(vet, tam);
	
	mergeSort(vet, 0, tam-1);
	
	printf("\n\nVetor ordenado:");
	mostrar(vet, tam);
	
	return 0;
}


