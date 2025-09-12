#include <stdio.h>
#include <time.h>
#include <locale.h>

int main(){
	
	setlocale(LC_TIME, "pt_BR.UTF-8");
	
	time_t tempo_atual;
	struct tm *info_tempo;
	char data[80];
	
	time(&tempo_atual);
	
	info_tempo = localtime(&tempo_atual);
	
	//Formato: DD/MM/AAAA HH:MM:SS
	strftime(data, 80, "%d/%m/%Y %H:%M:%S", info_tempo);	
	printf("Data formato 01: %s\n", data);
	
	//Formato: dia_da_semana, dia_do_mes, ano_com_2_digitos
	strftime(data, 80, "%A, %d, %y", info_tempo);
	printf("Data formato 02: %s\n", data);
}
