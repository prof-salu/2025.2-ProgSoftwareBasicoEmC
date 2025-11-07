#include <stdio.h>

int main(){
	const long long LIMITE = 10000000000;
	long long i;
	
	printf("Iniciando a contagem de 1 ate %lld...\n", LIMITE);
	
	printf("Processando...");
	
	for(i = 1; i <= LIMITE; i++){
		//Simulando um precessamento pesado!!!
	}
	
	printf("\nContagem concluida");
}
