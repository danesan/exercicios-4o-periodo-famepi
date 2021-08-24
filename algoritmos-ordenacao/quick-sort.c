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

void quickSort(int *vet, int esq, int dir) {
	register int i, j;
	int pivot, aux;
	i = esq;
	j = dir;
	pivot = vet[(esq + dir)/2];
	
	do {
		while (vet[i] < pivot && i < dir) i++;
		while (pivot < vet[j] && j > esq) j--;
		if (i <= j) {
			aux = vet[i];
			vet[i] = vet[j];
			vet[j] = aux;
			i++;
			j--;
		}
	} while(i <= j);
	
	if(esq < j)
		quickSort(vet, esq, j);
	if(i < dir)
		quickSort(vet, i, dir);
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
	
	quickSort(vet, 0, tam-1);
	
	printf("\n\nVetor ordenado:");
	mostrar(vet, tam);
	
	return 0;
}


