struct tNo
{
    int chave;
    struct tNo *esq, *dir, *pai;
};

struct tNo *criaNo(int chave);

struct tNo *inclui(struct tNo *no, int c);

int token_to_num(const char *str, int *indice);

struct tNo *montaarvore(const char *str);

void visita(struct tNo *no);

void emordem(struct tNo *no);

struct tNo *busca(struct tNo *no, int chave);

struct tNo *min(struct tNo *no);

struct tNo *sucessor(struct tNo *no);

void ajustaNoPai(struct tNo *no, struct tNo *novo);

struct tNo *exclui(struct tNo *no, struct tNo *raiz);

void imprime(const char *str, struct tNo *no);