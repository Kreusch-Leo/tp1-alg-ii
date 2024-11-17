#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "analise.h"
#include "sort.h"

// Cria uma copia do vetor
int *copia_vetor(int *vet) {
    if (!vet)
        return NULL;

    int *copy;
    copy = malloc(sizeof(int) * 1025);

    for (int i = 0; i < 1025; i++) 
        copy[i] = vet[i];
    
    return copy;
}

// Calcula a media dos valores
long media(int dados[], int tamanho) {
    long soma = 0;
    int tam = 0; // Contador de valores validos

    for (int i = 0; i < tamanho; i++) {
        if (dados[i] >= 0) { // Verifica se o valor e nao-negativo
            soma += dados[i];
            tam++; // Conta os valores validos
        }
    }

    if (tam > 0) {
        return (soma / tam); // Retorna a media se houver valores validos
    } else {
        return 0; // Retorna 0 se nao houver valores validos
    }
}

// Calcula a variancia dos valores
long variancia(int dados[], int tamanho) {
    long m = media(dados, tamanho);
    int tam = 0;
    long somaQuadrados = 0;

    for (int i = 0; i < tamanho; i++) {
        if (dados[i] >= 0) { // Verifica se o valor e nao-negativo
            somaQuadrados += pow(dados[i] - m, 2);
            tam++; // Conta os valores validos
        }
    }

    if (tam > 0) {
        return (somaQuadrados / tam); // Retorna a variancia se houver valores validos
    } else {
        return 0; // Retorna 0 se nao houver valores validos
    }
}

// Calcula o desvio padrao
float desvio_padrao(int dados[], int tamanho) {
    return sqrt(variancia(dados, tamanho)); // Calcula o desvio padrao com base na variancia
}


// Executa a ordenacao e coleta os dados
int get_data(struct info_t *info) {
    int len = 1025;
    
    if (!info || !info->vetor)
        return -1;

    int *auxVet; 
    int access, comp;
    struct data_sort_t *bubRes, *shellRes1, *shellRes2, *quickRes1, *quickRes2;
    
    // BubbleSort
    access = 0;
    comp = 0;
    auxVet = copia_vetor(info->vetor);
    bubRes = malloc(sizeof(struct data_sort_t));
    bubble_sort(auxVet, len, &access, &comp);
    bubRes->acessos = access;
    bubRes->comparacoes = comp;
    info->bubble = bubRes;

    // ShellSort com espacamento 16
    access = 0;
    comp = 0;
    auxVet = copia_vetor(info->vetor);
    shellRes1 = malloc(sizeof(struct data_sort_t));
    shell_sort(auxVet, len, 16, &access, &comp);
    shellRes1->acessos = access;
    shellRes1->comparacoes = comp;
    info->shell_1 = shellRes1;

    // ShellSort com espacamento 30
    access = 0;
    comp = 0;
    auxVet = copia_vetor(info->vetor);
    shellRes2 = malloc(sizeof(struct data_sort_t));
    shell_sort(auxVet, len, 30, &access, &comp);
    shellRes2->acessos = access;
    shellRes2->comparacoes = comp;
    info->shell_2 = shellRes2;

    // QuickSort com pivo no inicio
    access = 0;
    comp = 0;
    auxVet = copia_vetor(info->vetor);
    quickRes1 = malloc(sizeof(struct data_sort_t));
    quick_sort(auxVet, 1, len -1 , &access, &comp, 0); // len - 1 devido a implementacao do quicksort
    quickRes1->acessos = access;
    quickRes1->comparacoes = comp;
    info->quick_1 = quickRes1;

    // QuickSort com pivo no meio
    access = 0;
    comp = 0;
    auxVet = copia_vetor(info->vetor);
    quickRes2 = malloc(sizeof(struct data_sort_t));
    quick_sort(auxVet, 1, len - 1, &access, &comp, 1); // len - 1 devido a implementacao do quicksort
    quickRes2->acessos = access;
    quickRes2->comparacoes = comp;
    info->quick_2 = quickRes2;

    info->vetorOrd = auxVet;

    return 0;
}

// Libera a memoria alocada
void destroi(struct info_t *info) {
    if (!info)
        return;

    if (info->vetor)
        free(info->vetor);

    if (info->vetorOrd)
        free(info->vetorOrd);

    if (info->bubble)
        free(info->bubble);

    if (info->shell_1)
        free(info->shell_1);

    if (info->shell_2)
        free(info->shell_2);

    if (info->quick_1)
        free(info->quick_1);

    if (info->quick_2)
        free(info->quick_2);

    free(info);
}
