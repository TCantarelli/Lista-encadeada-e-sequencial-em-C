#include "declarations.h"

int main () {

    ListaEncadeada listaEnc;
    listaEnc.inicio = NULL;
    listaEnc.fim = NULL;
    listaEnc.tamanho = 0;

    No* lista = NULL;
    Dados* dados;
    dados = (Dados*) malloc(sizeof(Dados));
    int option;
    int tam = 0;
    bool continuar = true;
    while (continuar) {
        showMenuPrimary();
        scanf("%d", &option);
        while (getchar() != '\n');

        switch (option){
            case 1: {
                int arquivoDesejado;
                showMenuFile();

                scanf("%d", &arquivoDesejado);

                switch (arquivoDesejado){
                    case 1: readFile("NomeRG10.txt", &listaEnc);
                        break;
                    case 2: readFile("NomeRG50.txt", &listaEnc);
                        break;
                    case 3: readFile("NomeRG100.txt", &listaEnc); break;
                    case 4: readFile("NomeRG1K.txt", &listaEnc);
                        break;
                    case 5: readFile("NomeRG10K.txt", &listaEnc);
                        break;
                    case 6: readFile("NomeRG1M.txt", &listaEnc);
                        break;
                    case 7: readFile("NomeRG100M.txt", &listaEnc);
                        break;
                    default: printf("Opcao escolhida invalida!\n");
                        break;
                }
                break;
            }

            case 2: {
                int opcao;
                showMenuFile();

                scanf("%d", &opcao);
                switch (opcao){
                    case 1: readFileSequencial("NomeRG10.txt", &dados, &tam);
                        break;
                    case 2: readFileSequencial("NomeRG50.txt", &dados, &tam);
                        break;
                    case 3: readFileSequencial("NomeRG100.txt", &dados, &tam);
                        break;
                    case 4: readFileSequencial("NomeRG1K.txt", &dados, &tam);
                        break;
                    case 5: readFileSequencial("NomeRG10K.txt", &dados, &tam);
                        break;
                    case 6: readFileSequencial("NomeRG1M.txt", &dados, &tam);
                        break;
                    case 7: readFileSequencial("NomeRG100M.txt", &dados, &tam);
                        break;
                    default: printf("Opcao escolhida invalida!\n"); break;
                }
                break;
            }
            case 3: {
                int rgDesejado;

                printf("Digite o RG que deseja procurar OBS: APENAS NUMEROS\n");
                scanf("%d", &rgDesejado);
                pesquisaEncadeada(&listaEnc, rgDesejado);

            }
            break;
            case 4: {
                int rg_desejado;
                printf("Digite o RG que deseja buscar: \n");
                scanf("%d", &rg_desejado);
                pesquisaSimples(dados, rg_desejado, tam);
            }
            break;
            case 5:{
                imprimir(&listaEnc);
            }
                break;
            case 6:{
                imprimirSequencial(dados, tam);
            }
                break;
            case 7: {
                printf("Digite o nome que você quer adicionar:\n");
                char new_name[BUFLEN];
                fgets(new_name, BUFLEN, stdin);
                new_name[strcspn(new_name, "\n")] = '\0';
                printf("Agora digite o RG da pessoa %s : ", new_name);
                int new_rg;
                scanf("%d", &new_rg);
                while (getchar() != '\n');

                addFinalEncadeada(&listaEnc, new_name, new_rg);
            }break;
            case 8: {
                printf("Digite o nome que você quer adicionar:\n");
                char new_name[BUFLEN];
                fgets(new_name, BUFLEN, stdin);
                new_name[strcspn(new_name, "\n")] = '\0';
                printf("Agora digite o RG da pessoa %s : ", new_name);
                int new_rg;
                scanf("%d", &new_rg);
                while (getchar() != '\n');
                addFinalSequencial(&dados, &tam, new_name , new_rg );
            }break;
            case 9: {
                printf("Digite o nome que você quer adicionar:\n");
                char new_name[BUFLEN];
                fgets(new_name, BUFLEN, stdin);
                new_name[strcspn(new_name, "\n")] = '\0';
                printf("Agora digite o RG da pessoa %s : ", new_name);
                int new_rg;
                scanf("%d", &new_rg);
                while (getchar() != '\n');
                addInicioEncadeada(&listaEnc, new_name, new_rg);
            }break;
            case 10: {
                printf("Digite o nome que você quer adicionar:\n");
                char new_name[BUFLEN];
                fgets(new_name, BUFLEN, stdin);
                new_name[strcspn(new_name, "\n")] = '\0';
                printf("Agora digite o RG da pessoa %s : ", new_name);
                int new_rg;
                scanf("%d", &new_rg);
                while (getchar() != '\n');
                addInicioSequencial(&dados, &tam, new_name, new_rg);
            }break;
            case 11: {
                printf("Digite o nome que você quer adicionar:\n");
                char new_name[BUFLEN];
                fgets(new_name, BUFLEN, stdin);
                new_name[strcspn(new_name, "\n")] = '\0';
                printf("Agora digite o RG da pessoa %s : ", new_name);
                int new_rg;
                scanf("%d", &new_rg);
                int pos;
                printf("Em qual posicao deseja adicionar esses dados?\n");
                scanf("%d", &pos);
                while (getchar() != '\n');
                addMeioEncadeada(&listaEnc, new_name, new_rg, pos);
            }break;
            case 12: {
                printf("Digite o nome que você quer adicionar:\n");
                char new_name[BUFLEN];
                fgets(new_name, BUFLEN, stdin);
                new_name[strcspn(new_name, "\n")] = '\0';
                printf("Agora digite o RG da pessoa %s : ", new_name);
                int new_rg;
                scanf("%d", &new_rg);
                int pos;
                printf("Em qual posicao deseja adicionar esses dados?\n");
                scanf("%d", &pos);
                while (getchar() != '\n');
                addMeioSequencial(&dados, &tam, new_name, new_rg, pos);
            }break;
            case 13: {
                if (listaEnc.tamanho == 0) {
                    printf("A lista esta vazia!\n");
                    break;
                }
                printf("Digite qual posicao deseja remover:\n");
                int pos;
                scanf("%d", &pos);
                while (getchar() != '\n');
                removerPosicaoEncadeada(&listaEnc, pos);
            }break;
            case 14: {
                if (listaEnc.tamanho == 0) {
                    printf("A lista esta vazia!\n");
                    break;
                }
                printf("Digite qual posicao deseja remover:\n");
                int pos;
                scanf("%d", &pos);
                while (getchar() != '\n');
                removerPosicaoSequencial(&dados,&tam, pos);
            }break;
            case 167: {
                continuar = false;
            }
            break;
            default:
                printf("Opcao invalida principal!\n");
                break;
        }
    }
    printf("\nBy Cantarelli");
    return 0;
}