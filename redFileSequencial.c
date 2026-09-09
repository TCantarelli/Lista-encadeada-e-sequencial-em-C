#include "declarations.h"

void readFileSequencial(char nomeArquivo[],Dados** dados, int* tam) {

    FILE* arquivo = fopen(nomeArquivo, "r");

    if (arquivo == NULL) {
        printf("impossivel abrir o arquivo %s", nomeArquivo);
        return;
    }
    *dados = NULL;
    int new_rg;
    char new_name[MAX_NAME];
    *tam = 0;
    int tam_temp = 0;

    while (fscanf(arquivo," %49[^,],%d", new_name, &new_rg) == 2) {
        tam_temp++;
    }
    rewind(arquivo);

    Dados* temp = (Dados*) malloc( (tam_temp) * sizeof(Dados));

    if (temp == NULL) {
        printf("Erro de memoria!\n");
        fclose(arquivo);
        return;
    }
    *dados = temp;
    int i = 0;

    for (int i = 0; i < tam_temp && (fscanf(arquivo," %49[^,],%d", new_name, &new_rg) == 2); i++){

        strcpy((*dados)[(i)].name, new_name);
        (*dados)[(i)].rg = new_rg;
    }
    *tam = tam_temp;
    fclose(arquivo);
}