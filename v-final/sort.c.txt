#include <stdlib.h>
#include "sort.h"

void select_sort(int vetor[], int length, int *accessCounter, int *compCounter) {
    int i, j, min, aux;

    for (i = 1; i < length; i++) {
        min = i;
        for (j = i + 1; j < length; j++) {
            (*compCounter)++;
            if (vetor[j] < vetor[min]) min = j;
        }
        aux = vetor[min];
        vetor[min] = vetor[i];
        vetor[i] = aux;
        (*accessCounter) += 3;
    }
}

void bubble_sort(int vetor[], int length, int *accessCounter, int *compCounter) {
    int i, j, aux;

    for (i = 1; i < length; i++) {
        (*compCounter)++;
        for (j = length - 1; j >= i; j--) {
            (*compCounter)++;
            if (vetor[j] < vetor[j - 1]) {
                (*compCounter)++;
                aux = vetor[j];
                vetor[j] = vetor[j - 1];
                vetor[j - 1] = aux;
                (*accessCounter) += 3;
            }
        }
    }
}

void particao(int vet[], int esq, int dir, int *pos_pivo, int *accessCounter, int *compCounter, int esqPiv) {
    int i = esq;
    int j = dir;
    int pivo, aux;

    if (esqPiv) { // 0 seleciona o primeiro elemento
        pivo = vet[dir];
    } else { // seleciona o mais proximo do meio
        pivo = vet[(esq + dir) / 2];  // Pivo ajustado para o valor médio
    }

    while (i < j) {
        while (i < dir && vet[i] <= pivo) {
            i++;
            (*compCounter)++;
        }
        while (vet[j] > pivo) {
            j--;
            (*compCounter)++;
        }
        if (i < j) {
            aux = vet[i];
            vet[i] = vet[j];
            vet[j] = aux;
            (*accessCounter) += 3;
        }
    }
    vet[esq] = vet[j];
    vet[j] = pivo;
    (*pos_pivo) = j;
    (*accessCounter) += 2;
}

void quick_sort(int v[], int esq, int dir, int *accessCounter, int *compCounter, int esqPiv) {
    int pos_pivo;

    if (esq < dir) {
        (*compCounter)++;
        particao(v, esq, dir, &pos_pivo, accessCounter, compCounter, esqPiv);
        quick_sort(v, esq, pos_pivo - 1, accessCounter, compCounter, esqPiv);
        quick_sort(v, pos_pivo + 1, dir, accessCounter, compCounter, esqPiv);
    }
}

void shell_sort(int vetor[], int length, int espacamento, int *accessCounter, int *compCounter) {
    int i, j, aux;

    // Espacamento dado em sala
     
    do {
        espacamento = espacamento * 3 + 1;
    } while (espacamento < (length - 1) / 3);

    
    do {
        espacamento /= 3;
        for (i = espacamento; i < length; i++) {
            (*compCounter)++;
            aux = vetor[i];
            (*accessCounter)++;
            j = i;

            while (j >= espacamento && vetor[j - espacamento] > aux) {
                (*compCounter)++;
                vetor[j] = vetor[j - espacamento];
                (*accessCounter) ++;
                j -= espacamento;
            }
            
            vetor[j] = aux;
            (*accessCounter)++;
        }
    } while (espacamento > 1);
}
