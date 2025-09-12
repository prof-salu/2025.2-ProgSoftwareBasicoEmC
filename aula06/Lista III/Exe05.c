#include <stdio.h>
#include <stdlib.h>

int main(){
	int tamanho;
	printf("Informe o tamanho do vetor: ");
	scanf("%d", &tamanho);
	
	//Alocando a memoria de forma dinamica
	float *vetorDinamico = (float*) malloc(tamanho * sizeof(float));
	
	printf("Informe os %d valores: ", tamanho);
	//Preenchendo o vetor dinamico
	int i;
	float somaValores = 0;
	for(i = 0; i < tamanho; i++){
		printf("Valor %d:", (i+1));
		scanf("%f", &vetorDinamico[i]);
		somaValores += vetorDinamico[i];//Calculando a soma dos valores
	}
	
	float media = somaValores / tamanho;//calculando a media dos valores
	//Resultado
	printf("A media dos valores: %f", media);
	
	//Liberando a memoria utilizada pelo vetor
	free(vetorDinamico);	
}
