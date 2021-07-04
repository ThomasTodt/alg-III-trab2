struct tNo_A
{
    struct tNo_B *chave;
    struct tNo_A *esq, *dir, *pai;
};

struct tNo_B
{
    int chave;
    struct tNo_B *esq, *dir;
};

struct tNo_B *criaNo_B(int chave);

struct tNo_B *inclui_B(struct tNo_B *no, int c);

int chars_para_int(const char *str, int *indice);

struct tNo_B *montaarvore_B(const char *str);

int soma_arvore(struct tNo_B *no);

int soma_entrada(char *bonsai);

struct tNo_A *criaNo(struct tNo_B *chave);

struct tNo_A *inclui(struct tNo_A *no, struct tNo_B *bonsai);

int token_to_num(const char *str, int *indice);

struct tNo_A *montaarvore(const char *str);

void visita(struct tNo_A *no);

void emordem(struct tNo_A *no);

struct tNo_A *busca(struct tNo_A *no, int chave);

struct tNo_A *min(struct tNo_A *no);

struct tNo_A *sucessor(struct tNo_A *no);

void ajustaNoPai(struct tNo_A *no, struct tNo_A *novo);

struct tNo_A *exclui(struct tNo_A *no, struct tNo_A *raiz);

void imprime(const char *str, struct tNo_A *no);
