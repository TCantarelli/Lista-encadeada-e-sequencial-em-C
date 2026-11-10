#include "declarations.h"

void inverterListaSequencial(Dados* dados, int tam) {



    for (int i=0; i<tam/2; i++) {
        int j = tam-1-i;

        int temp = dados[i].rg;
        char name_temp[MAX_NAME];
        strcpy (name_temp, dados[i].name);

        dados[i].rg = dados[j].rg;
        strcpy (dados[i].name, dados[j].name);

        dados[j].rg = temp;
        strcpy(dados[j].name, name_temp);
    }
}