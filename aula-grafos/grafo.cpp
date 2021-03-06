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
	printf("\n***Grafo com matriz de adjac?ncias***");
	printf("\n\n-------------- MENU ---------------");
	printf("\n[1] Iniciar grafo");
	printf("\n[2] Inserir aresta");
	printf("\n[3] Remover aresta");
	printf("\n[4] Mostrar grafo");
	printf("\n[5] Busca em profundidade");
	printf("\n[6] Busca em largura");
	printf("\n[0] Sair");
	printf("\n\nDigite sua op??o: ");
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
	
	printf("\n\nDigite o 1? v?rtice: ");
	scanf("%d", &v1);
	printf("\nDigite o 2? v?rtice: ");
	scanf("%d", &v2);
	
	*vi = v1;
	*vf = v2;
}

int verticesOk(int vi, int vf, int v) {
	if(vi < 0 || vi >= v){
		printf("\n\n V?RTICE %d INV?LIDO!", vi);
		return 0;
	}
	if(vf < 0 || vf >= v){
		printf("\n\n V?RTICE %d INV?LIDO!", vf);	
		return 0;
	}
	return 1;
}

void inserirAresta(tipoGrafo *grafo, int vi, int vf, int v) {	
	if(!verticesOk(vi, vf, v)){
		printf("\n N?O ? POSS?VEL ADICIONAR ESSE V?RTICES %d - %d", vi, vf);
		return;
	} else if(vi != vf && grafo->Adj[vi][vf] == 0) {
		grafo->Adj[vi][vf] = 1;
		grafo->Adj[vf][vi] = 1;
		grafo->totalA++;
		printf("\n\n ARESTA %d - %d INSERIDA COM SUCESSO!", vi, vf);
	} else {
		printf("\n\n ARESTA %d - %d J? EXISTE!", vi, vf);
	}
}

void exibeMatriz (tipoGrafo *grafo) {
	int i = 0, j =0;
	
	for(i=0;i < grafo->totalV; i++) {
		for(j=0;j < grafo->totalV; j++){
			printf("%d ", grafo->Adj[i][j]);			
		}
		printf("\n");
	}
}

void mostrarGrafo(tipoGrafo *grafo) {
	int i = 0, j = 0;
	
	exibeMatriz(grafo);
	
	printf("\n\n GRAFO COM MATRIZ DE ADJAC?NCIA COM %d V?RTICES\n", grafo->totalV);
	for(i=0; i < grafo->totalV;i++) {
		printf("\n%2d:",i);
		for(j=0; j < grafo->totalV;j++) {
			if(grafo->Adj[i][j]) {
				printf("%2d ", j);
			}
		}
	}
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
					printf("\n\nDigite a quantidade de v?rtices: ");
					scanf("%d", &v);
					grafo = iniciarGrafo(grafo, v);
					printf("\n\n GRAFO GERADO COM SUCESSO!");
				} else {
					printf("\n\n ERRO! J? EXISTE UM GRAFO ALOCADO!");
				}
				getch();
				break;
			case 2:
				if(!grafo) {
					printf("\n\n ERRO! AINDA N?O EXISTE GRAFO ALOCADO!");
				} else {
					pegarVertices(&vi, &vf);
					inserirAresta(grafo, vi, vf, v);
				}
				getch();
				break;
			case 4: 
				if(!grafo) {
					printf("\n\n ERRO! AINDA N?O EXISTE GRAFO ALOCADO!");
				} else {
					mostrarGrafo(grafo);
				}
				getch();
				break;
		}
	}
	
	return 0;
}
