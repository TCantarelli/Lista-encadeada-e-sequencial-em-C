#include "declarations.h"

void addInicioSequencial(Dados** dados, int* tam, char new_name[], int new_rg, int* cn, int* mn) {
    *cn = 0;
    *mn = 0;

    Dados* temp = (Dados*) realloc(*dados, (*tam + 1) * sizeof(Dados));
    (*mn)++;

    (*cn)++;
    if (temp == NULL) {
        printf("Memoria Insuficiente!\n");
        return;
    }
    *dados = temp;
    (*mn)++;

    for (int i = *tam; i > 0; i--) {
        (*cn)++;
        (*dados)[i] = (*dados)[i - 1];
        (*mn)++;
    }

    strcpy((*dados)[0].name, new_name);
    (*dados)[0].rg = new_rg;
    (*mn += 2);

    (*tam)++;
    (*mn)++;

    printf("Adicionado no inicio (Sequencial) | C(n): %d | M(n): %d\n", *cn, *mn);
}