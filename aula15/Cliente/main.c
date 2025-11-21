#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#include <process.h>

#pragma comment(lib, "ws2_32.lib")

#define PORTA 12345
#define BUFFER_SIZE 1024

unsigned __stdcall receberMensagens(void* socket_ptr){
	SOCKET sock = *((SOCKET*) socket_ptr);
	char buffer[BUFFER_SIZE];
	int bytes;
	
	while((bytes = recv(sock, buffer, BUFFER_SIZE - 1, 0)) > 0){
		buffer[bytes] = '\0';
		printf("\r%s\n>", buffer);
	}
	return 0;
}

int main(){
	WSADATA wsa;
	SOCKET sock;
	struct sockaddr_in addr;
	char ip_server[32], nome[50], msg[BUFFER_SIZE];
	
	//Inicialização
	if(WSAStartup(MAKEWORD(2,2), &wsa) != 0){
		printf("Erro ao inicializar o socket.\n");
		return 1;
	}
	
	//Coleta de dados
	printf("--- BEM-VINDO AO CHAT ---\n");
	
	printf("Seu nome de usuario: ");
	if(fgets(nome, 50, stdin) != NULL){
		nome[strcspn(nome, "\n")] = 0;
	}
	
	printf("IP do Servidor (local = 127.0.0.1): ");
	if(fgets(ip_server, 32, stdin) != NULL){
		ip_server[strcspn(ip_server, "\n")] = 0;
	}
	
	//Conexao
	sock = socket(AF_INET, SOCK_STREAM, 0);
	addr.sin_family = AF_INET;
	addr.sin_port = htons(PORTA);
	addr.sin_addr.s_addr = inet_addr(ip_server);
	
	if(connect(sock, (struct sockaddr*)&addr, sizeof(addr)) < 0){
		printf("Falha ao conectar!");
		printf("Verifique o IP digitado ou se o servidor esta rodando.\n");
		return 1;
	}
	
	//Enviar nome ao servidor
	send(sock, nome, strlen(nome), 0);
	printf("Conectado! Pode digitar as suas mensagens.\n");
	
	//Inicia a escuta de mensagens
	_beginthreadex(NULL, 0, receberMensagens,
	               &sock, 0 , NULL);
	
	//Loop
	while(1) {
		printf("> ");
		if(fgets(msg, BUFFER_SIZE, stdin) == NULL){
			break;
		}
		//Remove o enter da mensagem
		msg[strcspn(msg, "\n")] = 0;
		
		if(strcmp(msg, "sair") == 0){
			break;
		}
		
		if(strlen(msg) > 0){
			send(sock, msg, strlen(msg), 0);
		}
	}
	
	closesocket(sock);
	WSACleanup();
	printf("Chat encerrado.\n");
	return 0;	
}
