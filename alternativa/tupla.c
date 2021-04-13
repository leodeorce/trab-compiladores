#include <stdio.h>
#include <stdlib.h>
#include "tupla.h"

struct tupla {
    char *name;
    int  line;
    AST  *node;
};

Tupla* new_tupla(char* name, int line, AST* node) {
    Tupla* tupla = (struct tupla*) malloc(sizeof(struct tupla));
    tupla->name = name;
    tupla->line = line;
    tupla->node = node;
    return tupla;
}

void tupla_add_child(Tupla* parent, Tupla* child) {
    add_child(parent->node, child->node);
}

void empty_tupla(Tupla* tupla) {
    tupla->node = NULL;
}

void change_name(Tupla* tupla, char* name) {
    tupla->name = name;
}

void change_line(Tupla* tupla, int line) {
    tupla->line = line;
}

void change_node(Tupla* tupla, AST* node) {
    tupla->node = node;
}

AST* getAST(Tupla* tupla) {
    return tupla->node;
}

char* tupla_get_name(Tupla* tupla) {
	return tupla->name;
}

int tupla_get_line(Tupla* tupla) {
	return tupla->line;
}