from Node import Node

class FilaListaEncadeada:
    def __init__(self):
        self.front =  None      #front = inicio da fila
        self.rear = None        #rear = final da fila
    def isEmpty(self):
        return (self.rear == None)  #funcao que verifica se a fila esta vazia

    def enqueue(self, valor):
        newNode = Node(valor)  #cria um novo node que sera adicionado na fila
        if self.isEmpty():
            self.rear = self.front = newNode  #define o novo node como o front e o rear, ja que ele sera o primeiro da fila
        else:
            self.rear.next = newNode  #apenas define o node como o novo valor da fila
            self.rear = newNode
    
    def dequeue(self):
        if self.isEmpty():
            print("erro! lista vazia..")
            return None
        valor = self.front.dado  #aloca o dado do ultimo node da fila
        self.front = self.front.next  #define o valor 
        if self.front is None:
            self.rear = None
        return valor
    
    def len(self):
        nodeLocal = self.front
        i = 0

        while nodeLocal is not None:    #percorre a fila - O(n)
            nodeLocal = nodeLocal.next
            i += 1
        return i 
