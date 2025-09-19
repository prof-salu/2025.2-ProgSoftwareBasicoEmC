#include <stdio.h>
#include <time.h>

struct tm textoParaData(const char *data){
	//Cria uma data com os valores zerados
	struct tm novaData = {0};
	
	sscanf(data, "%d/%d/%d", &novaData.tm_mday, 
							&novaData.tm_mon,
							&novaData.tm_year);
	novaData.tm_year -= 1900; //Ajuste para o ano (inicia em 1900)
	novaData.tm_mon -= 1; //ajuste para o mes (0-11)
	
	return novaData;	
}
int main(){
	char data[11];
	
	printf("Informe a data [DD/MM/AAAA]: ");
	scanf("%10s", &data);
	
	struct tm dataStruct = textoParaData(data);
	
	mktime(&dataStruct);
	char* dias_semana[] = {"Domingo", "Segunda", "Terca", "Quarta",
					"Quinta", "Sexta", "Sabado"};
	
	int dia = dataStruct.tm_wday;
	printf("Dia da semana: %d\n", dia);
	printf("Dia da semana: %s\n", dias_semana[dia]);
}
