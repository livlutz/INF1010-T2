/*L�via Lutz dos Santos - 2211055*/

/*Headers para usar as fun��es printf, free e malloc*/

#include <stdio.h>
#include <stdlib.h>

//Incluindo o .h com os prot�tipos das fun��es usadas pelo struct abb

#include "abb.h"

/*No struct de uma abb temos um inteiro que ser� inserido em cada n�, 
um ponteiro para o n� a esquerda e um para o n� a direita*/

struct abb {
	int n;
	Abb* dir;
	Abb* esq;
};

/*criaAbbVazia serve para inicializar cada n� da �rvore como NULL*/

Abb* criaAbbVazia(void) {
	return NULL;
}

/*Inserindo na abb com repeti��o (N�meros repetidos ser�o inseridos na quantidade de vezes que
s�o gerados)*/

Abb* insereAbb(int i, Abb* a) {
	/*Se o n� passado como par�metro estiver vazio (NULL), alocamos seu espa�o na 
	mem�ria para guardar seu inteiro e inicialmente seus ponteiros s�o NULL*/

	if (abbVazia(a)) {
		a = (Abb*)malloc(sizeof(Abb));
		a->n = i;
		a->esq = a->dir = NULL;
	}

	/*Se o n� do par�metro n�o for NULL, comparamos o valor inteiro passado com seu inteiro*/

	/*Se o n�mero passado for menor, inserimos seu n� a esquerda recursivamente*/

	else if (i < a->n) {
		a->esq = insereAbb(i, a->esq);
	}

	/*Se o n�mero for maior, inserimos seu n� a direita recursivamente*/

	else {
		a->dir = insereAbb(i,a->dir);
	}

	/*Retornamos a abb atualizada*/

	return a;
}

/*abbVazia verifica se a abb passada como par�metro est� vazia, retorna 1 (True) se estiver,
sen�o, retorna 0 (False)*/

int abbVazia(Abb* a) {
	return a == NULL;
}

/*abb_imprime imprime a abb em pr� - ordem, ou seja, primeiro as informa��es no n� raiz,
seguido dos n�s � esquerda e por fim os n�s � direita*/

void abb_imprime(Abb* a){
	/*Imprimindo as informa��es do n� raiz, incluindo seu valor inteiro e os ponteiros do
	n� � esquerda, � direita e seu pr�prio ponteiro*/

	printf("No: %p Esquerda:%p valor:%d direita:%p\n", a, a->esq, a->n, a->dir);

	/*Imprime as informa��es dos n�s � esquerda recursivamente*/
	
	if (a->esq != NULL) {
		abb_imprime(a->esq);
	}

	/*Imprime as informa��es dos n�s � direita recursivamente*/

	if (a->dir != NULL) {
		abb_imprime(a->dir);
	}
}

/*Calcula a altura da abb*/

int arvbb_altura(Abb* no) {
	/*Se a �rvore for vazia, a altura � 0*/

	if (abbVazia(no)) {
		return 0;
	}
	
	/*Guardamos as alturas das sub - �rvores � esquerda e direita nas vari�veis h_esq e h_dir respectivamente
	nas chamadas recursivas da fun��o*/
	
	else {
		int h_esq = arvbb_altura(no->esq);
		int h_dir = arvbb_altura(no->dir);
		
		/*Se a altura da esquerda for menor, retornamos o valor da direita + 1*/
		
		if (h_esq < h_dir) {
			return h_dir + 1;
		}

		/*Sen�o retornamos o valor da esquerda + 1*/

		else {
			return h_esq + 1;
		}
	}
}

/*Verifica se a abb � uma abb*/

int is_abb(Abb* a) {

	/*Se a abb for vazia, ela ainda � considerada uma abb j� que n�o possui n�s para a compara��o*/
	
	if (abbVazia(a)) {
		return 1;
	}

	/*Se o inteiro � esquerda for maior, a �rvore n�o est� em ordem e, portanto
	n�o � uma abb, a fun��o retorna 0 (False)*/

	if (a->esq != NULL && a->esq->n > a->n) {
		return 0;
	}

	/*Se o inteiro � direita for menor, a �rvore n�o est� em ordem e a fun��o retorna 0*/

	if (a->dir != NULL && a->dir->n < a->n) {
		return 0;
	}

	/*Usamos as vari�veis abbEsq e abbDir para guardar o valor das chamadas recursivas da fun��o
	para a sub �rvore � esquerda e � direita respectivamente*/

	int abbEsq = is_abb(a->esq);
	int abbDir = is_abb(a->dir);

	/*Se ambas as sub �rvores forem uma abb (inteiros forem ambos == 1 (True)), 
	entao a fun��o retorna 1 (True) pois a �rvore toda � uma abb*/

	if (abbEsq == 1 && abbDir == 1) {
		return 1;
	}

	/*Caso contr�rio, a �rvore n�o � uma abb e a fun��o retorna 0 (False)*/

	else {
		return 0;
	}
}

/*Troca todos os n�s da esquerda pelos da direita e vice - versa, retornando a �rvore atualizada*/

Abb* swapLeftRight(Abb* a) {

	/*Se a �rvore for vazia, retornamos a �rvore*/

	if (abbVazia(a)) {
		return a;
	}

	/*Guardamos o resultado da troca das sub - �rvores esquerda e direita em duas vari�veis
	de ponteiro para abb left e right respectivamente*/

	Abb* left = swapLeftRight(a->esq);
	Abb* right = swapLeftRight(a->dir);

	/*Fazemos com que a sub - �rvore � esquerda seja o resultado da troca da direita e vice versa*/

	a->esq = right;
	a->dir = left;

	/*Retornamos a �rvore atualizada*/

	return a;
}

/*Libera a mem�ria ocupada pela abb*/

Abb* abb_libera(Abb* a) {
	/*Se a �rvore n�o for vazia, liberamos a mem�ria, sen�o a fun��o retorna NULL*/

	if (!abbVazia(a)) {
		/*Libera a sub - �rvore � esquerda*/
		
		abb_libera(a->esq); 
		
		/*Libera a sub - �rvore � direita*/

		abb_libera(a->dir);

		/*Libera o n� raiz*/

		free(a); 
	}
	return NULL;
}