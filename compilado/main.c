#include "includes/pilhaArray.h"
#include "includes/filaArray.h"
#include "includes/pilhaListaEncadeada.h"
#include "includes/filaListaEncadeada.h"
#include "includes/testes.h"
int main() {
    srand(time(NULL));  // gerador de numeros

    int tamanhos[] = {1000, 10000, 100000, 1000000, 1500000};
    int total = sizeof(tamanhos) / sizeof(tamanhos[0]);

    for (int i = 0; i < total; i++) {  //iterador para cada teste
        printf("\n=====================================================");
        printf("\n--- teste com %d elementos ---", tamanhos[i]);
        printf("\n====================================================\n");

        // teste da fila com array
        testarFilaArray(tamanhos[i]);

        // teste da pilha com arry
        testarPilhaArray(tamanhos[i]);

        //teste da fila encadeada
        testarFilaEncadeada(tamanhos[i]);
        
        //teste da pilha encadeada
        testarPilhaEncadeada(tamanhos[i]);
    }


    return 0;
}
