#include<stdio.h>
#include <string.h>
#include <cstdlib>
#define SIZE 200

char nome[SIZE][50];
char email[SIZE][50];
int cpf[SIZE];
int op;
void cadastro();
void pesquisa();
void lista();


int main (void){
	do{
		system("cls");
		printf("\n---Menu---\n1 - Cadastrar pessoas\n2 - Listar todos\n3 - Pesquisar pessoas\n4 - Sair\n");
		scanf("%d", &op);
		switch(op) {
			case 1:
				cadastro();
				break;
			case 2:
				lista();
				break;
			case 3:
				pesquisa();
				break;
			case 4:
				system("exit");
				break;
			default:
				printf("Opcao invalida");
				getchar();
				getchar();
				break;			
		}
	}while(op!=4);
}

void lista() {
	int i;
	for(i=0;i<SIZE;i++){
		if(cpf[i]>0){
			printf("\nNome: %s \nE-mail: %s \nCPF: %d", nome[i], email[i], cpf[i]);
		}else{
			break;
		}
	}
	getchar();
	getchar();
}// Fim da função de listagem

void cadastro() {
	static int linha;
	do{
		printf("\nDigite o nome: ");
		scanf("%s", &nome[linha]);
		printf("\nDigite o e-mail: ");
		scanf("%s", &email[linha]);
		printf("\nDigite o CPF: ");
		scanf("%d", &cpf[linha]);
		printf("\nDigite 1 para continuar ou outro valor para sair ");
		scanf("%d", &op);
		linha++;
	}while(op == 1);
} // Fim da função de cadastro

void pesquisa() {
	int cpfPesquisa;
	char emailPesquisa[50];
	int i;
	do {
		printf("\n1 - CPF\n2 - E-mail\n");
		scanf("%d", &op);
		switch(op) {
			case 1:
				printf("\nDigite o CPF: ");
				scanf("%d", &cpfPesquisa);
				for(i=0;i<SIZE; i++){
					if(cpf[i]==cpfPesquisa){
						printf("\nNome: %s \nE-mail: %s \nCPF: %d", nome[i], email[i], cpf[i]);
					}
				}
				break;
			case 2:
				printf("\nDigite o E-mail: ");
				scanf("%s", emailPesquisa);
				for(i=0;i<SIZE; i++){
					if(strcmp(email[i], emailPesquisa)==0){
						printf("\nNome: %s \nE-mail: %s \nCPF: %d", nome[i], email[i], cpf[i]);
					}
				}
				break;
			default:
				printf("\nOpcao invalida ");
				break;		
		}
		printf("\nDigite 1 para continuar pesquisando ou outro valor para sair ");
		scanf("%d", &op);
	}while(op == 1);
}// Fim da função de pesquisa
