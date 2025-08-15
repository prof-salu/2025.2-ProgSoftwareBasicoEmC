#include <stdio.h>
#include <locale.h>

int main(){
	/*Faça um Programa que peça as 4 notas bimestrais e mostre a média.*/
	
	setlocale(LC_ALL, "Portuguese");
	float n1, n2, n3, n4, media;
	
	printf("Informe a n1: "); //saida
	scanf("%f", &n1); //entrada
	
	printf("Informe a n2: "); //saida
	scanf("%f", &n2); //entrada
	
	printf("Informe a n3: "); //saida
	scanf("%f", &n3); //entrada
	
	printf("Informe a n4: "); //saida
	scanf("%f", &n4); //entrada
	
	media = (n1 + n2 + n3 + n4) / 4;
	
	printf("\nMédia final: %.1f", media);
}

