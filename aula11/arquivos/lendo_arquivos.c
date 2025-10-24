#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *arquivo;//Ponteiro do arquivo
	char linha[200];
	//Abre o arquivo no modo leitura
	arquivo = fopen("noticia.txt", "r");
	
	if(arquivo == NULL){
		printf("Falha ao ler o conteudo do arquivo!");
		exit(1);
	}
	
	printf("Conteudo do arquivo: \n\n");
	
	//Le linha por linha do arquivo
	while(fgets(linha, sizeof(linha), arquivo) != NULL){
		printf("%s", linha);//Imprime cada linha do arquivo
	}
	
	fclose(arquivo);
}
