#include "declarations.h"

void salvarListaEncadeada(ListaEncadeada* lista, char nomeArquivo[]) {
    FILE* arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo %s!\n", nomeArquivo);
        return;
    }

    No* atual = lista->inicio;
    while (atual != NULL) {
        fprintf(arquivo, "%s,%d\n", atual->name, atual->rg);
        atual = atual->prox;
    }

    fclose(arquivo);
    printf("Lista encadeada salva com sucesso em %s!\n", nomeArquivo);
}