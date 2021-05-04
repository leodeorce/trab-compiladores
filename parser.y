%output  "parser.c"
%defines "parser.h"
%define  parse.error verbose
%define  parse.lac   full

%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "list.h"
#include "tupla.h"
#include "ast.h"
#include "parser.h"
#include "code.h"

int  yylex(void);
void yyerror(const char* s);
int  yylex_destroy(void);

int  check_var(Tupla* tupla);
AST* new_var(Tupla* tupla, Type type);

Type unify(Type left, Type right, const char*, Type (*unify)(Type, Type));
Conv check_assign(Type left, Type right);
void check_bool_type(const char* cmd, Type type);
void check_name(Tupla* tupla, const char* name);
Conv check_string(Tupla* tupla);

void free_tupla_full(Tupla* t1, Tupla* t2);

void type_error(const char*, Type, Type);

extern char *yytext;
extern int  yylineno;

Var_table *vt;
Str_table *st;

AST *root;

%}

%define api.value.type {Tupla*}

%token ASSIGN ARROW COMMA SEMI COLON TERNARY CHAIN PIPELINE DOT SPREAD PLUS INCREMENT
PLUS_ASSIGN SUB DECREMENT SUB_ASSIGN MULT MULT_ASSIGN DIV DIV_ASSIGN EXP EXP_ASSIGN REM
REM_ASSIGN BITWISE_NOT BITWISE_AND BITWISE_AND_ASSIGN BITWISE_OR BITWISE_OR_ASSIGN
BITWISE_XOR BITWISE_XOR_ASSIGN LOGICAL_NOT LOGICAL_NULL LOGICAL_NULL_ASSIGN LOGICAL_AND
LOGICAL_AND_ASSIGN LOGICAL_OR LOGICAL_OR_ASSIGN EQ EQ_STRICT INEQ INEQ_STRICT LT LT_EQ
GT GT_EQ LSHIFT LSHIFT_ASSIGN RSHIFT RSHIFT_ASSIGN RSHIFT_UNSIGNED RSHIFT_UNSIGNED_ASSIGN
LPAR RPAR LBRACE RBRACE LBRACKET RBRACKET INT_VAL REAL_VAL STR_VAL ID BREAK CASE CATCH
CLASS CONST_RW CONTINUE DEBUGGER DEFAULT DELETE DO ELSE ENUM EXPORT EXTENDS FALSE_RW
FINALLY FOR FUNCTION IF IMPLEMENTS IMPORT IN INSTANCEOF INTERFACE LET NEW NULL_RW PACKAGE
PRIVATE PROTECTED PUBLIC RETURN SUPER SWITCH THIS THROW TRUE_RW TRY TYPEOF VAR VOID_RW
WHILE WITH AWAIT YIELD STATIC AS ASYNC FROM GET OF SET TARGET ANY BOOLTYPE CONSTRUCTOR
DECLARE MODULE REQUIRE NEVER NUMBER STRING SYMBOL TYPE UNDEFINED UNKNOWN

%precedence E_ID
%left LOGICAL_NULL LOGICAL_AND LOGICAL_OR
%left EQ EQ_STRICT INEQ INEQ_STRICT LT LT_EQ GT GT_EQ
%left BITWISE_OR
%left BITWISE_XOR
%left BITWISE_AND
%left LSHIFT RSHIFT RSHIFT_UNSIGNED
%left PLUS SUB
%left MULT DIV REM
%right EXP
%precedence BITWISE_NOT LOGICAL_NOT
%precedence ID
%right DOT

%start begin

%%

begin:
    line
    {
        root = new_node(BEGIN_NODE, 0, NO_TYPE);
        add_child(root, tupla_get_node($1));
        free($1);
    }
;

line:
    stmt-list   { $$ = $1; }
|   %empty      { $$ = new_tupla(NULL, 0, NO_TYPE, NULL); }
;

stmt-list:

    stmt-list stmt
    {
        tupla_add_child($1, $2);
        $$ = $1;
        free($2);
    }

|   stmt
    {
        $$ = new_tupla(NULL, 0, NO_TYPE, new_node(BLOCK_NODE, 0, NO_TYPE));
        tupla_add_child($$, $1);
        free($1);
    }
;

stmt:
    var-declr SEMI          { $$ = $1; }
