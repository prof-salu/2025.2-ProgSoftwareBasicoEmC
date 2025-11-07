#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

typedef struct{
	int id;
	long long inicio;
	long long fim;
}DadosThread;
//LPVOID --> Ponteiro generico que recebe os dados da thread
//DWORD WINAPI --> tipo esperado de retorno (thread) no windows
DWORD WINAPI contar(LPVOID param){
	DadosThread *dados = (DadosThread *) param;
	long long i = dados->inicio;
	
	printf("[ID: %d] Processando ...\n", dados->id);
	
	for(i; i < dados->fim;i++){
		//Contando...
		printf("%d ", i);
	}
	free(dados);
	return 0;
}

int main(){
	const long long fim = 10000;
	const NUM_THREADS = 10;
	long long inicio = 1;
	long long por_thread = fim / NUM_THREADS;
	HANDLE handles[NUM_THREADS];
	
	int i = 0;
	
	for(i; i < NUM_THREADS; i++){
		DadosThread *dados = (DadosThread *) malloc(sizeof(DadosThread));		
		dados->id = i + 1;
		dados->inicio = inicio;
		dados->fim = inicio + por_thread -1;
		
		if(i == NUM_THREADS - 1){
			dados->fim = fim;
		}
		
		//Criando a thread
		handles[i] = CreateThread(NULL, 0, contar, dados, 0 , NULL);
		
		inicio = dados->fim + 1;
	}
	
	//Aguarda as threads terminarem
	WaitForMultipleObjects(NUM_THREADS, handles, TRUE, INFINITE);
	
	CloseHandle(handles[0]);
	CloseHandle(handles[1]);
	CloseHandle(handles[2]);
	CloseHandle(handles[3]);
	
	printf("Contagem concluida!");
}
