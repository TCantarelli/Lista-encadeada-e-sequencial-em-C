#include "declarations.h"
void addMeioEncadeada(ListaEncadeada* lista, char new_name[], int new_rg, int pos) {


    if (pos < 1 || pos > lista->tamanho+1) {
        printf("Posicao invalida!\n");
        return;
    }
    if (pos == 1) {
        addInicioEncadeada(lista, new_name, new_rg);
        return;
    }
    No* atual = lista->inicio;

    for (int i = 1; i < pos - 1; i++) {
        atual = atual->prox;
    }
    No* novo_no = (No*)malloc(sizeof(No));

    if (novo_no == NULL) {
        printf("Memoria Insuficiente!\n");
        return;
    }
    novo_no->rg = new_rg;
    strcpy(novo_no->name, new_name);

    novo_no->prox = atual->prox;
    atual->prox = novo_no;

    if (novo_no->prox == NULL) {
        lista->fim = novo_no;
    }

    lista->tamanho++;
    printf("Adicionado com sucesso na posicao %d!\n", pos);

}