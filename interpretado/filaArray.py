class FilaArray:
    def __init__(self, capacity):  #construtr simples
        self.capacity = capacity
        self.arr = [None] * capacity
        self.front = 0
        self.rear = -1
        self.size = 0

    def isEmpty(self):
        return (self.size == 0)  #retorna true caso o tamanho da fila seja nulo
    
    def isFull(self):
        return (self.size == (self.capacity - 1))  #retorna true caso a fila tenha estourado a capacidade
    
    def enqueue(self, n):
        if self.isFull():
            print("erro! fila cheia..")
            return
        
        self.rear = (self.rear + 1) % self.capacity  #conserva as posicoes da fila de forma ciclica
        self.arr[self.rear] = n
        self.size += 1

    def dequeue(self):
        if self.isEmpty():
            print("erro! fila vazia..")
            return
        valor = self.arr[self.rear]
        self.rear = (self.rear + 1) % self.capacity
        self.size -= 1
        return valor  #retorna o valor retirado da fila
    
    def len(self):
        return self.size  #retorna o tamanho