|   func-def
|   class-def
|   expr SEMI               { tupla_free_name($1); $$ = $1; }
|   assign-expr SEMI        { $$ = $1; }
|   if-stmt                 { $$ = $1; }
|   while-stmt              { $$ = $1; }
|   do-while-stmt
|   for-stmt
|   RETURN SEMI
|   RETURN expr SEMI
|   BREAK SEMI
|   CONTINUE SEMI
;

assign-expr:

    var-att assignment expr

|   ID assignment expr
    {
        int  idx = check_var($1);
        Type id_type = getType(vt, idx);

        tupla_change_node($1, new_node(VAR_USE_NODE, idx, id_type));
        $$ = new_tupla(NULL, 0, NO_TYPE, new_node(ASSIGN_NODE, 0, NO_TYPE));

        Conv conversion = check_assign( id_type, tupla_get_type($3) );

        if(conversion != NONE) {
            NodeKind conversion_nodekind = conv2node(conversion);
            AST* type_conversion = new_node(conversion_nodekind, 0, tupla_get_type($3));
            add_child(type_conversion, tupla_get_node($1));
            add_child(tupla_get_node($$), type_conversion);
        } else {
            tupla_add_child($$, $1);
        }

        tupla_add_child($$, $3);
        free_tupla_full($1, $3);
    }

|   vet-idx assignment expr
;

for-stmt:
    FOR LPAR assign-expr SEMI expr SEMI expr RPAR LBRACE line RBRACE
|   FOR LPAR assign-expr SEMI expr SEMI assign-expr RPAR LBRACE line RBRACE
|   FOR LPAR assign-expr SEMI expr SEMI RPAR LBRACE line RBRACE
|   FOR LPAR assign-expr SEMI SEMI expr RPAR LBRACE line RBRACE
|   FOR LPAR assign-expr SEMI SEMI assign-expr RPAR LBRACE line RBRACE
|   FOR LPAR assign-expr SEMI SEMI RPAR LBRACE line RBRACE
|   FOR LPAR var-declr SEMI expr SEMI expr RPAR LBRACE line RBRACE
|   FOR LPAR var-declr SEMI expr SEMI assign-expr RPAR LBRACE line RBRACE
|   FOR LPAR var-declr SEMI expr SEMI RPAR LBRACE line RBRACE
|   FOR LPAR var-declr SEMI SEMI expr RPAR LBRACE line RBRACE
|   FOR LPAR var-declr SEMI SEMI assign-expr RPAR LBRACE line RBRACE
|   FOR LPAR var-declr SEMI SEMI RPAR LBRACE line RBRACE
|   FOR LPAR SEMI expr SEMI expr RPAR LBRACE line RBRACE
|   FOR LPAR SEMI expr SEMI assign-expr RPAR LBRACE line RBRACE
|   FOR LPAR SEMI expr SEMI RPAR LBRACE line RBRACE
|   FOR LPAR SEMI SEMI expr RPAR LBRACE line RBRACE
|   FOR LPAR SEMI SEMI assign-expr RPAR LBRACE line RBRACE
|   FOR LPAR SEMI SEMI RPAR LBRACE line RBRACE
;

assignment:
    ASSIGN
|   LOGICAL_NULL_ASSIGN
|   LOGICAL_AND_ASSIGN
|   LOGICAL_OR_ASSIGN
|   PLUS_ASSIGN
|   SUB_ASSIGN
|   MULT_ASSIGN
|   DIV_ASSIGN
|   EXP_ASSIGN
|   REM_ASSIGN
|   BITWISE_AND_ASSIGN
|   BITWISE_OR_ASSIGN
|   BITWISE_XOR_ASSIGN
|   LSHIFT_ASSIGN
|   RSHIFT_ASSIGN
|   RSHIFT_UNSIGNED_ASSIGN
;

do-while-stmt:
    DO LBRACE line RBRACE WHILE LPAR expr RPAR
|   DO LBRACE line RBRACE WHILE LPAR assign-expr RPAR
;

while-stmt:

    WHILE LPAR expr RPAR LBRACE line RBRACE
    {
        check_bool_type("while", tupla_get_type($3));
        $$ = new_tupla(NULL, 0, NO_TYPE, new_node(WHILE_NODE, 0, NO_TYPE));
        tupla_add_child($$, $3);
        tupla_add_child($$, $6);
        tupla_free_name($3);
        free($3);
        free($6);
    }

|   WHILE LPAR assign-expr RPAR LBRACE line RBRACE
;

