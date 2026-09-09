#include "declarations.h"
void readFile(char fileName[], ListaEncadeada* lista) {

    FILE *arquivo = fopen(fileName, "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s", fileName);
        return;
    }
    No* atual = NULL;
    No* ultimo = NULL;
    char new_name[MAX_NAME];
    int new_rg;
    while (fscanf(arquivo," %49[^,],%d", new_name, &new_rg) == 2) {
        addFinalEncadeada(lista, new_name, new_rg);
    }
    fclose(arquivo);
}