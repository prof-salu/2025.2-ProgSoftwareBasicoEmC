#include <stdio.h>
#include <stdlib.h> //malloc e free

int main(){
	//Criar um vetor dinamico para armazenar numeros.
	
	int tamanho;
	printf("Informe o tamanho do vetor: ");
	scanf("%d", &tamanho);
	
	//Calculo dinamico de memoria
	double *vetor = (int*) malloc(tamanho * sizeof(double));
	
	//Preenchendo o vetor
	int i = 0;
	for(i; i < tamanho; i++){
		printf("Informe o valor: ");
		scanf("%d", &vetor[i]);
	}
	
	//Imprimindo o vetor
	printf("Dados do vetor: ");
	for(i = 0; i < tamanho; i++){
		printf(" %d", &vetor[i]);
	}
	
	//Libera a memoria 
	free(vetor);
	//Boa pratica (evita usar um ponteiro invalido)
	vetor = NULL;
}
