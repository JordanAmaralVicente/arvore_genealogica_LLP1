//bibliotecas
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//definição das funções
int cadastrapessoas();
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
				cadastrapessoas();
			break;
		
			default:
				printf("** OPÇÃO INVÁLIDA **");
			break;
		}
		op = menu();
	}
	return 0;
}

int cadastrapessoas(){
	FILE *ARQ_pessoas = fopen("pessoas.txt", "a");
	pessoa p;

	if(ARQ_pessoas == NULL)
		return 0;

	printf("\nDigite seu ID >>");
	scanf("%d", &p.id);
	printf("Digite seu NOME >>");
	scanf("%s", p.nome);
	printf("Digite sua DATA DE NASCIMENTO>>");
	scanf("%s", p.dataNasc);
	printf("Digite sua NATURALIDADE >>");
	scanf("%s", p.naturalidade);

	fprintf(ARQ_pessoas, "%d %s %s %s\n", p.id, p.nome, p.dataNasc, p.naturalidade);
	
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