%output  "parser.c"
%defines "parser.h"
%define  parse.error verbose
%define  parse.lac   full

%{

#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "list.h"
#include "tupla.h"
#include "ast.h"
#include "parser.h"

int  yylex(void);
void yyerror(const char* s);
int  yylex_destroy(void);

void debug(char*);

int  check_var(Tupla* tupla);
AST* new_var(Tupla* tupla, Type type);

Type unify(Type left, Type right, const char*, Type (*unify)(Type, Type));
Conv check_assign(Type left, Type right);

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
%left LOGICAL_NULL LOGICAL_AND LOGICAL_OR EQ EQ_STRICT INEQ INEQ_STRICT LT LT_EQ GT GT_EQ
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
        debug("begin-1");
        root = new_node(BEGIN_NODE, 0, NO_TYPE);
        add_child(root, tupla_get_node($1));
        free($1);
    }
;

line:

    stmt-list
    {
        debug("line-1");
        $$ = $1;
    }

|   %empty
    {
        debug("line-2");
        $$ = new_tupla(NULL, 0, NO_TYPE, NULL);
    }
;

stmt-list:

    stmt-list stmt
    {
        debug("stmt-list-1");
        tupla_add_child($1, $2);
        $$ = $1;
        free($2);
    }

|   stmt
    {
        debug("stmt-list-2");
        $$ = new_tupla(NULL, 0, NO_TYPE, new_node(BLOCK_NODE, 0, NO_TYPE));
        tupla_add_child($$, $1);
        free($1);
    }
;

stmt:
    var-declr SEMI          { debug("stmt-1"); $$ = $1; }
|   func-def
|   class-def

|   expr SEMI
    {
        debug("stmt-4");
        tupla_free_name($1);
        $$ = $1;
    }

|   assign-expr SEMI        { debug("stmt-5"); $$ = $1; }
|   if-stmt
|   while-stmt
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
        debug("assign-expr-2");

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
    ASSIGN                  { debug("assignment-1"); }
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
|   WHILE LPAR assign-expr RPAR LBRACE line RBRACE
;

if-stmt:
    IF LPAR expr RPAR LBRACE line RBRACE
|   IF LPAR expr RPAR LBRACE line RBRACE ELSE LBRACE line RBRACE
|   IF LPAR expr RPAR LBRACE line RBRACE ELSE stmt
|   IF LPAR assign-expr RPAR LBRACE line RBRACE
|   IF LPAR assign-expr RPAR LBRACE line RBRACE ELSE LBRACE line RBRACE
|   IF LPAR assign-expr RPAR LBRACE line RBRACE ELSE stmt
;

logic-expr:

    expr EQ expr
    {
        debug("logic-expr-1");
        unify(tupla_get_type($1), tupla_get_type($3), "==", unify_comp);
        $$ = new_tupla(NULL, 0, BOOLEAN_TYPE, new_node(EQ_NODE, 0, BOOLEAN_TYPE));
        tupla_add_child($$, $1);
        tupla_add_child($$, $3);
        free_tupla_full($1, $3);
    }

|   expr EQ_STRICT expr

|   expr INEQ expr
    {
        debug("logic-expr-3");
        unify(tupla_get_type($1), tupla_get_type($3), "!=", unify_comp);
        $$ = new_tupla(NULL, 0, BOOLEAN_TYPE, new_node(INEQ_NODE, 0, BOOLEAN_TYPE));
        tupla_add_child($$, $1);
        tupla_add_child($$, $3);
        free_tupla_full($1, $3);
    }

|   expr INEQ_STRICT expr

|   expr LT expr
    {
        debug("logic-expr-5");
        unify(tupla_get_type($1), tupla_get_type($3), "<", unify_comp);
        $$ = new_tupla(NULL, 0, BOOLEAN_TYPE, new_node(LT_NODE, 0, BOOLEAN_TYPE));
        tupla_add_child($$, $1);
        tupla_add_child($$, $3);
        free_tupla_full($1, $3);
    }

|   ID LT expr
    {
        debug("logic-expr-6");
        int  idx = check_var($1);
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
        debug("logic-expr-7");
        unify(tupla_get_type($1), tupla_get_type($3), "<=", unify_comp);
        $$ = new_tupla(NULL, 0, BOOLEAN_TYPE, new_node(LT_EQ_NODE, 0, BOOLEAN_TYPE));
        tupla_add_child($$, $1);
        tupla_add_child($$, $3);
        free_tupla_full($1, $3);
    }

