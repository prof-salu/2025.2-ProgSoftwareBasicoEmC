#include <stdio.h>

int main(){
	/*Faça um Programa que peça a temperatura em graus Fahrenheit, 
	transforme e mostre a temperatura em graus Celsius. 
	
	FORMULA --> C = (5 * (F-32) / 9).
	*/
	float celsius, fahrenheit;
	
	printf("Informe a temperatura em FAHRENHEIT: ");
	scanf("%f", &fahrenheit);
	
	celsius = (5 * (fahrenheit-32) / 9);
	
	printf("%.2f graus FAHRENHEIT e equivalente a %.2f graus Celsius.", 
													fahrenheit, celsius);
}
