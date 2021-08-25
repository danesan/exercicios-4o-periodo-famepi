#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

void inserir(int *vet, int tam){
	int i = 0;
	
	for(i;i < tam; i++){
		vet[i] = rand() % 100;
	}
}

void mostrar(int *vet, int tam){
	int i = 0;

	printf("\n\n[");
	for(i;i < tam; i++){
		if (i == tam-1) {
			printf("%d", vet[i]);
		} else {
			printf("%d ", vet[i]);
		}
	}
	printf("]");
}

/*-------------------------------------------------------
SEJA f UMA FUNÇÃO DE COMPLEXIDADE TAL QUE f(n) É O NÚMERO
DE COMPARAÇÕES ENTRE OS ELEMENTOS DE UM VETOR A, SE A 
CONTIVER n ELEMENTOS.LOGO: f(n) = n - 1, PARA n > 0.

TEOREMA: Qualquer algoritmo para encontrar o maior elemento
de um conjunto com n elementos, sendo n >= 1, faz pelo menos 
n-1 comparações.
PROVA: Cada um dos n-1 elementos tem que ser mostrada, 
através de comparações, que é menor do que algum outro. Logo
n-1 comparações são necessárias.
--------------------------------------------------------*/
int max(int *vet, int tam) {
	int i = 0, max = vet[0];
	for(; i < tam; i++){
		if(max < vet[i]) {
			max = vet[i];
		}
	}
	return max;
}

/*-------------------------------------------------------
SEJA f UMA FUNÇÃO DE COMPLEXIDADE TAL QUE f(n) É O NÚMERO
DE COMPARAÇÕES ENTRE OS ELEMENTOS DE UM VETOR A, SE A 
CONTIVER n ELEMENTOS.LOGO: f(n) = 2(n - 1), PARA n > 0.
-------------------------------------------------------*/
void maxMin1(int *vet, int tam) {
	int i = 0, min = vet[0], max = vet[0];
	for(; i < tam; i++){
		if(vet[i] > max) {
			max = vet[i];
		}
		if(vet[i] < min) {
			min = vet[i];
		}
	}
	printf("\nMínimo: %d Máximo: %d", min, max);
}

/*-------------------------------------------------------
SEJA f UMA FUNÇÃO DE COMPLEXIDADE TAL QUE f(n) É O NÚMERO
DE COMPARAÇÕES ENTRE OS ELEMENTOS DE UM VETOR A, SE A 
CONTIVER n ELEMENTOS.LOGO: 
melhor caso: f(n) = n - 1, 
pior caso: f(n) = 2(n - 1)
caso médio: f(n) = 3n/2 - 3/2. Pois f(n) = 2(n-1)/2
 + (n-1)/2
PARA n > 0.
-------------------------------------------------------*/
void maxMin2(int *vet, int tam) {
	int i = 0, min = vet[0], max = vet[0];
	for(; i < tam; i++){
		if(vet[i] > max) {
			max = vet[i];
		} else if(vet[i] < min) {
			min = vet[i];
		}
	}
	printf("\nMínimo: %d Máximo: %d", min, max);
}

void maxMin3(int *vet, int tam) {
	int i = 2, min = vet[0], max = vet[0];
	if(tam % 2 > 0) {
		vet[tam] = vet[tam-1];
	}
	if(vet[0] > vet[1]) {
		max = vet[0];
		min = vet[1];
	} else {
		max = vet[1];
		min = vet[0];	
	}
	while(i < tam){
		if(vet[i] > vet[i+1]) {
			if(vet[i] > max) {
				max = vet[i];
			}
			if(vet[i+1] < min) {
				min = vet[i+1];
			}
		} else {
			if(vet[i] < min) {
				min = vet[i];
			}
			if(vet[i+1] > max) {
				max = vet[i+1];
			}
		}
		i += 2;
	}
	printf("\nMínimo: %d Máximo: %d", min, max);
}

int main() {
	setlocale(LC_ALL, "");
	int i = 0, tam = 0, *vet;
	srand(time(NULL));
	
	scanf("%d", &tam);
	vet = (int *) malloc(tam * sizeof(int));
	
	inserir(vet, tam);
	mostrar(vet, tam);
	maxMin3(vet, tam);
	
	return 0;
}
