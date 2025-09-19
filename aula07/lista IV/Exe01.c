#include <stdio.h>
#include <time.h>

int main(){
	time_t segundos;
	struct tm *tempo;
	//EPOCH time --> 01/01/1970
	time(&segundos);
	printf("%ld\n", segundos);
	//Converte o valor em segundos para localtime
	tempo = localtime(&segundos);
	
	printf("%02d/%02d/%04d %02d:%02d:%02d\n",
										tempo->tm_mday,
										tempo->tm_mon + 1,
										tempo->tm_year + 1900,
										tempo->tm_hour,
										tempo->tm_min,
										tempo->tm_sec);
}
