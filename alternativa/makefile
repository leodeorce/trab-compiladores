# Makefile - Ubuntu 20.04.2 - bison
SHELL := /bin/bash

ENTRADA = teste

all: comp-bison comp-flex comp-gcc
	@echo "Done."

comp-bison: parser.y
	bison -Wall -v -o parser.c  parser.y

comp-flex: scanner.l
	flex scanner.l

comp-gcc: scanner.c parser.c list.c types.c tupla.c ast.c
	gcc -Wall scanner.c parser.c list.c types.c tupla.c ast.c -ly -o ast

run-ts:
	ts-node $(ENTRADA).ts

run:
	./ast < $(ENTRADA).ts

dot:
	./ast < $(ENTRADA).ts 2> $(ENTRADA).dot
	dot -Tpdf $(ENTRADA).dot -o $(ENTRADA).pdf

clean:
	rm -f scanner.c parser.c parser.h parser.output ast *.dot *.pdf
