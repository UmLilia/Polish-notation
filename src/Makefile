CC=gcc
CFLAGS=-Wextra -Werror -Wall

all:
	$(CC) $(CFLAGS) graph.c graphic.c calculation.c parsing.c structures.c -o ../build/graph -lm

test: all
	clear
	../build/graph

clean:
	rm ../build/graph
