
#include "declarations.h"

void pesquisaSimples(Dados* dados, int rg_desejado, int tam)
{
    for (int i = 0; i < tam; i++) {
        if (dados[i].rg == rg_desejado) {
            printf("RG: %d encontrado! na posição %d \n", rg_desejado, i+1);
            printf("Nome: %s, RG: %d\n", dados[i].name, dados[i].rg);
        }
    }
    printf("RG: %d não encontrado!", rg_desejado);
}
