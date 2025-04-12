SRC := ./src
INC := ./includes
BIN := ./bin

all: $(BIN) $(BIN)/output

$(BIN):
	if [ ! -d $(BIN) ]; then mkdir $(BIN); fi

$(BIN)/output: $(BIN)/main.o $(BIN)/filaArray.o $(BIN)/pilhaArray.o $(BIN)/filaListaEncadeada.o $(BIN)/pilhaListaEncadeada.o $(BIN)/testes.o
	gcc $(BIN)/main.o $(BIN)/filaArray.o $(BIN)/pilhaArray.o $(BIN)/filaListaEncadeada.o $(BIN)/pilhaListaEncadeada.o $(BIN)/testes.o

$(BIN)/main.o: main.c
	gcc -c main.c	-o $(BIN)/main.o 

$(BIN)/filaArray.o: $(SRC)/filaArray.c $(INC)/filaArray.h
	gcc -c $(SRC)/filaArray.c -o $(BIN)/filaArray.o

$(BIN)/pilhaArray.o: $(SRC)/pilhaArray.c $(INC)/pilhaArray.h
	gcc -c $(SRC)/pilhaArray.c -o $(BIN)/pilhaArray.o

$(BIN)/filaListaEncadeada.o: $(SRC)/filaListaEncadeada.c $(INC)/filaListaEncadeada.h
	gcc -c $(SRC)/filaListaEncadeada.c -o $(BIN)/filaListaEncadeada.o

$(BIN)/pilhaListaEncadeada.o: $(SRC)/pilhaListaEncadeada.c $(INC)/pilhaListaEncadeada.h
	gcc -c $(SRC)/pilhaListaEncadeada.c -o $(BIN)/pilhaListaEncadeada.o

$(BIN)/testes.o: $(SRC)/testes.c $(INC)/testes.h
	gcc -c $(SRC)/testes.c -o $(BIN)/testes.o


clean:
	@if [ -d $(BIN) ]; then rm $(BIN)/*; fi
	@if [ -d $(BIN) ]; then rmdir $(BIN); fi