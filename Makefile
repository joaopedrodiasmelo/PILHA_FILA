all:
	gcc -c fila.c -o fila.o
	gcc -c pilha.c -o pilha.o
	gcc main.c pilha.o	fila.o -o main

run:
	./main

clear:
	rm ./main ./pilha.o ./fila.o