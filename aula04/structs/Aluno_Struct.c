#include <stdio.h>
#include <string.h>

//Estrutura (struct) de um aluno
struct Aluno{
	char nome[100];
	int matricula;
	int idade;
	float media;
};

int main(){
	struct Aluno a1;
	struct Aluno a2;
	
	strcpy(a1.nome, "Juca");
	//DOT Notation
	a1.matricula = 2025001;
	a1.idade = 27;
	a1.media = 7.7;
	
	printf("---Dados do aluno---");
	printf("\nNome: %s", a1.nome);
	printf("\nMatricula: %d", a1.matricula);
	printf("\nIdade: %d", a1.idade);
	printf("\nMedia: %.2f", a1.media);
}
