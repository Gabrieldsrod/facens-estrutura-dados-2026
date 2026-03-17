#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

/* Inicializa uma lista */
void cria(Lista *p_l)
{
	*p_l = NULL;
}

/* Verifica se a lista está vazia ou não */
int vazia(Lista *p_l)
{
	if (*p_l == NULL)
		return 1;
	return 0;
}

/* Insere um elemento no início da lista */
void insere_inicio(Lista *p_l, elem_t e)
{
	No_lista *novo;
	novo = (No_lista *)malloc(sizeof(No_lista));
	novo->info = e;
	novo->ant = NULL;
	novo->prox = *p_l; // 2
	if (!vazia(p_l))
		(*p_l)->ant = novo;
	*p_l = novo;
}

/* Insere um elemento no final da lista */
void insere_fim(Lista *p_l, elem_t e)
{
	No_lista *novo, *aux;
	novo = (No_lista *)malloc(sizeof(No_lista));
	novo->info = e;
	novo->prox = NULL;
	if (vazia(p_l))
	{
		*p_l = novo;
		novo->ant = NULL;
	}

	aux = *p_l;
	while (aux->prox != NULL)
		aux = aux->prox;
	aux->prox = novo;
	novo->ant = aux;
}

/* Insere um elemento na lista de maneira ordenada.
   Retorna 0 caso o elemento já exista na lista.
   Assume que a lista está ordenada */
int insere_ordenado(Lista *p_l, elem_t e)
{
	No_lista *aux, *novo;
	aux = *p_l;
	if (vazia(p_l) || e < (*p_l)->info)
	{
		insere_inicio(p_l, e);
		return 1;
	}
	while (aux != NULL && aux->info < e)
		aux = aux->prox;

	if (aux->info == e)
		return 0;

	if (aux->info > e)
	{
		novo = (No_lista *)malloc(sizeof(No_lista));
		novo->info = e;
		novo->prox = aux;
		novo->ant = aux->ant;
		aux->ant = novo;		// novo->prox->ant
		novo->ant->prox = novo; // aux->ant->ant->prox
		return 1;
	}

	insere_fim(p_l, e);
}

/* Verifica se a lista está ordenada */
int ordenada(Lista *p_l)
{
	No_lista *aux;
	aux = *p_l;
	while (aux != NULL && aux->prox != NULL)
	{
		if (aux->info > aux->prox->info)
			return 0;
		aux = aux->prox;
	}
	return 1;
}

/* Ordena a lista */
void ordena(Lista *p_l)
{
	No_lista *aux;
	aux = *p_l;
	while (aux != NULL)
	{
		No_lista *aux2 = aux->prox;
		while (aux2 != NULL)
		{
			if (aux->info > aux2->info)
			{
				elem_t temp = aux->info;
				aux->info = aux2->info;
				aux2->info = temp;
			}
			aux2 = aux2->prox;
		}
		aux = aux->prox;
	}
}

/* Remove o elemento que está no início da lista.
   Retorna 0 caso a lista esteja vazia */
int remove_inicio(Lista *p_l, elem_t *p_e)
{
	if (vazia(p_l))
		return 0;
	No_lista *aux = *p_l;
	*p_e = aux->info;
	*p_l = aux->prox;
	if (*p_l != NULL)
		(*p_l)->ant = NULL;
	free(aux);
	return 1;
}

/* Remove o elemento que está no final da lista.
   Retorna 0 caso a lista esteja vazia */
int remove_fim(Lista *p_l, elem_t *p_e)
{
	if (vazia(p_l))
		return 0;
	No_lista *aux = *p_l;
	while (aux->prox != NULL)
		aux = aux->prox;
	*p_e = aux->info;
	if (aux->ant != NULL)
		aux->ant->prox = NULL;
	else
		*p_l = NULL; // Lista tinha apenas um elemento
	free(aux);
	return 1;
}

/* Remove o nó de valor e.
   Retorna 0 caso este nó não tenha sido encontrado */
int remove_valor(Lista *p_l, elem_t e)
{
	No_lista *aux = *p_l;
	while (aux != NULL && aux->info != e)
		aux = aux->prox;
	if (aux == NULL)
		return 0;
	if (aux->ant != NULL)
		aux->ant->prox = aux->prox;
	else
		*p_l = aux->prox;
	if (aux->prox != NULL)
		aux->prox->ant = aux->ant;
	free(aux);
	return 1;
}

/* Inverte os elementos de uma lista */
void inverte(Lista *p_l)
{
	No_lista *aux = *p_l;
	No_lista *temp = NULL;
	while (aux != NULL)
	{
		temp = aux->ant;
		aux->ant = aux->prox;
		aux->prox = temp;
		aux = aux->ant; // aux->prox antes da troca
	}
	if (temp != NULL)
		*p_l = temp->ant; // temp->ant é o novo início da lista
}

/* Remove todos os nós da lista */
void libera(Lista *p_l)
{
	No_lista *aux = *p_l;
	while (aux != NULL)
	{
		No_lista *temp = aux;
		aux = aux->prox;
		free(temp);
	}
	*p_l = NULL;
}

/* Exibe o conteúdo da lista */
void exibe(Lista *p_l)
{
	No_lista *aux;
	aux = *p_l;
	printf("\n");
	while (aux != NULL)
	{
		printf("%d ", aux->info);
		aux = aux->prox;
	}
	printf("\n");
}