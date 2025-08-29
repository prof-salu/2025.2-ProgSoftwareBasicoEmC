#include <stdio.h>

int main(){
	//Cadastrar as informações de um aluno
		//nome
		//matricula
		//idade
		//media
		
	char nome[100] = "Juca";
	int matricula = 2025001;
	int idade = 23;
	float media = 7.7;
	
	printf("---Dados do aluno---");
	printf("\nNome: %s", nome);
	printf("\nMatricula: %d", matricula);
	printf("\nIdade: %d", idade);
	printf("\nMedia: %.2f", media);
}
