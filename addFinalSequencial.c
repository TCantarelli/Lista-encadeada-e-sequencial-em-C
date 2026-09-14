#include "declarations.h"

void addFinalSequencial(Dados** dados, int* tam, char new_name[], int new_rg, int* cn, int* mn) {
    *cn = 0;
    *mn = 0;

    Dados* temp = (Dados*) realloc(*dados, (*tam + 1) * sizeof(Dados));
    (*mn)++;


    (*cn)++;
    if (temp == NULL) {
        printf("Memoria insuficiente!\n");
        return;
    }
    *dados = temp;
    (*mn)++;

    strcpy((*dados)[*tam].name, new_name);
    (*dados)[*tam].rg = new_rg;
    (*mn += 2);

    (*tam)++;
    (*mn)++;

    printf("Adicionado no final (Sequencial) | C(n): %d | M(n): %d\n", *cn, *mn);
}