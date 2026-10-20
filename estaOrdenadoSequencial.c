#include "declarations.h"

void estaOrdenadoSequencial(Dados* dados,int tam) {
    for (int i = 1; i < tam; i++) {
        if (dados[i - 1].rg > dados[i].rg) {
            printf("Fora de ordem na pos %d\n", i);
            return;
        }
    }
    printf("Esta em ordem!\n");
    return;
}