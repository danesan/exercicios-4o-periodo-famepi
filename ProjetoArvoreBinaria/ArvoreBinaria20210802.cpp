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
	printf("\n Digite o código: ");
	scanf("%d", &item.cod);
	fflush(stdin);
	printf("\n Digite o nome do item: ");
	gets(item.nome);
	printf("\n Digite a quantidade: ");
	scanf("%d", &item.quant);
	
	return (item);
}

tipo_no* inserir(tipo_item aux, tipo_no *raiz, tipo_no *r) {
	
	if(!r) { //se não estiver apontando para algum endereço de memória
		r = (tipo_no *) malloc(sizeof(tipo_no));
		
		if(!r) {
			printf("\n\n ERRO: problema de espeço de memória!");
			getch();
			exit(0);
		}
		
		r->esq = NULL;
		r->dir = NULL;
		r->item = aux;
		
		if(!raiz) {
			printf("\n\n Item inserido com sucesso!");
			getch();
			return r;   //primeiro entrada => raiz da árvore
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
		inserir(aux, r, r->esq); // aqui entra a recursão para o filho da esquerdsa
	} else if(aux.cod > r->item.cod) {
		inserir(aux, r, r->dir); //aqui entra a recursão para o filho da direita
	} else {
		printf("\n\n IMPOSSÍVEL INSERIR!");
		printf("\n\n Motivo: Já existe um item com o código %d na árvore", aux.cod);
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
		printf("\n\n O item de código %d não está na árvore", codPesq);
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

tipo_no* excluir(int *achou, int codExcluir, tipo_no *raiz) {
	if(!raiz) {
		return raiz;
	}
	
	tipo_no *p1, *p2;
	if(raiz->item.cod == codExcluir) { // quando encontra o código de fato e apagar a raiz(ou a folha nó)
		*achou = 1;
		
		if(raiz->esq == raiz->dir) { //se eles são nulos, ou seja, é um nó folha
			free(raiz);
			return NULL;
		} else if(raiz->esq == NULL) {
			p1 = raiz->dir;
			free(raiz);
			return p1;
		} else {
			//vai para a raiz da subárvore direita
			p1 = raiz->dir;
			p2 = raiz->dir;
			
			//navega até o último nó mais a esquerda
			while(p1->esq) {
				p1 = p1->esq;
			}
			
			//essa folha vai ser a nova raiz
			p1->esq = raiz->esq;
			free(raiz);
			
			return p2;
		}
	}
	
	if(raiz->item.cod < codExcluir){
		raiz->dir = excluir(achou, codExcluir, raiz->dir);
	} else {
		raiz->esq = excluir(achou, codExcluir, raiz->esq);	
	}
	return raiz;
}


int menu() {
	int op = 0;
	
	do {
		printf("\n\n ********** MENU **********");
		printf("\n [1] - INSERIR");
		printf("\n [2] - MOSTRAR");
		printf("\n [3] - PESQUISAR");
		printf("\n [4] - EXCLUIR");
		printf("\n [0] - SAIR");
		
		printf("\n\n Opção: ");
		scanf("%d", &op);
		
		if(op == 0) {
			exit(0);
		} else if(op < 1 || op > 5) {
			printf("\nOPÇÃO INVÁLIDA!");
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
					printf("\nÁrvore vazia! Insira uma item primeiro.");
					getch();
					break;
				}
				printf("\n\nCONTEÚDO DA ÁRVORE: ");
				mostrar(raiz);
				getch();
				break;
			case 3: 
				printf("\n\nPESQUISA DA ÁRVORE ");
				printf("\n\n\Digite o código do item a pesquisar: ");
				scanf("%d", &cod);
				achou = 0;
				pesquisar(cod, raiz);
				if(!achou) {
					printf("\n\nO item de código %d não está na árvore", cod);
				} else {
	    				printf("\n\n O item de código %d foi excluído com sucesso !!!", cod);	
					}
				getch();
				break;
			case 4: 
				printf("\n\nEXCLUIR DA ÁRVORE ");
				printf("\n\n\Digite o código do item a excluir: ");
				scanf("%d", &cod);
				achou = 0;
				raiz = excluir(&achou, cod, raiz);
				if(!achou) {
					printf("\n\nO item de código %d não está na árvore", cod);
				}
				getch();
				break;

		}
	} while (true);
	return 0;
}
