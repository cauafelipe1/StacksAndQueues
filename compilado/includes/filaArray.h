#ifndef FILAARRAY_H
#define FILAARRAY_H
#include "libs.h"

typedef struct {
    int arr[MAX_SIZE];
    int front, rear, size;
} FilaArray;

void criarFilaArray(FilaArray* fila);
bool isEmptyFilaArray(FilaArray* fila);
bool isFullFilaArray(FilaArray* fila);
void enqueueFilaArray(FilaArray* fila, int valor);
int dequeueFilaArray(FilaArray* fila);
int lenFilaArray(FilaArray* fila);
#endif