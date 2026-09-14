#include "declarations.h"

void addFinalEncadeada(ListaEncadeada* lista, char new_name[], int new_rg, int* cn, int* mn) {
    *cn = 0;
    *mn = 0;


    No* novo_no = (No*)malloc(sizeof(No));
    (*mn)++;

    (*cn)++;
    if (novo_no == NULL) {
        return;
    }
    novo_no->prox = NULL;
    (*mn)++;
    strcpy(novo_no->name, new_name);
    (*mn)++;
    novo_no->rg = new_rg;
    (*mn)++;

    (*cn)++;
    if (lista->inicio == NULL) {
        lista->inicio = novo_no;
        lista->fim = novo_no;
        (*mn += 2);
    }
    else {
        lista->fim->prox = novo_no;
        lista->fim = novo_no;
        (*mn += 2);
    }
    lista->tamanho++;
    (*mn)++;
}