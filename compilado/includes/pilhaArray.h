#ifndef PILHAARRAY_H
#define PILHAARRAY_H
#include "libs.h"

//definicao da estrutura, contendo array e o header
typedef struct
{
    int arr[MAX_SIZE];
    int header;
} PilhaArray;

void pushPilhaArray(PilhaArray* pilha, int n);

int popPilhaArray(PilhaArray* pilha);

bool isEmptyPilhaArray(PilhaArray* pilha);

int lenPilhaArray(PilhaArray* pilha);
#endif