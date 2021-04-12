#include <stdio.h>
#include "tupla.h"

struct tupla {
    char *name;
    int  line;
    AST  *node;
};

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