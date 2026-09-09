#include "declarations.h"

void addInicioSequencial(Dados** dados, int* tam, char new_name[], int new_rg) {
    Dados* temp = (Dados*) realloc(*dados, (*tam+1) *sizeof(Dados));

    if (temp == NULL) {
        printf("Memoria Insuficiente!\n");
        return;
    }
    *dados = temp;
    for (int i  = *tam; i > 0; i--) {
        (*dados)[i] = (*dados)[i-1];
    }
    strcpy((*dados)[0].name, new_name);
    (*dados)[0].rg = new_rg;

    (*tam)++;

    printf("Adicionado com sucesso no inicio da Lista Simples!\n");
}