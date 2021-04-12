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

AST* check_var(Tupla* tupla);
AST* new_var(Tupla* tupla, Type type);

AST* unify_bin_op(Type left, Type right, const char*, Type (*unify)(Type, Type));
AST* check_assign(Type left, Type right);
AST* change_type(Tupla* tupla, Type type);

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
        add_child(root, getAST($1));
    }
;

line:
    stmt-list       { debug("line-1"); $$ = $1; }
|   %empty          { debug("line-2"); empty_tupla($$); }
;

stmt-list:
    stmt-list stmt  { debug("stmt-list-1"); tupla_add_child($1, $2); $$ = $1; }
|   stmt            { debug("stmt-list-2"); change_node($$, new_node(BLOCK_NODE, 0, NO_TYPE)); }
;

stmt:
    var-declr SEMI          { debug("stmt-1"); $$ = $1; }
|   func-def                { debug("stmt-2"); }
|   class-def
|   expr SEMI               { debug("stmt-4"); }
|   assign-expr SEMI        { debug("stmt-5"); }
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
        //check_var($1);
        //check_assign( get_type($1), $3 );
        //change_type($1, $3);
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
|   expr EQ_STRICT expr
|   expr INEQ expr
|   expr INEQ_STRICT expr
|   expr LT expr
|   ID LT expr
|   expr LT_EQ expr
|   expr GT expr
|   expr GT_EQ expr
|   expr LOGICAL_NULL expr
|   expr LOGICAL_AND expr
|   expr LOGICAL_OR expr
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

    LET id-list
    {
        debug("var-declr-1");
        change_node($$, new_var($2, UNKNOWN_TYPE));
    }

|   LET id-list ASSIGN expr
    {
        debug("var-declr-2");
        //new_var($2, $4);
    }

|   LET id-list ASSIGN obj-def
    {
        debug("var-declr-3");
    }

|   LET ID COLON var-type
    {
        debug("var-declr-4");
        //new_var($2, $4);
    }

|   LET ID COLON var-type ASSIGN expr
    {
        debug("var-declr-5");
        //new_var($2, $4);
    }

|   LET ID COLON var-type LBRACKET RBRACKET
    {
        debug("var-declr-6");
    }

|   LET ID COLON var-type LBRACKET RBRACKET ASSIGN expr
    {
        debug("var-declr-7");
    }

|   VAR id-list
    {
        debug("var-declr-8");
        //new_var($2, UNKNOWN_TYPE);
    }

|   VAR id-list ASSIGN expr
    {
        debug("var-declr-9");
        //new_var($2, $4);
    }

|   VAR id-list ASSIGN obj-def
    {
        debug("var-declr-10");
    }

|   VAR ID COLON var-type
    {
        debug("var-declr-11");
        //new_var($2, $4);
    }

|   VAR ID COLON var-type ASSIGN expr
    {
        debug("var-declr-12");
        //new_var($2, $4);
    }

|   VAR ID COLON var-type LBRACKET RBRACKET
    {
        debug("var-declr-13");
    }

|   VAR ID COLON var-type LBRACKET RBRACKET ASSIGN expr
    {
        debug("var-declr-14");
    }

|   CONST_RW id-list ASSIGN expr
    {
        debug("var-declr-15");
        //new_var($2, $4);
    }

|   CONST_RW ID COLON var-type ASSIGN expr
    {
        debug("var-declr-16");
        //new_var($2, $4);
    }

|   CONST_RW ID COLON var-type LBRACKET RBRACKET ASSIGN expr
    {
        debug("var-declr-17");
    }

|   CONST_RW id-list ASSIGN obj-def
    {
        debug("var-declr-18");
    }
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
    NUMBER      { debug("var-type-1"); /* $$ = NUMBER_TYPE;  */}
