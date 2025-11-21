#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>
#include <process.h>
#include <string.h>

#pragma comment(lib, "ws2_32.lib")

#define PORTA 12345
#define MAX_CLIENTES 10
#define BUFFER_SIZE 1024

struct ClienteInfo{
	SOCKET socket;
	char nome[50];
	int ativo;
};

struct ClienteInfo clientes[MAX_CLIENTES];
CRITICAL_SECTION cs;

void enviarMensagensParaTodos(char* msg, SOCKET remetente){
	//Bloqueia o acesso a lista
	EnterCriticalSection(&cs);
	int i;
	for(i = 0; i < MAX_CLIENTES; i++){
		if(clientes[i].ativo && clientes[i].socket != remetente){
			send(clientes[i].socket, msg, strlen(msg), 0);
		}
	}
	//Libera o acesso a lista
	LeaveCriticalSection(&cs);
}

unsigned __stdcall clienteThread(void* index_ptr){
	int index = *(int*)index_ptr;
	free(index_ptr);
	
	SOCKET sock = clientes[index].socket;
	char buffer[BUFFER_SIZE];
	char msg_final[BUFFER_SIZE + 50];
	int bytes;
	//Primeira mensagem recebida é o nome
	bytes = recv(sock, clientes[index].nome, 49, 0);
	if(bytes <= 0){
		closesocket(sock);
		clientes[index].ativo = 0;
		return 0;
	}
	clientes[index].nome[bytes] = '\0';//finaliza o nome
	
	printf(">> Cliente conectado: %s (Slot %d)\n", 
					clientes[index].nome, index);
	
	//Avisa a todos do novo cliente
	sprintf(msg_final, "--- %s entrou no chat ---", 
					clientes[index].nome);
	
	enviarMensagensParaTodos(msg_final, sock);
	
	//Loop
	while((bytes = recv(sock, buffer, BUFFER_SIZE - 1, 0)) > 0){
		buffer[bytes] = '\0';
		
		//Formatando a mensagem
		sprintf(msg_final, "[%s]: %s", clientes[index].nome, buffer);
		printf("%s\n", msg_final);//exibe no logo do servidor
		enviarMensagensParaTodos(msg_final, sock);
	}
	
	//Fechar a conexao
	printf(">> Cliente %s desconectou.\n", clientes[index].nome);
	sprintf(msg_final, "--- %s saiu do chat ---", clientes[index].nome);
	enviarMensagensParaTodos(msg_final, sock);
	
	closesocket(sock);
	EnterCriticalSection(&cs);
	clientes[index].ativo = 0;
	LeaveCriticalSection(&cs);
	return 0;
}

int main(){
	WSADATA wsa;
	SOCKET server, novaConexao;
	struct sockaddr_in addr;
	int addr_len = sizeof(addr);
	
	WSAStartup(MAKEWORD(2,2), &wsa);
	InitializeCriticalSection(&cs);
	
	//Limpa a lista de clientes
	int i;
	for(i = 0; i < MAX_CLIENTES; i++){
		clientes[i].ativo = 0;
	}
	
	//Cria e configura o socket
	server = socket(AF_INET, SOCK_STREAM, 0);
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = INADDR_ANY; //Aceita conexões de qualquer ip
	
	addr.sin_port = htons(PORTA);
	bind(server, (struct sockaddr*) &addr, sizeof(addr));
	listen(server, 5);//Fila de espera
	
	printf("=== Servidor de chat iniciado na porta %d ===\n",
													PORTA);
	
	while(1){
		novaConexao = accept(server, (struct sockaddr*)&addr, &addr_len);
		if(novaConexao == INVALID_SOCKET){
			continue;
		}
		//Tenta achar um slot livre na lista
		int slot_encontrado = -1;
		EnterCriticalSection(&cs);
		for(i = 0; i < MAX_CLIENTES;i++){
			if(!clientes[i].ativo){
				clientes[i].socket = novaConexao;
				clientes[i].ativo = 1;
				slot_encontrado = i;
				break;
			}
		}
		LeaveCriticalSection(&cs);
		
		if(slot_encontrado != -1){
			int* idx_prt = (int*)malloc(sizeof(int));
			*idx_prt = slot_encontrado;
			_beginthreadex(NULL, 0, clienteThread,
						 idx_prt, 0, NULL);
		}else{
			printf("Servidor cheio. Conexão rejeitada. \n",
			closesocket(novaConexao));
		}		
	}												
}





