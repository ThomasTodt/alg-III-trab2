#include <stdio.h>
#include <stdlib.h>
#include "Arvore_A.h"

int main(void)
{
    struct tNo_A *raiz = NULL;

    char comando;
    char bonsai[100];
    char continuar = 'y';

    while(continuar == 'y'){ // na verdade, tem que dar um jeito disso ler um arquivo ate o final
        scanf("%c", &comando);
        scanf("%s", bonsai);
        switch(comando){
            case 'i':
                inclui(raiz, bonsai); 
                break;
            case 'b':
                busca(raiz, soma_entrada(bonsai));
                break;
            case 'r':
                exclui(raiz, soma_entrada(bonsai));
                break;
        }
        printf("continuar? (y/n): \n");
        scanf("%c", continuar); 
    }
    /*emordem(raiz);*/

    return 0;
}
