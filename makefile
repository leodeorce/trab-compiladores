# Makefile - Ubuntu 20.04.2 - bison
SHELL := /bin/bash

ENTRADA = teste

all: comp-bison comp-flex comp-gcc
	@echo "Done."

comp-bison: parser.y
	bison -Wall -v -o parser.c  parser.y

comp-flex: scanner.l
	flex scanner.l

comp-gcc: scanner.c parser.c list.c types.c tupla.c ast.c code.c
	gcc -Wall scanner.c parser.c list.c types.c tupla.c ast.c code.c -ly -o mips

run-ts:
	ts-node $(ENTRADA).ts

run-out:
	./mips < $(ENTRADA).ts > $(ENTRADA).out

run:
	./mips < $(ENTRADA).ts

clean:
	rm -f scanner.c parser.c parser.h parser.output *.out mips
