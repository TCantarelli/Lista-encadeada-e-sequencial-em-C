#include "declarations.h"
/**
 *
 * By : Thiago Cantarelli Pereira da Silva RA: 2884020
 */
int buscaBinariaSequencial(Dados* dados, int tam, int rgBuscado, int* cn, int* mn) {
    *cn = 0;
    *mn = 0;

    int inicio = 0;
    int fim = tam - 1;

    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;

        (*cn)++;
        if (dados[meio].rg == rgBuscado) {
            return meio;
        }

        (*cn)++;
        if (dados[meio].rg < rgBuscado) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    return -1;
}