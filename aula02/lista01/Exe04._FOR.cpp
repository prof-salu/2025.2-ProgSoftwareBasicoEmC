#include <stdio.h>

int main(){
	//4. Faça um Programa que peça N números e imprima o maior deles
	int input, maior, qtd_dados;
	
	printf("Informe a quantidade de valores: ");
	scanf("%d", &qtd_dados);
	
	for(int i = 0; i < qtd_dados; i++){
		printf("Informe o valor %02d: ", i+1);
		scanf("%d", &input);
		
		if(i == 0){
			maior = input;
			continue;
		}
		
		if(input > maior){
			maior = input;
		}
	}
	
	printf("Maior valor informado: %d", maior);	
}
