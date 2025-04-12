class PilhaArray:
    def __init__(self, capacity):  #construtor
        self.capacity = capacity
        self.arr = [None] * capacity
        self.header = -1
    
    def isEmpty(self):  
        return self.header == -1  #retorna true caso o header == 1, i.e., caso nenhum item esteja empilhado
    
    def isFull(self):
        return (self.header == self.capacity - 1)  #retorna true caso o header esteja prestes a estourar a capacidade do array
    
    def push(self, valor):  
        if self.isFull():
            print("erro! pilha cheia...")
            return
        self.header += 1
        self.arr[self.header] = valor  #define o proximo item da pilha como o valor inserido

    def pop(self):
        if self.isEmpty():
            print("erro! nenhum item na pilha..")
            return
        valor = self.arr[self.header]  #aloca o valor do topo da pilha em uma variavel local
        self.header -= 1  #diminui o header de maneira que ele "aponte" para o valor anterior da fila, que agora estara no topo
        return valor
    
    def len(self):
        return (self.header + 1)
