#ifndef AST_H
#define AST_H

#include "types.h"

typedef enum {
    ASSIGN_NODE,
    EQ_NODE,
    BEGIN_NODE,
    BLOCK_NODE,
    BOOL_VAL_NODE,
    IF_NODE,
    NUM_VAL_NODE,
    LT_NODE,
    SUB_NODE,
    DIV_NODE,
    PLUS_NODE,
    STR_VAL_NODE,
    MULT_NODE,
    VAR_DECL_NODE,
    VAR_USE_NODE,

    B2I_NODE,   // Conversion of types.
    B2R_NODE,
    B2S_NODE,
    I2S_NODE,
    R2S_NODE
} NodeKind;

struct node; // Opaque structure to ensure encapsulation.

typedef struct node AST;

struct list;

typedef struct list List;

AST* new_node(NodeKind kind, int data, Type type);

void add_child(AST *parent, AST *child);
AST* get_child(AST *parent, int idx);

AST* new_subtree(NodeKind kind, Type type, int child_count, ...);

NodeKind get_kind(AST *node);
char*    kind2str(NodeKind kind);

int    get_idx(AST *node);
void   set_double_data(AST *node, double data);
double get_double_data(AST *node);

Type get_node_type(AST *node);
int  get_child_count(AST *node);

void print_tree(AST *ast);
void print_dot(AST *ast);

void free_tree(AST *ast);

#endif
