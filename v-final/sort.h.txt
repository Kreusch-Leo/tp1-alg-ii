/*
 * Trabalho Pratico 01
 * Arquivo de header para os algoritmos de ordenacao
 * Feito em 20/11/2024 para a disciplina CI1056 - ALGORITMOS E ESTRUTURAS DE DADOS 2
 *
*/
#ifndef ALG_SORT_H
#define ALG_SORT_H

// Função de ordenação por insert sort
void insert_sort(int vetor[], int *accessCounter, int *compCounter);

// Função de ordenação por selection sort
void select_sort(int vetor[], int length, int *accessCounter, int *compCounter);

// Função de ordenação por bubble sort
void bubble_sort(int vetor[], int length, int *accessCounter, int *compCounter);

// Função de particionamento para o algoritmo quick sort
void particao(int vet[], int esq, int dir, int *pos_pivo, int *accessCounter, int *compCounter, int esqPiv);

// Função de ordenação quick sort
void quick_sort(int v[], int esq, int dir, int *accessCounter, int *compCounter, int esqPiv);

// Função de ordenação shell sort com espaçamento definido
void shell_sort(int vetor[], int length, int espacamento, int *accessCounter, int *compCounter);

#endif // ALG_SORT_H
