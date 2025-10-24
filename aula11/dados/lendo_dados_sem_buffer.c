#include<stdio.h>
#include <ctype.h>
#include <conio.h> //Inclui funções para manipulacao do console

int main(){
	char caractere;
	printf("Entre com um texto [(.) ponto para sair.]\n");	
	do{
		//Le um caractere sem "ecoar" na tela do terminal
		caractere = getch();
		if(islower(caractere)){
			caractere = toupper(caractere);
		}else{
			caractere = tolower(caractere);
		}
		putchar(caractere);
	}while(caractere != '.');
}
