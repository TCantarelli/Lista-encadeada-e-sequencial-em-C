#include "declarations.h"
void liberarListaEncadeada(ListaEncadeada* lista) {
    if (lista == NULL)
        return;


    No* atual = lista->inicio;
    No* proximo_no;


    while (atual != NULL) {
        proximo_no = atual->prox;
        free(atual);
        atual = proximo_no;
    }

    lista->inicio = NULL;
    printf("Lista encadeada Liberada com exito!\n");
}