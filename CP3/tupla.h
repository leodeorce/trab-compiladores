#ifndef TUPLA_H
#define TUPLA_H

#include "types.h"
#include "ast.h"

struct tupla;
typedef struct tupla Tupla;

Tupla* new_tupla(char* name, int line, Type type, AST* node);

void tupla_add_child(Tupla* parent, Tupla* child);

void tupla_change_name(Tupla* tupla, char* name);
void tupla_change_line(Tupla* tupla, int line);
void tupla_change_type(Tupla* tupla, Type type);
void tupla_change_node(Tupla* tupla, AST* node);

AST*  tupla_get_node(Tupla* tupla);
char* tupla_get_name(Tupla* tupla);
int   tupla_get_line(Tupla* tupla);
Type  tupla_get_type(Tupla* tupla);

void tupla_free_name(Tupla* tupla);

#endif