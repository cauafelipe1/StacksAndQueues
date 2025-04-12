#include "../includes/libs.h"
#include "../includes/pilhaListaEncadeada.h"

PilhaEncadeada* createPilhaEncadeada() {
    PilhaEncadeada* newPilha = (PilhaEncadeada*) malloc(sizeof(PilhaEncadeada));
    if (newPilha == NULL) {
        printf("erro ao alocar memoria para pilha..\n");
        exit(1);
    }
    newPilha->topo = NULL;
    return newPilha;
}

void pushPilhaEncadeada(PilhaEncadeada* pilha, int valor) {
    if (pilha == NULL) {
        printf("erro!! pilha invalida..\n");
        return;
    }

    No* newNo = (No*) malloc(sizeof(No));   //criando novo node
    if (newNo == NULL) {
        printf("erro ao alocar memoria para novo node..\n");
        exit(1);
    }

    newNo->dado = valor;
    newNo->proximo = pilha->topo; //ligando o ponteiro do novo node ao proximo da pilha

    pilha->topo = newNo;    //definindo como node do topo
}

bool isEmptyPilhaEncadeada(PilhaEncadeada* pilha) {
    return (pilha == NULL || pilha->topo == NULL);
}

int popPilhaEncadeada(PilhaEncadeada* pilha) {
    if (isEmptyPilhaEncadeada(pilha)) {
        printf("erro! pilha vazia ou invalida..\n");
        return -1;
    }

    No* noRemovido = pilha->topo;
    int valorRemovido = noRemovido->dado; //armazena os dados do node removido

    pilha->topo = noRemovido->proximo; //redefine o topo da pilha com o node anterior
    free(noRemovido);  //libera a memoria alocada para o node

    return valorRemovido;  //retorna o valor removido
}

int lenPilhaEncadeada(PilhaEncadeada* pilha) {
    if (pilha == NULL) return 0;

    int i = 0;
    No* item = pilha->topo; //variavel local

    while (item != NULL) {  //loop percorrendo a pilha ate chegar no ultimo node (O(n))
        i++;
        item = item->proximo;
    }
    return i; //retornando contador representando o numero de itens na pilha
}

void freePilhaEncadeada(PilhaEncadeada* pilha) { 
    if (pilha == NULL) return;

    No* atual = pilha->topo;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->proximo;
        free(temp);
    }

    free(pilha);  //para liberar o espaço alocado pela pilha
}
