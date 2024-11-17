#include "search.h"

int pesquisa_sequencial(int vet[], int length, int chave, int *compCounter) {
    for (int i = 1; i < length; i++) {
        (*compCounter) += 2; // Cada iteracao exige comparar o elemento com a chave e se nao ultrapassamos o length do vetor
        if (vet[i] == chave) {
            return i; // Retorna o indice onde a chave foi encontrada
        }
    }
    return -1; // Retorna -1 se a chave no for encontrada
}

int pesquisa_sequencial_sentinela(int vet[], int length, int chave, int *compCounter) {
    // Coloca a chave na posicao 0 como sentinela
    vet[0] = chave;

    int i = length - 1; // Comeca da ultima pos

    // Percorre de tras para frente ate encontrar a chave
    while (vet[i] != chave) {
        i--;
        (*compCounter)++;
    }

    // Verifica se o elemento foi encontrado dentro do vetor (nao a sentinela)
    (*compCounter)++;
    if (i == 0) {
        return -1; // Nao encontrado
    }
    return i; // Retorna o indice encontrado
}

int pesquisa_binaria(int vet[], int length, int chave, int *compCounter) {
    int esquerda = 0;
    int direita = length - 1;

    while (esquerda <= direita) {
        int meio = esquerda + (direita - esquerda) / 2;
        (*compCounter)++;
        // Verifica se o elemento esta no meio
        if (vet[meio] == chave) {
            return meio;
        }

        // Se for maior, ignora a metade esquerda
        if (vet[meio] < chave) {
            esquerda = meio + 1;
        }
        // Se for menor, ignora a metade direita
        else {
            direita = meio - 1;
        }
    }

    // Retorna -1 se o elemento nao for encontrado
    return -1;
}