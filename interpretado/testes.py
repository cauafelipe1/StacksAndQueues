from Node import Node
from pilhaArray import PilhaArray
from filaArray import FilaArray
from filaListaEncadeada import FilaListaEncadeada
from pilhaListaEncadeada import PilhaListaEncadeada
import time
import tracemalloc
import random
import sys


def testarPilhaArray(n):
    print(f"\n[teste com {n} elementos - Pilha com Array]")

    pilha = PilhaArray(n)

    # teste do push
    inicio = time.time()
    for _ in range(n):
        pilha.push(random.randint(0, 1000))
    fim = time.time()
    tempoInsercao = fim - inicio

    #t teste do pop
    inicio = time.time()
    while not pilha.isEmpty():
        pilha.pop()
    fim = time.time()
    tempoRemocao = fim - inicio

    # memória estimada
    memoria_mb = (sys.getsizeof(pilha.arr) + sys.getsizeof(pilha)) / (1024 * 1024)

    print(f"> tempo de insercao: {tempoInsercao:.6f} segundos")
    print(f"> tempo de remocao: {tempoRemocao:.6f} segundos")
    print(f"> memoria estimada: {memoria_mb:.2f} MB")


def testarPilhaEncadeada(n):
    print(f"\n[teste com {n} elementos - Pilha com Lista Encadeada]")

    pilha = PilhaListaEncadeada()

    #testando o push
    tracemalloc.start()
    inicio_insercao = time.time()
    for i in range(n):
        pilha.push(i)
    fim_insercao = time.time()
    tempo_insercao = fim_insercao - inicio_insercao

    #testando o pop
    inicio_remocao = time.time()
    for i in range(n):
        pilha.pop()
    fim_remocao = time.time()
    tempo_remocao = fim_remocao - inicio_remocao

    #memoria estimada
    memoria_usada = tracemalloc.get_traced_memory()[1] / (1024 * 1024)
    tracemalloc.stop()

    print(f"> tempo de insercao: {tempo_insercao:.6f} segundos")
    print(f"> tempo de remocao:  {tempo_remocao:.6f} segundos")
    print(f"> memoria estimada:  {memoria_usada:.2f}MB")

def testarFilaArray(n):
    print(f"\n\n[teste com {n} elementos - Fila com Array estatico]")

    fila = FilaArray(capacity=n + 1) 

    tracemalloc.start()
    inicio_insercao = time.time()
    #testando o enqueue
    for _ in range(n):
        fila.enqueue(random.randint(0, 1000))

    fim_insercao = time.time()
    tempo_insercao = fim_insercao - inicio_insercao

    
    inicio_remocao = time.time()
    #testando o dequeue
    while not fila.isEmpty():
        fila.dequeue()
    fim_remocao = time.time()
    tempo_remocao = fim_remocao - inicio_remocao

    memoria_usada, _ = tracemalloc.get_traced_memory()
    tracemalloc.stop()

    #resultados
    print(f"> tempo de insercao: {tempo_insercao:.6f} segundos")
    print(f"> tempo de remocao: {tempo_remocao:.6f} segundos")
    print(f"> memoria estimada: {memoria_usada / (1024 * 1024):.2f} MB")


def testarFilaEncadeada(n):
    print(f"\n[teste com {n} elementos - Fila com Lista Encadeada]")

    fila = FilaListaEncadeada()

    #testando o enqueue
    inicio_insercao = time.time()
    for _ in range(n):
        fila.enqueue(random.randint(0, 1000))
    fim_insercao = time.time()
    tempo_insercao = fim_insercao - inicio_insercao

    #testando o dequeue
    inicio_remocao = time.time()
    while not fila.isEmpty():
        fila.dequeue()
    fim_remocao = time.time()
    tempo_remocao = fim_remocao - inicio_remocao

    # estimativa de memoria ajustada pois o tracemalloc nao estava pegando a memoria usada
    memoria_bytes = n * 64 + 64
    memoria_mb = memoria_bytes / (1024 * 1024)

    #resultados
    print(f"> tempo de insercao: {tempo_insercao:.6f} segundos")
    print(f"> tempo de remocao: {tempo_remocao:.6f} segundos")
    print(f"> memoria estimada: {memoria_mb:.2f} MB")
