#include <stdio.h>

int conta_tamanho(char *palavra){
	int contador= 0;
	
	while(*palavra != '\0'){
		//incrementa o contador
		contador++;
		//incrementa o ponteiro
		palavra++;
	}
	
	return contador;
}

int main(){
	char minhaString[] = "Programacao de Software Basico em C";
	
	int tamanho = conta_tamanho(&minhaString);
	
	printf("A string %s tem %d caracteres.", 
									minhaString, 
									tamanho);
}
