#include "../includes/libs.h"
#include "../includes/filaArray.h"
#include "../includes/pilhaArray.h"
#include "../includes/filaListaEncadeada.h"
#include "../includes/pilhaListaEncadeada.h"
#define MAX 1500000


void testarFilaArray(int n) {
    printf("\n[Fila com array estatico]\n");

    FilaArray fila;
    criarFilaArray(&fila);

    clock_t inicio, fim;
    double tempoInsercao, tempoRemocao;

    //testando o enqueue
    inicio = clock();
    for (int i = 0; i < n; i++) {
        enqueueFilaArray(&fila, rand() % 1000);
    }
    fim = clock();
    tempoInsercao = (double)(fim - inicio) / CLOCKS_PER_SEC;

    //testando o dequeue
    inicio = clock();
    while (!isEmptyFilaArray(&fila)) {
        dequeueFilaArray(&fila);
    }
    fim = clock();
    tempoRemocao = (double)(fim - inicio) / CLOCKS_PER_SEC;

    // Estimativa de memória
    size_t bytes = sizeof(int) * MAX_SIZE;
    double memoriaMB = bytes / (1024.0 * 1024.0);

    printf("> tempo de insercao: %.6f segundos\n", tempoInsercao);
    printf("> tempo de remocao: %.6f segundos\n", tempoRemocao);
    printf("> memoria estimada: %.2fMB\n", memoriaMB);
}

void testarPilhaArray(int quantidade) {
    printf("\n[Pilha com array estatico]\n");

    PilhaArray pilha;
    pilha.header = 0;

    clock_t inicio, fim;
    double tempoInsercao, tempoRemocao;

    //teste com o push
    inicio = clock();
    for (int i = 0; i < quantidade; i++) {
        pushPilhaArray(&pilha, rand() % 1000);
    }
    fim = clock();
    tempoInsercao = (double)(fim - inicio) / CLOCKS_PER_SEC;

    //teste com o pop
    inicio = clock();
    while (pilha.header > 0) {
        popPilhaArray(&pilha);
    }
    fim = clock();
    tempoRemocao = (double)(fim - inicio) / CLOCKS_PER_SEC;

    //memoria estimada
    double memoriaMB = (sizeof(PilhaArray)) / (1024.0 * 1024.0);

    printf("> Tempo de insercao: %.6f segundos\n", tempoInsercao);
    printf("> Tempo de remocao: %.6f segundos\n", tempoRemocao);
    printf("> memoria estimada: %.2fMB\n", memoriaMB);
}


void testarFilaEncadeada(int quantidade) {
    printf("\n[Fila com lista encadeada]\n");

    FilaEncadeada* fila = criarFilaEncadeada();

    clock_t inicio, fim;
    double tempoInsercao, tempoRemocao;

    //teste do enqueue
    inicio = clock();
    for (int i = 0; i < quantidade; i++) {
        enqueueFilaEncadeada(fila, rand() % 1000);
    }
    fim = clock();
    tempoInsercao = (double)(fim - inicio) / CLOCKS_PER_SEC;

    //teste do dequeue
    inicio = clock();
    while (!isEmptyFilaEncadeada(fila)) {
        dequeueFilaEncadeada(fila);
    }
    fim = clock();
    tempoRemocao = (double)(fim - inicio) / CLOCKS_PER_SEC;

    //memoria estimada: (tamanho de cada node * quantidade) + tamanho da estrutura
    double memoriaMB = ((sizeof(No) * quantidade) + sizeof(FilaEncadeada)) / (1024.0 * 1024.0);

    printf("> tempo de inserção: %.6f segundos\n", tempoInsercao);
    printf("> tempo de remoção: %.6f segundos\n", tempoRemocao);
    printf("> memoria estimada: %.2fMB\n", memoriaMB);

    free(fila); //libera a estrutura
}


void testarPilhaEncadeada(int qtdElementos) {
    printf("\n[Pilha com Lista Encadeada]\n");

    PilhaEncadeada* pilha = createPilhaEncadeada();

    //testanto push
    clock_t inicioInsercao = clock();
    for (int i = 0; i < qtdElementos; i++) {
        pushPilhaEncadeada(pilha, i);
    }
    clock_t fimInsercao = clock();
    double tempoInsercao = (double)(fimInsercao - inicioInsercao) / CLOCKS_PER_SEC;

    //testando o pop
    clock_t inicioRemocao = clock();
    for (int i = 0; i < qtdElementos; i++) {
        popPilhaEncadeada(pilha);
    }
    clock_t fimRemocao = clock();
    double tempoRemocao = (double)(fimRemocao - inicioRemocao) / CLOCKS_PER_SEC;

    // estimativa de memoria
    double memoriaBytes = sizeof(PilhaEncadeada) + qtdElementos * sizeof(No);
    double memoriaMB = memoriaBytes / (1024 * 1024);

    // resultados
    printf("> tempo de insercao: %.6f segundos\n", tempoInsercao);
    printf("> tempo de remocao: %.6f segundos\n", tempoRemocao);
    printf("> memoria estimada: %.2fMB\n", memoriaMB);

    // limpeza
    freePilhaEncadeada(pilha);
}