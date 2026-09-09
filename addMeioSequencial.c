#include "declarations.h"

void addMeioSequencial(Dados** dados, int* tam, char new_name[], int new_rg, int pos) {

    pos--;

    if (pos < 0 || pos > *tam) {
        printf("Posicao Invalida!\n");
        return;
    }
    Dados* temp = (Dados*) realloc(*dados, (*tam + 1) * sizeof(Dados));

    if (temp == NULL) {
        printf("Memoria insuficiente!\n");
        return;
    }
    *dados = temp;
    for (int i = (*tam); i > pos ; i--) {
        (*dados)[i] = (*dados)[i-1];
    }
    strcpy((*dados)[pos].name, new_name);
    (*dados)[pos].rg = new_rg;

    (*tam)++;
    printf("Adicionado com sucesso na posicao %d da lista sequencial!\n", pos+1);
}