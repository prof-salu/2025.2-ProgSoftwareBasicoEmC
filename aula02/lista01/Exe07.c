#include <stdio.h>

int main(){
	/*7. Fa�a um Programa que leia um vetor de 5 n�meros 
	inteiros, mostre a soma, a multiplica��o e os n�meros.*/
	
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






