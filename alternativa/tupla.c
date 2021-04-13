#include <stdio.h>
#include <stdlib.h>
#include "tupla.h"

struct tupla {
    char *name;
    int  line;
    Type type;
    AST  *node;
};

Tupla* new_tupla(char* name, int line, Type type, AST* node) {
    Tupla* tupla = (struct tupla*) malloc(sizeof(struct tupla));
    tupla->name = name;
    tupla->line = line;
    tupla->type = type;
    tupla->node = node;
    printf("tupla criada\n");
    return tupla;
}

void tupla_add_child(Tupla* parent, Tupla* child) {
    add_child(parent->node, child->node);
}

void tupla_change_name(Tupla* tupla, char* name) {
    tupla->name = name;
}

void tupla_change_line(Tupla* tupla, int line) {
    tupla->line = line;
}

void tupla_change_node(Tupla* tupla, AST* node) {
    tupla->node = node;
}

AST* tupla_get_node(Tupla* tupla) {
    return tupla->node;
}

char* tupla_get_name(Tupla* tupla) {
	return tupla->name;
}

int tupla_get_line(Tupla* tupla) {
	return tupla->line;
}

Type  tupla_get_type(Tupla* tupla) {
    return tupla->type;
}

void tupla_free_name(Tupla* tupla) {
    free(tupla->name);
}