/* 
 * Trabalho Practico 01
 * Arquivo de header para os algoritmos de analise estatistica
 * Feito em 20/11/2024 para a disciplina CI1056 - ALGORITMOS E ESTRUTURAS DE DADOS 2
 *
 */

#ifndef ANALISE_H
#define ANALISE_H

// Estrutura para armazenar os dados de acessos e comparacoes de um algoritmo de ordenacao
struct data_sort_t {
    int acessos;
    int comparacoes;
};

// Estrutura para armazenar os vetores e os resultados das ordenacoes
struct info_t {
    int *vetor;
    int *vetorOrd;
    struct data_sort_t *bubble;
    struct data_sort_t *shell_1;
    struct data_sort_t *shell_2;
    struct data_sort_t *quick_1;
    struct data_sort_t *quick_2;
};

// Funcoes para estatistica
long media(int dados[], int tamanho);
long variancia(int dados[], int tamanho);
float desvio_padrao(int dados[], int tamanho);

// Funcao para coletar dados sobre as ordenacoes e armazenar
int get_data(struct info_t *info);

// Funcao para liberar a memoria alocada para a estrutura info_t
void destroi(struct info_t *info);

#endif // ANALISE_H
