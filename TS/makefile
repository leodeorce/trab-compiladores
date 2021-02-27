# Makefile - Ubuntu 20.04.2 - flex
SHELL := /bin/bash

EXECUTABLE = scanner.out
FILE_RE = scanner.l
FILE_SCAN = scanner.c
ENTRADA_TS = entrada.ts
ENTRADA_JS = entrada.js

all: compflex compc run

run: compc
	./$(EXECUTABLE) < $(ENTRADA_TS)

compflex:
	flex $(FILE_RE)

compc: compflex
	gcc $(FILE_SCAN) -lfl -o $(EXECUTABLE)

rmproper:
	rm $(FILE_SCAN) $(EXECUTABLE)

run-js:
	tsc $(ENTRADA_TS)
	node $(ENTRADA_JS)

run-ts:
	ts-node $(ENTRADA_TS)