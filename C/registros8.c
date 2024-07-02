/*8. Uma loja de calçados possui um cadastro de até 1000 peças de reposição em seu estoque.
Para cada peça são armazenados os seguintes dados: código da peça; preço unitário;
descrição da peça; e quantidade disponível em estoque. Você deve elaborar um programa
para:
a) Ler certa quantidade de peças para o cadastro. Considere que o código -999 encerra a
entrada de dados;
b) Exibir uma listagem das peças que possuem menos de X unidades, onde X é uma
quantidade fornecida pelo usuário.*/

#include <stdio.h>
#include <string.h>


typedef struct {
	
	int cod;
	float preco;
	char desc[50];
	int qtd;
	
} pecas;


int main(){
	
	pecas p[1000];
	int cont, qtd_exibir;
	
	for(int i=0; i<1000; i++){
		
		printf("\n\nDigite o codigo da peca %d:", i+1);
		scanf("%d", &p[i].cod);
		if(p[i].cod != -999){
			printf("\nDigite o preco da peca %d:", i+1);
			scanf("%f", &p[i].preco);
			printf("\nDigite a descricao da peca %d:", i+1);
			fflush(stdin);
			gets(p[i].desc);
			printf("\nDigite a quantidade disponivel da peca %d:", i+1);
			scanf("%d", &p[i].qtd);
		} else {
			cont = i;
			i=1000;
		}

	}
	
	printf("\n\nDigite uma quantidade: ");
	scanf("%d", &qtd_exibir);
	printf("\n\nPecas com quantidade em estoque menor que %d", qtd_exibir);
	for(int i=0; i<cont; i++){

		if(p[i].qtd < qtd_exibir){
			printf("\n\nCodigo: %d", p[i].cod);
			printf("\nPreco: %.2f", p[i].preco);
			printf("\nDescricao: ");
			puts(p[i].desc);
			printf("Quantidade: %d", p[i].qtd);
		}
		
	}
	
	return 0;
}