if-stmt:

    IF LPAR expr RPAR LBRACE line RBRACE
    {
        check_bool_type("if", tupla_get_type($3));
        $$ = new_tupla(NULL, 0, NO_TYPE, new_node(IF_NODE, 0, NO_TYPE));
        tupla_add_child($$, $3);
        tupla_add_child($$, $6);
        tupla_free_name($3);
        free($3);
        free($6);
    }

|   IF LPAR expr RPAR LBRACE line RBRACE ELSE LBRACE line RBRACE
    {
        check_bool_type("if", tupla_get_type($3));
        $$ = new_tupla(NULL, 0, NO_TYPE, new_node(IF_NODE, 0, NO_TYPE));
        tupla_add_child($$, $3);
        tupla_add_child($$, $6);
        tupla_add_child($$, $10);
        tupla_free_name($3);
        free($3);
        free($6);
        free($10);
    }

|   IF LPAR expr RPAR LBRACE line RBRACE ELSE stmt
    {
        check_bool_type("if", tupla_get_type($3));
        $$ = new_tupla(NULL, 0, NO_TYPE, new_node(IF_NODE, 0, NO_TYPE));
        tupla_add_child($$, $3);
        tupla_add_child($$, $6);
        tupla_add_child($$, $9);
        tupla_free_name($3);
        free($3);
        free($6);
        free($9);
    }

|   IF LPAR assign-expr RPAR LBRACE line RBRACE
|   IF LPAR assign-expr RPAR LBRACE line RBRACE ELSE LBRACE line RBRACE
|   IF LPAR assign-expr RPAR LBRACE line RBRACE ELSE stmt
;

logic-expr:

    expr EQ expr
    {
        unify(tupla_get_type($1), tupla_get_type($3), "==", unify_comp);
        $$ = new_tupla(NULL, 0, BOOLEAN_TYPE, new_node(EQ_NODE, 0, BOOLEAN_TYPE));
        tupla_add_child($$, $1);
        tupla_add_child($$, $3);
        free_tupla_full($1, $3);
    }

|   expr EQ_STRICT expr

|   expr INEQ expr
    {
        unify(tupla_get_type($1), tupla_get_type($3), "!=", unify_comp);
        $$ = new_tupla(NULL, 0, BOOLEAN_TYPE, new_node(INEQ_NODE, 0, BOOLEAN_TYPE));
        tupla_add_child($$, $1);
        tupla_add_child($$, $3);
        free_tupla_full($1, $3);
    }

|   expr INEQ_STRICT expr

|   expr LT expr
    {
        unify(tupla_get_type($1), tupla_get_type($3), "<", unify_comp);
        $$ = new_tupla(NULL, 0, BOOLEAN_TYPE, new_node(LT_NODE, 0, BOOLEAN_TYPE));
        tupla_add_child($$, $1);
        tupla_add_child($$, $3);
        free_tupla_full($1, $3);
    }

|   ID LT expr
    {
        int idx = check_var($1);
        Type id_type = getType(vt, idx);
        unify(id_type, tupla_get_type($3), "<", unify_comp);
        tupla_change_node($1, new_node(VAR_USE_NODE, idx, id_type));
        $$ = new_tupla(NULL, 0, BOOLEAN_TYPE, new_node(LT_NODE, 0, BOOLEAN_TYPE));
        tupla_add_child($$, $1);
        tupla_add_child($$, $3);
        free_tupla_full($1, $3);
    }

|   expr LT_EQ expr
    {
        unify(tupla_get_type($1), tupla_get_type($3), "<=", unify_comp);
        $$ = new_tupla(NULL, 0, BOOLEAN_TYPE, new_node(LT_EQ_NODE, 0, BOOLEAN_TYPE));
        tupla_add_child($$, $1);
        tupla_add_child($$, $3);
        free_tupla_full($1, $3);
    }

|   expr GT expr
    {
        unify(tupla_get_type($1), tupla_get_type($3), ">", unify_comp);
        $$ = new_tupla(NULL, 0, BOOLEAN_TYPE, new_node(GT_NODE, 0, BOOLEAN_TYPE));
        tupla_add_child($$, $1);
        tupla_add_child($$, $3);
        free_tupla_full($1, $3);
    }

|   expr GT_EQ expr
    {
        unify(tupla_get_type($1), tupla_get_type($3), ">=", unify_comp);
        $$ = new_tupla(NULL, 0, BOOLEAN_TYPE, new_node(GT_EQ_NODE, 0, BOOLEAN_TYPE));
        tupla_add_child($$, $1);
        tupla_add_child($$, $3);
        free_tupla_full($1, $3);
    }

