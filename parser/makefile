# Makefile - Ubuntu 20.04.2 - bison
SHELL := /bin/bash

PARSER = parser
SCANNER = scanner
EXECUTABLE = cp1.out
ENTRADA = entrada
FLAGS_BISON = -Wall -o
FLAGS_GCC = -Wall -o

all: comp-bison comp-flex comp-gcc run

comp-bison:
	bison $(FLAGS_BISON) $(PARSER).c $(PARSER).y

comp-flex:
	flex $(SCANNER).l

comp-gcc:
	gcc $(FLAGS_GCC) $(EXECUTABLE) $(SCANNER).c $(PARSER).c -ly

run:
	./$(EXECUTABLE) < $(ENTRADA).ts

rm:
	rm $(PARSER).c $(PARSER).h $(SCANNER).c $(EXECUTABLE)
