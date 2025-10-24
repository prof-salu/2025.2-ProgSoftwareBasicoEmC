#include <stdio.h>
#include <string.h>

int main(){
	char nome[50];
	printf("Informe o seu nome: ");
	//Evita o overflow
	fgets(nome, sizeof(nome), stdin);
	
	printf("Nome: %s", nome);
	
	printf("\nQuantidade de caracteres: %d\n", strlen(nome)-1);
}