|   expr LOGICAL_NULL expr

|   expr LOGICAL_AND expr
    {
        unify(tupla_get_type($1), tupla_get_type($3), "&&", unify_comp);
        $$ = new_tupla(NULL, 0, BOOLEAN_TYPE, new_node(AND_NODE, 0, BOOLEAN_TYPE));
        tupla_add_child($$, $1);
        tupla_add_child($$, $3);
        free_tupla_full($1, $3);
    }

|   expr LOGICAL_OR expr
    {
        unify(tupla_get_type($1), tupla_get_type($3), "||", unify_comp);
        $$ = new_tupla(NULL, 0, BOOLEAN_TYPE, new_node(OR_NODE, 0, BOOLEAN_TYPE));
        tupla_add_child($$, $1);
        tupla_add_child($$, $3);
        free_tupla_full($1, $3);
    }
;

class-def:
    CLASS ID LBRACE class-att-list RBRACE
;

class-att-list:
    SEMI class-att-list
|   class-att SEMI class-att-list
|   class-att
|   %empty
;

class-att:
    ID COLON var-type
|   access-modif ID COLON var-type
|   ID LPAR params RPAR LBRACE line RBRACE
|   ID LPAR params RPAR COLON var-type LBRACE line RBRACE
;

access-modif:
    PUBLIC
|   PRIVATE
|   PROTECTED
;

func-def:
    FUNCTION ID LPAR params RPAR LBRACE line RBRACE
|   FUNCTION ID LPAR params RPAR COLON var-type LBRACE line RBRACE
;

params:
    COMMA ID
|   COMMA ID COLON var-type
|   ID COMMA ID
|   ID COLON var-type  COMMA ID COLON var-type
|   ID COLON var-type  COMMA ID
|   ID COLON var-type
|   ID COMMA  ID COLON var-type
|   %empty
;

var-declr:

    var-declr-rw id-list
    {
        $$ = $2;
        tupla_change_node($$, new_var($2, UNDEFINED_TYPE));
        tupla_free_name($$);
    }

|   var-declr-rw id-list ASSIGN expr
    {
        $$ = new_tupla(NULL, 0, NO_TYPE, new_node(ASSIGN_NODE, 0, NO_TYPE));
        tupla_change_node($2, new_var($2, tupla_get_type($4)));
        tupla_add_child($$, $2);
        tupla_add_child($$, $4);
        free_tupla_full($2, $4);
    }

|   var-declr-rw id-list ASSIGN obj-def

|   var-declr-rw ID COLON var-type
    {
        $$ = $2;
        tupla_change_node($$, new_var($2, tupla_get_type($4)));
        tupla_free_name($$);
        free($4);
    }

|   var-declr-rw ID COLON var-type ASSIGN expr
    {
        check_assign(tupla_get_type($4), tupla_get_type($6));
        $$ = new_tupla(NULL, 0, NO_TYPE, new_node(ASSIGN_NODE, 0, NO_TYPE));
        tupla_change_node($2, new_var($2, tupla_get_type($6)));
        tupla_add_child($$, $2);
        tupla_add_child($$, $6);
        free_tupla_full($2, $6);
        free($4);
    }

|   var-declr-rw ID COLON var-type LBRACKET RBRACKET
|   var-declr-rw ID COLON var-type LBRACKET RBRACKET ASSIGN expr
|   CONST_RW id-list ASSIGN expr
|   CONST_RW ID COLON var-type ASSIGN expr
|   CONST_RW ID COLON var-type LBRACKET RBRACKET ASSIGN expr
|   CONST_RW id-list ASSIGN obj-def
;

var-declr-rw:
    LET
|   VAR
;

id-list:
    ID COMMA id-list
|   ID                  { $$ = $1; }
;

obj-def:
    LBRACE obj-att-list RBRACE
;

obj-att-list:
    COMMA obj-att-list
|   obj-att COMMA obj-att-list
|   obj-att
|   %empty
;

obj-att:
    ID COLON var-val
;

var-type:
    NUMBER      { $$ = new_tupla(NULL, 0, NUMBER_TYPE, NULL);    }
|   STRING      { $$ = new_tupla(NULL, 0, STRING_TYPE, NULL);    }
|   BOOLTYPE    { $$ = new_tupla(NULL, 0, BOOLEAN_TYPE, NULL);   }
|   UNDEFINED   { $$ = new_tupla(NULL, 0, UNDEFINED_TYPE, NULL); }
|   ANY
|   VOID_RW
|   NEVER
;

