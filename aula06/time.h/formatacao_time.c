#include <stdio.h>
#include <time.h>

int main(){
	time_t tempo_atual;
	time(&tempo_atual);
	
	printf("Data e hora (ctime): %s", ctime(&tempo_atual));
}
