#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Num{
	int n1, n2;
};

int main(){
	FILE *arquivo;//Ponteiro do arquivo
	//char texto[] = "Senha de acesso secreta: 123456";
	struct Num obj;
	
	arquivo = fopen("config.bin", "wb");	
	
	//Verifica se o arquivo foi criado
	if(arquivo == NULL){
		printf("Erro! Falha ao abrir o arquivo.");
		exit(1);
	}
	//Escreve o conteudo no arquivo
	int i;
	for(i = 1; i < 10; i++){
		obj.n1 = i;
		obj.n2 = 12 + i;
		fwrite(&obj, sizeof(struct Num), 1, arquivo);
	}	
	
	//fwrite(&texto, sizeof(char), strlen(texto), arquivo);
	//Fecha o arquivo
	fclose(arquivo);
	
	printf("Arquivo criado e escrito com sucesso!");
	
}
