#include <stdio.h>
#include <ctype.h>

int main(){
	char caractere;
	
	printf("Informe um caractere [(.) ponto encerra o programa]: ");
	
	do{
		caractere = getchar();
		//Verifica se o caractere e minusculo
		if(islower(caractere)){
			caractere = toupper(caractere);//converte para maiusculo
		}else{
			caractere = tolower(caractere);//converte para minusculo
		}
		//Exibe o caractere no console
		putchar(caractere);
	}while(caractere != '.');
}
