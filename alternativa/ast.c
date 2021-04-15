
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include "list.h"

struct list {
    AST* first;
    AST* last;
};

struct node {
    NodeKind kind;
    union {
        int    as_idx;
        double as_number;
    } data;
    Type  type;
    int   count;
    List  children;
    AST   *next;
};

AST* new_node(NodeKind kind, int data, Type type) {
    AST* node = malloc(sizeof * node);
    node->kind = kind;
    node->data.as_idx = data;
    node->type = type;
    node->count = 0;
    node->children.first = NULL;
    node->children.last = NULL;
    return node;
}

void add_child(AST *parent, AST *child) {
    if(parent->children.last != NULL) {
        parent->children.last->next = child;
        parent->children.last = child;
    } else {
        parent->children.first = child;
        parent->children.last = child;
    }
    parent->count++;
}

AST* get_child(AST *parent, int idx) {
    if(idx >= parent->count)
        return NULL;
    AST* node = parent->children.first;
    for(int i = 0; i < idx; i++)
        node = node->next;
    return node;
}

AST* new_subtree(NodeKind kind, Type type, int child_count, ...) {
    AST* node = new_node(kind, 0, type);
    va_list ap;
    va_start(ap, child_count);
    for (int i = 0; i < child_count; i++) {
        add_child(node, va_arg(ap, AST*));
    }
    va_end(ap);
    return node;
}

NodeKind get_kind(AST *node) {
    return node->kind;
}

int get_idx(AST *node) {
    return node->data.as_idx;
}

void set_double_data(AST *node, double data) {
    node->data.as_number = data;
}

double get_double_data(AST *node) {
    return node->data.as_number;
}

void set_node_type(AST *node, Type type) {
    node->type = type;
}

Type get_node_type(AST *node) {
    return node->type;
}

int get_child_count(AST *node) {
    return node->count;
}

NodeKind conv2node(Conv conv) {
    switch(conv) {
        case N2S: return N2S_NODE; break;
        case B2S: return B2S_NODE; break;
        case U2S: return U2S_NODE; break;
        case N2U: return N2U_NODE; break;
        case S2U: return S2U_NODE; break;
        case B2U: return B2U_NODE; break;
        default:  return BLOCK_NODE;
    }
}

void free_tree(AST *tree) {
    if (tree == NULL) return;
    AST* aux;
    for (int i = 0; i < tree->count; i++) {
        aux = tree->children.first->next;
        free_tree(tree->children.first);
        tree->children.first = aux;
    }
    free(tree);
}

// Dot output.

int nr;

extern Var_table *vt;

char* kind2str(NodeKind kind) {
    switch(kind) {
        case AND_NODE:      return "&&";
        case ASSIGN_NODE:   return "=";
        case EQ_NODE:       return "==";
        case BEGIN_NODE:    return "begin";
        case BLOCK_NODE:    return "block";
        case BOOL_VAL_NODE: return "";
        case DIV_NODE:      return "/";
        case GT_EQ_NODE:    return ">=";
        case GT_NODE:       return ">";
        case IF_NODE:       return "if";
        case INEQ_NODE:     return "!=";
        case LT_EQ_NODE:    return "<=";
        case LT_NODE:       return "<";
        case MULT_NODE:     return "*";
        case NUM_VAL_NODE:  return "";
        case OR_NODE:       return "||";
        case PLUS_NODE:     return "+";
        case SUB_NODE:      return "-";
        case STR_VAL_NODE:  return "";
        case VAR_DECL_NODE: return "var_decl";
        case VAR_USE_NODE:  return "var_use";
        case WHILE_NODE:    return "while";
        case B2S_NODE:      return "B2S";
        case B2U_NODE:      return "B2U";
        case N2S_NODE:      return "N2S";
        case N2U_NODE:      return "N2U";
        case S2U_NODE:      return "S2U";
        case U2S_NODE:      return "U2S";
        default:            return "ERROR!!";
    }
}

int has_data(NodeKind kind) {
    switch(kind) {
        case BOOL_VAL_NODE:
        case NUM_VAL_NODE:
        case STR_VAL_NODE:
        case VAR_DECL_NODE:
        case VAR_USE_NODE:
            return 1;
        default:
            return 0;
    }
}

int print_node_dot(AST *node) {
    int my_nr = nr++;
    fprintf(stderr, "node%d[label=\"", my_nr);
    if (node->type != NO_TYPE) {
        fprintf(stderr, "(%s) ", get_text(node->type));
    }
    if (node->kind == VAR_DECL_NODE || node->kind == VAR_USE_NODE) {
        fprintf(stderr, "%s@", getName(vt, node->data.as_idx));
    } else {
        fprintf(stderr, "%s", kind2str(node->kind));
    }
    if (has_data(node->kind)) {
        if (node->kind == NUM_VAL_NODE) {
            fprintf(stderr, "%.2f", node->data.as_number);
        } else if (node->kind == STR_VAL_NODE) {
            fprintf(stderr, "@%d", node->data.as_idx);
        } else {
            fprintf(stderr, "%d", node->data.as_idx);
        }
    }
    fprintf(stderr, "\"];\n");
    for (int i = 0; i < node->count; i++) {
        int child_nr = print_node_dot( get_child(node, i) );
        fprintf(stderr, "node%d -> node%d;\n", my_nr, child_nr);
    }
    return my_nr;
}

void print_dot(AST *tree) {
    nr = 0;
    fprintf(stderr, "digraph {\ngraph [ordering=\"out\"];\n");
    print_node_dot(tree);
    fprintf(stderr, "}\n");
}
