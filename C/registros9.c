/*9.Um inventor deve preencher um formulário contendo os seguintes dados: nome do inventor e do projeto;
breve descrição do seu invento; valor de financiamento solicitado; prazo de execução em
meses.O órgão financiador faz um cadastro destes dados, agregando um
campo que indica se o prazo está ou não atrasado. 
Faça um algoritmo para ler os dados de 50 projetos, e depois exibir:
a) Uma listagem dos projetos com até 6 meses de prazo, contendo o nome e o prazo, incluindo o total financiado;
b) Uma listagem dos projetos em atraso, contendo o nome e o inventor, incluindo o total financiado.*/
#include <stdio.h>
#include <string.h>

typedef struct {
	
	char nome_inventor[50];
	char nome_projeto[50];
	char desc[50];
	float valor;
	int prazo;
	int atrasado;
	
} projetos;

void listagem(projetos p[]){
	
	printf("Projetos com ate 6 meses de prazo:");
	for(int i=0; i<3; i++){
		
		if(p[i].prazo <= 6){
			printf("\n\nNome do Projeto:");
			puts(p[i].nome_projeto);
			printf("Prazo: %d", p[i].prazo);
			printf("\nFinanciado: %.2f", p[i].valor);
		}
		
	}
	
	printf("\n\n\nProjetos em atraso:");
		for(int i=0; i<3; i++){
		
		if(p[i].atrasado == 1){
			printf("\n\nNome do Projeto:");
			puts(p[i].nome_projeto);
			printf("Nome do Inventor:");
			puts(p[i].nome_inventor);
			printf("Financiado: %.2f", p[i].valor);
		}
		
	}
	
}

int main(){
	
	projetos p[50];
	int cont;
	
	for(int i=0; i<3; i++){
		
		printf("\n\nDigite o nome do inventor do projeto %d:", i+1);
		fflush(stdin);
		gets(p[i].nome_inventor);
		printf("\n\nDigite o nome do projeto %d:", i+1);
		fflush(stdin);
		gets(p[i].nome_projeto);
		printf("\nDigite a descricao do projeto %d:", i+1);
		fflush(stdin);
		gets(p[i].desc);
		printf("\nDigite o valor do projeto %d:", i+1);
		scanf("%f", &p[i].valor);
		printf("\nDigite o prazo do projeto %d:", i+1);
		scanf("%d", &p[i].prazo);
		printf("\nO projeto %d esta atrasado?(0-nao 1-sim): ", i+1);
		scanf("%d", &p[i].atrasado);
	
	}
	
	listagem(p);
	
	return 0;
}