#include "declarations.h"

void addInicioEncadeada(ListaEncadeada* lista, char new_name[], int new_rg, int* cn, int* mn) {
    *cn = 0;
    *mn = 0;

    No* novo_no = (No*) malloc(sizeof(No));
    (*mn)++;

    (*cn)++;
    if (novo_no == NULL) {
        printf("Memoria insuficiente!\n");
        return;
    }

    strcpy(novo_no->name, new_name);
    (*mn)++;
    novo_no->rg = new_rg;
    (*mn)++;

    novo_no->prox = lista->inicio;
    (*mn)++;

    lista->inicio = novo_no;
    (*mn)++;

    (*cn)++;
    if (lista->fim == NULL) {
        lista->fim = novo_no;
        (*mn)++;
    }

    lista->tamanho++;
    (*mn)++;

    printf("Adicionado no inicio (Encadeada) | C(n): %d | M(n): %d\n", *cn, *mn);
}