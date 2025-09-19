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
	char data1[11]; //"DD/MM/YYYY"
	char data2[11];//"DD/MM/YYYY"
	
	printf("Informe a primeira data [DD/MM/AAAA]: ");
	scanf("%10s", &data1);
	
	printf("Informe a segunda data [DD/MM/AAAA]: ");
	scanf("%10s", &data2);	
	
	struct tm primData = textoParaData(data1);
	struct tm segData = textoParaData(data2);
	
	//Converte para timestamp (EPOCH time)
	time_t timestamp1 = mktime(&primData);
	time_t timestamp2 = mktime(&segData);
	
	double diferenca_segundos = difftime(timestamp2, timestamp1);
	//printf("%d", diferenca_segundos);
	int diferenca_em_dias = diferenca_segundos / (60 * 60 * 24);
	
	printf("A diferencia em dias e: %d\n", diferenca_em_dias);	
}
