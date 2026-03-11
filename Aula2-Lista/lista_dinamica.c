#include<stdio.h>
#include<stdlib.h>
#include"lista_dinamica.h"

/* Inicializa uma lista */
void cria(Lista *p_l){
	*p_l = NULL;
}

/* Verifica se a lista está vazia ou não */
int vazia(Lista *p_l){
	if (*p_l == NULL)
		return 1;
	return 0;
}

/* Insere um elemento no início da lista */
void insere_inicio(Lista *p_l, elem_t e){
	No_lista *novo;
	novo = (No_lista*) malloc (sizeof(No_lista));
	novo->info = e;
	novo->prox = *p_l;
	
	*p_l = novo;
}

/* Insere um elemento no final da lista */
void insere_fim(Lista *p_l, elem_t e){
	No_lista *novo;
	novo = (No_lista*) malloc(sizeof(No_lista));
	
	novo->info = e;
	novo->prox = NULL;
	
	//se vazia
	if(vazia(p_l)) {
		*p_l = novo;
	}
	else {
		No_lista *aux = *p_l;
		while (aux->prox != NULL) {
			aux = aux->prox;
		} 
		
		aux->prox = novo;
	}
	
}

/* Insere um elemento na lista de maneira ordenada.
Retorna 0 caso o elemento já exista na lista.
Assume que a lista está ordenada */
int insere_ordenado(Lista *p_l, elem_t e){
	No_lista *novo, *atual, *anterior;

    atual = *p_l;
    anterior = NULL;

    while (atual != NULL && atual->info < e) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual != NULL && atual->info == e) 
        return 0; 
    

    novo = (No_lista*) malloc(sizeof(No_lista));
    if (novo == NULL) 
		return -1; 

    novo->info = e;
    novo->prox = atual;

   
    if (anterior == NULL) { // Inserção no início (lista vazia ou novo elemento é o menor)
        *p_l = novo;
    } else { // Inserção no meio ou no fim
        anterior->prox = novo;
    }

    return 1;
}

/* Verifica se a lista está ordenada */
int ordenada(Lista *p_l){
	No_lista *aux;
	aux = *p_l;
	
	while (aux != NULL && aux->prox != NULL) {
		if (aux->info > aux->prox->info)
			return 0;
		
		aux = aux->prox;
	}
}

/* Ordena a lista */
void ordena(Lista *p_l){
	if (vazia(p_l)) 
		return;
    
    No_lista *aux, *aux2;
    elem_t temp;
    
    for (aux = *p_l; aux != NULL; aux = aux->prox) {
        for (aux2 = aux->prox; aux2 != NULL; aux2 = aux2->prox) {
            if (aux->info > aux2->info) {
                temp = aux->info;
                aux->info = aux2->info;
                aux2->info = temp;
            }
        }
    }
}


/* Remove o elemento que está no início da lista.
Retorna 0 caso a lista esteja vazia */
int remove_inicio(Lista *p_l, elem_t *p_e){
	if (vazia(*p_l))
		return 0;
	
	No_lista *aux;
	aux = *p_l;
	
	*p_e = aux->info;
	
	*p_l = aux->prox; 
	
	free(aux);
	return 1;
}

/* Remove o elemento que está no final da lista.
Retorna 0 caso a lista esteja vazia */
int remove_fim(Lista *p_l, elem_t *p_e){
	if (vazia(p_l)) 
		return 0;
    
    No_lista *aux = *p_l;
    No_lista *anterior = NULL;

    // Percorre até o último, guardando o anterior
    while (aux->prox != NULL) {
        anterior = aux;
        aux = aux->prox;
    }

    *p_e = aux->info;
    
    if (anterior == NULL) { 
        *p_l = NULL;
    } else {
        anterior->prox = NULL; 
    }
    
    free(aux);
    return 1;
}

/* Remove o nó de valor e.
Retorna 0 caso este nó não tenha sido encontrado */
int remove_valor(Lista *p_l, elem_t e){
	No_lista *aux, *rem;
	aux = *p_l;
	if (!vazia(p_l)){
	
		if(aux->info == e){
			*p_l = aux->prox;
			free(aux);
			return 1;
		} else if (aux->prox != NULL){
		// mais de um elemento
			while (aux->prox != NULL && aux->prox->info != e)
				aux = aux->prox;
			rem = aux->prox;
			aux->prox = rem->prox;
			free(rem);
			return 1;
		}
	}
	return 0;
}

/* Inverte os elementos de uma lista */
void inverte(Lista *p_l){
	if (vazia(p_l) || (*p_l)->prox == NULL) { // Vazia ou nó sozinho
        return;
    }

    No_lista *anterior = NULL;
    No_lista *atual = *p_l;
    No_lista *proximo = NULL;

    while (atual != NULL) {
        proximo = atual->prox;
        atual->prox = anterior;
        anterior = atual;
        atual = proximo;
    }

    
    *p_l = anterior;
}

/* Remove todos os nós da lista */
void libera(Lista *p_l){
	if (vazia(*p_l))
		return;
		
	No_lista *atual, *prox;
	atual = *p_l;
	
	while (atual != NULL) {
		prox = atual->prox;
		free(atual);
		atual = prox;
	}
	
	*p_l = NULL;
}

/* Exibe o conteúdo da lista */
void exibe(Lista *p_l){
	No_lista *aux;
	aux = *p_l;
	
	printf("\n");
	while (aux != NULL){
		printf("%d ", aux->info);
		aux = aux->prox;
	}
	printf("\n");
}

