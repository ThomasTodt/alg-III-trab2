CC=gcc
CFLAGS=-ansi -Wall

busca: BST.o main.o
	$(CC) -o busca BST.o main.o