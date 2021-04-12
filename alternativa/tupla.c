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
	printf("change_name1\n");
    tupla->name = name;
	printf("change_name2\n");
}

void change_line(Tupla* tupla, int line) {
	printf("change_line1\n");
    tupla->line = line;
	printf("change_line2\n");
}

void change_node(Tupla* tupla, AST* node) {
    printf("check1\n");
    tupla->node = node;
    printf("check2\n");
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