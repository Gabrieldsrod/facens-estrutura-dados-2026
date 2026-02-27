#include<stdio.h>
#include"bag.h"
int main()
{
	Bag sacola;
	int op = 0, num;
	init(&sacola);
	printf("Teste da TAD bag\n");
	while(op != 5){
		printf("1. Inserir, 2. Remover, 3. Buscar, 4. Tamanho, 5. Sair\n");
		scanf("%d", &op);
		switch(op){
			case 1: // insere
				printf("Entre com um valor para a bag: ");
				scanf("%d", &num);
				if(insert(&sacola, num))
					printf("Insercao realizada com sucesso! \n");
				else
					printf("Sacola cheia!\n");
				
			case 2: // remove
			
			case 3: //busca
			
			case 4: // tamanho
			
			case 5: break;
			
			default: printf("Opao invalida\n");
		}
		printall(sacola);	
	}
	return 0;
}
