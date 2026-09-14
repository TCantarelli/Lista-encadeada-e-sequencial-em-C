#include "declarations.h"

void salvarListaSequencial(Dados* dados, int tam, char nomeArquivo[]) {
    FILE* arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo %s!\n", nomeArquivo);
        return;
    }

    for (int i = 0; i < tam; i++) {
        fprintf(arquivo, "%s,%d\n", dados[i].name, dados[i].rg);
    }

    fclose(arquivo);
    printf("Lista sequencial salva com sucesso em %s!\n", nomeArquivo);
}