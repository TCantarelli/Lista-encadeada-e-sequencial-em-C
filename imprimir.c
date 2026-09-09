#include "declarations.h"
void imprimir(ListaEncadeada* lista) {

    if (lista->inicio == NULL) {
        printf("A lista esta vazia!");
        return;
    }
    int operations = 0;
    No* atual = lista->inicio;

    while (atual != NULL) {
        printf("%s %d  %d\n", atual->name, atual->rg, ++operations);
        atual = atual->prox;
    }
}
void imprimirSequencial(Dados* dados, int tam) {

    for (int i=0;i < tam; i++) {

        printf("%s %d pos: %d\n", dados[i].name, dados[i].rg,i+1);
    }

}