/*
 * Trabalho Pratico 01
 * Arquivo de header para os algoritmos de ordenacao
 * Feito em 20/11/2024 para a disciplina CI1056 - ALGORITMOS E ESTRUTURAS DE DADOS 2
 *
*/
#ifndef ALG_SORT_H
#define ALG_SORT_H

// Funcao de ordenacao por insert sort
void insert_sort(int vetor[], int *accessCounter, int *compCounter);

// Funcao de ordenacao por selection sort
void select_sort(int vetor[], int length, int *accessCounter, int *compCounter);

// Funcao de ordenacao por bubble sort
void bubble_sort(int vetor[], int length, int *accessCounter, int *compCounter);

// Funcao para encontrar a mediana de tres numeros
int mediano_de_tres(int vet[], int esq, int dir, int *accessCounter);

// Funcao de particionamento para o algoritmo quick sort
void particao(int vet[], int esq, int dir, int *pos_pivo, int *accessCounter, int *compCounter, int esqPiv);

// Funcao de ordenacao quick sort
void quick_sort(int v[], int esq, int dir, int *accessCounter, int *compCounter, int esqPiv);

// Funcao de ordenacao shell sort com espaco definido
void shell_sort(int vetor[], int length, int espacamento, int *accessCounter, int *compCounter);

#endif // ALG_SORT_H
