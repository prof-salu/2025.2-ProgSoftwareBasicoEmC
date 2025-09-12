#include <stdio.h>

void somaVetores(int *vetA, int *vetB, int *vetResultado, int tamanho){
	int i = 0;
	for(i = 0; i < tamanho; i++){
		vetResultado[i] = vetA[i] + vetB[i];
	}
}

void imprimeVetor(int *vetor, int tamanho){
	int i = 0;
	printf("-->[");
	for(i; i < tamanho; i++){
		printf(" %d", vetor[i]);
	}
	printf("]\n");
}

int main(){
	int vetA[] = {10, 30, 22, 15, 4};
	int vetB[] = {11, 34, 21, -9, 12};
	int tamanho = 5;
	int vetResultado[tamanho];
	
	somaVetores(vetA, vetB, vetResultado, tamanho);
	printf("Vetor A");
	imprimeVetor(vetA, tamanho);
	printf("Vetor B");
	imprimeVetor(vetB, tamanho);
	printf("Vetor Resultado");
	imprimeVetor(vetResultado, tamanho);
}
