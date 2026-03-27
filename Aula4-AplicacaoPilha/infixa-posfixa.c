#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include <string.h>

int prioridade(char a, char b) {
    if (a == "*" || a =='/') {
        return 1;
    }

    if (b == "*" || b =='/') {
        return 0;
    }
    return 1;
}

int main()
{
    char infixa[50];
    Pilha p;
    int i;
    char aux;

    printf("Digite a expressao infixa: ");
    scanf("%s", infixa);

    i = 0;
    cria_pilha(&p);
    while (infixa[i] != '\0') {
        switch (infixa[i])
        {
        case '(':
            insere_pilha(&p, infixa[i]);
            break;

        case ')':
            aux = remove_pilha(&p);
            while (!pilha_vazia(&p)) {
                /* code */
            }
            
            break;

        
        default:
            break;
        }
    }
    


    return 0;
}
