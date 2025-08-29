#include <stdio.h>
#include <string.h>

//Atividade 3: Funcionários da Empresa

typedef struct{
	int id;
	char nome[100];
	float salario;
}Funcionario;

int main(){
	Funcionario empresa[5];
	int i, posicao_maior_salario;
	
	printf("---Cadastro de funcionario---");
	for(i = 0; i < 5; i++){
		printf("\nInforme o ID: ");
		scanf("%d", &empresa[i].id);
		
		printf("Informe o nome do funcionario: ");
		scanf(" %[^\n]", &empresa[i].nome);
		
		printf("Informe o salario do funcionario: ");
		scanf("%f", &empresa[i].salario);
		
		if(i == 0){
			posicao_maior_salario = i;
			continue;
		}
		
		if(empresa[i].salario > empresa[posicao_maior_salario].salario){
			posicao_maior_salario = i;
		}
	}
	printf("\n---Fim do Cadastro de funcionario---");
	
	printf("\nFuncionario: %s", empresa[posicao_maior_salario].nome);	
	printf("\nSalario: R$ %.2f", empresa[posicao_maior_salario].salario);	
}
