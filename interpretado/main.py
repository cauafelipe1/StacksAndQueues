from testes import *



if __name__ == "__main__":
    tamanhos = [1000, 10000, 100000, 1000000, 1500000]

    for n in tamanhos:
        print("\n" + "="*55)
        print(f"--- teste com {n} elementos ---")
        print("="*55)

        testarPilhaArray(n)
        testarFilaArray(n)
        testarPilhaEncadeada(n)
        testarFilaEncadeada(n)