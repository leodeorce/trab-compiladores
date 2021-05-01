#ifndef AST_H
#define AST_H

#include "types.h"

typedef enum {

    AND_NODE,
    ASSIGN_NODE,
    EQ_NODE,
    BEGIN_NODE,
    BLOCK_NODE,
    BOOL_VAL_NODE,
    DIV_NODE,
    GT_EQ_NODE,
    GT_NODE,
    IF_NODE,
    INEQ_NODE,
    LT_EQ_NODE,
    LT_NODE,
    MULT_NODE,
    NUM_VAL_NODE,
    OR_NODE,
    PLUS_NODE,
    PRINT_NODE,
    SUB_NODE,
    STR_VAL_NODE,
    VAR_DECL_NODE,
    VAR_USE_NODE,
    WHILE_NODE,

    B2S_NODE,
    B2U_NODE,
    N2S_NODE,
    N2U_NODE,
    S2U_NODE,
    U2S_NODE

} NodeKind;

struct node;
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

void set_node_type(AST *node, Type type);
Type get_node_type(AST *node);
int  get_child_count(AST *node);

NodeKind conv2node(Conv conv);

void print_tree(AST *ast);
void print_dot(AST *ast);

void free_tree(AST *ast);


#endif
