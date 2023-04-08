/*L�via Lutz dos Santos - 2211055*/

/*Headers para usar as fun��es printf, free e malloc*/

#include <stdio.h>
#include <stdlib.h>

//Incluindo o .h com os prot�tipos das fun��es usadas pelo struct da �rvore bin�ria

#include "arvBin.h"

/*No struct de uma �rvore bin�ria temos um inteiro que ser� inserido em cada n�,
um ponteiro para o n� � esquerda e um para o n� � direita*/

struct arv_bin {
	int num;
	arvBin* esq;
	arvBin* dir;
};

/*criaArv inicializa cada n� da �rvore como NULL*/

arvBin* criaArv(void) {
	return NULL;
}

/*arv_vazia verifica se a �rvore bin�ria passada como par�metro est� vazia, retorna 1 (True) se estiver,
sen�o, retorna 0 (False)*/

int arv_vazia(arvBin* a) {
	return a == NULL;
}

/*arv_criaRaiz cria um novo n� da �rvore bin�ria que guardar� o inteiro passado
como par�metro*/

arvBin* arv_criaRaiz(int n) {

	/*Criamos um novo n� usando malloc para alocarmos seu espa�o na mem�ria*/

	arvBin* a = (arvBin*)malloc(sizeof(arvBin));

	/*Caso o n� n�o seja alocado adequadamente,a fun��o retorna NULL */

	if (a == NULL) {
		return NULL;
	}
	/*Guardamos o inteiro no espa�o para o inteiro no n� e inicializamos os n�s da esquerda
	e direita como NULL*/

	a->num = n;
	a->esq = NULL;
	a->dir = NULL;

	/*Retornamos o novo n�*/

	return a;
}

/*Fun��o de inserir os n�s na �rvore bin�ria por n�vel*/

/*Passamos um vetor de inteiros como par�metro para inserir todos os seus elementos na �rvore 
(Esse vetor guarda os n�meros gerados aleatoriamente no programa principal)*/

/*Passamos tambem o �ndice de um elemento no vetor (i) a quantidade de elementos no vetor (n)
e o n� da �rvore que o elemento ser� inserido*/

arvBin* insere(arvBin* a, int v[], int i, int n) {

	/*Se o �ndice for menor que o tamanho do vetor, podemos inserir os elementos*/

	if (i < n) {
		/*Criamos um novo n� da �rvore contendo o elemento do �ndice atual*/

		arvBin* temp = arv_criaRaiz(v[i]);
		
		/*Passamos esse n� para a �rvore passada como par�metro*/

		a = temp;

		/*Repetimos o processo recursivamente nas sub - �rvores � esquerda e � direita*/

		/*Por�m nas chamadas recursivas das fun��es vamos atualizando o �ndice do elemento
		do vetor que queremos inserir.

		Por exemplo: Sabemos que vamos inserir elementos �mpares nos n�s a esquerda e pares nos n�s � direita
		portanto, na inser��o da sub - �rvore � esquerda, o �ndice sempre ser� 2*i + 1 (�mpar)
		e na sub - �rvore � direita, o �ndice sempre ser� 2*i + 2 (par).

		OBS : adicionei 1 pois a contagem de �ndices come�a em 0, sen�o, a representa��o comum de
		2*i e 2*i +1 para par e �mpar, respectivamente, seria usada*/

		a->esq = insere(a->esq, v, (2 * i + 1), n);

		a->dir = insere(a->dir, v, (2 * i + 2), n);
	}

	/*Retornamos a �rvore atualizada*/

	return a;

}

/*arvImprime imprime a �rvore bin�ria em pr�- ordem, ou seja, primeiro as informa��es no n� raiz,
seguido dos n�s � esquerda e por fim os n�s � direita*/

