#include "declarations.h"

void addInicioEncadeada(ListaEncadeada* lista, char new_name[], int new_rg) {

    No* novo_no = (No*) malloc(sizeof(No));

    if (novo_no == NULL) {
        printf("Memoria insuficiente!\n");
        return;
    }
    strcpy(novo_no->name, new_name);
    novo_no->rg = new_rg;
    novo_no->prox = lista->inicio;

    lista->inicio = novo_no;

    if (lista->fim == NULL) {
        lista->fim = novo_no;
    }
    lista->tamanho++;
    printf("Dados adicionados com exito na lista encadeada!\n");
}