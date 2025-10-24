#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Num{
	int n1, n2;
};

int main(){
	FILE *arquivo;//Ponteiro do arquivo
	struct Num obj;
	
	arquivo = fopen("config.bin", "rb");
	
	//Verifica se o arquivo existe
	if(arquivo == NULL){
		printf("Erro! Falha ao ler o arquivo.");
		exit(1);
	}
	//Le o conteudo no arquivo
	int i;
	for(i = 1; i < 10; i++){
		fread(&obj, sizeof(struct Num), 1, arquivo);
		printf("n1: %d\tn2: %d\n", obj.n1, obj.n2);
	}	
	
	//fwrite(&texto, sizeof(char), strlen(texto), arquivo);
	//Fecha o arquivo
	fclose(arquivo);
	
	printf("Arquivo lido com sucesso!");
	
}
