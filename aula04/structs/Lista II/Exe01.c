#include <stdio.h>
#include <string.h>

//Atividade 1: Cadastro Simples 

typedef struct{
	char modelo[100];
	char marca[100];
	int ano;
}Carro;

int main(){
	Carro meu_carro;
	
	printf("Digite a marca do carro: ");
	scanf(" %[^\n]", &meu_carro.marca);
	
	printf("Digite o modelo do carro: ");
	scanf(" %[^\n]", &meu_carro.modelo);
	
	printf("Digite o ano do carro: ");
	scanf("%d", &meu_carro.ano);
	
	printf("\n---Dados do carro---");
	printf("\nMarca: %s", meu_carro.marca);
	printf("\nModelo: %s", meu_carro.modelo);
	printf("\nAno: %d", meu_carro.ano);
	
}
