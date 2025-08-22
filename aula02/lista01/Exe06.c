#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
	/*Faça um programa que leia e valide as seguintes informações: 
		• Nome: maior que 3 caracteres; 
		• Idade: entre 0 e 150; 
		• Salário: maior que zero; 
		• Sexo: 'f' ou 'm'; 
		• Estado Civil: 's', 'c', 'v', 'd';
	*/
	
	char nome[100];
	int idade;
	float salario;
	char sexo, estadoCivil;
		
	do{
		printf("Informe o nome: ");
		scanf("%s", &nome);
	}while(strlen(nome) <= 3); //precisa importar a biblioteca string.h
	
	do{
		printf("Informe a idade: ");
		scanf("%d", &idade);
	}while (idade < 0 || idade > 150);
	
	do{
		printf("Informe o salario: ");
		scanf("%f", &salario);
	}while (salario <= 0);
	
	do{
		printf("Informe o sexo [F(feminino) | M(masculino)]: ");
		scanf(" %c", &sexo);
		/*O espaço em branco antes do %c do scanf serve para limpar o buffer 
		do teclado com a quebra de linha (ENTER)*/
	}while(tolower(sexo) != 'f' && tolower(sexo)!= 'm');
	
	do{
		printf("Informe o estado civil: [C(casado) | S(solteiro) | V(viuvo) | D(divorciado)]");
		scanf(" %c", &estadoCivil);
	}while(tolower(estadoCivil) != 'c' && tolower(estadoCivil) != 's'
			&& tolower(estadoCivil)!= 'v' && tolower(estadoCivil) != 'd');
			
	printf("###Ficha de cadastro####");
	printf("\nNome: %s", nome);
	printf("\nIdade: %d", idade);
	printf("\nSalario: R$ %.2f", salario);
	printf("\nSexo: %c", sexo);
	printf("\nEstado civil: %c", estadoCivil);
	printf("\n########################");
}
