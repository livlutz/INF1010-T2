/*Lívia Lutz dos Santos - 2211055*/

#include <stdio.h>
#include <stdlib.h>

/*Incluindo os .h's que contém as funções para arvores binárias e abb's respectivamente*/

#include "arvBin.h"
#include "abb.h"

/*Definindo a quantidade de números aleatórios que serão gerados nesse programa*/

#define N 10

int main(void) {

	/*Declarando variáveis inteiras para guardar o número gerado aleatoriamente, 
	a altura da árvore binária, a altura da abb, valores de retorno da função de verificação 
	de abb para a árvore binária e a abb respectivamente*/

	int r,alturaBin,alturaBinBusca,t,v;

	/*Declarando um array de tipo inteiro para armazenar os números gerados aleatoriamente*/

	int arr[N];

	/*A variável do tipo arvBin é declarada para criar a árvore binária e a do tipo Abb cria a abb*/

	arvBin* arvore;
	Abb* a;

	/*Inicializando as 2 árvores chamando suas respectivas funçães de inicialização*/

	arvore = criaArv();
	a = criaAbbVazia();

	/*a) Exibir os números gerados aleatoriamente na ordem que foram gerados*/

	printf("Ordem gerada:\n");
	printf("\n");

	/*Loop para gerar a quantidade de números que foi anteriormente estabelecida com define*/
	
	for (int i = 0; i < N; i++) {
		/*A função rand gera um número aleatoriamente, o operador %20 é para que o limite superior desta geração
		seja o número 20 (o número gerado será o resto da sua divisão por 20) e adicionamos mais um para estabelecer
		o limite inferior de 1 (caso o resto da divisão seja igual a 0, adicionamos 1 para que seja um número gerado no
		intervalo de [1,20]*/

		r = rand() % 20 + 1;

		/*Adicionamos os números no array de acordo com a ordem que são gerados*/
		arr[i] = r;

		/*Por fim, imprimimos o número gerado a cada loop*/
		printf("%d\n", r);
	}

	printf("\n");

	/*b) Inserir os números gerados numa árvore binária por nível*/

	/*Passamos o índice como 0 para começarmos a inserir do começo do array, 
	o índice se atualiza dentro da função conforme cada chamada recursiva*/
	
	arvore = insere(arvore, arr, 0, N);

	/*c) Inserir os números gerados numa abb com repetição 
	(todos os valores gerados serão inseridos na abb, incluindo valores repetidos)*/

	/*Loop que percorre o array de inteiros para que cada elemento seja inserido na abb*/

	for (int j = 0; j < N; j++) {
		a = insereAbb(arr[j], a);
	}

	/*d) Imprimir a árvore binária e a abb em pré - ordem*/
	/*Primeiro exibimos a árvore binária em pré - ordem seguida da abb*/

	printf("Arvore binaria em pre ordem:\n");
	printf("\n");
	arvImprime(arvore);
	printf("\n");
	printf("Abb em pre ordem:\n");
	printf("\n");
	abb_imprime(a);
	printf("\n");

	/*e) Verificar se a abb e a árvore binária são abb's*/
	/*Chamada da função de verifição de abb, guardamos seu retorno nas variáveis inteiras t e v 
	para árvore binária e abb respectivamente*/

	t = eh_abb(arvore);
	v = is_abb(a);

	/*Ambas as funções retornam 1 se a árvore for uma abb, retornam 0 caso contrário*/
	/*Informamos se a árvore for ou não uma abb com uma mensagem adequada dependendo
	dos valores de t e v*/

	if (t == 1) {
		printf("Arvore binaria eh uma abb\n");
	}

	else {
		printf("Arvore binaria nao eh uma abb\n");
	}

	printf("\n");
	
	if (v == 1) {
		printf("Abb eh uma abb\n");
	}
	else {
		printf("Abb nao eh uma abb\n");
	}

	printf("\n");

	/*f) Indicar a altura das 2 árvores*/
	/*Usamos as variáveis alturaBin e alturaBinBusca para guardar o valor da
	altura de cada árvore e imprimimos os valores com uma mensagem adequada dizendo
	a qual árvore eles pertencem*/

	alturaBin = arvBin_altura(arvore);

	printf("Altura da arvore binaria: %d\n",alturaBin);
	printf("\n");

	alturaBinBusca = arvbb_altura(a);

	printf("Altura da abb: %d\n", alturaBinBusca);
	printf("\n");

	/*g) Trocar todos os nós da direita e da esquerda de cada árvore*/

	/*Atualizamos cada árvore com a chamada da sua respectiva função de troca de nós
	e exibimos as novas árvores em pré - ordem*/

	arvore = trocaDirEsq(arvore);
	printf("Arvore binaria apos a troca:\n");
	printf("\n");
	arvImprime(arvore);
	printf("\n");

	a = swapLeftRight(a);
	printf("Abb apos a troca:\n");
	printf("\n");
	abb_imprime(a);
	printf("\n");

	/*Liberando a memória usada pelas 2 árvores*/

	/*Atualizamos as árvores usando a função de liberar a memória de cada tipo de árvore,
	se ambas as árvores forem NULL no final de cada chamada, quer dizer que a memória foi
	liberada adequadamente e imprimimos uma mensagem adequada para indicar isso*/

	arvore = arv_libera(arvore);
	a = abb_libera(a);

	if (arv_vazia(arvore) && abbVazia(a)) {
		printf("Memoria liberada!\n");
	}
	
	return 0;
}