#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <conio.h>

typedef struct tipo_item {
	int cod;
	char nome[30];
	int quant;
};


typedef struct tipo_no {
	tipo_item item;
	tipo_no *esq;
	tipo_no *dir;
};

tipo_item preencher_item() {
	tipo_item item;
	printf("\n\n ***** PREENCHENDO ITEM A SER INSERIDO *****");
	printf("\n Digite o c�digo: ");
	scanf("%d", &item.cod);
	fflush(stdin);
	printf("\n Digite o nome do item: ");
	gets(item.nome);
	printf("\n Digite a quantidade: ");
	scanf("%d", &item.quant);
	
	return (item);
}

tipo_no* inserir(tipo_item aux, tipo_no *raiz, tipo_no *r) {
	
	if(!r) { //se n�o estiver apontando para algum endere�o de mem�ria
		r = (tipo_no *) malloc(sizeof(tipo_no));
		
		if(!r) {
			printf("\n\n ERRO: problema de espe�o de mem�ria!");
			getch();
			exit(0);
		}
		
		r->esq = NULL;
		r->dir = NULL;
		r->item = aux;
		
		if(!raiz) {
			printf("\n\n Item inserido com sucesso!");
			getch();
			return r;   //primeiro entrada => raiz da �rvore
		}
		
		if(aux.cod < raiz->item.cod) {
			raiz->esq = r;
		} else {
			raiz->dir = r;
		}
		
		printf("\n\n Item inserido com sucesso!");
		getch();
		return r;
	}
	
	if(aux.cod < r->item.cod) {
		inserir(aux, r, r->esq); // aqui entra a recurs�o para o filho da esquerdsa
	} else if(aux.cod > r->item.cod) {
		inserir(aux, r, r->dir); //aqui entra a recurs�o para o filho da direita
	} else {
		printf("\n\n IMPOSS�VEL INSERIR!");
		printf("\n\n Motivo: J� existe um item com o c�digo %d na �rvore", aux.cod);
		getch();
	}
}

void mostrar(tipo_no *raiz) {
	
	if(!raiz) {
		return;
	}
	
	mostrar(raiz->esq);
	printf("\n**********************");
	printf("\n Cod: %d", raiz->item.cod);	
	printf("\n Nome: %s", raiz->item.nome);
	printf("\n Quantidade: %d \n", raiz->item.quant);
	mostrar(raiz->dir);
}

void pesquisar(int codPesq, tipo_no *raiz) {
	if(!raiz) {
		printf("\n\n O item de c�digo %d n�o est� na �rvore", codPesq);
		return;
	}

	if(codPesq < raiz->item.cod){
		pesquisar(codPesq, raiz->esq);
		return;
	}
	if(codPesq > raiz->item.cod){
		pesquisar(codPesq, raiz->dir);
	} else {
		printf("\n\n***** ITEM ENCONTRADO *****");
		printf("\n Cod: %d", raiz->item.cod);	
		printf("\n Nome: %s", raiz->item.nome);
		printf("\n Quantidade: %d \n", raiz->item.quant);
	}

}

void excluir() {
}

void mostrarItem() {
	
}

int menu() {
	int op = 0;
	
	do {
		printf("\n\n ********** MENU **********");
		printf("\n [1] - INSERIR");
		printf("\n [2] - MOSTRAR");
		printf("\n [3] - ");
		printf("\n [4] - ");
		printf("\n [5] - ");
		printf("\n [0] - SAIR");
		
		printf("\n\n Op��o: ");
		scanf("%d", &op);
		
		if(op == 0) {
			exit(0);
		} else if(op < 1 || op > 5) {
			printf("\nOP��O INV�LIDA!");
			getch();
			system("cls");
		} 
		return op;
	} while (true);
}




int main() {
	setlocale(LC_ALL,"");
	
	int op, cod, achou;
	tipo_no *raiz = NULL;
	tipo_item aux;
	
	do {
		system("cls");
		op = menu();
		
		switch(op) {
			case 0 : 
				printf("\n\n\t FIM DO PROGRAMA.\n\n");
				getch();
				return 0;
			case 1:
				aux = preencher_item();
				if(!raiz) 
					raiz = inserir(aux, raiz, raiz);
				else 
					inserir(aux, raiz, raiz);
				break;
			case 2:  
				if(!raiz) {
					printf("\n�rvore vazia! Insira uma item primeiro.");
					getch();
					break;
				}
				printf("\n\n\CONTE�DO DA �RVORE: ");
				mostrar(raiz);
				getch();
				break;
			case 3: 
				printf("\n\n\PESQUISA DA �RVORE ");
				printf("\n\n\Digite o c�digo do item a pesquisar: ");
				scanf("%d", &cod);
				achou = 0;
				//pesquisar(&achou, cod, raiz);
				if(!achou) {
					printf("\n\nO item de c�digo %d n�o est� na �rvore", cod);
				}
				getch();
				break;
			case 4: 
				printf("\n\n\EXCLUIR DA �RVORE ");
				printf("\n\n\Digite o c�digo do item a excluir: ");
				scanf("%d", &cod);
				achou = 0;
				//raiz = excluir(&achou, cod, raiz);
				if(!achou) {
					printf("\n\nO item de c�digo %d n�o est� na �rvore", cod);
				}
				getch();
				break;

		}
	} while (true);
	return 0;
}
