#include "declarations.h"

void addMeioSequencial(Dados** dados, int* tam, char new_name[], int new_rg, int pos, int* cn, int* mn) {
    *cn = 0;
    *mn = 0;

    pos--;
    (*mn)++;

    (*cn += 2);
    if (pos < 0 || pos > *tam) {
        printf("Posicao Invalida!\n");
        return;
    }

    Dados* temp = (Dados*) realloc(*dados, (*tam + 1) * sizeof(Dados));
    (*mn)++;

    (*cn)++;
    if (temp == NULL) {
        printf("Memoria insuficiente!\n");
        return;
    }
    *dados = temp;
    (*mn)++;

    for (int i = (*tam); i > pos; i--) {
        (*cn)++;
        (*dados)[i] = (*dados)[i - 1];
        (*mn)++;
    }

    strcpy((*dados)[pos].name, new_name);
    (*dados)[pos].rg = new_rg;
    (*mn += 2);

    (*tam)++;
    (*mn)++;

    printf("Adicionado na posicao %d (Sequencial) | C(n): %d | M(n): %d\n", pos + 1, *cn, *mn);
}