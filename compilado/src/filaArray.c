#include "../includes/libs.h"
#include "../includes/filaArray.h"


void criarFilaArray(FilaArray* fila) {  //instancia de criacao de uma fila vazia
    fila->front = 0;
    fila->rear = -1;
    fila->size = 0;
}

bool isEmptyFilaArray(FilaArray* fila) {
    return (fila->size == 0);  //verificacao simples se a fila esta vazia
}

bool isFullFilaArray(FilaArray* fila) {
    return (fila->size == MAX_SIZE); //verificacao simples se a fila esta cheia
}

void enqueueFilaArray(FilaArray* fila, int valor) {
    if (isFullFilaArray(fila)) {
        printf("erro! fila cheia..");  //verifica se a fila esta cheia
    }
    else{
    fila->rear = (fila->rear + 1) % MAX_SIZE; //o resto da divisao mantem a fila circular pois MAX_SIZE & MAX_SIZE = 0
    fila->arr[fila->rear] = valor;  //o valor se adiciona na fila
    
    fila->size++;  //o tamanho da fila aumenta
    }
}

int dequeueFilaArray(FilaArray* fila) {
    if (isEmptyFilaArray(fila)){
        printf("erro! fila vazia..");  //verifica se a fila esta vazia
        return -1;
    }

    int elementoRemovido = fila->arr[fila->front];  //aloca o elemento que sera removido na variavel local
    fila->front = (fila->front + 1) % MAX_SIZE;   //move a fila pra frente de maneira circular
    fila->size--;  //diminui o tamanho da fila
    
    return elementoRemovido;  //retorna o elemento removido
    
}

int lenFilaArray(FilaArray* fila) {
    return fila->size; //operacao simples de retornar tamanho
}