void arvImprime(arvBin* a){
	/*At� o final da �rvore, imprimimos suas informa��es*/

	if (!arv_vazia(a)) {
		/*Imprimindo as informa��es do n� raiz, incluindo seu valor inteiro e os ponteiros do
		n� � esquerda, � direita e seu pr�prio ponteiro*/

		printf("No:%p Esquerda:%p Valor:%d Direita:%p\n", a, a->esq, a->num, a->dir);
		
		/*Imprime as informa��es dos n�s � esquerda recursivamente*/
		
		arvImprime(a->esq); 
		
		/*Imprime as informa��es dos n�s � direita recursivamente*/
		
		arvImprime(a->dir); 
	}
}

/*Calcula a altura da �rvore bin�ria*/

int arvBin_altura(arvBin* no) {
	/*Se a �rvore for vazia, a altura � 0*/

	if (arv_vazia(no)) {
		return 0;
	}

	/*Guardamos as alturas das sub - �rvores � esquerda e direita nas vari�veis h_esq e h_dir respectivamente
	nas chamadas recursivas da fun��o*/

	else {
		int h_esq = arvBin_altura(no->esq);
		int h_dir = arvBin_altura(no->dir);

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

/*Verifica se a �rvore bin�ria � uma abb*/

int eh_abb(arvBin* a) {
	/*Se a �rvore for vazia, ela ainda � considerada uma abb 
	j� que n�o possui n�s para compara��o*/

	if (arv_vazia(a)) {
		return 1;
	}

	/*Se o inteiro � esquerda for maior, a �rvore n�o est� em ordem e, portanto
	n�o � uma abb, a fun��o retorna 0 (False)*/

	if (a->esq != NULL && a->esq->num > a->num) {
		return 0;
	}

	/*Se o inteiro � direita for menor, a �rvore n�o est� em ordem e a fun��o retorna 0*/

	if (a->dir != NULL && a->dir->num < a->num) {
		return 0;
	}

	/*Usamos as vari�veis arvEsq e arvDir para guardar o valor das chamadas recursivas da fun��o
	para a sub - �rvore � esquerda e � direita respectivamente*/

	int arvEsq = eh_abb(a->esq);
	int arvDir = eh_abb(a->dir);

	/*Se ambas as sub - �rvores forem uma abb (inteiros forem ambos == 1 (True)), ent�o a fun��o retorna 1 (True) 
	pois a �rvore toda � uma abb*/

	if (arvEsq == 1 && arvDir == 1) {
		return 1;
	}

	/*Caso contr�rio, a �rvore n�o � uma abb e a fun��o retorna 0 (False)*/

	else {
		return 0;
	}
}

/*Troca todos os n�s da esquerda pelos da direita e vice - versa, retornando a �rvore atualizada*/

arvBin* trocaDirEsq(arvBin* a) {
	/*Se a �rvore for vazia, retornamos a �rvore*/

	if (arv_vazia(a)) {
		return a;
	}

	/*Guardamos o resultado da troca das sub �rvores esquerda e direita em duas vari�veis
	de ponteiro para �rvore bin�ria esq e dir respectivamente*/

	arvBin*esq = trocaDirEsq(a->esq);
	arvBin*dir = trocaDirEsq(a->dir);

	/*Fazemos com que a sub - �rvore a esquerda seja o resultado da troca da direita e vice - versa*/

	a->esq = dir;
	a->dir = esq;

	/*Retornamos a �rvore atualizada*/

	return a;
}

/*Libera a mem�ria ocupada pela �rvore bin�ria*/

arvBin* arv_libera(arvBin* a) {
	/*Se a �rvore n�o for vazia, liberamos a mem�ria, sen�o a fun��o retorna NULL*/

	if (!arv_vazia(a)) {
		/*Libera a sub - �rvore � esquerda*/

		arv_libera(a->esq); 
		
		/*Libera a sub - �rvore � direita*/
		
		arv_libera(a->dir); 

		/*Libera o n� raiz*/

		free(a); 
	}
	return NULL;
}