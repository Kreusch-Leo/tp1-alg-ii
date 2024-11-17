#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <unistd.h>

#include "sort.h"
#include "search.h"
#include "analise.h"

#define TAM 1025 // 1024 + 1 (sentinela)
#define MAX 2048 // Valor maximo para os inteiros dos vetores
#define MIN 0 // Valor minimo para os inteiros
#define ANALISES 1000 // Numero de analises que serao feitas

void spacing() { // Espacamento simples
    printf("\n\n");
}

int get_int(int lim) { // Pede ao usuario um valor e verifica a valitade ate um certo limite
    int num;
    int resultado;

    while (1) {
        printf("Digite sua opcao: ");
        resultado = scanf("%d", &num); 

        if (resultado == 1 && num <= lim && num >= 0) { // Verifica a validade do resultado, se esta no limite e se nao eh negativo
            return num;  

        } else {
            while (getchar() != '\n'); // Limpa o buffer e descarta o valor invalido
            printf("\033[1;31mValor invalido. Tente de novo.\033[0m\n");
            printf("\n");
        }
    }
}

int request_op() { // Interface inicial para o usuário
    int op;

    spacing();
    printf("Digite a função que deseja executar: \n");
    printf("1 - Cria novo Vetor\n");
    printf("2 - Ordena Vetor (Bubble, Shell, Quick)\n");
    printf("3 - Busca elemento (Sequencial e Binaria)\n");
    printf("4 - Executa analise geral\n");
    printf("5 - Encerra a operacao\n");
    op = get_int(5);

    return op;
}

int aleat() { // Sorteia um numero aleatorio entre min e max
  return rand() % (MAX - MIN + 1) + MIN;
}

int *cria_vetor() { // Aloca um vetor e preenche com numeros aleatorios de MIN a MAX (sem repetir valores)
    int *vet;
    
    vet = malloc(TAM * sizeof(int));
    
    if (!vet)
        return NULL;

    vet[0] = 0; // Reservado para o sentinela

    int *block = malloc((MAX + 1) * sizeof(int));
    if (!block) {
        free(vet);  
        return NULL;
    }
    for (int i = 0; i <= MAX; i++) {
        block[i] = 0;
    }
    for (int i = 1; i <= 1024; i++) {
        int num;
        do {
            num = aleat();  
        } while (block[num] != 0);
        
        vet[i] = num;  
        block[num] = 1;  
    }
    free(block);  
    return vet;
}

void imprime_vetor_red(int vet[]) { // Imprime os 5 primeiros e 5 ultimos elementos de um vetor
    int i;

    printf("[ %d", vet[1]);

    for (i = 2; i <= 5; i++)
        printf(", %d", vet[i]);

    printf(", ... ");

    for (i = 1019; i <= 1024; i++)
        printf(", %d", vet[i]);
    printf(" ]\n\33[0m");
}

