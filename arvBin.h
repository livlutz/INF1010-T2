/*Lívia Lutz dos Santos - 2211055*/

/*Struct da árvore binária*/

typedef struct arv_bin arvBin;

/*Função que inicializa cada nó da árvore binária como NULL*/

arvBin* criaArv(void);

/*Função que verifica se a árvore binária está vazia*/

int arv_vazia(arvBin* a);

/*Função que cria cada nó da árvore binária*/

arvBin* arv_criaRaiz(int n);

/*Função que imprime a árvore binária em pré - ordem*/

void arvImprime(arvBin* a);

/*Função que calcula a altura da árvore binária*/

int arvBin_altura(arvBin* no);

/*Função que insere um nó na árvore binária por nível*/

arvBin* insere(arvBin* a, int v[], int i, int n);

/*Função que verifica se a árvore binária é uma abb*/

int eh_abb(arvBin* a);

/*Função que troca todos os nós esquerdos da árvore pelos direitos e vice - versa*/

arvBin* trocaDirEsq(arvBin* a);

/*Função que libera a memória ocupada pela árvore binária*/

arvBin* arv_libera(arvBin* a);
