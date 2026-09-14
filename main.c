#include "declarations.h"

int main () {

    ListaEncadeada listaEnc;
    listaEnc.inicio = NULL;
    listaEnc.fim = NULL;
    listaEnc.tamanho = 0;

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
                int cn = 0, mn = 0;

                printf("Digite o RG que deseja procurar OBS: APENAS NUMEROS\n");
                scanf("%d", &rgDesejado);
                pesquisaEncadeada(&listaEnc, rgDesejado, &cn, &mn);
            }
            break;
            case 4: {
                int rg_desejado;
                int cn = 0, mn = 0;

                printf("Digite o RG que deseja buscar: \n");
                scanf("%d", &rg_desejado);
                pesquisaSimples(dados, rg_desejado, tam, &cn, &mn);
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

                int cn = 0, mn = 0;
                addFinalEncadeada(&listaEnc, new_name, new_rg, &cn, &mn);
                printf("Adicionado no final (Encadeada) | C(n): %d | M(n): %d\n", cn, mn);
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

                int cn = 0, mn = 0;
                addFinalSequencial(&dados, &tam, new_name, new_rg, &cn, &mn);
                printf("Adicionado no final (Sequencial) | C(n): %d | M(n): %d\n", cn, mn);
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

                int cn = 0, mn = 0;
                addInicioEncadeada(&listaEnc, new_name, new_rg, &cn, &mn);
                printf("Adicionado no inicio (Encadeada) | C(n): %d | M(n): %d\n", cn, mn);
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

                int cn = 0, mn = 0;
                addInicioSequencial(&dados, &tam, new_name, new_rg, &cn, &mn);
                printf("Adicionado no inicio (Sequencial) | C(n): %d | M(n): %d\n", cn, mn);
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

                int cn = 0, mn = 0;
                addMeioEncadeada(&listaEnc, new_name, new_rg, pos, &cn, &mn);
                printf("Adicionado na posicao %d (Encadeada) | C(n): %d | M(n): %d\n", pos, cn, mn);
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

                int cn = 0, mn = 0;
                addMeioSequencial(&dados, &tam, new_name, new_rg, pos, &cn, &mn);
                printf("Adicionado na posicao %d (Sequencial) | C(n): %d | M(n): %d\n", pos, cn, mn);
            }break;
            case 13: {
                if (tam == 0) {
                    printf("A lista esta vazia!\n");
                    break;
                }
                printf("Digite qual posicao deseja remover da lista sequencial:\n");
                int pos;
                scanf("%d", &pos);
                while (getchar() != '\n');

                int cn = 0, mn = 0;
                removerPosicaoSequencial(&dados, &tam, pos, &cn, &mn);
                printf("Removido da posicao %d (Sequencial) | C(n): %d | M(n): %d\n", pos, cn, mn);
            }break;
            case 14: {
                if (listaEnc.tamanho == 0) {
                    printf("A lista esta vazia!\n");
                    break;
                }
                printf("Digite qual posicao deseja remover da lista encadeada:\n");
                int pos;
                scanf("%d", &pos);
                while (getchar() != '\n');

                int cn = 0, mn = 0;
                removerPosicaoEncadeada(&listaEnc, pos, &cn, &mn);
                printf("Removido da posicao %d (Encadeada) | C(n): %d | M(n): %d\n", pos, cn, mn);
            }break;
            case 15: {
                int opcaoArquivo;
                showMenuFile();
                scanf("%d", &opcaoArquivo);
                while (getchar() != '\n');

                char nomeArq[50];
                switch (opcaoArquivo){
                    case 1: strcpy(nomeArq, "NomeRG10.txt"); break;
                    case 2: strcpy(nomeArq, "NomeRG50.txt"); break;
                    case 3: strcpy(nomeArq, "NomeRG100.txt"); break;
                    case 4: strcpy(nomeArq, "NomeRG1K.txt"); break;
                    case 5: strcpy(nomeArq, "NomeRG10K.txt"); break;
                    case 6: strcpy(nomeArq, "NomeRG1M.txt"); break;
                    case 7: strcpy(nomeArq, "NomeRG100M.txt"); break;
                    default:
                        printf("Opcao invalida!\n");
                        break;
                }

                ListaEncadeada listaTeste;
                listaTeste.inicio = NULL;
                listaTeste.fim = NULL;
                listaTeste.tamanho = 0;

                clock_t inicioEnc = clock();
                readFile(nomeArq, &listaTeste);
                clock_t fimEnc = clock();
                double tempoEnc = (double)(fimEnc - inicioEnc) / CLOCKS_PER_SEC;

                Dados* dadosTeste = NULL;
                int tamTeste = 0;

                clock_t inicioSeq = clock();
                readFileSequencial(nomeArq, &dadosTeste, &tamTeste);
                clock_t fimSeq = clock();
                double tempoSeq = (double)(fimSeq - inicioSeq) / CLOCKS_PER_SEC;

                printf("\n--- TEMPO DE LEITURA (%s) ---\n", nomeArq);
                printf("Lista Encadeada:  %.6f segundos\n", tempoEnc);
                printf("Lista Sequencial: %.6f segundos\n", tempoSeq);

                if (tempoEnc < tempoSeq) {
                    printf("-> A Lista Encadeada foi mais rápida.\n");
                } else if (tempoSeq < tempoEnc) {
                    printf("-> A Lista Sequencial foi mais rápida.\n");
                } else {
                    printf("-> Ambas levaram o mesmo tempo.\n");
                }

                free(dadosTeste);
                break;
            }
            case 16: {
                if (listaEnc.tamanho == 0 || tam == 0) {
                    printf("As listas precisam estar preenchidas para comparar a remocao!\n");
                    break;
                }

                int pos;
                printf("Digite a posicao que deseja remover de ambas as listas: ");
                scanf("%d", &pos);
                while (getchar() != '\n');

                int cn_enc = 0, mn_enc = 0;
                clock_t inicio_enc = clock();
                removerPosicaoEncadeada(&listaEnc, pos, &cn_enc, &mn_enc);
                clock_t fim_enc = clock();
                double tempo_enc = (double)(fim_enc - inicio_enc) / CLOCKS_PER_SEC;

                int cn_seq = 0, mn_seq = 0;
                clock_t inicio_seq = clock();
                removerPosicaoSequencial(&dados, &tam, pos, &cn_seq, &mn_seq);
                clock_t fim_seq = clock();
                double tempo_seq = (double)(fim_seq - inicio_seq) / CLOCKS_PER_SEC;

                printf("\n==================================================\n");
                printf("       COMPARACAO DE REMOCAO (Posicao %d)\n", pos);
                printf("==================================================\n");
                printf("LISTA ENCADEADA:\n");
                printf(" - Tempo de Execucao : %.6f segundos\n", tempo_enc);
                printf(" - Comparacoes C(n)  : %d\n", cn_enc);
                printf(" - Movimentacoes M(n): %d\n", mn_enc);

                printf("\nLISTA SEQUENCIAL:\n");
                printf(" - Tempo de Execucao : %.6f segundos\n", tempo_seq);
                printf(" - Comparacoes C(n)  : %d\n", cn_seq);
                printf(" - Movimentacoes M(n): %d\n", mn_seq);
                printf("==================================================\n");

                if (tempo_enc < tempo_seq) {
                    printf("-> Vencedor em Tempo: Lista Encadeada foi mais rapida.\n");
                } else if (tempo_seq < tempo_enc) {
                    printf("-> Vencedor em Tempo: Lista Sequencial foi mais rapida.\n");
                } else {
                    printf("-> Empate exato no tempo de execucao.\n");
                }
                printf("==================================================\n");
                break;
            }
            case 17: {
                printf("Digite o nome que quer adicionar no inicio: ");
                char nome[BUFLEN];
                fgets(nome, BUFLEN, stdin);
                nome[strcspn(nome, "\n")] = '\0';

                printf("Digite o RG: ");
                int rg;
                scanf("%d", &rg);
                while (getchar() != '\n');

                int cn_enc = 0, mn_enc = 0;
                clock_t inicio_enc = clock();
                addInicioEncadeada(&listaEnc, nome, rg, &cn_enc, &mn_enc);
                clock_t fim_enc = clock();
                double tempo_enc = (double)(fim_enc - inicio_enc) / CLOCKS_PER_SEC;

                int cn_seq = 0, mn_seq = 0;
                clock_t inicio_seq = clock();
                addInicioSequencial(&dados, &tam, nome, rg, &cn_seq, &mn_seq);
                clock_t fim_seq = clock();
                double tempo_seq = (double)(fim_seq - inicio_seq) / CLOCKS_PER_SEC;

                printf("\n==================================================\n");
                printf("       COMPARACAO DE INSERCAO NO INICIO\n");
                printf("==================================================\n");
                printf("LISTA ENCADEADA:\n");
                printf(" - Tempo de Execucao : %.6f segundos\n", tempo_enc);
                printf(" - Comparacoes C(n)  : %d\n", cn_enc);
                printf(" - Movimentacoes M(n): %d\n", mn_enc);

                printf("\nLISTA SEQUENCIAL:\n");
                printf(" - Tempo de Execucao : %.6f segundos\n", tempo_seq);
                printf(" - Comparacoes C(n)  : %d\n", cn_seq);
                printf(" - Movimentacoes M(n): %d\n", mn_seq);
                printf("==================================================\n");
                break;
            }
            case 18: {
                printf("Digite o nome que quer adicionar no fim: ");
                char nome[BUFLEN];
                fgets(nome, BUFLEN, stdin);
                nome[strcspn(nome, "\n")] = '\0';

                printf("Digite o RG: ");
                int rg;
                scanf("%d", &rg);
                while (getchar() != '\n');

                int cn_enc = 0, mn_enc = 0;
                clock_t inicio_enc = clock();
                addFinalEncadeada(&listaEnc, nome, rg, &cn_enc, &mn_enc);
                clock_t fim_enc = clock();
                double tempo_enc = (double)(fim_enc - inicio_enc) / CLOCKS_PER_SEC;

                int cn_seq = 0, mn_seq = 0;
                clock_t inicio_seq = clock();
                addFinalSequencial(&dados, &tam, nome, rg, &cn_seq, &mn_seq);
                clock_t fim_seq = clock();
                double tempo_seq = (double)(fim_seq - inicio_seq) / CLOCKS_PER_SEC;

                printf("\n==================================================\n");
                printf("       COMPARACAO DE INSERCAO NO FIM\n");
                printf("==================================================\n");
                printf("LISTA ENCADEADA:\n");
                printf(" - Tempo de Execucao : %.6f segundos\n", tempo_enc);
                printf(" - Comparacoes C(n)  : %d\n", cn_enc);
                printf(" - Movimentacoes M(n): %d\n", mn_enc);

                printf("\nLISTA SEQUENCIAL:\n");
                printf(" - Tempo de Execucao : %.6f segundos\n", tempo_seq);
                printf(" - Comparacoes C(n)  : %d\n", cn_seq);
                printf(" - Movimentacoes M(n): %d\n", mn_seq);
                printf("==================================================\n");
                break;
            }
            case 19: {
                printf("Digite o nome que quer adicionar: ");
                char nome[BUFLEN];
                fgets(nome, BUFLEN, stdin);
                nome[strcspn(nome, "\n")] = '\0';

                printf("Digite o RG: ");
                int rg;
                scanf("%d", &rg);

                int pos;
                printf("Digite a posicao N desejada: ");
                scanf("%d", &pos);
                while (getchar() != '\n');

                int cn_enc = 0, mn_enc = 0;
                clock_t inicio_enc = clock();
                addMeioEncadeada(&listaEnc, nome, rg, pos, &cn_enc, &mn_enc);
                clock_t fim_enc = clock();
                double tempo_enc = (double)(fim_enc - inicio_enc) / CLOCKS_PER_SEC;

                int cn_seq = 0, mn_seq = 0;
                clock_t inicio_seq = clock();
                addMeioSequencial(&dados, &tam, nome, rg, pos, &cn_seq, &mn_seq);
                clock_t fim_seq = clock();
                double tempo_seq = (double)(fim_seq - inicio_seq) / CLOCKS_PER_SEC;

                printf("\n==================================================\n");
                printf("     COMPARACAO DE INSERCAO NO MEIO (Posicao %d)\n", pos);
                printf("==================================================\n");
                printf("LISTA ENCADEADA:\n");
                printf(" - Tempo de Execucao : %.6f segundos\n", tempo_enc);
                printf(" - Comparacoes C(n)  : %d\n", cn_enc);
                printf(" - Movimentacoes M(n): %d\n", mn_enc);

                printf("\nLISTA SEQUENCIAL:\n");
                printf(" - Tempo de Execucao : %.6f segundos\n", tempo_seq);
                printf(" - Comparacoes C(n)  : %d\n", cn_seq);
                printf(" - Movimentacoes M(n): %d\n", mn_seq);
                printf("==================================================\n");
                break;
            }
            case 20: {
                if (listaEnc.tamanho == 0) {
                    printf("A lista encadeada esta vazia!\n");
                    break;
                }
                char nomeArq[50];
                printf("Digite o nome do arquivo para salvar a lista encadeada (ex: saidaEnc.txt): ");
                scanf("%49s", nomeArq);
                while (getchar() != '\n');

                salvarListaEncadeada(&listaEnc, nomeArq);
                break;
            }
            case 21: {
                if (tam == 0) {
                    printf("A lista sequencial esta vazia!\n");
                    break;
                }
                char nomeArq[50];
                printf("Digite o nome do arquivo para salvar a lista sequencial (ex: saidaSeq.txt): ");
                scanf("%49s", nomeArq);
                while (getchar() != '\n');

                salvarListaSequencial(dados, tam, nomeArq);
                break;
            }
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