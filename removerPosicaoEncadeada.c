#include "declarations.h"

void removerPosicaoEncadeada(ListaEncadeada* lista, int pos) {
    if (lista->inicio == NULL || pos < 1 || pos > lista->tamanho) {
        printf("Posicao invalida ou lista vazia!\n");
        return;
    }
    No* noParaRemover = NULL;

    if (pos == 1) {
        noParaRemover = lista->inicio;
        lista->inicio = lista->inicio->prox;

        if (lista->inicio == NULL)
            lista->fim = NULL;
    }
    else {
        No* atual = lista->inicio;

        for (int i = 1; i < ( pos -1 ); i++) {
            atual = atual->prox;
        }
        noParaRemover = atual->prox;
        atual->prox = noParaRemover->prox;
        if (noParaRemover == lista->fim) {
            lista->fim = atual;
        }
        free(noParaRemover);
        lista->tamanho--;
    }

}