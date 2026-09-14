#include "declarations.h"
void readFile(char fileName[], ListaEncadeada* lista) {

    FILE *arquivo = fopen(fileName, "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s", fileName);
        return;
    }
    char new_name[MAX_NAME];
    int new_rg;

    int total_cn = 0;
    int total_mn = 0;
    int cn_item = 0, mn_item = 0;
    char linha[100];

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        total_cn++;
        int res = sscanf(linha, " %49[^,],%d", new_name, &new_rg);
        total_cn += 2;

        if (res == 2) {
            addFinalEncadeada(lista, new_name, new_rg, &cn_item, &mn_item);
            total_cn += cn_item;
            total_mn += mn_item;
        }
        else if (res == 1) {

            int rg_padrao = 0; // Valor padrão para RG indefinido
            addFinalEncadeada(lista, new_name, rg_padrao, &cn_item, &mn_item);
            total_cn += cn_item;
            total_mn += mn_item;
        }
    }
    fclose(arquivo);

    printf("\nLeitura do arquivo %s concluída (Encadeada)!\n", fileName);
    printf("Total de elementos: %d\n", lista->tamanho);
    printf("Metricas Totais -> C(n): %d | M(n): %d\n", total_cn, total_mn);
}