|   STRING      { debug("var-type-2"); /* $$ = STRING_TYPE;  */}
|   UNKNOWN     { debug("var-type-3"); /* $$ = UNKNOWN_TYPE; */}
|   BOOLTYPE    { debug("var-type-4"); /* $$ = BOOLEAN_TYPE; */}
|   ANY         { debug("var-type-5"); /* $$ = ANY_TYPE;     */}
|   VOID_RW     { debug("var-type-6"); /* $$ = VOID_TYPE;    */}
|   NEVER       { debug("var-type-7"); /* $$ = NEVER_TYPE;   */}
;

expr:
    idx-safe-expr   { debug("expr-1"); }
|   idx-unsafe-expr { debug("expr-2"); }
|   LPAR expr RPAR  { debug("expr-3"); $$ = $2; }
;

idx-unsafe-expr:
    array-expr      { debug("idx-unsafe-expr-1"); }
|   logic-expr      { debug("idx-unsafe-expr-2"); }
|   var-obj         { debug("idx-unsafe-expr-3"); }
;

idx-safe-expr:
    var-val         { debug("idx-safe-expr-1"); }
|   var-att         { debug("idx-safe-expr-2"); }
|   arit-expr       { debug("idx-safe-expr-3"); }
|   bitw-expr       { debug("idx-safe-expr-4"); }
|   shift-expr      { debug("idx-safe-expr-5"); }
|   unary-expr      { debug("idx-safe-expr-6"); }
|   vet-idx         { debug("idx-safe-expr-7"); }
|   ID %prec E_ID
    {
        debug("idx-safe-expr-8");
        //check_var($1);
        //$$ = get_type($1);
    }
;

vet-idx:
    ID LBRACKET idx-safe-expr RBRACKET
;

unary-expr:

    INCREMENT ID
    {
        debug("unary-expr-1");
        //check_var($2);
    }

|   INCREMENT var-att

|   DECREMENT ID
    {
        debug("unary-expr-3");
        //check_var($2);
    }

|   DECREMENT var-att

|   ID INCREMENT
    {
        debug("unary-expr-5");
        //check_var($1);
    }

|   var-att INCREMENT

|   ID DECREMENT
    {
        debug("unary-expr-7");
        //check_var($1);
    }

|   var-att DECREMENT

|   LOGICAL_NOT expr

|   BITWISE_NOT expr
;

arit-expr:

    expr PLUS expr
    {
        debug("arit-expr-1");
        //$$ = unify_bin_op($1, $3, "+", unify_plus);
    }

|   expr SUB expr
    {
        debug("arit-expr-2");
    }

|   expr MULT expr
|   expr DIV expr
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
|   var-met DOT ID
|   var-met DOT var-att
|   var-att DOT var-met
|   ID DOT ID
;

var-met:
    ID LPAR args-list RPAR
;

args-list:
    COMMA args-list               { debug("args-list-1"); $$ = $2; }
|   expr COMMA args-list          { debug("args-list-2"); }
|   assign-expr COMMA args-list   { debug("args-list-3"); }
|   expr                          { debug("args-list-4"); }
|   assign-expr                   { debug("args-list-5"); }
|   %empty                        { debug("args-list-6"); }
;

var-obj:
    ID LPAR args-list RPAR
|   ID LT var-type GT LPAR args-list RPAR
|   NEW ID LPAR args-list RPAR
|   NEW ID LT var-type GT LPAR args-list RPAR
;

var-val:
    INT_VAL         { debug("var-val-1");  /*$$ = NUMBER_TYPE;  */}
|   REAL_VAL        { debug("var-val-2");  /*$$ = NUMBER_TYPE;  */}
|   STR_VAL         { debug("var-val-3");  /*$$ = STRING_TYPE;  */}
|   TRUE_RW         { debug("var-val-4");  /*$$ = BOOLEAN_TYPE; */}
|   FALSE_RW        { debug("var-val-5");  /*$$ = BOOLEAN_TYPE; */}
|   SUB INT_VAL     { debug("var-val-6");  /*$$ = NUMBER_TYPE;  */}
|   SUB REAL_VAL    { debug("var-val-7");  /*$$ = NUMBER_TYPE;  */}
|   SUB STR_VAL     { debug("var-val-8");  /*$$ = STRING_TYPE;  */}
|   SUB TRUE_RW     { debug("var-val-9");  /*$$ = BOOLEAN_TYPE; */}
|   SUB FALSE_RW    { debug("var-val-10"); /*$$ = BOOLEAN_TYPE; */}
|   NULL_RW
|   UNDEFINED
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

