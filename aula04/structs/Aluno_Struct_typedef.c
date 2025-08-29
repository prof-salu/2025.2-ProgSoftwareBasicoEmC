#include <stdio.h>
#include <string.h>

typedef struct{
	char titulo[100];
	char autor[100];
	int anoPublicacao;
}Livro;


int main(){
	Livro l1 = {"Aprendendo C", "Juca Pereira", 2018};
	Livro l2;
	
	strcpy(l2.titulo, "Programando com Java");
	strcpy(l2.autor, "Ana MArcela");
	l2.anoPublicacao = 2020;
	
	printf("---Dados do livro---");
	printf("\nTitulo: %s", l1.titulo);
	printf("\nAutor: %s", l1.autor);
	printf("\nAno da publicacao: %d", l1.anoPublicacao);
	
		printf("\n\n---Dados do livro---");
	printf("\nTitulo: %s", l2.titulo);
	printf("\nAutor: %s", l2.autor);
	printf("\nAno da publicacao: %d", l2.anoPublicacao);
}
