from Node import Node

class PilhaListaEncadeada:
    def __init__(self):  #construtor simples
        self.topo = None

    def isEmpty(self):
        return (self.topo == None)  #retorna true caso o topo seja nulo
    
    def push(self, valor):      #funcao responsavel por inserir itens no topo da pilha
        newNode = Node(valor)
        newNode.next = self.topo
        self.topo = newNode

    def pop(self):      #funcao responsavel por desempilhar
        if self.isEmpty():
            print("erro! pilha vazia")
            return None
        valor = self.topo
        self.topo = self.topo.next
        return self.topo    #retorna o valor que estava no topo da pilha
    
    def len(self):      #percorre a pilha ate encontrar um valor nulo - O(n)
        i = 0
        nodeLocal = self.topo
        while nodeLocal is not None:
            nodeLocal = nodeLocal.next
            i += 1
        return i       #retorna quantos itens tem na pilha
 