AST* check_var(Tupla* tupla) {

    struct node *item = findVar(vt, tupla_get_name(tupla));

    printf("CHECK_VAR\tyylineno: %d,\tname: %s\n", yylineno, tupla_get_name(tupla));

    if (item == NULL) {
        printf("SEMANTIC ERROR (%d): variable '%s' was not declared.\n", yylineno, tupla_get_name(tupla));
        exit(EXIT_FAILURE);
    }

    return NULL;
}

AST* new_var(Tupla* tupla, Type type) {

    printf("NEW_VAR\t\tyylineno: %d,\tname: %s,\tline: %d,\ttype: %s\n",
            yylineno, tupla_get_name(tupla), tupla_get_line(tupla), get_text(type));

    struct node *item = findVar(vt, tupla_get_name(tupla));

    if (item != NULL) {
        printf("SEMANTIC ERROR (%d): variable '%s' already declared at line %d.\n",
                tupla_get_line(tupla), tupla_get_name(tupla), getLine(item));
        exit(EXIT_FAILURE);
    }

    int idx = addVar(&vt, tupla_get_line(tupla), tupla_get_name(tupla), type);
    return new_node(VAR_DECL_NODE, idx, type);
}

// -----------------------------------------------------------------------

AST* unify_bin_op(Type left, Type right, const char* op, Type (*unify)(Type, Type)) {

    printf("UNIFY\t\tyylineno: %d,\tleft: %s,\tright: %s,\top: %s\n",
            yylineno, get_text(left), get_text(right), op);

    Type unif = unify(left, right);

    if (unif == NO_TYPE) {
        type_error(op, left, right);
    }

    return NULL;
}

AST* check_assign(Type left, Type right) {

    printf("CHECK_ASSIGN\tyylineno: %d,\tleft: %s,\tright: %s\n",
            yylineno, get_text(left), get_text(right));

    switch(left) {

        case NUMBER_TYPE:
            switch(right) {
                case NUMBER_TYPE:  break;
                case ANY_TYPE:     break;
                case NEVER_TYPE:   break;
                default:           type_error("=", left, right);
            }
            break;

        case STRING_TYPE:
            switch(right) {
                case STRING_TYPE:  break;
                case ANY_TYPE:     break;
                case NEVER_TYPE:   break;
                default:           type_error("=", left, right);
            }
            break;

        case BOOLEAN_TYPE:
            switch(right) {
                case BOOLEAN_TYPE: break;
                case ANY_TYPE:     break;
                case NEVER_TYPE:   break;
                default:           type_error("=", left, right);
            }
            break;

        case VOID_TYPE:
            switch(right) {
                case VOID_TYPE:    break;
                case ANY_TYPE:     break;
                case NEVER_TYPE:   break;
                default:           type_error("=", left, right);
            }
            break;

        case NEVER_TYPE:
            switch(right) {
                case NEVER_TYPE:   break;
                default:           type_error("=", left, right);
            }
            break;

        default: break;
    }

    return NULL;
}

AST* change_type(Tupla* tupla, Type type) {
    printf("ADD_TYPE\t\tname: %s,\ttype: %s\n", get_text(type), tupla_get_name(tupla));
    changeVarType(vt, tupla_get_name(tupla), type);
    return NULL;
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

    yyparse();
    printf("Parse successful\n");
    
    printVars(vt);
    printStrs(st);

    freeVars(&vt);
    freeStrs(&st);
    free_tree(root);

    yylex_destroy();

    return 0;
}