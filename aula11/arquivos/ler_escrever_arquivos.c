#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	FILE *arquivo;
	char nome[100];
	
	arquivo = fopen("chamada.txt", "a");
	
	if(arquivo == NULL){
		printf("Falaha ao abrir o arquivo!");
		exit(1);
	}
	
	//Repete até o usuario informar como nome a palavra SAIR
	while(1){
		printf("Informe o nome (ou sair): ");
		
		if(fgets(nome, 100, stdin) == NULL){
			printf("Erro na leitura");
			break;
		}
		
		//Ignora a quebre de linha "extra"
		nome[strcspn(nome, "\n")] = 0;
		
		if(strcmp(nome, "sair") == 0){
			printf("Salvando lista...");
			break;
		}
		
		fprintf(arquivo, "%s\n", nome);
		printf("Nome adicionado.\n");		
	}
	fclose(arquivo);
	printf("Captura finalizada.");
}
