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
	printf("Digite um n�mero: ");
	scanf("%d", &num);
	if(num > 0)
    	printf("O %do termo da s�rie de Fibonnaci � %d",num, fibonacci(num));
}
