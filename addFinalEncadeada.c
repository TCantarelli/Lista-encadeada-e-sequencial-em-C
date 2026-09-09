#include "declarations.h"

void addFinalEncadeada(ListaEncadeada* lista, char new_name[], int new_rg) {
    No* novo_no = (No*)malloc(sizeof(No));
    if (novo_no == NULL) {
        printf("Memoria insuficiente para alocação de memoria!\n");
        return;
    }
    novo_no->prox = NULL;
    strcpy(novo_no->name, new_name);
    novo_no->rg = new_rg;

    if (lista->inicio == NULL) {
        lista->inicio = novo_no;
        lista->fim = novo_no;
    }
    else {
        lista->fim->prox = novo_no;
        lista->fim = novo_no;
    }
    lista->tamanho++;
}