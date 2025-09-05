#include <stdio.h>

//Criar uma função que receba dois valores inteiros
//a e b, e troca-los de lugar.

//Exemplo:
	//entrada --> a = 5 e b = 10
	//saida --> a = 10 e b = 5

void troca_valores(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
	
	//printf("\n**Valor A: %d**", a);
	//printf("\n**Valor B: %d**\n", b);
}

int main(){
	int a = 5;
	int b = 10;
	
	printf("Valores originais: A=%d, B=%d\n", a, b);
	troca_valores(&a, &b);
	printf("Valores trocados: A=%d, B=%d\n", a, b);
}
