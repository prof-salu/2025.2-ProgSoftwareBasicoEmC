#include <stdio.h>
#include <time.h>

int main(){
	clock_t inicio, fim;
	float tempoDecorrido;
	
	inicio = clock();
	int i;
	for(i = 0; i < 100000; i++){
		printf("%d ", i);
	}
	
	fim = clock();	
	tempoDecorrido = (fim - inicio) / CLOCKS_PER_SEC;	
	printf("\n\nTempo decorrido: %f", tempoDecorrido);
}
