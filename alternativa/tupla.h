#ifndef TUPLA_H
#define TUPLA_H

#include "ast.h"

struct tupla;
typedef struct tupla Tupla;

void tupla_add_child(Tupla* parent, Tupla* child);
void empty_tupla(Tupla* tupla);

void change_name(Tupla* tupla, char* name);
void change_line(Tupla* tupla, int line);
void change_node(Tupla* tupla, AST* node);

AST*  getAST(Tupla* tupla);
char* tupla_get_name(Tupla* tupla);
int   tupla_get_line(Tupla* tupla);

#endif