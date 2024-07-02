// Micael Granzotto Bernardi
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencheCartela(int c[][5]) {

	int v[15], valor, cond=0;

	for(int i=0; i<15; i++) {			//laço para gerar 15 numeros aleatorios sem repetição

		valor = 1+(rand() % 60);		//gera um valor aleatorio entre 1-60

		for(int j=0; j<=i-1; j++) {		//percorre o vetor 'v' para ver se o valor ja foi gerado
			if(v[j] == valor) {
				cond=1;					//se foi gerado a variavel 'cond' recebe 1
			}
		}
		if(cond==1) {
			cond=0;
			i--;						//caso a variavel 'cond' tenha recebido 1 é reduzido o contador do laço para gerar um novo valor
		} else {
			v[i] = valor;				//caso a variavel 'cond' continue em 0 o valor gerado é adicionado no vetor 'v'
		}
	}

	for(int i=0, k=0; i<3; i++) {		//laço para colocar os valores gerados no vetor para a matriz que pertence a cartela
		for(int j=0; j<5; j++) {
			c[i][j] = v[k];
			k++;
		}
	}
}

void marcacartela(int c[][5], int valor) {

	for(int i=0; i<3; i++) {			//laços para percorrer a matriz e marcar com '-1' quando o elemento for igual ao valor recebido
		for(int j=0; j<5; j++) {
			if(c[i][j] == valor) {
				c[i][j] = -1;
			}
		}
	}
}

int verifica(int c[][5]) {

	int cond=0;

	for(int i=0; i<3; i++) {
		for(int j=0; j<5; j++) {		//verifica a quantidade de elementos 'marcados' dentro da cartela
			if(c[i][j] == -1) {
				cond++;
			}
		}
	}
	if(cond == 15) {					//retorna '1' caso toda a cartela estiver preenchida
		return 1;
	} else {
		return 0;
	}
}

void mostracartela(int m[][5]) {
	printf(" -----------------------------------------\n");
	for(int i=0; i<3; i++) {
		printf(" |");
		for(int j=0; j<5; j++) {
			printf(" [%d]\t", m[i][j]);
		}
		printf("|\n");
	}
	printf(" -----------------------------------------\n");
}

int main() {

	srand(time(NULL));

	int jogador1[3][5], jogador2[3][5], jogador3[3][5], sorteados[60], valor, condicao, i=0;

	preencheCartela(jogador1);
	preencheCartela(jogador2); 					// Chama funcao que preenche as cartelas dos jogadores
	preencheCartela(jogador3);

	printf("\n\n\n Jogador 1:\n");
	mostracartela(jogador1);
	printf("\n Jogador 2:\n");
	mostracartela(jogador2);
	printf("\n Jogador 3:\n");
	mostracartela(jogador3);

	do {
		getchar();
		system("cls");

		do {									//Laço usado para gerar numeros aleatorios sem repetição
			condicao=0;
			valor = 1+(rand() % 60); 			// gera um numero aleatorio entre 1-60

			for(int i=0; i<60; i++) {			//percorre o vetor 'sorteados' para testar se o valor ja foi sorteado
				if(valor == sorteados[i]) {
					condicao=1;					//em caso do valor ja ter sido sorteado a variavel 'condicao' recebe o valor 1
					break;
				}
			}
			if(condicao==0) {					//testa se a variavel 'condicao' recebeu o valor 1
				sorteados[i] = valor;			//caso nao tenha recebido, o valor sorteado sera adicionado no vetor 'sorteados'
				i++;
			}

		} while(condicao==1);					//enquanto a variavel 'condicao' receber o valor 1 sera repetido o laço

		printf(" #####################");
		printf("\n ## Valor sorteado: %d\n", valor);
		printf(" #####################");

		marcacartela(jogador1, valor);
		marcacartela(jogador2, valor); 			// Chama funcao que marca o valor sorteado casa ele apareca na cartela
		marcacartela(jogador3, valor);

		printf("\n Jogador 1:\n");
		mostracartela(jogador1);				//função que mostra a cartela dos jogadores
		printf("\n Jogador 2:\n");
		mostracartela(jogador2);
		printf("\n Jogador 3:\n");
		mostracartela(jogador3);

	} while(verifica(jogador1)==0 && verifica(jogador2)==0 && verifica(jogador3)==0); //utiliza o retorno da função para testar se algum jogador venceu

	system("cls");

	if(verifica(jogador1)==1) {					
		printf("\nJogador1: Bingo!\n");
		mostracartela(jogador1);
	}
	if(verifica(jogador2)==1) {					//Verifica qual jogador ganhou para anunciar a vitório
		printf("\nJogador2: Bingo!\n");			//Em caso de empate os dois ou tres vencedores serao mostrados
		mostracartela(jogador2);
	}
	if(verifica(jogador3)==1) {
		printf("\nJogador3: Bingo!\n");
		mostracartela(jogador3);
	}

	return 0;
}