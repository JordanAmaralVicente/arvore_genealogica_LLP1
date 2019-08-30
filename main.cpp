//bibliotecas
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<strings.h>

//definição das funções
int cadastraPessoas();
int cadastraParentesco();
int ListaIdade();
int menu();

// structs 
typedef struct data{
	int dia, mes, ano;
}data;

typedef struct pessoa{
	int id;
	char nome[30], naturalidade[20];
	data  dataNasc;
}pessoa;

typedef struct parentesco{
	int pessoa_1, pessoa_2;
	char tipo[10];
}parentesco;

typedef struct idade{
	int id, idade;
}idade;
void insertionSort(idade arr[], int n);
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
			case 3:
				//MOSTRA ARVORE GENEALOGICA
			break;
			case 4:
				ListaIdade();
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
	scanf("%s", &p.nome);
	printf("Digite sua DATA DE NASCIMENTO (dd/mm/aaaa) separados por espaço\n>>");
	scanf("%d", &p.dataNasc.dia);
	scanf("%d", &p.dataNasc.mes);
	scanf("%d", &p.dataNasc.ano);
	printf("Digite sua NATURALIDADE\n>>");
	scanf("%s", &p.naturalidade);

	fprintf(ARQ_pessoas, "%d %s %d %d %d %s\n", p.id, p.nome, p.dataNasc.dia, p.dataNasc.mes, p.dataNasc.ano, p.naturalidade);
	
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
		   "\n| 3 | BUSCA RELACIONAMENTO  |"
		   "\n+---------------------------+"
		   "\n| 4 |     LISTAR PESSOAS    |"
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

int ListaIdade(){
	idade vetor_Idade[9999];
	pessoa vetor_Pessoa[9999];
	char dataStr[9]; //mm/dd/aa
	char *dia, *mes, *ano;
	_strdate(dataStr);
	mes = strtok(dataStr, "/");
    for(int i=1; i<3; i++){
        if(i == 1){
    		dia = strtok(NULL, "/");
    	}else if(i ==2){
    		ano = strtok(NULL, "/");
    	}
    }
	int d = atoi(dia), m = atoi(mes), a = atoi(ano)+2000;
	
	char *aux, *aux2; 
	int ID_file, DIA_file, MES_file, ANO_file;
	FILE *ARQ_pessoas = fopen("pessoas.txt", "r");
	if(ARQ_pessoas == NULL){
		printf("ERRO AO ABRIR ARQUIVO");
		return 0;
	}
	int cont=0;
	char Str[30], Str2[20];
	while(!feof(ARQ_pessoas)){
		fscanf(ARQ_pessoas,"%d %s %d %d %d %s",&ID_file, &Str, &DIA_file, &MES_file, &ANO_file, &Str2);
		int Calculo_ano = a - ANO_file;
		vetor_Idade[cont].id = ID_file;
		vetor_Idade[cont].idade = Calculo_ano;
		vetor_Pessoa[cont].id = ID_file;
		strcpy(vetor_Pessoa[cont].nome, Str);
		vetor_Pessoa[cont].dataNasc.dia = DIA_file; 
		vetor_Pessoa[cont].dataNasc.mes = MES_file;
		vetor_Pessoa[cont].dataNasc.ano = ANO_file;
		strcpy(vetor_Pessoa[cont].naturalidade, Str2);
		cont++;
	}
	insertionSort(vetor_Idade, 9999);
	
	
	fclose(ARQ_pessoas);
	return 1;
}
void insertionSort(idade arr[], int n){ 
    int i, key, key2, j; 
    for (i = 1; i < n; i++) { 
        key = arr[i].idade;
		key2 = arr[i].id; 
        j = i-1; 
        while (j >= 0 && arr[j].idade > key) { 
            arr[j + 1].idade = arr[j].idade;
			arr[j + 1].id = arr[j].id; 
            j = j - 1; 
        } 
        arr[j + 1].idade = key;
		arr[j + 1].id = key2; 
    } 
} 
