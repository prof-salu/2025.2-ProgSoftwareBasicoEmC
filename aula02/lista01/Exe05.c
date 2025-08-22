#include <stdio.h>
#include <ctype.h>

int main(){
	//5. Faça um Programa que verifique se uma letra digitada é vogal ou consoante.
	
	char letra, letraCaixaAlta;
	
	printf("Informe uma letra: ");
	scanf("%c", &letra);
	
	letraCaixaAlta = toupper(letra); //precisa importar a biblioteca ctype.h
	
	if(letraCaixaAlta == 'A' || letraCaixaAlta == 'E' || letraCaixaAlta == 'I' || 
		letraCaixaAlta == 'O' || letraCaixaAlta == 'U'){
		printf("A letra (\"%c\") e uma VOGAL.", letra);
	}else{
		printf("A letra (\"%c\") e uma CONSOANTE.", letra);
	}	
}
