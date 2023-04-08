/*L�via Lutz dos Santos - 2211055*/

#include <stdio.h>
#include <stdlib.h>

/*Incluindo os .h's que cont�m as fun��es para arvores bin�rias e abb's respectivamente*/

#include "arvBin.h"
#include "abb.h"

/*Definindo a quantidade de n�meros aleat�rios que ser�o gerados nesse programa*/

#define N 10

int main(void) {

	/*Declarando vari�veis inteiras para guardar o n�mero gerado aleatoriamente, 
	a altura da �rvore bin�ria, a altura da abb, valores de retorno da fun��o de verifica��o 
	de abb para a �rvore bin�ria e a abb respectivamente*/

	int r,alturaBin,alturaBinBusca,t,v;

	/*Declarando um array de tipo inteiro para armazenar os n�meros gerados aleatoriamente*/

	int arr[N];

	/*A vari�vel do tipo arvBin � declarada para criar a �rvore bin�ria e a do tipo Abb cria a abb*/

	arvBin* arvore;
	Abb* a;

	/*Inicializando as 2 �rvores chamando suas respectivas fun��es de inicializa��o*/

	arvore = criaArv();
	a = criaAbbVazia();

	/*a) Exibir os n�meros gerados aleatoriamente na ordem que foram gerados*/

	printf("Ordem gerada:\n");
	printf("\n");

	/*Loop para gerar a quantidade de n�meros que foi anteriormente estabelecida com define*/
	
	for (int i = 0; i < N; i++) {
		/*A fun��o rand gera um n�mero aleatoriamente, o operador %20 � para que o limite superior desta gera��o
		seja o n�mero 20 (o n�mero gerado ser� o resto da sua divis�o por 20) e adicionamos mais um para estabelecer
		o limite inferior de 1 (caso o resto da divis�o seja igual a 0, adicionamos 1 para que seja um n�mero gerado no
		intervalo de [1,20]*/

		r = rand() % 20 + 1;

		/*Adicionamos os n�meros no array de acordo com a ordem que s�o gerados*/
		arr[i] = r;

		/*Por fim, imprimimos o n�mero gerado a cada loop*/
		printf("%d\n", r);
	}

	printf("\n");

	/*b) Inserir os n�meros gerados numa �rvore bin�ria por n�vel*/

	/*Passamos o �ndice como 0 para come�armos a inserir do come�o do array, 
	o �ndice se atualiza dentro da fun��o conforme cada chamada recursiva*/
	
	arvore = insere(arvore, arr, 0, N);

	/*c) Inserir os n�meros gerados numa abb com repeti��o 
	(todos os valores gerados ser�o inseridos na abb, incluindo valores repetidos)*/

	/*Loop que percorre o array de inteiros para que cada elemento seja inserido na abb*/

	for (int j = 0; j < N; j++) {
		a = insereAbb(arr[j], a);
	}

	/*d) Imprimir a �rvore bin�ria e a abb em pr� - ordem*/
	/*Primeiro exibimos a �rvore bin�ria em pr� - ordem seguida da abb*/

	printf("Arvore binaria em pre ordem:\n");
	printf("\n");
	arvImprime(arvore);
	printf("\n");
	printf("Abb em pre ordem:\n");
	printf("\n");
	abb_imprime(a);
	printf("\n");

	/*e) Verificar se a abb e a �rvore bin�ria s�o abb's*/
	/*Chamada da fun��o de verifi��o de abb, guardamos seu retorno nas vari�veis inteiras t e v 
	para �rvore bin�ria e abb respectivamente*/

	t = eh_abb(arvore);
	v = is_abb(a);

	/*Ambas as fun��es retornam 1 se a �rvore for uma abb, retornam 0 caso contr�rio*/
	/*Informamos se a �rvore for ou n�o uma abb com uma mensagem adequada dependendo
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

	/*f) Indicar a altura das 2 �rvores*/
	/*Usamos as vari�veis alturaBin e alturaBinBusca para guardar o valor da
	altura de cada �rvore e imprimimos os valores com uma mensagem adequada dizendo
	a qual �rvore eles pertencem*/

	alturaBin = arvBin_altura(arvore);

	printf("Altura da arvore binaria: %d\n",alturaBin);
	printf("\n");

	alturaBinBusca = arvbb_altura(a);

	printf("Altura da abb: %d\n", alturaBinBusca);
	printf("\n");

	/*g) Trocar todos os n�s da direita e da esquerda de cada �rvore*/

	/*Atualizamos cada �rvore com a chamada da sua respectiva fun��o de troca de n�s
	e exibimos as novas �rvores em pr� - ordem*/

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

	/*Liberando a mem�ria usada pelas 2 �rvores*/

	/*Atualizamos as �rvores usando a fun��o de liberar a mem�ria de cada tipo de �rvore,
	se ambas as �rvores forem NULL no final de cada chamada, quer dizer que a mem�ria foi
	liberada adequadamente e imprimimos uma mensagem adequada para indicar isso*/

	arvore = arv_libera(arvore);
	a = abb_libera(a);

	if (arv_vazia(arvore) && abbVazia(a)) {
		printf("Memoria liberada!\n");
	}
	
	return 0;
}