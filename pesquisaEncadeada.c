#include "declarations.h"

void pesquisaEncadeada(ListaEncadeada* lista, int rg_desejado, int* cn, int* mn)
{
    No* atual = lista->inicio;
    int pos = 1;
    *cn = 0;
    *mn = 0;

    (*mn)++;

    while (atual != NULL) {
        (*cn)++;
        (*cn)++;

        if (atual->rg == rg_desejado) {
            printf("RG encontrado!\n");
            printf("Nome: %s | RG: %d | Posicao: %d\n", atual->name, atual->rg, pos);
            printf("Metricas -> C(n): %d | M(n): %d\n", *cn, *mn);
            return;
        }

        atual = atual->prox;
        (*mn)++;
        pos++;
    }

    printf("RG %d não encontrado.\n", rg_desejado);
    printf("Metricas -> C(n): %d | M(n): %d\n", *cn, *mn);
}
