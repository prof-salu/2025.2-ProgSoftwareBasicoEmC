#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *arquivo;//Ponteiro do arquivo
	char texto[] = "Ola, esta e um texto de exemplo.\nAqui comeca a segunda linha";
	
	//Abre/cria o arquivo para escrita
	//w --> escrita (cria um novo arquivo)
	//r --> leitura (apenas)
	//a --> escrita (adiciona dados ao arquivo existente)
	
	//O padrão é salvar
	
	printf("\n\t\rjuca \"lindao\"\n");
	arquivo = fopen("C:\\exemplos\\meu_arquivo.txt", "w");
	//Verifica se o arquivo foi criado
	if(arquivo == NULL){
		printf("Erro! Falha ao abrir o arquivo.");
		exit(1);
	}
	//Escreve o conteudo no arquivo
	fprintf(arquivo, "%s", texto);
	//Fecha o arquivo
	fclose(arquivo);
	
	printf("Arquivo criado e escrito com sucesso!");
	
}
