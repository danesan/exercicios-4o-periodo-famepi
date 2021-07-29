#include <stdio.h>
#include <locale.h>

int somatorio(int n){
	if(n == 1)
		return 1;
	return n + somatorio(n-1);
}

int main() {
	setlocale(LC_ALL, "");
	int num;
	printf("Digite um número: ");
	scanf("%d", &num);
	if(num > 0)
    	printf("Somatório de %d é %d",num, somatorio(num));
}
