#include "declarations.h"

void pesquisaSimples(Dados* dados, int rg_desejado, int tam, int* cn, int* mn)
{
    *cn = 0;
    *mn = 0;

    for (int i = 0; i < tam; i++) {
        (*cn)++;
        (*cn)++;

        if (dados[i].rg == rg_desejado) {
            printf("RG: %d encontrado na posicao %d!\n", rg_desejado, i+1);
            printf("Nome: %s | RG: %d\n", dados[i].name, dados[i].rg);
            printf("Metricas -> C(n): %d | M(n): %d\n", *cn, *mn);
            return;
        }
    }
    (*cn)++;
    printf("Metricas -> C(n): %d | M(n): %d\n", *cn, *mn);
    printf("RG: %d não encontrado!\n", rg_desejado);
}