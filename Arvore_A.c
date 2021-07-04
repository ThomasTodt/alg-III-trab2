#include <stdio.h>
#include <stdlib.h>
#include "Arvore_A.h"

struct tNo_B *criaNo_B(int chave)
{
    struct tNo_B *n = (struct tNo_B *)malloc(sizeof(struct tNo_B));
    n->chave = chave;
    n->esq = NULL;
    n->dir = NULL;
    return n;
}

struct tNo_B *inclui_B(struct tNo_B *no, int c)
{
    if (no == NULL)
        return criaNo_B(c);
    if (c < no->chave)
    {
        no->esq = inclui(no->esq, c);
        // no->esq->pai = no;
    }
    else
    {
        no->dir = inclui(no->dir, c);
        // no->dir->pai = no;
    }
    return no;
}

int chars_para_int(const char *str, int *indice)
{
    char numero[10];
    int i;
    for(i=0;str[*indice]>47;i++){
        numero[i] = str[*indice];
        *indice++;
    }
    numero[i] = '\0';
    return atoi(numero);
}

struct tNo_B *montaarvore_B(const char *str)
{
    struct tNo_B *raiz = NULL;
    int i = 0;
    raiz = inclui_B(NULL, chars_para_int(str, &i));
    while (str[i] != '\0')
    {
        inclui(raiz, chars_para_int(str, &i));
    }
    return raiz;
}

int soma_arvore(struct tNo_B *no){
    // soma os numeros nos nós da arvore contida
    if(no == NULL)
        return 0;
    
    return (no->chave + soma_arvore(no->esq) + soma_arvore(no->esq));
}

int soma_entrada(char *bonsai){
    int i = 0;
    int soma = 0;
    while(bonsai[i] != '\0'){
        if(bonsai[i] > 47){ /* se for um numero */
            soma += chars_para_int(bonsai, &i);
        }
        else
            i++;
    }

    return soma;
}

struct tNo_A *criaNo(struct tNo_B *chave)
{
    struct tNo_A *n = (struct tNo_A *)malloc(sizeof(struct tNo_A));
    n->chave = chave;
    n->esq = NULL;
    n->dir = NULL;
    n->pai = NULL;
    return n;
}

struct tNo_A *inclui(struct tNo_A *no, struct tNo_B *bonsai)
{
    if (no == NULL)
        return criaNo(montaarvore_B(bonsai));
    if (soma_entrada(bonsai) < soma_arvore(no->chave)) // se a arvore sendo incluida tiver soma menor que a arvore no no atual
    {
        no->esq = inclui(no->esq, bonsai);
        no->esq->pai = no;
    }
    else
    {
        no->dir = inclui(no->dir, bonsai);
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

struct tNo_A *montaarvore(const char *str)
{
    struct tNo_A *raiz = NULL;
    int i = 0;
    raiz = inclui(NULL, token_to_num(str, &i));
    while (str[i] != '\0')
    {
        inclui(raiz, token_to_num(str, &i));
    }
    return raiz;
}

void visita(struct tNo_A *no)
{
    printf("%d.", no->chave);
}

void emordem(struct tNo_A *no)
{
    if (no != NULL)
    {
        emordem(no->esq);
        visita(no);
        emordem(no->dir);
    }
}

struct tNo_A *busca(struct tNo_A *no, int chave)
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

struct tNo_A *min(struct tNo_A *no)
{
    if (no->esq == NULL)
        return no;
    else
        return min(no->esq);
}

struct tNo_A *sucessor(struct tNo_A *no)
{
    struct tNo_A *s = NULL;
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

void ajustaNoPai(struct tNo_A *no, struct tNo_A *novo)
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

struct tNo_A *exclui(struct tNo_A *no, struct tNo_A *raiz)
{
    struct tNo_A *s, *novaRaiz = raiz;
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

void imprime(const char *str, struct tNo_A *no)
{
    printf("||%s ", str);
    if (no != NULL)
        printf("[ %d ]", no->chave);
    else
        printf("Não");
    printf("Encontrado\n");
}
