#include "declarations.h"

void addMeioEncadeada(ListaEncadeada* lista, char new_name[], int new_rg, int pos, int* cn, int* mn) {
    *cn = 0;
    *mn = 0;

    (*cn += 2);
    if (pos < 1 || pos > lista->tamanho+1) {
        printf("Posicao invalida!\n");
        return;
    }

    (*cn)++;
    if (pos == 1) {
        addInicioEncadeada(lista, new_name, new_rg, cn, mn);
        return;
    }

    No* atual = lista->inicio;
    (*mn)++;


    for (int i = 1; i < pos - 1; i++) {
        (*cn += 2);
        atual = atual->prox;
        (*mn)++;
    }

    No* novo_no = (No*)malloc(sizeof(No));
    (*mn)++;

    (*cn)++;
    if (novo_no == NULL) {
        printf("Memoria Insuficiente!\n");
        return;
    }
    novo_no->rg = new_rg;
    strcpy(novo_no->name, new_name);
    (*mn += 2);

    novo_no->prox = atual->prox;
    atual->prox = novo_no;
    (*mn += 2);

    (*cn)++;
    if (novo_no->prox == NULL) {
        lista->fim = novo_no;
        (*mn)++;
    }

    lista->tamanho++;
    (*mn)++;

    printf("Adicionado na posicao %d (Encadeada) | C(n): %d | M(n): %d\n", pos, *cn, *mn);
}