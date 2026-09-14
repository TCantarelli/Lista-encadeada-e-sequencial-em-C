#include "declarations.h"

void removerPosicaoEncadeada(ListaEncadeada* lista, int pos, int* cn, int* mn) {
    *cn = 0;
    *mn = 0;

    (*cn += 3);
    if (lista->inicio == NULL || pos < 1 || pos > lista->tamanho) {
        printf("Posicao invalida ou lista vazia!\n");
        return;
    }
    No* noParaRemover = NULL;
    (*mn)++;

    (*cn)++;

    if (pos == 1) {
        noParaRemover = lista->inicio;
        lista->inicio = lista->inicio->prox;
        (*mn += 2);

        (*cn)++;
        if (lista->inicio == NULL) {
            lista->fim = NULL;
            (*mn)++;
        }
    }
    else {
        No* atual = lista->inicio;
        (*mn)++;

        for (int i = 1; i < (pos - 1); i++) {
            (*cn)++;
            atual = atual->prox;
            (*mn)++;
        }
        noParaRemover = atual->prox;
        atual->prox = noParaRemover->prox;
        (*mn += 2);

        (*cn)++;
        if (noParaRemover == lista->fim) {
            lista->fim = atual;
            (*mn)++;
        }
    }

    free(noParaRemover);
    lista->tamanho--;
    (*mn)++;

    printf("Removido da posicao %d (Encadeada) | C(n): %d | M(n): %d\n", pos, *cn, *mn);
}