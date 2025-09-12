#include <stdio.h>
#include <time.h>

int main(){
	struct tm minha_data = {0};//Inicializa a scrutc com zero
	
	//data --> 27/12/2030
	minha_data.tm_year = 2030 - 1900;
	minha_data.tm_mon = 11;
	minha_data.tm_mday = 27;
	
	//Convertendo um struct para uma data
	time_t data_futura = mktime(&minha_data);
	
	printf("Data no futuro: %s\n", ctime(&data_futura));
	printf("Dia da semana: %d", minha_data.tm_wday);
}
