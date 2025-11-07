#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

typedef struct{
	const char* nome;
	int tipoTarefa;
}ConvidadoFesta;

void fazNumero1(const char* nome){
	printf("%s batendo na porta\n", nome);
	fflush(stdout);//Garante que a mensagem seja impressa imediatamente
	
	printf("%s entra no banheiro\n", nome);
	printf("%s fazendo coisa rapida\n", nome);
	fflush(stdout);
	
	Sleep(8000);//Faz a thread dormir por 8 segundos
	printf("%s (numero 1) dando descarga\n", nome);
	Sleep(3000);
	printf("%s (numero 1) lavando as maos\n", nome);
	Sleep(3000);
	printf("%s (numero 1) saindo do banheiro\n", nome);
	Sleep(1000);
	fflush(stdout);	
}

void fazNumero2(const char* nome){
	printf("%s batendo na porta\n", nome);
	fflush(stdout);//Garante que a mensagem seja impressa imediatamente
	
	printf("%s entra no banheiro\n", nome);
	printf("%s fazendo coisa demorada\n", nome);
	fflush(stdout);
	
	Sleep(15000);//Faz a thread dormir por 15 segundos
	printf("%s (numero 2) dando descarga\n", nome);
	Sleep(3000);
	printf("%s (numero 2) lavando as maos\n", nome);
	Sleep(3000);
	printf("%s (numero 2) saindo do banheiro\n", nome);
	Sleep(1000);
	fflush(stdout);	
}

DWORD WINAPI rotinaBanheiro(LPVOID param){
	ConvidadoFesta* convidado = (ConvidadoFesta*) param;
	
	if(convidado->tipoTarefa == 1){
		fazNumero1(convidado->nome);
	}else if(convidado->tipoTarefa == 2){
		fazNumero2(convidado->nome);
	}
	
	free(convidado);
	return 0;
}

int main(){
	const char* nomes[] = {"Joao", "Harry", "Gabi", "Gigi"};
	int tarefas[] = {1, 2, 1, 2};
	HANDLE threads[4];
	ConvidadoFesta* convidados[4];
	
	printf("Iniciando a festa maluca....\n\n");
	
	int i = 0;
	for(i; i < 4; i++){
		convidados[i] = (ConvidadoFesta*) malloc(sizeof(ConvidadoFesta));
		convidados[i]->nome = nomes[i];
		convidados[i]->tipoTarefa = tarefas[i];
		
		threads[i] = CreateThread(NULL, 0, rotinaBanheiro,
		                          convidados[i], 0, NULL);
	}
	
	WaitForMultipleObjects(4, threads, TRUE, INFINITE);
	
	CloseHandle(threads[0]);
	CloseHandle(threads[1]);
	CloseHandle(threads[2]);
	CloseHandle(threads[3]);	
}
