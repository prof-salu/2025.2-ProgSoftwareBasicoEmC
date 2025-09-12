#include <stdio.h>
#include <time.h>

int main(){
	time_t tempo_atual;
	
	struct tm *info_tempo_local;
	struct tm *info_tempo_gmt;
	
	time(&tempo_atual);
	
	//Converte para o fuso horario local
	info_tempo_local = localtime(&tempo_atual);
	
	//Converte para o fuso GMT/UTC
	info_tempo_gmt = gmtime(&tempo_atual);
	
	printf("---Horario local---\n");
	printf("Data: %02d/%02d/%d\n", info_tempo_local->tm_mday,
								info_tempo_local->tm_mon + 1,
								info_tempo_local->tm_year + 1900);
	printf("Horas: %02d:%02d:%02d\n", info_tempo_local->tm_hour,
									info_tempo_local->tm_min,
									info_tempo_local->tm_sec);
									
	printf("\n---Horario GMT---\n");
	printf("Data: %02d/%02d/%d\n", info_tempo_gmt->tm_mday,
								info_tempo_gmt->tm_mon + 1,
								info_tempo_gmt->tm_year + 1900);
	printf("Horas: %02d:%02d:%02d\n", info_tempo_gmt->tm_hour,
									info_tempo_gmt->tm_min,
									info_tempo_gmt->tm_sec);
}
