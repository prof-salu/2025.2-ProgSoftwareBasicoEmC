#include <stdio.h>

int main(){
	//Ponteiros --> variavel especial que armazena 
	// a posi��o de mem�ria
	
	//Sintaxe
	//tipo_dado * nome_ponteiro;
	
	//Operadores:
	//& (endere�o da mem�ria)
	//* (ponteiro)
	
	int idade = 30;
	//Armazena a posi��o de mem�ria da variavel idade
	int *ponteiroIdade = &idade;
	
	printf("Valor da variavel 'idade': %d\n", 
											idade);
	printf("Endereco de memoria de 'idade': %p\n", 
											&idade);
	
	printf("Valor do 'ponteiro idade': %p\n", 
										ponteiroIdade);
	printf("Valor apontado pelo 'ponteiro idade': %d\n", 
										*ponteiroIdade);
	//Alterando o valor atraves do ponteiro
	*ponteiroIdade = 40;									
	
	printf("Novo valor da variavel 'idade': %d\n",
										idade);
											
}
