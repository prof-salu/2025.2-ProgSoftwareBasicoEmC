#include <stdio.h>
#include <time.h>

int main(){
	time_t inicio, fim;
	double tempoDecorrido;
	
	printf("Pressione qualquer tecla para iniciar...\n");
	getch();
	time(&inicio);
	
	printf("Cronometro iniciado.");
	printf("Pressione qualquer tecla para parar...\n");
	
	getch();
	time(&fim);
	
	tempoDecorrido = difftime(fim, inicio);
	int minutos = (int) tempoDecorrido / 60;
	int segundos = (int) tempoDecorrido % 60;
	printf("Tempo decorrido: %02d:%02d", minutos, segundos);
}
