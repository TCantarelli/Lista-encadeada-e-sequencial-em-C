#include "declarations.h"

void removerPosicaoSequencial(Dados** dados, int *tam, int pos) {
    pos--;

    if (*tam == 0) {
        printf("A lista ja esta vazia!");
        return;
    }
    if (pos < 0 ||  pos >= *tam) {
        printf("Posicao Invalida!\n");
        return;
    }

    for (int i = pos ; i < ((*tam) -1);i++) {
        (*dados)[i] = (*dados)[i+1];
    }
    Dados* temp = (Dados*) realloc( *dados, (*tam-1)*sizeof(Dados));
    if (temp != NULL || *tam - 1 == 0) {
        *dados = temp;
    }
    (*tam)--;
    printf("Elemento na posicao %d foi removido com sucesso!", pos+1);
}