#include <stdio.h>
#include <locale.h>

int fibonacci(int n){
	if(n <= 1){
		//printf("%d ", n);
		return n;
	}
	printf("%d ", fibonacci(n-1));
	return n-1;
	//return fibonacci(n-1);
}

int main() {
	setlocale(LC_ALL, "");
	int num;
	printf("Digite um n�mero: ");
	scanf("%d", &num);
	fibonacci(num);
	//if(num > 0)
    //	printf("O %do termo da s�rie de Fibonnaci � %d",num, fibonacci(num));
}
