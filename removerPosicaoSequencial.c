#include "declarations.h"

void removerPosicaoSequencial(Dados** dados, int *tam, int pos, int* cn, int* mn) {
    *cn = 0;
    *mn = 0;

    pos--;
    (*mn)++;

    (*cn)++;
    if (*tam == 0) {
        printf("A lista ja esta vazia!\n");
        return;
    }

    (*cn += 2);
    if (pos < 0 || pos >= *tam) {
        printf("Posicao Invalida!\n");
        return;
    }

    for (int i = pos; i < ((*tam) - 1); i++) {
        (*cn)++;
        (*dados)[i] = (*dados)[i + 1];
        (*mn)++;
    }

    Dados* temp = (Dados*) realloc(*dados, (*tam - 1) * sizeof(Dados));
    (*mn)++;

    (*cn)++;
    if (temp != NULL || *tam - 1 == 0) {
        *dados = temp;
        (*mn)++;
    }

    (*tam)--;
    (*mn)++;

    printf("Removido da posicao %d (Sequencial) | C(n): %d | M(n): %d\n", pos + 1, *cn, *mn);
}