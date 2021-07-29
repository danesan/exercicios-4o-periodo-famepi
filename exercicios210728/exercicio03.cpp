#include <stdio.h>
#include <locale.h>

int fibonacci(int n){
	//if(n < 3)
	//	return 1;
	if(n <= 1){
		return  n;
	}
	return fibonacci(n-1) + fibonacci(n-2);;
}

int main() {
	setlocale(LC_ALL, "");
	int num;
	printf("Digite um número: ");
	scanf("%d", &num);
	if(num > 0)
    	printf("O %do termo da série de Fibonnaci é %d",num, fibonacci(num));
}