expr:
    idx-safe-expr   { $$ = $1; }
|   idx-unsafe-expr { $$ = $1; }
|   LPAR expr RPAR  { $$ = $2; }
;

idx-unsafe-expr:
    array-expr
|   logic-expr      { $$ = $1; }
|   var-obj
;

idx-safe-expr:
    var-val         { $$ = $1; }
|   var-att         { $$ = $1; }
|   arit-expr       { $$ = $1; }
|   bitw-expr
|   shift-expr
|   unary-expr
|   vet-idx
|   ID %prec E_ID
    {
        int idx = check_var($1);
        Type type = getType(vt, idx);
        tupla_change_type($1, type);
        tupla_change_node($1, new_node(VAR_USE_NODE, idx, type));
        $$ = $1;
    }
;

vet-idx:
    ID LBRACKET idx-safe-expr RBRACKET
;

unary-expr:
    INCREMENT ID
|   INCREMENT var-att
|   DECREMENT ID
|   DECREMENT var-att
|   ID INCREMENT
|   var-att INCREMENT
|   ID DECREMENT
|   var-att DECREMENT
|   LOGICAL_NOT expr
|   BITWISE_NOT expr
;

arit-expr:

    expr PLUS expr
    {
        Type type_final = unify(tupla_get_type($1), tupla_get_type($3), "+", unify_plus);
        $$ = new_tupla(NULL, 0, type_final, new_node(PLUS_NODE, 0, type_final));
        tupla_add_child($$, $1);
        tupla_add_child($$, $3);
        free_tupla_full($1, $3);
    }

|   expr SUB expr
    {
        Type type_final = unify(tupla_get_type($1), tupla_get_type($3), "-", unify_other_arith);
        $$ = new_tupla(NULL, 0, type_final, new_node(SUB_NODE, 0, type_final));
        tupla_add_child($$, $1);
        tupla_add_child($$, $3);
        free_tupla_full($1, $3);
    }

|   expr MULT expr
    {
        Type type_final = unify(tupla_get_type($1), tupla_get_type($3), "*", unify_other_arith);
        $$ = new_tupla(NULL, 0, type_final, new_node(MULT_NODE, 0, type_final));
        tupla_add_child($$, $1);
        tupla_add_child($$, $3);
        free_tupla_full($1, $3);
    }

|   expr DIV expr
    {
        Type type_final = unify(tupla_get_type($1), tupla_get_type($3), "/", unify_other_arith);
        $$ = new_tupla(NULL, 0, type_final, new_node(DIV_NODE, 0, type_final));
        tupla_add_child($$, $1);
        tupla_add_child($$, $3);
        free_tupla_full($1, $3);
    }

|   expr EXP expr
|   expr REM expr
;

bitw-expr:
    expr BITWISE_AND expr
|   expr BITWISE_OR expr
|   expr BITWISE_XOR expr
;

shift-expr:
    expr LSHIFT expr
|   expr RSHIFT expr
|   expr RSHIFT_UNSIGNED expr
;

var-att:
    ID DOT var-att
|   var-att DOT ID

|   ID DOT var-met
    {
        check_name($1, "console");
        $$ = new_tupla(NULL, 0, NO_TYPE, new_node(PRINT_NODE, 0, NO_TYPE));
        tupla_add_child($$, $3);
        free_tupla_full($1, $3);
    }

|   var-met DOT ID
|   var-met DOT var-att
|   var-att DOT var-met
|   ID DOT ID
;

var-met:
    ID LPAR args-list RPAR
    {
        check_name($1, "log");
        tupla_free_name($1);
        free($1);
        $$ = $3;
    }
;

args-list:
    COMMA args-list
|   expr COMMA args-list
|   assign-expr COMMA args-list

|   expr
    {
        Conv conversion = check_string($1);
        if(conversion == NONE) {
            tupla_free_name($1);
            $$ = $1;
        }
        else {
            NodeKind conversion_nodekind = conv2node(conversion);
            $$ = new_tupla(NULL, 0, STRING_TYPE, new_node(conversion_nodekind, 0, STRING_TYPE));
            tupla_add_child($$, $1);
            tupla_free_name($1);
            free($1);
        }
    }

|   assign-expr
|   %empty
;

var-obj:
    ID LPAR args-list RPAR
|   ID LT var-type GT LPAR args-list RPAR
|   NEW ID LPAR args-list RPAR
|   NEW ID LT var-type GT LPAR args-list RPAR
;

