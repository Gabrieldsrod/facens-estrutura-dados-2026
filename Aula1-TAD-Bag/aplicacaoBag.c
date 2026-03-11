#include<stdio.h>
#include"bag.h"
int main()
{
	Bag sacola;
	int op = 0, num;
	init(&sacola);
	printf("Teste da TAD bag\n");
	while(op != 5){
		printf("\n1. Inserir, 2. Remover, 3. Buscar, 4. Tamanho, 5. Sair\n");
		scanf("%d", &op);
		switch(op){
			case 1: // insere
				printf("Entre com um valor para a bag: ");
				scanf("%d", &num);
				if (insert(&sacola, num) == 1)
					printf("Insercao realizada com sucesso! \n");
				else
					printf("Sacola cheia!\n");
				break;
				
			case 2: // remove
				printf("Entre com um valor para a bag para remove-lo: ");
				scanf("%d", &num);
				if (delete(&sacola, num)) 
					printf("Remocao realizada com sucesso! \n");
				else
					printf("Numero nao encontrado para exclusao");
				break;
					
			case 3: { //busca 
			
				printf("Entre com um valor para a bag para busca-lo: ");
				scanf("%d", &num);
				int count = check(&sacola, num);
				printf("Foram encontrados %i deste numero", count);
				break;
			}
			case 4: {// tamanho
				int tamanho;
				tamanho = size(&sacola);
				printf("A sacola tem %i elementos", tamanho);
				break;
			}
			case 5: 
				break;
			
			default: 
				printf("Opcao invalida\n");
		}
		printall(sacola);	
	}
	return 0;
}
