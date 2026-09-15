#include "declarations.h"
void imprimir(ListaEncadeada* lista) {

    if (lista->inicio == NULL) {
        printf("A lista esta vazia!");
        return;
    }
    int operations = 0;
    No* atual = lista->inicio;

    while (atual != NULL) {
        printf("Nome: %s RG: %d Pos: %d\n", atual->name, atual->rg, ++operations);
        atual = atual->prox;
    }
}
void imprimirSequencial(Dados* dados, int tam) {

    for (int i=0;i < tam; i++) {
        printf("Nome: %s RG: %d Pos: %d\n", dados[i].name, dados[i].rg,i+1);
    }

}
