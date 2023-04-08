/*Lívia Lutz dos Santos - 2211055*/

/*Headers para usar as funções printf, free e malloc*/

#include <stdio.h>
#include <stdlib.h>

//Incluindo o .h com os protótipos das funções usadas pelo struct da árvore binária

#include "arvBin.h"

/*No struct de uma árvore binária temos um inteiro que será inserido em cada nó,
um ponteiro para o nó à esquerda e um para o nó à direita*/

struct arv_bin {
	int num;
	arvBin* esq;
	arvBin* dir;
};

/*criaArv inicializa cada nó da árvore como NULL*/

arvBin* criaArv(void) {
	return NULL;
}

/*arv_vazia verifica se a árvore binária passada como parâmetro está vazia, retorna 1 (True) se estiver,
senão, retorna 0 (False)*/

int arv_vazia(arvBin* a) {
	return a == NULL;
}

/*arv_criaRaiz cria um novo ná da árvore binária que guardará o inteiro passado
como parâmetro*/

arvBin* arv_criaRaiz(int n) {

	/*Criamos um novo nó usando malloc para alocarmos seu espaço na memória*/

	arvBin* a = (arvBin*)malloc(sizeof(arvBin));

	/*Caso o nó não seja alocado adequadamente,a função retorna NULL */

	if (a == NULL) {
		return NULL;
	}
	/*Guardamos o inteiro no espaço para o inteiro no nó e inicializamos os nós da esquerda
	e direita como NULL*/

	a->num = n;
	a->esq = NULL;
	a->dir = NULL;

	/*Retornamos o novo nó*/

	return a;
}

/*Função de inserir os nós na árvore binária por nível*/

/*Passamos um vetor de inteiros como parâmetro para inserir todos os seus elementos na árvore 
(Esse vetor guarda os números gerados aleatoriamente no programa principal)*/

/*Passamos tambem o índice de um elemento no vetor (i) a quantidade de elementos no vetor (n)
e o nó da árvore que o elemento será inserido*/

arvBin* insere(arvBin* a, int v[], int i, int n) {

	/*Se o índice for menor que o tamanho do vetor, podemos inserir os elementos*/

	if (i < n) {
		/*Criamos um novo nó da árvore contendo o elemento do índice atual*/

		arvBin* temp = arv_criaRaiz(v[i]);
		
		/*Passamos esse nó para a árvore passada como parâmetro*/

		a = temp;

		/*Repetimos o processo recursivamente nas sub - árvores à esquerda e à direita*/

		/*Porém nas chamadas recursivas das funções vamos atualizando o índice do elemento
		do vetor que queremos inserir.

		Por exemplo: Sabemos que vamos inserir elementos ímpares nos nós a esquerda e pares nos nós à direita
		portanto, na inserção da sub - árvore à esquerda, o índice sempre será 2*i + 1 (ímpar)
		e na sub - árvore à direita, o índice sempre será 2*i + 2 (par).

		OBS : adicionei 1 pois a contagem de índices começa em 0, senão, a representação comum de
		2*i e 2*i +1 para par e ímpar, respectivamente, seria usada*/

		a->esq = insere(a->esq, v, (2 * i + 1), n);

		a->dir = insere(a->dir, v, (2 * i + 2), n);
	}

	/*Retornamos a árvore atualizada*/

	return a;

}

/*arvImprime imprime a árvore binária em pré- ordem, ou seja, primeiro as informações no nó raiz,
seguido dos nós à esquerda e por fim os nós à direita*/

void arvImprime(arvBin* a){
	/*Até o final da árvore, imprimimos suas informações*/

	if (!arv_vazia(a)) {
		/*Imprimindo as informações do nó raiz, incluindo seu valor inteiro e os ponteiros do
		nó à esquerda, à direita e seu próprio ponteiro*/

		printf("No:%p Esquerda:%p Valor:%d Direita:%p\n", a, a->esq, a->num, a->dir);
		
		/*Imprime as informações dos nós à esquerda recursivamente*/
		
		arvImprime(a->esq); 
		
		/*Imprime as informações dos nós à direita recursivamente*/
		
		arvImprime(a->dir); 
	}
}

/*Calcula a altura da árvore binária*/

int arvBin_altura(arvBin* no) {
	/*Se a árvore for vazia, a altura é 0*/

	if (arv_vazia(no)) {
		return 0;
	}

	/*Guardamos as alturas das sub - árvores à esquerda e direita nas variáveis h_esq e h_dir respectivamente
	nas chamadas recursivas da função*/

	else {
		int h_esq = arvBin_altura(no->esq);
		int h_dir = arvBin_altura(no->dir);

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

/*Verifica se a árvore binária é uma abb*/

int eh_abb(arvBin* a) {
	/*Se a árvore for vazia, ela ainda é considerada uma abb 
	já que não possui nós para comparação*/

	if (arv_vazia(a)) {
		return 1;
	}

	/*Se o inteiro à esquerda for maior, a árvore não está em ordem e, portanto
	não é uma abb, a função retorna 0 (False)*/

	if (a->esq != NULL && a->esq->num > a->num) {
		return 0;
	}

	/*Se o inteiro à direita for menor, a árvore não está em ordem e a função retorna 0*/

	if (a->dir != NULL && a->dir->num < a->num) {
		return 0;
	}

	/*Usamos as variáveis arvEsq e arvDir para guardar o valor das chamadas recursivas da função
	para a sub - árvore à esquerda e à direita respectivamente*/

	int arvEsq = eh_abb(a->esq);
	int arvDir = eh_abb(a->dir);

	/*Se ambas as sub - árvores forem uma abb (inteiros forem ambos == 1 (True)), então a função retorna 1 (True) 
	pois a árvore toda é uma abb*/

	if (arvEsq == 1 && arvDir == 1) {
		return 1;
	}

	/*Caso contrário, a árvore não é uma abb e a função retorna 0 (False)*/

	else {
		return 0;
	}
}

/*Troca todos os nós da esquerda pelos da direita e vice - versa, retornando a árvore atualizada*/

arvBin* trocaDirEsq(arvBin* a) {
	/*Se a árvore for vazia, retornamos a árvore*/

	if (arv_vazia(a)) {
		return a;
	}

	/*Guardamos o resultado da troca das sub árvores esquerda e direita em duas variáveis
	de ponteiro para árvore binária esq e dir respectivamente*/

	arvBin*esq = trocaDirEsq(a->esq);
	arvBin*dir = trocaDirEsq(a->dir);

	/*Fazemos com que a sub - árvore a esquerda seja o resultado da troca da direita e vice - versa*/

	a->esq = dir;
	a->dir = esq;

	/*Retornamos a árvore atualizada*/

	return a;
}

/*Libera a memória ocupada pela árvore binária*/

arvBin* arv_libera(arvBin* a) {
	/*Se a árvore não for vazia, liberamos a memória, senão a função retorna NULL*/

	if (!arv_vazia(a)) {
		/*Libera a sub - árvore à esquerda*/

		arv_libera(a->esq); 
		
		/*Libera a sub - árvore à direita*/
		
		arv_libera(a->dir); 

		/*Libera o nó raiz*/

		free(a); 
	}
	return NULL;
}