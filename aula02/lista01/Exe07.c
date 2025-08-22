#include <stdio.h>

int main(){
	/*7. Faça um Programa que leia um vetor de 5 números 
	inteiros, mostre a soma, a multiplicação e os números.*/
	
	int numeros[5];
	int soma = 0, multiplicacao = 1, i;
	
	printf("Informe o valores inteiros.\n");
	
	for(i = 0; i < 5; i++){
		printf("Informe valor %02d: ", i + 1);
		scanf("%d", &numeros[i]);
		
		soma += numeros[i];
		multiplicacao *= numeros[i];
	}
	
	printf("Numeros: ");
	for(i = 0; i < 5; i++){
		printf("%d ", numeros[i]);
	}
	
	printf("\nSoma: %d", soma);
	printf("\nMultiplicacao: %d", multiplicacao);
}






