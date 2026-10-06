#include "declarations.h"

void selectionSortEncadeada(ListaEncadeada* lista, int* cn, int* mn) {
    *cn = 0;
    *mn = 0;

    (*cn)++;
    if (lista->inicio == NULL || lista->inicio->prox == NULL) {
        printf("Lista vazia ou so tem 1 elemento!\n");
        return;
    }
    (*cn)++;
    for (No* atual = lista->inicio; atual->prox!= NULL; atual = atual->prox) {
        No* menor = atual;
        (*cn)++;
        for (No* seguinte = atual->prox; seguinte != NULL; seguinte = seguinte->prox) {
            (*cn)++;
            if (seguinte->rg < menor->rg) {
                (*mn)++;
                menor = seguinte;
            }
        }
        (*cn)++;
        if (menor != atual) {
            int temp_rg = atual->rg;
            char temp_name[MAX_NAME];
            strcpy(temp_name, atual->name);


            atual->rg = menor->rg;
            strcpy(atual->name, temp_name);

            menor->rg = temp_rg;
            strcpy(menor->name, temp_name);
            (*mn) = (*mn) + 6;
        }
        (*cn)++;
    }
    printf("Ordenado na lista (Encadeada) | C(n): %d | M(n): %d\n", *cn, *mn);
}