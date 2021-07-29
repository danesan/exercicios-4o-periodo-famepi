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
	printf("Digite um número: ");
	scanf("%d", &num);
	if(num >= 0)
    	printf("Fatorial de %d é %d",num, fatorial(num));
}
