#include <stdio.h>

int main(){
	/*Fa�a um Programa que pergunte quanto voc� ganha 
	por hora e o n�mero de horas trabalhadas no m�s.
	Calcule e mostre o total do seu sal�rio no referido 
	m�s.
	*/
	
	float ganhoHora, totalHoras, salarioMes;
	
	printf("Informe o ganho por hora: ");
	scanf("%f", &ganhoHora);
	
	printf("Informe o numeros de horas trabalhadas:");
	scanf("%f", &totalHoras);
	
	salarioMes = ganhoHora * totalHoras;
	
	printf("\nSalario: R$ %.2f", salarioMes);
}
