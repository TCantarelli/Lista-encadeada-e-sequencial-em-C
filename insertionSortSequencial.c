#include "declarations.h"

void insertionSortSequencial(Dados* dados, int tam, int *cn, int *mn) {
    *cn = 0;
    *mn = 0;

    for (int i = 1 ;i < tam;i++) {
        Dados atual = dados[i];

        (*mn)++;
        int j = i - 1;
        (*cn)++;

        while (j >= 0 && dados[j].rg > atual.rg) {
            dados[j + 1] = dados[j];
            (*mn)++;
            j--;
            if (j>=0)
                (*cn)++;
        }
        dados[j + 1] = atual;
        (*mn)++;
    }
}