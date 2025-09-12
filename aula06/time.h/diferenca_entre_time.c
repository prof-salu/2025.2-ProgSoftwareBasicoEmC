#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main(){
	time_t inicio, fim;
	float diferenca;
	
	time(&inicio);//Captura o inicio do timer
	printf("Inicio da contagem...\n");
	
	sleep(10);//pausa de 10 segundos
	
	time(&fim);//Captura o Fim do timer
	printf("Fim da contagem...\n");
	
	diferenca = difftime(fim, inicio);
	
	printf("Tempo decorrido: %.2f segundos.", diferenca);
}
