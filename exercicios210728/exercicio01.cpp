#include <stdio.h>
#include <locale.h>

int fatorial(int n){
	if(n == 0)
	return 1;
	return n*fatorial(n-1);
}

int main() {
	setlocale(LC_ALL, "");
	int num;
	printf("Digite um n�mero: ");
	scanf("%d", &num);
	if(num >= 0)
    	printf("Fatorial de %d � %d",num, fatorial(num));
}
