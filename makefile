# Makefile - Ubuntu 20.04.2 - flex
SHELL := /bin/bash

ENTRADA = entrada

all: comp-flex comp-gcc
	@echo "Done."

comp-flex:
	flex scanner.l

comp-gcc: comp-flex
	gcc -Wall scanner.c -lfl -o scanner

run-ts:
	ts-node $(ENTRADA).ts

run:
	./scanner < $(ENTRADA).ts

clean:
	rm -f scanner.c scanner
