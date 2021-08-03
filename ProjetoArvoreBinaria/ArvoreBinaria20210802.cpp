#include <stdio.h>
#include <locale.h>
#include <system.h>

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

inserir() {
	
}

mostrar() {
	
}

pesquisar() {
	
}

excluir() {
}

mostrarItem() {
	
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
				aux = preencher _item();
				if(!raiz) 
					raiz = inserir(aux, raiz, raiz);
				else 
					inserir(aux, raiz, raiz);
				break;
			case 2: 
				printf("\n\n\CONTEÚDO DA ÁRVORE: ");
				mostrar(raiz);
				getch();
				break;
			case 3: 
				printf("\n\n\PESQUISA DA ÁRVORE ");
				printf("\n\n\Digite o código do item a pesquisar: ");
				scanf("%d", &cod);
				achou = 0;
				pesquisar(&achou, cod, raiz);
				if(!achou) {
					printf("\n\nO item de código %d não está na árvore", cod);
				}
				getch();
				break;
			case 4: 
				printf("\n\n\EXCLUIR DA ÁRVORE ");
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
	}
}
