#include "declarations.h"
/**
 *
 * By : Thiago Cantarelli Pereira da Silva RA: 2884020
 */
void bubbleSortSequencial(Dados* dados, int tam, int *cn , int*mn) {

    *cn = 0;
    *mn = 0;

    for (int i =0 ; i < tam-1; i ++)
    {
        bool trocou = false;
        (*cn)++;

        for (int j = 0; j< tam-1-i;j++) {
            (*cn)++;
            if (dados[j].rg > dados[j+1].rg) {
                Dados tem = dados[j];

                dados[j] = dados[j+1];
                dados[j+1] = tem;
                (*mn) = (*mn) + 3;
                trocou = true;
            }
        }
        if (!trocou)
            break;
    }
}