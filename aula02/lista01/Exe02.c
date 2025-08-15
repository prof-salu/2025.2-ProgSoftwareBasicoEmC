#include <stdio.h>

int main(){
	/*Faça um Programa que pergunte quanto você ganha 
	por hora e o número de horas trabalhadas no mês.
	Calcule e mostre o total do seu salário no referido 
	mês.
	*/
	
	float ganhoHora, totalHoras, salarioMes;
	
	printf("Informe o ganho por hora: ");
	scanf("%f", &ganhoHora);
	
	printf("Informe o numeros de horas trabalhadas:");
	scanf("%f", &totalHoras);
	
	salarioMes = ganhoHora * totalHoras;
	
	printf("\nSalario: R$ %.2f", salarioMes);
}
