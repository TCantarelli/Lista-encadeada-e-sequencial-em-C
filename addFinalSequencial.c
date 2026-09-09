#include "declarations.h"
void addFinalSequencial(Dados** dados, int* tam, char new_name[], int new_rg) {

    Dados* temp = (Dados*) realloc(*dados, (*tam + 1) * sizeof(Dados));

    if (temp == NULL) {
        printf("Memoria insuficiente para adicionar no final da lista simples!\n");
        return;
    }
    *dados = temp;

    strcpy((*dados)[*tam].name, new_name);
    (*dados)[*tam].rg = new_rg;

    (*tam)++;
    printf("Dados foram adicionados com sucesso no final da lista simples!\n");
}