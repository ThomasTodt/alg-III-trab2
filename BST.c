#include <stdio.h>
#include <stdlib.h>
#include "BST.h"

struct tNo *criaNo(int chave)
{
    struct tNo *n = (struct tNo *)malloc(sizeof(struct tNo));
    n->chave = chave;
    n->esq = NULL;
    n->dir = NULL;
    n->pai = NULL;
    return n;
}

struct tNo *inclui(struct tNo *no, int c)
{
    if (no == NULL)
        return criaNo(c);
    if (c < no->chave)
    {
        no->esq = inclui(no->esq, c);
        no->esq->pai = no;
    }
    else
    {
        no->dir = inclui(no->dir, c);
        no->dir->pai = no;
    }
    return no;
}

int token_to_num(const char *str, int *indice)
{
    char token[100];
    int i = 0;
    while (str[*indice] != '\0' && str[*indice] != ' ')
    {
        token[i] = str[*indice];
        i++;
        (*indice)++;
    }
    token[i] = '\0';
    (*indice)++;
    return atoi(token);
}

struct tNo *montaarvore(const char *str)
{
    struct tNo *raiz = NULL;
    int i = 0;
    raiz = inclui(NULL, token_to_num(str, &i));
    while (str[i] != '\0')
    {
        inclui(raiz, token_to_num(str, &i));
    }
    return raiz;
}

void visita(struct tNo *no)
{
    printf("%d.", no->chave);
}

void emordem(struct tNo *no)
{
    if (no != NULL)
    {
        emordem(no->esq);
        visita(no);
        emordem(no->dir);
    }
}

struct tNo *busca(struct tNo *no, int chave)
{
    if (no == NULL)
        return NULL;

    if (no->chave == chave)
        return no;
    if (chave < no->chave)
        return busca(no->esq, chave);
    else
        return busca(no->dir, chave);
}

struct tNo *min(struct tNo *no)
{
    if (no->esq == NULL)
        return no;
    else
        return min(no->esq);
}

struct tNo *sucessor(struct tNo *no)
{
    struct tNo *s = NULL;
    if (no->dir != NULL)
        return min(no->dir);
    else
    {
        s = no->pai;
        while (s != NULL && no == s->dir)
        {
            no = s;
            s = s->pai;
        }
    }
    return s;
}

void ajustaNoPai(struct tNo *no, struct tNo *novo)
{
    if (no->pai != NULL)
    {
        if (no->pai->esq == no)
            no->pai->esq = novo;
        else
            no->pai->dir = novo;
        if (novo != NULL)
            novo->pai = no->pai;
    }
}

struct tNo *exclui(struct tNo *no, struct tNo *raiz)
{
    struct tNo *s, *novaRaiz = raiz;
    if (no->esq == NULL)
    {
        ajustaNoPai(no, no->dir);
        free(no);
    }
    else
    {
        if (no->dir == NULL)
        {
            ajustaNoPai(no, no->esq);
            free(no);
        }
        else
        {
            s = sucessor(no);
            ajustaNoPai(s, s->dir);
            s->esq = no->esq;
            s->dir = no->dir;
            ajustaNoPai(no, s);
            if (no == raiz)
                novaRaiz = s;
            free(no);
        }
    }
    return novaRaiz;
}

void imprime(const char *str, struct tNo *no)
{
    printf("||%s ", str);
    if (no != NULL)
        printf("[ %d ]", no->chave);
    else
        printf("Não");
    printf("Encontrado\n");
}
