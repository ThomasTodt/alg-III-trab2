#include <stdio.h>
#include <stdlib.h>
#include "BST.h"

int main(void)
{
    struct tNo *raiz = NULL;
    int v;
    char entrada[] = "10 15 5 55 50 7 8 14 13 49\0";

    raiz = montaarvore(entrada);

    printf("Percurso em ordem: ");
    emordem(raiz);
    printf("\n");

    printf("\n");
    imprime("busca", busca(raiz, 15));
    imprime("busca", busca(raiz, 50));
    imprime("busca", busca(raiz, 10));
    imprime("busca 17", busca(raiz, 17));
    printf("\n");

    imprime("minimo raiz: ", min(raiz));
    imprime("minimo 15: ", min(busca(raiz, 15)));
    imprime("minimo 55: ", min(busca(raiz, 55)));
    printf("\n");

    imprime("sucessor raiz: ", sucessor(raiz));
    imprime("sucessor 15: ", sucessor(busca(raiz, 15)));
    imprime("sucessor 5: ", sucessor(busca(raiz, 5)));
    imprime("sucessor 8: ", sucessor(busca(raiz, 8)));
    imprime("sucessor 55: ", sucessor(busca(raiz, 55)));
    printf("\n");

    v = 49;
    printf("Exclusão: %d \n", v);
    raiz = exclui(busca(raiz, v), raiz);
    emordem(raiz);

    return 0;
}