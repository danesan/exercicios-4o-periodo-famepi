#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct tipoAresta {
	int vi, vf;
};

typedef struct tipoGrafo {
	int totalV;
	int totalA;
	int **Adj;
};

int **iniciarMatriz(int linha, int coluna) {
	int i = 0, j = 0;
	
	int **M = (int **)malloc(linha * sizeof(int *));
	
	for(;i < linha; i++) {
		M[i] = (int *)malloc(coluna * sizeof(int));
	}

	for(i = 0;i < linha; i++) {
		for(j = 0;j < coluna; j++){
			M[i][j] = 0;
			printf("%d ", M[i][j]);			
		}
		printf("\n");
	}
		
	return M;
}

int menu() {
	int op;
	printf("\n***Grafo com matriz de adjacências***");
	printf("\n\n-------------- MENU ---------------");
	printf("\n[1] Iniciar grafo");
	printf("\n[2] Inserir aresta");
	printf("\n[3] Remover aresta");
	printf("\n[4] Mostrar grafo");
	printf("\n[5] Busca em profundidade");
	printf("\n[6] Busca em largura");
	printf("\n[0] Sair");
	printf("\n\nDigite sua opção: ");
	scanf("%d", &op);
	return op;
}

tipoGrafo *iniciarGrafo(tipoGrafo *grafo, int v){
	grafo = (tipoGrafo *)malloc(sizeof(tipoGrafo));
	grafo->totalV = v;
	grafo->totalA = 0;
	grafo->Adj = iniciarMatriz(v,v);
	
	return grafo;
}

void liberarGrafo(tipoGrafo *grafo) {
	if(grafo != NULL) {
		int i;
		for(i = 0; i < grafo->totalV; i++)
			free(grafo->Adj[i]);
		free(grafo->Adj);
	}
}

void pegarVertices(int *vi, int *vf){
	int v1, v2;
	
	printf("\n\nDigite o 1º vértice: ");
	scanf("%d", &v1);
	printf("\nDigite o 2º vértice: ");
	scanf("%d", &v2);
	
	*vi = v1;
	*vf = v2;
}

void inserirAresta(tipoGrafo *grafo, int vi, int vf, int v) {
	printf("\n\n ARESTAS %d - %d", vi, vf);
	
	if(vi >= v || vf >= v){
		printf("\n\n NÃO É POSSÍVEL ADICIONAR ESSE VÉRTICES %d - %d INSERIDA COM SUCESSO!", vi, vf);
	} else if(vi != vf && grafo->Adj[vi][vf] == 0) {
		grafo->Adj[vi][vf] = 1;
		grafo->Adj[vf][vi] = 1;
		grafo->totalA++;
		printf("\n\n ARESTA %d - %d INSERIDA COM SUCESSO!", vi, vf);
	} else {
		printf("\n\n ARESTA %d - %d JÁ EXISTE!", vi, vf);
	}
	getch();
}

int main() {
	setlocale(LC_ALL, "");
	tipoGrafo *grafo = NULL;
	int op;
	int v,vi,vf;
	
	for(;;){
		system("cls");
		op = menu();
		
		switch (op) {
			case 0 :
				liberarGrafo(grafo);
				printf("\n\n FIM DO PROGRAMA!");	
				return 0;
			case 1:
				if(!grafo) {
					printf("\n\nDigite a quantidade de vértices: ");
					scanf("%d", &v);
					grafo = iniciarGrafo(grafo, v);
					printf("\n\n GRAFO GERADO COM SUCESSO!");
				} else {
					printf("\n\n ERRO! JÁ EXISTE UM GRAFO ALOCADO!");
				}
				getch();
				break;
			case 2:
				if(!grafo) {
					printf("\n\n ERRO! AINDA NÃO EXISTE GRAFO ALOCADO!");
				} else {
					pegarVertices(&vi, &vf);
					inserirAresta(grafo, vi, vf, v);
				}
				break;
		}
	}
	
	return 0;
}
