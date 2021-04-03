# Makefile - Ubuntu 20.04.2 - bison
SHELL := /bin/bash

ENTRADA = in/c10

all: comp-bison comp-flex comp-gcc
	@echo "Done."

comp-bison:
	bison -Wall -v -o parser.c parser.y

comp-flex: comp-bison
	flex scanner.l

comp-gcc: comp-bison comp-flex
	gcc -Wall scanner.c parser.c list.c types.c -ly -o analise_sem

run-ts:
	ts-node $(ENTRADA).ts

run:
	./analise_sem < $(ENTRADA).ts

clean:
	rm -f scanner.c parser.c parser.h parser.output analise_sem
