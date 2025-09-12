#include <stdio.h>

void encontrarMinMax(int *vetor, 
					int tamanho, 
					int *min, 
					int *max){
	if (tamanho <= 0){
		return;
	}
	
	int i;
	for(i = 0; i < tamanho;i++){
		if(i==0){
			*min = vetor[i];
			*max = vetor[i];
		}
		
		if(vetor[i] < *min){
			*min = vetor[i];
		}
		
		if(vetor[i] > *max){
			*max = vetor[i];
		}
	}	
}

void somarCinco(int *a){
		*a = *a + 5;
		printf("Valor dentro da funcao: %d\n", a);
}

int main(){
	int valor = 10;
	somarCinco(&valor);
	printf("Valor: %d\n", valor);
	
	int lista[] = {4, 6, 8, 2, -12, 56, 78, 33, 11, -1};
	int tamanho = 10;
	int min, max;
	encontrarMinMax(lista, tamanho, &min, &max);
	printf("Valor maximo: %d\n", max);
	printf("Valor minimo: %d\n", min);	
}
