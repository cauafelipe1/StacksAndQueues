#include "../includes/libs.h"
#include "../includes/filaListaEncadeada.h"

FilaEncadeada* criarFilaEncadeada() {
    FilaEncadeada* newFila = (FilaEncadeada*) malloc(sizeof(FilaEncadeada));  //aloca espaço necessario da memoria pra fila
    newFila->inicio = NULL;  //seta os ponteiros do inicio e fim como nulos
    newFila->fim = NULL;  
    return newFila;  //retorna a nova fila
}

bool isEmptyFilaEncadeada(FilaEncadeada* fila) {
    return(fila->fim == NULL);
}

void enqueueFilaEncadeada(FilaEncadeada* fila, int valor) {
    No* newNo = (No*) malloc(sizeof(No));  //aloca memoria para o novo node e prepara ele para inserir na fila
    newNo->dado = valor;
    newNo->proximo = NULL;

    if (isEmptyFilaEncadeada(fila)) {  //caso nao tenha nenhum node no final da fila, ela esta vazia 
        fila->inicio = newNo; //logo o novo node é o inicial e o final da fila
        fila->fim = newNo;

    } else {  //caso onde a fila contem outros itens ja
        fila->fim->proximo = newNo;  //o ultimo elemento aponto para o novo node  
        fila->fim = newNo;  //o final da fila se atualiza
    }
    
}

int dequeueFilaEncadeada(FilaEncadeada* fila) {
    if (isEmptyFilaEncadeada(fila)){
        printf("erro! a fila esta vazia..");  //verifica se a pilha ta vazia
        return -1;
    }
    
    No* noRemovido = fila->inicio;  //aloca o node que sera removido em uma variavel local
    int valorRemovido = noRemovido->dado; // aloca o valor do node removido em uma variavel local

    fila->inicio = noRemovido->proximo; //atualiza o inicio da fila

    if (fila->inicio == NULL)    {  //se a fila ficou vazia, entao o seus valores de incio e fim devem ficar nulos 
        fila->fim = NULL;
    }

    free(noRemovido);  //libera o espaco alocado pelo node
    return valorRemovido;  //retorna o valor do node removido
    
}

int lenFilaEncadeada(FilaEncadeada* fila) {
    int i =  0;
    No* nodeLocal = fila->inicio; //aolca o node no inicio da fila em uma variavel local

    while (nodeLocal != NULL) {  //percorre a fila ate encontrar o elemento nulo, aumentando o contador em cada ocorrencia
        i++;
        nodeLocal = nodeLocal->proximo;
    }
    return i;  //retorna o contador indicando o numero de itens na fila
    
}