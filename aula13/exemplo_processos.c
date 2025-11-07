#include <windows.h>
#include <stdio.h>

int main(){
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	//Limpando  as estruturas de memoria
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));
	//Comando a ser executado no CMD
	LPCSTR cmd = "notepad.exe";
	//Criando o processo
	if(!CreateProcess(NULL, (LPSTR) cmd, NULL, NULL, FALSE, 0, 
					  NULL, NULL, &si, &pi)){
		printf("Falha ao criar o processo!");
		return 1;
	}
	
	printf("Processo filho criado com sucesso! PID: %lu\n",
													pi.dwProcessId);
	printf("Thread principal do processo filho: %lu\n",
													pi.dwThreadId);	
	//Fecha o processo e a thread
	CloseHandle(pi.hProcess);											;
	CloseHandle(pi.hThread);
}
