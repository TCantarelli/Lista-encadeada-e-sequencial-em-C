#include "declarations.h"
void pesquisaEncadeada(ListaEncadeada* lista, int rg_desejado)
{
    No* atual = lista->inicio;
    int pos = 1;
    while (atual != NULL) {
        if (atual->rg == rg_desejado) {
            printf("RG encontrado!\n");
            printf("Nome : %s RG: %d posicao : %d\n", atual->name, atual->rg, pos);
            return;
        }
        atual = atual->prox;
        pos++;
    }
    printf("RG %d não encontrado", rg_desejado);
}