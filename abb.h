/*L�via Lutz dos Santos - 2211055*/

/*Struct da abb*/

typedef struct abb Abb;

/*Fun��o que inicializa cada n� da abb como NULL*/

Abb* criaAbbVazia(void);

/*Fun��o que insere um n� na abb*/

Abb* insereAbb(int i, Abb* a);

/*Fun��o que indica se abb � vazia*/

int abbVazia(Abb* a);

/*Fun��o que imprime a abb em pr� - ordem*/

void abb_imprime(Abb* a);

/*Fun��o que calcula a altura de uma abb*/

int arvbb_altura(Abb* no);

/*Fun��o que verifica se uma abb � uma abb*/

int is_abb(Abb* a);

/*Fun��o que troca os n�s esquerdos e direitos de uma abb*/

Abb* swapLeftRight(Abb* a);

/*Fun��o que libera a mem�ria ocupada por uma abb*/

Abb* abb_libera(Abb* a);
