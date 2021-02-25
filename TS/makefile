# Makefile - Ubuntu 20.04.2 - flex
SHELL := /bin/bash

EXECUTABLE = ezlang.out
FILE_RE = ezlang.l
FILE_SCAN = lex.yy.c
ENTRADA = entrada.ts

all: compflex compc run

run: compc
	./$(EXECUTABLE) < $(ENTRADA)

compflex:
	flex $(FILE_RE)

compc: compflex
	gcc $(FILE_SCAN) -o $(EXECUTABLE)

rmproper:
	rm $(FILE_SCAN) $(EXECUTABLE)

