#include "declarations.h"
void selectionSortSequencial(Dados* dados, int tam, int* cn, int* mn) {
    *cn = 0;
    *mn = 0;

    for (int i = 0; i < (tam - 1); i++) {
        int indice_menor = i;

        for (int j = i + 1; j < tam; j++) {
            (*cn)++;
            if (dados[j].rg < dados[indice_menor].rg) {
                indice_menor = j;
            }
        }


        if (indice_menor != i) {
            Dados temp = dados[i];
            dados[i] = dados[indice_menor];
            dados[indice_menor] = temp;

            *mn += 3;
        }
    }
    printf("Selection Sort (Sequencial) concluido | C(n): %d | M(n): %d\n", *cn, *mn);
}