//Micael Granzotto Bernardi
#include <stdio.h>
#include <string.h>

void mudarextensao(char arq[]){
	int pos;
	char novaext[10];
	
	printf("Digite a nova extensao do arquivo: ");
	fflush(stdin);
	gets(novaext);
	
    for (int i = 0; arq[i] != '\0'; i++) {
        if (arq[i] == '.') {
            pos = i+1;
        }
    }

    for (int i = pos, j = 0; novaext[j] != '\0'; i++, j++) {
        arq[i] = novaext[j];
        pos++;
    }
    
    arq[pos] = '\0';
	
	printf("Novo arquivo: \n");
	puts(arq);
	
}

void mudarnome(char arq[]){
	int pos;
	char novonome[50], extensao[10];
	
	printf("Digite o novo nome do arquivo(sem o '.'): ");
	fflush(stdin);
	gets(novonome);

    for (int i = 0; arq[i] != '\0'; i++) {
        if (arq[i] == '.') {
            pos = i;
        }
    }
    
	strcpy(extensao, arq + pos);  					//retira apenas a extensao do arquivo
	
//	for(int i=pos, j=0; arq[i] != '\0'; i++, j++){
//		extensao[j] = arq[i];	  					//Faz a mesma coisa que a linha 45
//	}
    
    strcpy(arq, novonome);
    strcat(arq, extensao);

	printf("Novo arquivo: \n");
	puts(arq);
	
}

int main(){
	
	char arquivo[60];
	int cond=0;
	
	printf("Digite o nome do arquivo: ");
	gets(arquivo);
	
	do{
		printf("\nO que deseja fazer com o arquivo?\n1 - Mudar Nome\n2 - Mudar Extensao\n");
		scanf("%d", &cond);
		switch(cond){
			case 1:{
				mudarnome(arquivo);
				break;
			}
			case 2:{
				mudarextensao(arquivo);
				break;
			}
			default:{
				printf("Acao Invalida!");
				break;
			}
		}
	} while(cond!=1 && cond!=2);
	
	return 0;
}