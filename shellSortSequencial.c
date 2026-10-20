#include "declarations.h"

void shellSortSequencial(Dados* dados, int tam, int* mn, int* cn) {
    (*mn) = 0;
    (*cn) = 0;
    int k = 1;
    while ((int)((pow(3, k + 1) - 1) / 2) < tam) {
        k++;
    }
    while (k>= 1) {

        int h = (int)((pow(3,k) - 1)/2);

        for (int i = h ; i < tam; i++) {
            Dados tmp = dados[i];

            (*mn)++;
            int j = i;

            while (j>=h) {
                (*cn)++;

                if (dados[j-h].rg > tmp.rg) {
                    dados[j] = dados[j-h];
                    (*mn)++;
                    j -=h;
                }
                else
                    break;
            }
            dados[j] = tmp;
            (*mn)++;
        }

        k--;
    }
}