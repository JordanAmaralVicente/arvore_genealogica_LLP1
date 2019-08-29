//bibliotecas
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//definição das funções
int cadastraPessoas();
int cadastraParentesco();
int menu();
// structs 
typedef struct pessoa{
	int id;
	char nome[30], dataNasc[10], naturalidade[20];
}pessoa;

typedef struct parentesco{
	int pessoa_1, pessoa_2;
	char tipo[10];
}parentesco;

//funcoes
int main(){
	int op;

	op = menu();
	while(op != 0){
		switch (op){
			case 1:
				cadastraPessoas();
			break;
			case 2:
				cadastraParentesco();
			break;
			default:
				printf("** OPÇÃO INVÁLIDA **");
			break;
		}
		op = menu();
	}
	return 0;
}

int cadastraPessoas(){
	FILE *ARQ_pessoas = fopen("pessoas.txt", "a");
	pessoa p;

	if(ARQ_pessoas == NULL)
		return 0;

	printf("\nDigite seu ID\n>>");
	scanf("%d", &p.id);
	printf("Digite seu NOME\n>>");
	scanf("%s", p.nome);
	printf("Digite sua DATA DE NASCIMENTO\n>>");
	scanf("%s", p.dataNasc);
	printf("Digite sua NATURALIDADE\n>>");
	scanf("%s", p.naturalidade);

	fprintf(ARQ_pessoas, "%d; %s; %s; %s;\n", p.id, p.nome, p.naturalidade, p.dataNasc);
	
	printf("* PESSOA CADASTRADA COM SUCESSO *\n");

	fclose(ARQ_pessoas);
	return 1;
}

int menu(){
	printf("\n+---------------------------+"
           "\n|           MENU            |"
           "\n+---------------------------+"
		   "\n| 1 |   CADASTRAR PESSOA    |"
           "\n+---------------------------+"
		   "\n| 2 | CADASTRAR PARENTESCO  |"
		   "\n+---------------------------+"
		   "\n| 0 |         SAIR          |"
		   "\n+---------------------------+"
		   "\n>>"
	);
	int n;
	scanf("%d", &n);
	return n;
}

int cadastraParentesco(){
	parentesco p;
	printf("Digite o ID da pessoa 1\n>>");
	scanf("%d", &p.pessoa_1);
	printf("Digite o ID da pessoa 2\n>>");
	scanf("%d", &p.pessoa_2);
	printf("\nDigite a relação de pessoa 1 -> pessoa 2\n>>");
	scanf("%s", &p.tipo);

	FILE *ARQ_parentesco = fopen("parentesco.txt", "a");
	if(ARQ_parentesco == NULL)
		return 0;

	fprintf(ARQ_parentesco, "%d; %d; %s;\n", p.pessoa_1, p.pessoa_2, p.tipo);
	fclose(ARQ_parentesco);
	return 1;
}