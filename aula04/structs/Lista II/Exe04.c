#include <stdio.h>
#include <string.h>

//Atividade 4: Gerenciando Contatos 

typedef struct{
	char nome[100];
	char email[100];
	char telefone[20];
}Contato;

int main(){
	int max_contatos = 5;
	int contatos_cadastrados = 0;
	int i, opcao;
	
	Contato agenda[max_contatos];
	
	do{
		printf("\n---Agenda---");
		printf("\n1- Adicionar");
		printf("\n2- Listar");
		printf("\n3- Sair");
		printf("\nEscolha uma opcao: ");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1:
				if(contatos_cadastrados < max_contatos){
					printf("Nome: ");
					scanf(" %[^\n]", &agenda[contatos_cadastrados].nome);
					printf("E-mail: ");
					scanf(" %[^\n]", &agenda[contatos_cadastrados].email);
					printf("Telefone: ");
					scanf(" %[^\n]", &agenda[contatos_cadastrados].telefone);
					//Incrementa o contador de contatos
					contatos_cadastrados++;
				}else{
					printf("\nAgenda cheia.");
				}
				break;
			case 2:
				if(contatos_cadastrados == 0){
					printf("\nNenum contato cadastrado!");
				}else{
					for(i = 0;i < contatos_cadastrados; i++){
						printf("\nNome: %s", agenda[i].nome);
						printf("\nE-mail: %s", agenda[i].email);
						printf("\nTelefone: %s\n", agenda[i].telefone);
					}	
				}
				break;
				
			case 3:
				printf("\nEncerrando a agenda.");
				break;
			default:
				printf("\nOpcao invalida.");
		}
	}while(opcao != 3);	
}
