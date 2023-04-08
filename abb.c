/*Lívia Lutz dos Santos - 2211055*/

/*Headers para usar as funções printf, free e malloc*/

#include <stdio.h>
#include <stdlib.h>

//Incluindo o .h com os protótipos das funções usadas pelo struct abb

#include "abb.h"

/*No struct de uma abb temos um inteiro que será inserido em cada nó, 
um ponteiro para o nó a esquerda e um para o nó a direita*/

struct abb {
	int n;
	Abb* dir;
	Abb* esq;
};

/*criaAbbVazia serve para inicializar cada nó da árvore como NULL*/

Abb* criaAbbVazia(void) {
	return NULL;
}

/*Inserindo na abb com repetição (Números repetidos serão inseridos na quantidade de vezes que
são gerados)*/

Abb* insereAbb(int i, Abb* a) {
	/*Se o nó passado como parâmetro estiver vazio (NULL), alocamos seu espaço na 
	memória para guardar seu inteiro e inicialmente seus ponteiros são NULL*/

	if (abbVazia(a)) {
		a = (Abb*)malloc(sizeof(Abb));
		a->n = i;
		a->esq = a->dir = NULL;
	}

	/*Se o nó do parâmetro não for NULL, comparamos o valor inteiro passado com seu inteiro*/

	/*Se o número passado for menor, inserimos seu nó a esquerda recursivamente*/

	else if (i < a->n) {
		a->esq = insereAbb(i, a->esq);
	}

	/*Se o número for maior, inserimos seu nó a direita recursivamente*/

	else {
		a->dir = insereAbb(i,a->dir);
	}

	/*Retornamos a abb atualizada*/

	return a;
}

/*abbVazia verifica se a abb passada como parâmetro está vazia, retorna 1 (True) se estiver,
senão, retorna 0 (False)*/

int abbVazia(Abb* a) {
	return a == NULL;
}

/*abb_imprime imprime a abb em pré - ordem, ou seja, primeiro as informações no nó raiz,
seguido dos nós à esquerda e por fim os nós à direita*/

void abb_imprime(Abb* a){
	/*Imprimindo as informações do nó raiz, incluindo seu valor inteiro e os ponteiros do
	nó à esquerda, à direita e seu próprio ponteiro*/

	printf("No: %p Esquerda:%p valor:%d direita:%p\n", a, a->esq, a->n, a->dir);

	/*Imprime as informações dos nós à esquerda recursivamente*/
	
	if (a->esq != NULL) {
		abb_imprime(a->esq);
	}

	/*Imprime as informações dos nós à direita recursivamente*/

	if (a->dir != NULL) {
		abb_imprime(a->dir);
	}
}

/*Calcula a altura da abb*/

int arvbb_altura(Abb* no) {
	/*Se a árvore for vazia, a altura é 0*/

	if (abbVazia(no)) {
		return 0;
	}
	
	/*Guardamos as alturas das sub - árvores à esquerda e direita nas variáveis h_esq e h_dir respectivamente
	nas chamadas recursivas da função*/
	
	else {
		int h_esq = arvbb_altura(no->esq);
		int h_dir = arvbb_altura(no->dir);
		
		/*Se a altura da esquerda for menor, retornamos o valor da direita + 1*/
		
		if (h_esq < h_dir) {
			return h_dir + 1;
		}

		/*Senão retornamos o valor da esquerda + 1*/

		else {
			return h_esq + 1;
		}
	}
}

/*Verifica se a abb é uma abb*/

int is_abb(Abb* a) {

	/*Se a abb for vazia, ela ainda é considerada uma abb já que não possui nós para a comparação*/
	
	if (abbVazia(a)) {
		return 1;
	}

	/*Se o inteiro à esquerda for maior, a árvore não está em ordem e, portanto
	não é uma abb, a função retorna 0 (False)*/

	if (a->esq != NULL && a->esq->n > a->n) {
		return 0;
	}

	/*Se o inteiro à direita for menor, a árvore não está em ordem e a função retorna 0*/

	if (a->dir != NULL && a->dir->n < a->n) {
		return 0;
	}

	/*Usamos as variáveis abbEsq e abbDir para guardar o valor das chamadas recursivas da função
	para a sub árvore à esquerda e à direita respectivamente*/

	int abbEsq = is_abb(a->esq);
	int abbDir = is_abb(a->dir);

	/*Se ambas as sub árvores forem uma abb (inteiros forem ambos == 1 (True)), 
	entao a função retorna 1 (True) pois a árvore toda é uma abb*/

	if (abbEsq == 1 && abbDir == 1) {
		return 1;
	}

	/*Caso contrário, a árvore não é uma abb e a função retorna 0 (False)*/

	else {
		return 0;
	}
}

/*Troca todos os nós da esquerda pelos da direita e vice - versa, retornando a árvore atualizada*/

Abb* swapLeftRight(Abb* a) {

	/*Se a árvore for vazia, retornamos a árvore*/

	if (abbVazia(a)) {
		return a;
	}

	/*Guardamos o resultado da troca das sub - árvores esquerda e direita em duas variáveis
	de ponteiro para abb left e right respectivamente*/

	Abb* left = swapLeftRight(a->esq);
	Abb* right = swapLeftRight(a->dir);

	/*Fazemos com que a sub - árvore à esquerda seja o resultado da troca da direita e vice versa*/

	a->esq = right;
	a->dir = left;

	/*Retornamos a árvore atualizada*/

	return a;
}

/*Libera a memória ocupada pela abb*/

Abb* abb_libera(Abb* a) {
	/*Se a árvore não for vazia, liberamos a memória, senão a função retorna NULL*/

	if (!abbVazia(a)) {
		/*Libera a sub - árvore à esquerda*/
		
		abb_libera(a->esq); 
		
		/*Libera a sub - árvore à direita*/

		abb_libera(a->dir);

		/*Libera o nó raiz*/

		free(a); 
	}
	return NULL;
}