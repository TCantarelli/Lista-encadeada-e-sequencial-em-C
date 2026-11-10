#include "declarations.h"
/**
 *
 * By : Thiago Cantarelli Pereira da Silva RA: 2884020
 */
void quickSortSequencial(Dados* dados, int tam, int* cn, int* mn) {
    if (tam <= 1) {
        return;
    }

    int i = 0;
    int j = tam - 1;

    int meio = tam / 2;
    Dados pivo = dados[meio];
    (*mn)++;

    while (i <= j) {
        (*cn)++;
        while (dados[i].rg < pivo.rg) {
            i++;
            (*cn)++;
        }
        
        (*cn)++;
        while (dados[j].rg > pivo.rg) {
            j--;
            (*cn)++;
        }
        
        if (i <= j) {
            Dados temp = dados[i];
            dados[i] = dados[j];
            dados[j] = temp;
            (*mn) += 3;
            
            i++;
            j--;
        }
    }


    if (0 < j) {
        quickSortSequencial(dados, j + 1, cn, mn);
    }

    if (i < tam - 1) {
        quickSortSequencial(dados + i, tam - i, cn, mn);
    }
}