#include <stdio.h>

void dobra_valor(int *vetor, int tamanho){
	int i;
	for(i = 0; i < tamanho; i++){
		vetor[i] = vetor[i] * 2;
	}
}

int main(){
	int numeros[] = {1, 4, 8, 10, 2};
	int tamanho = 5;
	//O nome de um vetor já um ponteiro na linguagem C
	//Pode ser omitido o caractere & nessa situação
	dobra_valor(&numeros, tamanho);
	int i;
	printf("Vetor com elementos dobrados: ");
	for(i = 0; i < tamanho; i++){
		printf(" %d", numeros[i]);
	}
}
