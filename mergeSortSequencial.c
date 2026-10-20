#include "declarations.h"

void mergeSortSequencial(Dados* dados, int tam, int* cn, int* mn) {
    *cn = 0;
    *mn = 0;

    if (tam <= 1)
        return;

    Dados* aux = (Dados*) malloc(tam * sizeof(Dados));
    if (aux == NULL) {
        printf("Memoria insuficiente para o Merge Sort!\n");
        return;
    }

    for (int tamanho_bloco = 1; tamanho_bloco < tam; tamanho_bloco = 2 * tamanho_bloco) {

        for (int inicio = 0; inicio < tam - 1; inicio += 2 * tamanho_bloco) {

            int meio = inicio + tamanho_bloco - 1;
            if (meio > tam - 1) {
                meio = tam - 1;
            }

            int fim = inicio + 2 * tamanho_bloco - 1;
            if (fim > tam - 1) {
                fim = tam - 1;
            }

            int i = inicio;
            int j = meio + 1;
            int k = inicio;

            while (i <= meio && j <= fim) {
                (*cn)++;
                if (dados[i].rg <= dados[j].rg) {
                    aux[k] = dados[i];
                    i++;
                } else {
                    aux[k] = dados[j];
                    j++;
                }
                (*mn)++;
                k++;
            }

            while (i <= meio) {
                aux[k] = dados[i];
                i++;
                k++;
                (*mn)++;
            }

            while (j <= fim) {
                aux[k] = dados[j];
                j++;
                k++;
                (*mn)++;
            }

            for (int m = inicio; m <= fim; m++) {
                dados[m] = aux[m];
                (*mn)++;
            }
        }
    }
    free(aux);
}