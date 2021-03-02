# Makefile - Ubuntu 20.04.2 - flex
SHELL := /bin/bash

SCANNER = scanner
EXECUTABLE = $(SCANNER).out
ENTRADA = entrada
FLAGS = -lfl -o

all: comp-flex comp-gcc run

comp-flex:
	flex $(SCANNER).l

comp-gcc: comp-flex
	gcc $(SCANNER).c $(FLAGS) $(EXECUTABLE)

run: comp-gcc
	./$(EXECUTABLE) < $(ENTRADA).ts

rm:
	rm $(SCANNER).c $(EXECUTABLE) $(ENTRADA).js

run-js:
	tsc $(ENTRADA).ts
	node $(ENTRADA).js

run-ts:
	ts-node $(ENTRADA).ts