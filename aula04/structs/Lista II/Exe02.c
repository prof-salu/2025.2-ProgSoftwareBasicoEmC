#include <stdio.h>
#include <string.h>

//Atividade 2: Figuras Geométricas: 

typedef struct{
	float altura;
	float largura;
}Retangulo;

int main(){
	Retangulo ret;
	
	float perimetro, area;
	
	printf("Informe a altura do retangulo: ");
	scanf("%f", &ret.altura);
	
	printf("Informe a largura do retangulo: ");
	scanf("%f", &ret.largura);
	
	area = ret.altura * ret.largura;
	perimetro = (ret.altura + ret.altura + ret.largura + ret.largura);
	
	printf("\nArea do retangulo: %.2f", area);
	printf("\nPerimetro do retangulo: %.2f", perimetro);
}
