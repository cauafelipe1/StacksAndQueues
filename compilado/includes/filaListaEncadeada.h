#ifndef FILALISTAENCADEADA_H
#define FILALISTAENCADEADA_H
#include "node.h"
#include "libs.h"

//OBS.: chamei os nos de node pra evitar o uso de caracteres fora da tabela ASCII

typedef struct {
    No* inicio; //ponteiro do primeiro elemento da fila
    No* fim;    //ponteiro do ultimo elemento da fila
} FilaEncadeada;

FilaEncadeada* criarFilaEncadeada();
bool isEmptyFilaEncadeada(FilaEncadeada* fila);
void enqueueFilaEncadeada(FilaEncadeada* fila, int valor);
int dequeueFilaEncadeada(FilaEncadeada* fila);
int lenFilaEncadeada(FilaEncadeada* fila);

#endif