#include "../includes/libs.h"
#include "../includes/pilhaArray.h"

//push
void pushPilhaArray(PilhaArray* pilha, int n) {
    if(pilha->header < MAX_SIZE) { 
       pilha->arr[pilha->header++] = n; //adiciona n no topo da pilha caso ela nao esteja cheia
    }
    else {
        printf("pilha cheia! %d nao foi inserido..", n);
    }
}

//pop
int popPilhaArray(PilhaArray* pilha) {
    if (pilha->header > 0) {
        pilha->header--;
        return pilha->arr[pilha->header]; //retorna o valor atual no topo da pilha
    } else {
        return -1; //retorna -1 indicando que a pilha esta vazia
    }
}

//isEmpty
bool isEmptyPilhaArray(PilhaArray* pilha) {
    return (pilha->header == -1); //verifica de o header esta com o valor -1, indicando que a pilha esta vazia
    }

//len
int lenPilhaArray(PilhaArray* pilha) {
    return (pilha->header + 1); //retorna o tamanho da pilha
}

