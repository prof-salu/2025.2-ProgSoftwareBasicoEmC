#include <stdio.h>
#include <time.h>

int main(){
	time_t tempo_atual;
	
	tempo_atual = time(NULL);
	
	//Segundos passados desde 01/01/1970 00:00:00
	printf("Tempo agora: %ld", tempo_atual);
}
