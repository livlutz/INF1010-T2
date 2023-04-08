/*L�via Lutz dos Santos - 2211055*/

/*Struct da �rvore bin�ria*/

typedef struct arv_bin arvBin;

/*Fun��o que inicializa cada n� da �rvore bin�ria como NULL*/

arvBin* criaArv(void);

/*Fun��o que verifica se a �rvore bin�ria est� vazia*/

int arv_vazia(arvBin* a);

/*Fun��o que cria cada n� da �rvore bin�ria*/

arvBin* arv_criaRaiz(int n);

/*Fun��o que imprime a �rvore bin�ria em pr� - ordem*/

void arvImprime(arvBin* a);

/*Fun��o que calcula a altura da �rvore bin�ria*/

int arvBin_altura(arvBin* no);

/*Fun��o que insere um n� na �rvore bin�ria por n�vel*/

arvBin* insere(arvBin* a, int v[], int i, int n);

/*Fun��o que verifica se a �rvore bin�ria � uma abb*/

int eh_abb(arvBin* a);

/*Fun��o que troca todos os n�s esquerdos da �rvore pelos direitos e vice - versa*/

arvBin* trocaDirEsq(arvBin* a);

/*Fun��o que libera a mem�ria ocupada pela �rvore bin�ria*/

arvBin* arv_libera(arvBin* a);