|   expr GT expr
    {
        debug("logic-expr-8");
        unify(tupla_get_type($1), tupla_get_type($3), ">", unify_comp);
        $$ = new_tupla(NULL, 0, BOOLEAN_TYPE, new_node(GT_NODE, 0, BOOLEAN_TYPE));
        tupla_add_child($$, $1);
        tupla_add_child($$, $3);
        free_tupla_full($1, $3);
    }

|   expr GT_EQ expr
    {
        debug("logic-expr-9");
        unify(tupla_get_type($1), tupla_get_type($3), ">=", unify_comp);
        $$ = new_tupla(NULL, 0, BOOLEAN_TYPE, new_node(GT_EQ_NODE, 0, BOOLEAN_TYPE));
        tupla_add_child($$, $1);
        tupla_add_child($$, $3);
        free_tupla_full($1, $3);
    }

|   expr LOGICAL_NULL expr

|   expr LOGICAL_AND expr
    {
        debug("logic-expr-11");
    }

|   expr LOGICAL_OR expr
    {
        debug("logic-expr-12");
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
    {
        debug("func-def-1");
    }

|   FUNCTION ID LPAR params RPAR COLON var-type LBRACE line RBRACE
    {
        debug("func-def-2");
    }
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
        debug("var-declr-1");
        $$ = $2;
        tupla_change_node($$, new_var($2, UNDEFINED_TYPE));
        tupla_free_name($$);
    }

|   var-declr-rw id-list ASSIGN expr
    {
        debug("var-declr-2");
        $$ = new_tupla(NULL, 0, NO_TYPE, new_node(ASSIGN_NODE, 0, NO_TYPE));
        tupla_change_node($2, new_var($2, tupla_get_type($4)));
        tupla_add_child($$, $2);
        tupla_add_child($$, $4);
        free_tupla_full($2, $4);
    }

|   var-declr-rw id-list ASSIGN obj-def

|   var-declr-rw ID COLON var-type
    {
        debug("var-declr-4");
        $$ = $2;
        tupla_change_node($$, new_var($2, tupla_get_type($4)));
        tupla_free_name($$);
        free($4);
    }

