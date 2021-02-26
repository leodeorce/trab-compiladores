# Makefile - Ubuntu 20.04.2 - flex
SHELL := /bin/bash

EXECUTABLE = scanner.out
FILE_RE = scanner.l
FILE_SCAN = scanner.c
ENTRADA = entrada.ts

all: compflex compc run

run: compc
	./$(EXECUTABLE) < $(ENTRADA)

compflex:
	flex $(FILE_RE)

compc: compflex
	gcc $(FILE_SCAN) -lfl -o $(EXECUTABLE)

rmproper:
	rm $(FILE_SCAN) $(EXECUTABLE)