int main() {
    int operation, chave, localizacao, compBusca;
    struct info_t *singleData = NULL;

    spacing();
    printf("Olá. Que tipo de análise faremos?\n");
    printf("\n0 - Seguir um padrão com a semente 0\n1 - Vetores aleatórios (baseados no horário do sistema)\n");

    operation = get_int(1);

    switch (operation) { // define a formacao dos inteiros para o vetor
        case 0:
            srand(0);
            break;
        
        case 1:
            srand(time(NULL)); 
            break;

        default:
            return -1;
    }

    do {
        operation = request_op();

        switch (operation) {
            case 1: // Cria vetor aleatorio
                singleData = malloc(sizeof(struct info_t));
                if (!singleData)
                    return -1;

                singleData->vetor = cria_vetor();
                if (!(singleData->vetor)) 
                    return -1;

                spacing();
                printf("\033[32mO vetor gerado na forma reduzida é: ");
                imprime_vetor_red(singleData->vetor);

                break;

            case 2: // Faz a analise basica para um unico vetor
                if (!singleData)
                    singleData = malloc(sizeof(struct info_t));
                if (!singleData)
                    return -1;

                if (!(singleData->vetor)) 
                    singleData->vetor = cria_vetor();
                if (!(singleData->vetor)) 
                    return -1;

                printf("\033[32mO vetor desordenado na forma reduzida é: ");
                imprime_vetor_red(singleData->vetor);
                spacing();

                get_data(singleData);

                printf("\033[34mO vetor ordenado na forma reduzida é: ");
                imprime_vetor_red(singleData->vetorOrd);
                spacing();

                printf("\033[34mOs resultados do BubbleSort foram:\n");
                printf("\033[33mComparacoes entre elementos: %d\n", singleData->bubble->comparacoes);
                printf("Acessos ao vetor para trocas: %d\n", singleData->bubble->acessos);
                spacing();

                printf("\033[34m Os resultados do ShellSort (espacamento 16) foram:\n");
                printf("\033[33mComparacoes entre elementos: %d\n", singleData->shell_1->comparacoes);
                printf("Acessos ao vetor para trocas: %d\n", singleData->shell_1->acessos);
                spacing();

                printf("\033[34m Os resultados do ShellSort (espacamento 32) foram:\n");
                printf("\033[33mComparacoes entre elementos: %d\n", singleData->shell_2->comparacoes);
                printf("Acessos ao vetor para trocas: %d\n", singleData->shell_2->acessos);
                spacing();

                printf("\033[34m Os resultados do QuickSort (pivo na primeira posicao) foram:\n");
                printf("\033[33mComparacoes entre elementos: %d\n", singleData->quick_1->comparacoes);
                printf("Acessos ao vetor para trocas: %d\n", singleData->quick_1->acessos);
                spacing();

                printf("\033[34m Os resultados do QuickSort (pivo na proximo do meio) foram:\n");
                printf("\033[33mComparacoes entre elementos: %d\n", singleData->quick_2->comparacoes);
                printf("Acessos ao vetor para trocas: %d\n\033[0m", singleData->quick_2->acessos);
                spacing();

                break;
            case 3: // Procura um inteiro dado pelo usuario no vetor com diferentes metodos
                if (!singleData)
                    singleData = malloc(sizeof(struct info_t));
                if (!singleData)
                    return -1;

                if (!(singleData->vetor)) 
                    singleData->vetor = cria_vetor();
                if (!(singleData->vetor)) 
                    return -1;

                get_data(singleData);
                
                spacing();
                printf("Escolha um valor que deseja encontrar\n");
                
                chave = get_int(2028);
                compBusca = 0;
                
                localizacao = pesquisa_sequencial(singleData->vetor, TAM, chave, &compBusca);
                if (localizacao < 0) {
                    printf("\033[31mELEMENTO NAO ESTA NO VETOR GERADO\033[0m");
                } else {
                    printf("\033[36mA pesquisa sequencial comum precisou de %d comparações para encontrar na posicao %d\n", compBusca, localizacao);
                    compBusca = 0;
                    localizacao = pesquisa_sequencial_sentinela(singleData->vetor, TAM, chave, &compBusca);
                    printf("A pesquisa sequencial com sentinela precisou de %d comparações para encontrar na posicao %d\n", compBusca, localizacao);
                    compBusca = 0;
                    localizacao = pesquisa_binaria(singleData->vetorOrd, TAM, chave, &compBusca);
                    printf("A pesquisa binaria precisou de %d comparações para encontrar na posicao %d\033[0m\n", compBusca, localizacao);
                    spacing();
                }
                break;
            case 4: // Faz a analise com ANALISES vetores
                int acessos[ANALISES], comparacoes[ANALISES];
                struct info_t *data[ANALISES];
                
                spacing();

                for (int i = 0; i < ANALISES; i++) {
                    printf("Preenchimento bem sucedido para o elemento %d\n", i);
                    data[i] = malloc(sizeof(struct info_t));
                    data[i]->vetor = cria_vetor();
                    get_data(data[i]);
                }
                // Bubble Sort
                spacing();
                for (int i = 0; i < ANALISES; i++) {
                    acessos[i] = data[i]->bubble->acessos;
                    comparacoes[i] = data[i]->bubble->comparacoes;
                }

                printf("Bubble Sort:\n");
                printf("Acessos:\n");
                printf("Média = %li\n", media(acessos, ANALISES));
                printf("Desvio padrao = %.2f\n\n", desvio_padrao(acessos, ANALISES));
                printf("Comparacoes:\n");
                printf("Média = %li\n", media(comparacoes, ANALISES));
                printf("Desvio padrao = %.2f\n", desvio_padrao(comparacoes, ANALISES));
                
                // Shell Sort (espacamento 16)
                spacing();
                for (int i = 0; i < ANALISES; i++) {
                    acessos[i] = data[i]->shell_1->acessos;
                    comparacoes[i] = data[i]->shell_1->comparacoes;
                }

                printf("Shell Sort (espacamento 16):\n");
                printf("Acessos:\n");
                printf("Média = %li\n", media(acessos, ANALISES));
                printf("Desvio padrao = %.2f\n\n", desvio_padrao(acessos, ANALISES));
                printf("Comparacoes:\n");
                printf("Média = %li\n", media(comparacoes, ANALISES));
                printf("Desvio padrao = %.2f\n", desvio_padrao(comparacoes, ANALISES));

                // Shell Sort (espacamento 32)
                spacing();
                for (int i = 0; i < ANALISES; i++) {
                    acessos[i] = data[i]->shell_2->acessos;
                    comparacoes[i] = data[i]->shell_2->comparacoes;
                }

                printf("Shell Sort (espacamento 32):\n");
                printf("Acessos:\n");
                printf("Média = %li\n", media(acessos, ANALISES));
                printf("Desvio padrao = %.2f\n\n", desvio_padrao(acessos, ANALISES));
                printf("Comparacoes:\n");
                printf("Média = %li\n", media(comparacoes, ANALISES));
                printf("Desvio padrao = %.2f\n", desvio_padrao(comparacoes, ANALISES));

                // Quick sort (pivo na primeira posicao)
                spacing();
                for (int i = 0; i < ANALISES; i++) {
                    acessos[i] = data[i]->quick_1->acessos;
                    comparacoes[i] = data[i]->quick_1->comparacoes;
                }

                printf("Quick sort (pivo na primeira posicao):\n");
                printf("Acessos:\n");
                printf("Média = %li\n", media(acessos, ANALISES));
                printf("Desvio padrao = %.2f\n\n", desvio_padrao(acessos, ANALISES));
                printf("Comparacoes:\n");
                printf("Média = %li\n", media(comparacoes, ANALISES));
                printf("Desvio padrao = %.2f\n", desvio_padrao(comparacoes, ANALISES));
                
                // Quick sort (pivo proximo do meio)
                spacing();
                for (int i = 0; i < ANALISES; i++) {
                    acessos[i] = data[i]->quick_2->acessos;
                    comparacoes[i] = data[i]->quick_2->comparacoes;
                }

                printf("Quick sort (pivo proximo do meio):\n");
                printf("Acessos:\n");
                printf("Média = %li\n", media(acessos, ANALISES));
                printf("Desvio padrao = %.2f\n\n", desvio_padrao(acessos, ANALISES));
                printf("Comparacoes:\n");
                printf("Média = %li\n", media(comparacoes, ANALISES));
                printf("Desvio padrao = %.2f\n", desvio_padrao(comparacoes, ANALISES));

                spacing();
                chave = aleat();
                int presente;

                // Pesquisa sequencial normal
                for (int i = 0; i < ANALISES; i++) {
                    presente = pesquisa_sequencial(data[i]->vetor, TAM, chave, &compBusca);
                    
                    if (presente < 0) {
                        comparacoes[i] = -1;
                        
                    } else {
                        comparacoes[i] = compBusca;
                    }
                    compBusca = 0;
                }
                printf("Pesquisa sequencial normal\n");
                printf("Comparacoes:\n");
                printf("Média = %li\n", media(comparacoes, ANALISES));
                printf("Desvio padrao = %.2f\n", desvio_padrao(comparacoes, ANALISES));

                spacing();

                // Pesquisa sequencial com sentinela
                for (int i = 0; i < ANALISES; i++) {
                    presente = pesquisa_sequencial_sentinela(data[i]->vetor, TAM, chave, &compBusca);
                    
                    if (presente < 0) {
                        comparacoes[i] = -1;
                        
                    } else {
                        comparacoes[i] = compBusca;
                    }
                    compBusca = 0;
                }
                printf("Pesquisa sequencial com sentinela\n");
                printf("Comparacoes:\n");
                printf("Média = %li\n", media(comparacoes, ANALISES));
                printf("Desvio padrao = %.2f\n", desvio_padrao(comparacoes, ANALISES));

                spacing();
                // Pesquisa Binaria
                for (int i = 0; i < ANALISES; i++) {
                    presente = pesquisa_binaria(data[i]->vetorOrd, TAM, chave, &compBusca);
                    
                    if (presente < 0) {
                        comparacoes[i] = -1;
                        
                    } else {
                        comparacoes[i] = compBusca;
                    }
                    compBusca = 0;
                }
                printf("Pesquisa Binaria\n");
                printf("Comparacoes:\n");
                printf("Média = %li\n", media(comparacoes, ANALISES));
                printf("Desvio padrao = %.2f\n", desvio_padrao(comparacoes, ANALISES));

                for (int i = 0; i < ANALISES; i++) { 
                    destroi(data[i]);
                }
                break;      
                     
            default:
                break;
            }
        } while (operation != 5); // finaliza o programa
    if (singleData)
        destroi(singleData);
    printf("\n\n\033[33m!!!!!\nObrigado pela atencao :)\n!!!!!\033[0m\n\n");
    
    return 0;
}