|   var-declr-rw ID COLON var-type ASSIGN expr
    {
        debug("var-declr-5");
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
    LET         { debug("var-declr-rw-1"); }
|   VAR         { debug("var-declr-rw-2"); }
;

id-list:
    ID COMMA id-list
|   ID
    {
        debug("id-list-2");
        $$ = $1;
    }
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
    NUMBER      { debug("var-type-1"); $$ = new_tupla(NULL, 0, NUMBER_TYPE, NULL);    }
|   STRING      { debug("var-type-2"); $$ = new_tupla(NULL, 0, STRING_TYPE, NULL);    }
|   UNDEFINED   { debug("var-type-3"); $$ = new_tupla(NULL, 0, UNDEFINED_TYPE, NULL); }
|   BOOLTYPE    { debug("var-type-4"); $$ = new_tupla(NULL, 0, BOOLEAN_TYPE, NULL);   }
|   ANY         // Desconsiderado
|   VOID_RW     // Desconsiderado
|   NEVER       // Desconsiderado
;

expr:
    idx-safe-expr   { debug("expr-1"); $$ = $1; }
|   idx-unsafe-expr
|   LPAR expr RPAR  { debug("expr-3"); $$ = $2; }
;

idx-unsafe-expr:
    array-expr
|   logic-expr      { debug("idx-unsafe-expr-1"); $$ = $1; }
|   var-obj
;

idx-safe-expr:
    var-val         { debug("idx-safe-expr-1"); $$ = $1; }
|   var-att
|   arit-expr       { debug("idx-safe-expr-3"); $$ = $1; }
|   bitw-expr
|   shift-expr
|   unary-expr
|   vet-idx
|   ID %prec E_ID
    {
        debug("idx-safe-expr-8");
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
        debug("arit-expr-1");
        Type type_final = unify(tupla_get_type($1), tupla_get_type($3), "+", unify_plus);
        $$ = new_tupla(NULL, 0, type_final, new_node(PLUS_NODE, 0, type_final));
        tupla_add_child($$, $1);
        tupla_add_child($$, $3);
        free_tupla_full($1, $3);
    }

|   expr SUB expr
    {
        debug("arit-expr-2");
        Type type_final = unify(tupla_get_type($1), tupla_get_type($3), "-", unify_other_arith);
        $$ = new_tupla(NULL, 0, type_final, new_node(SUB_NODE, 0, type_final));
        tupla_add_child($$, $1);
        tupla_add_child($$, $3);
        free_tupla_full($1, $3);
    }

|   expr MULT expr
    {
        debug("arit-expr-2");
        Type type_final = unify(tupla_get_type($1), tupla_get_type($3), "*", unify_other_arith);
        $$ = new_tupla(NULL, 0, type_final, new_node(MULT_NODE, 0, type_final));
        tupla_add_child($$, $1);
        tupla_add_child($$, $3);
        free_tupla_full($1, $3);
    }

|   expr DIV expr
    {
        debug("arit-expr-2");
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
        debug("var-att-3");
        //check_obj($1);
        //tupla_change_node($1, new_node(OBJ_USE_NODE, idx, NO_TYPE));
        //$$ = new_tupla(NULL, 0, NO_TYPE, new_node(METHOD_NODE, 0, NO_TYPE));
    }
|   var-met DOT ID
|   var-met DOT var-att
|   var-att DOT var-met
|   ID DOT ID
;

var-met:
    ID LPAR args-list RPAR
;

args-list:
    COMMA args-list
|   expr COMMA args-list
|   assign-expr COMMA args-list
|   expr
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
    INT_VAL         { debug("var-val-1");  $$ = $1; }
|   REAL_VAL        { debug("var-val-2");  $$ = $1; }
|   STR_VAL         { debug("var-val-3");  $$ = $1; }
|   TRUE_RW         { debug("var-val-4");  $$ = $1; }
|   FALSE_RW        { debug("var-val-5");  $$ = $1; }
|   SUB INT_VAL     { debug("var-val-6");  $$ = $2; }
|   SUB REAL_VAL    { debug("var-val-7");  $$ = $2; }
|   SUB STR_VAL     { debug("var-val-8");  $$ = $2; } // NaN
|   SUB TRUE_RW     { debug("var-val-9");  $$ = $2; }
|   SUB FALSE_RW    { debug("var-val-10"); $$ = $2; } // -0
;

array-expr:
    LBRACKET elmts-list RBRACKET
;

elmts-list:
    COMMA elmts-list            { debug("elmts-list-1"); $$ = $2; }
|   var-val COMMA elmts-list    { debug("elmts-list-2"); }
|   var-val                     { debug("elmts-list-3"); }
|   %empty                      { debug("elmts-list-4"); }
;

%%

void debug(char *text) {
    printf("DEBUG\t%s\n", text);
}

// -----------------------------------------------------------------------

int check_var(Tupla* tupla) {
    int idx = findVar(vt, tupla_get_name(tupla));
    printf("CHECK_VAR\tyylineno: %d,\tname: %s\n", yylineno, tupla_get_name(tupla));
    if (idx == -1) {
        printf("SEMANTIC ERROR (%d): variable '%s' was not declared.\n",
            yylineno, tupla_get_name(tupla));
        exit(EXIT_FAILURE);
    }
    return idx;
}

AST* new_var(Tupla* tupla, Type type) {
    printf("NEW_VAR\t\tyylineno: %d,\tname: %s,\tline: %d,\ttype: %s\n",
            yylineno, tupla_get_name(tupla), tupla_get_line(tupla), get_text(type));
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
    printf("UNIFY\t\tyylineno: %d,\tleft: %s,\tright: %s,\top: %s\n",
            yylineno, get_text(left), get_text(right), op);
    Type unif = unify(left, right);
    if (unif == NO_TYPE) {
        type_error(op, left, right);
    }
    return unif;
}

Conv check_assign(Type left, Type right) {

    printf("CHECK_ASSIGN\tyylineno: %d,\tleft: %s,\tright: %s\n",
            yylineno, get_text(left), get_text(right));

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

void free_tupla_full(Tupla* t1, Tupla* t2) {
    tupla_free_name(t1);
    tupla_free_name(t2);
    free(t1);
    free(t2);
}

// -----------------------------------------------------------------------

void type_error(const char *op, Type left, Type right) {
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
    //ot = createVarTable();

    //addVar(&ot, 0, "console", NO_TYPE);
    //addVar(&ot, 0, "log", NO_TYPE);

    yyparse();
    printf("Parse successful\n");
    
    printVars(vt);
    printStrs(st);

    print_dot(root);

    freeVars(&vt);
    freeStrs(&st);
    free_tree(root);

    yylex_destroy();

    return 0;
}