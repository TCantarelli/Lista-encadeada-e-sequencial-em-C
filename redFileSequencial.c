#include "declarations.h"

void readFileSequencial(char nomeArquivo[], Dados** dados, int* tam) {

    FILE* arquivo = fopen(nomeArquivo, "r");

    if (arquivo == NULL) {
        printf("impossivel abrir o arquivo %s", nomeArquivo);
        return;
    }
    *dados = NULL;
    *tam = 0;
    int tam_temp = 0;
    char linha[100];
    char new_name[MAX_NAME];
    int new_rg;

    int cn = 0;
    int mn = 0;

    mn++;
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        cn++;
        int res = sscanf(linha, " %49[^,],%d", new_name, &new_rg);
        cn += 2;
        if (res >= 1) {
            tam_temp++;
            mn++;
        }
    }

    rewind(arquivo);
    mn++;

    Dados* temp = (Dados*) malloc(tam_temp * sizeof(Dados));
    mn++;

    if (temp == NULL) {
        cn++;
        printf("Erro de memoria!\n");
        fclose(arquivo);
        return;
    }
    *dados = temp;
    mn++;

    int i = 0;
    while (fgets(linha, sizeof(linha), arquivo) != NULL && i < tam_temp) {
        cn += 2;
        int res = sscanf(linha, " %49[^,],%d", new_name, &new_rg);

        if (res == 2) {
            strcpy((*dados)[i].name, new_name);
            (*dados)[i].rg = new_rg;
            mn += 2;
            i++;
            mn++;
        } else if (res == 1) {
            strcpy((*dados)[i].name, new_name);
            (*dados)[i].rg = 0;
            i++;
            mn++;
        }
    }
    *tam = i;
    mn++;
    fclose(arquivo);

    printf("\nLeitura do arquivo %s concluída (Sequencial)!\n", nomeArquivo);
    printf("Total de elementos: %d\n", *tam);
    printf("Metricas Totais -> C(n): %d | M(n): %d\n", cn, mn);
}