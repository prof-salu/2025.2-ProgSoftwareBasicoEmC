#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char marca[50];
	char modelo[50];
	int ano;
}Veiculo;

int main(){
	//Alocando dinamicamente para um veiculo
	Veiculo *meuCarro = 
				(Veiculo*) malloc(sizeof(Veiculo));
				
	printf("Informe a marca: ");
	scanf("%s", &meuCarro->marca);
	
	printf("Informe o modelo: ");
	scanf("%s", &meuCarro->modelo);
	
	printf("Informe o ano: ");
	scanf("%d", &meuCarro->ano);
	
	printf("**Veiculo cadastrado**\n\n");
	printf("Marca: %s\n", meuCarro->marca);
	printf("Modelo: %s\n", meuCarro->modelo);
	printf("Ano: %d\n", meuCarro->ano);
	
	//Liberando a memoria
	free(meuCarro);
}
