#ifndef ED1_DECLARATIONS_H
#define ED1_DECLARATIONS_H

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BUFLEN 50
#define MAX_NAME 50

typedef struct No {
    char name[MAX_NAME];
    int rg;
    struct No *prox;
}No;

typedef struct {
    No* inicio;
    No* fim;
    int tamanho;
} ListaEncadeada;

typedef struct {
    char name[MAX_NAME];
    int rg;
}Dados;

void readFile(char fileName[], ListaEncadeada* lista);
void imprimir(ListaEncadeada* lista);
void readFileSequencial(char nomeArquivo[],Dados** dados, int* tam);
void imprimirSequencial(Dados* dados, int tam);
void pesquisaEncadeada(ListaEncadeada* lista, int rg_desejado, int* cn, int* mn);
void pesquisaSimples(Dados* dados, int rg_desejado, int tam, int* cn, int* mn);
void showMenuPrimary();
void showMenuFile();

void addFinalEncadeada(ListaEncadeada* lista, char new_name[], int new_rg, int* cn, int* mn);
void addFinalSequencial(Dados** dados, int* tam, char new_name[], int new_rg, int* cn, int* mn);
void addInicioEncadeada(ListaEncadeada* lista, char new_name[], int new_rg, int* cn, int* mn);
void addInicioSequencial(Dados** dados, int* tam, char new_name[], int new_rg, int* cn, int* mn);
void addMeioEncadeada(ListaEncadeada* lista, char new_name[], int new_rg, int pos, int* cn, int* mn);
void addMeioSequencial(Dados** dados, int* tam, char new_name[], int new_rg, int pos, int* cn, int* mn);
void removerPosicaoEncadeada(ListaEncadeada* lista, int pos, int* cn, int* mn);
void removerPosicaoSequencial(Dados** dados, int *tam, int pos, int* cn, int* mn);

void salvarListaEncadeada(ListaEncadeada* lista, char nomeArquivo[]);
void salvarListaSequencial(Dados* dados, int tam, char nomeArquivo[]);

#endif