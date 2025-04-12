#ifndef PILHALISTAENCADEADA_H
#define PILHALISTAENCADEADA_H
#include "node.h"
#include "libs.h"
typedef struct 
{
    No* topo; //ponteiro indicando o node do topo
} PilhaEncadeada;

PilhaEncadeada* createPilhaEncadeada();
void pushPilhaEncadeada(PilhaEncadeada* pilha, int valor);
int popPilhaEncadeada(PilhaEncadeada* pilha);
bool isEmptyPilhaEncadeada(PilhaEncadeada* pilha);
int lenPilhaEncadeada(PilhaEncadeada* pilha);
void freePilhaEncadeada(PilhaEncadeada* pilha);

#endif