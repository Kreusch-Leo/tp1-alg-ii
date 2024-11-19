/*
 * Trabalho Pratico 01
 * Arquivo de header para os algoritmos de pesquisa
 * Feito em 20/11/2024 para a disciplina CI1056 - ALGORITMOS E ESTRUTURAS DE DADOS 2
 *
 */

#ifndef PESQUISA_H
#define PESQUISA_H

// Funcao de pesquisa sequencial
int pesquisa_sequencial(int vet[], int length, int chave, int *compCounter);

// Funcao de pesquisa sequencial com sentinela
int pesquisa_sequencial_sentinela(int vet[], int length, int chave, int *compCounter);

// Funcao de pesquisa binaria
int pesquisa_binaria(int vet[], int length, int chave, int *compCounter);

#endif // PESQUISA_H
