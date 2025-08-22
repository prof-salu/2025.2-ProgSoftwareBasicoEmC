#include <stdio.h>
/* ESTRUTURA DE UMA FUNÇÃO
	retorno nome(param1, param2, paramN, ...){
		...
	}
*/

long long fatorial(int valor){
	int resultado = 1, i;
	//!5 ==> 5 * 4 * 3  * 2 * 1
	for(i = valor; i > 1; i--){
		resultado *= i;
	}
	
	return resultado;
}

int main(){
	/*8. Crie um programa que tenha uma função fatorial(), 
	que receba um parâmetro inteiro e retorne o valor do 
	fatorial desse número.*/
	
	printf("Fatorial: %d", fatorial(10));
}
