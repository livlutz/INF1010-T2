/*Lívia Lutz dos Santos - 2211055*/

/*Struct da abb*/

typedef struct abb Abb;

/*Função que inicializa cada nó da abb como NULL*/

Abb* criaAbbVazia(void);

/*Função que insere um nó na abb*/

Abb* insereAbb(int i, Abb* a);

/*Função que indica se abb é vazia*/

int abbVazia(Abb* a);

/*Função que imprime a abb em pré - ordem*/

void abb_imprime(Abb* a);

/*Função que calcula a altura de uma abb*/

int arvbb_altura(Abb* no);

/*Função que verifica se uma abb é uma abb*/

int is_abb(Abb* a);

/*Função que troca os nós esquerdos e direitos de uma abb*/

Abb* swapLeftRight(Abb* a);

/*Função que libera a memória ocupada por uma abb*/

Abb* abb_libera(Abb* a);