var-val:
    INT_VAL         { $$ = $1; }
|   REAL_VAL        { $$ = $1; }
|   STR_VAL         { $$ = $1; }
|   TRUE_RW         { $$ = $1; }
|   FALSE_RW        { $$ = $1; }
|   SUB INT_VAL     { $$ = $2; }
|   SUB REAL_VAL    { $$ = $2; }
|   SUB STR_VAL
|   SUB TRUE_RW
|   SUB FALSE_RW
;

array-expr:
    LBRACKET elmts-list RBRACKET
;

elmts-list:
    COMMA elmts-list
|   var-val COMMA elmts-list
|   var-val
|   %empty
;

%%

// -----------------------------------------------------------------------

int check_var(Tupla* tupla) {
    int idx = findVar(vt, tupla_get_name(tupla));
    if (idx == -1) {
        printf("SEMANTIC ERROR (%d): variable '%s' was not declared.\n",
            yylineno, tupla_get_name(tupla));
        exit(EXIT_FAILURE);
    }
    return idx;
}

AST* new_var(Tupla* tupla, Type type) {
    int idx_check = findVar(vt, tupla_get_name(tupla));
    if (idx_check != -1) {
        printf("SEMANTIC ERROR (%d): variable '%s' already declared at line %d.\n",
                tupla_get_line(tupla), tupla_get_name(tupla), getLine(vt, idx_check));
        exit(EXIT_FAILURE);
    }
    int idx = addVar(&vt, tupla_get_line(tupla), tupla_get_name(tupla), type);
    return new_node(VAR_DECL_NODE, idx, type);
}

// -----------------------------------------------------------------------

Type unify(Type left, Type right, const char* op, Type (*unify)(Type, Type)) {
    Type unif = unify(left, right);
    if (unif == NO_TYPE) {
        type_error(op, left, right);
    }
    return unif;
}

Conv check_assign(Type left, Type right) {

    switch(left) {

        case NUMBER_TYPE:
            switch(right) {
                case NUMBER_TYPE:     break;
                case UNDEFINED_TYPE:  return N2U;
                default:              type_error("=", left, right);
            }
            break;

        case STRING_TYPE:
            switch(right) {
                case STRING_TYPE:     break;
                case UNDEFINED_TYPE:  return S2U;
                default:              type_error("=", left, right);
            }
            break;

        case BOOLEAN_TYPE:
            switch(right) {
                case BOOLEAN_TYPE:    break;
                case UNDEFINED_TYPE:  return B2U;
                default:              type_error("=", left, right);
            }
            break;

        default: break;
    }

    return NONE;
}

void check_bool_type(const char* cmd, Type type) {
    if(type != BOOLEAN_TYPE) {
        printf("SEMANTIC ERROR (%d): conditional expression in '%s' is '%s' instead of '%s'.\n",
           yylineno, cmd, get_text(type), get_text(BOOLEAN_TYPE));
        exit(EXIT_FAILURE);
    }
}

void check_name(Tupla* tupla, const char* name) {
    char* tupla_name = tupla_get_name(tupla);
    if(strcmp(tupla_name, name) != 0) {
        printf("SEMANTIC ERROR (%d): cannot find name '%s'.\n", yylineno, tupla_name);
        exit(EXIT_FAILURE);
    }
}

Conv check_string(Tupla* tupla) {
    switch(tupla_get_type(tupla)) {
        case NUMBER_TYPE:    return N2S;
        case BOOLEAN_TYPE:   return B2S;
        case UNDEFINED_TYPE: return U2S;
        default:             return NONE;
    }
}

void free_tupla_full(Tupla* t1, Tupla* t2) {
    tupla_free_name(t1);
    tupla_free_name(t2);
    free(t1);
    free(t2);
}

// -----------------------------------------------------------------------

void type_error(const char* op, Type left, Type right) {
    printf("SEMANTIC ERROR (%d): incompatible types for operator '%s', LHS is '%s' and RHS is '%s'.\n",
        yylineno, op, get_text(left), get_text(right));
    exit(EXIT_FAILURE);
}

void yyerror(const char *s) {
    printf("SYNTAX ERROR (%d): %s\n", yylineno, s);
    exit(EXIT_FAILURE);
}

// -----------------------------------------------------------------------

int main(void) {

    st = createStrTable();
    vt = createVarTable();

    yyparse();
    
    emit_code(root);

    freeVars(&vt);
    freeStrs(&st);
    free_tree(root);

    yylex_destroy();

    return 0;
}