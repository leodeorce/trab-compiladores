%output "parser.c"
%defines "parser.h"
%define parse.error verbose
%define parse.lac full

%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "types.h"

int yylex(void);
void yyerror(char const*);

void check_var(char*);
void new_var(char*, int, Type);
void debug(char*);
void add_type(char*, Type);

extern char *yytext;
extern int yylineno;

Var_table *vt;
Str_table *st;

%}

%token ASSIGN ARROW COMMA SEMI COLON TERNARY CHAIN PIPELINE DOT SPREAD PLUS INCREMENT PLUS_ASSIGN SUB DECREMENT SUB_ASSIGN MULT MULT_ASSIGN DIV DIV_ASSIGN EXP EXP_ASSIGN REM REM_ASSIGN BITWISE_NOT BITWISE_AND BITWISE_AND_ASSIGN BITWISE_OR BITWISE_OR_ASSIGN BITWISE_XOR BITWISE_XOR_ASSIGN LOGICAL_NOT LOGICAL_NULL LOGICAL_NULL_ASSIGN LOGICAL_AND LOGICAL_AND_ASSIGN LOGICAL_OR LOGICAL_OR_ASSIGN EQ EQ_STRICT INEQ INEQ_STRICT LT LT_EQ GT GT_EQ LSHIFT LSHIFT_ASSIGN RSHIFT RSHIFT_ASSIGN RSHIFT_UNSIGNED RSHIFT_UNSIGNED_ASSIGN LPAR RPAR LBRACE RBRACE LBRACKET RBRACKET INT_VAL REAL_VAL STR_VAL ID	BREAK CASE CATCH CLASS CONST_RW CONTINUE DEBUGGER DEFAULT DELETE DO ELSE ENUM EXPORT EXTENDS FALSE_RW FINALLY FOR FUNCTION IF IMPLEMENTS IMPORT IN INSTANCEOF INTERFACE LET NEW NULL_RW PACKAGE PRIVATE PROTECTED PUBLIC RETURN SUPER SWITCH THIS THROW TRUE_RW TRY TYPEOF VAR VOID_RW WHILE WITH AWAIT YIELD STATIC AS ASYNC FROM GET OF SET TARGET ANY BOOLTYPE CONSTRUCTOR DECLARE MODULE REQUIRE NEVER NUMBER STRING SYMBOL TYPE UNDEFINED UNKNOWN

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

%union {
	struct tupla {
		char* name;
		int line;
		int type;
	} tupla;
};

%%

line:
	stmt-list
|	%empty
;

stmt-list:
	stmt-list stmt
|	stmt
;

stmt:
	var-declr SEMI { debug("stmt-1"); }
|	func-def { debug("STMT funccccc	--->1"); }
|	class-def
|	expr SEMI
|	assign-expr SEMI
|	if-stmt
|	while-stmt
|	do-while-stmt
|	for-stmt
|	RETURN SEMI
|	RETURN expr SEMI
|	BREAK SEMI
|	CONTINUE SEMI
;

assign-expr:
	var-att assignment expr 
|	ID assignment expr
|	vet-idx assignment expr
;

for-stmt:
	FOR LPAR assign-expr SEMI expr SEMI expr RPAR LBRACE line RBRACE
|	FOR LPAR assign-expr SEMI expr SEMI assign-expr RPAR LBRACE line RBRACE
|	FOR LPAR assign-expr SEMI expr SEMI RPAR LBRACE line RBRACE
|	FOR LPAR assign-expr SEMI SEMI expr RPAR LBRACE line RBRACE
|	FOR LPAR assign-expr SEMI SEMI assign-expr RPAR LBRACE line RBRACE
|	FOR LPAR assign-expr SEMI SEMI RPAR LBRACE line RBRACE
|	FOR LPAR var-declr SEMI expr SEMI expr RPAR LBRACE line RBRACE
|	FOR LPAR var-declr SEMI expr SEMI assign-expr RPAR LBRACE line RBRACE
|	FOR LPAR var-declr SEMI expr SEMI RPAR LBRACE line RBRACE
|	FOR LPAR var-declr SEMI SEMI expr RPAR LBRACE line RBRACE
|	FOR LPAR var-declr SEMI SEMI assign-expr RPAR LBRACE line RBRACE
|	FOR LPAR var-declr SEMI SEMI RPAR LBRACE line RBRACE
|	FOR LPAR SEMI expr SEMI expr RPAR LBRACE line RBRACE
|	FOR LPAR SEMI expr SEMI assign-expr RPAR LBRACE line RBRACE
|	FOR LPAR SEMI expr SEMI RPAR LBRACE line RBRACE
|	FOR LPAR SEMI SEMI expr RPAR LBRACE line RBRACE
|	FOR LPAR SEMI SEMI assign-expr RPAR LBRACE line RBRACE
|	FOR LPAR SEMI SEMI RPAR LBRACE line RBRACE
;

assignment:
	ASSIGN
|	LOGICAL_NULL_ASSIGN
|	LOGICAL_AND_ASSIGN
|	LOGICAL_OR_ASSIGN
|	PLUS_ASSIGN
|	SUB_ASSIGN
|	MULT_ASSIGN
|	DIV_ASSIGN
|	EXP_ASSIGN
|	REM_ASSIGN
|	BITWISE_AND_ASSIGN
|	BITWISE_OR_ASSIGN
|	BITWISE_XOR_ASSIGN
|	LSHIFT_ASSIGN
|	RSHIFT_ASSIGN
|	RSHIFT_UNSIGNED_ASSIGN
;

do-while-stmt:
	DO LBRACE line RBRACE WHILE LPAR expr RPAR
|	DO LBRACE line RBRACE WHILE LPAR assign-expr RPAR
;

while-stmt:
	WHILE LPAR expr RPAR LBRACE line RBRACE
|	WHILE LPAR assign-expr RPAR LBRACE line RBRACE
;

if-stmt:
	IF LPAR expr RPAR LBRACE line RBRACE
|	IF LPAR expr RPAR LBRACE line RBRACE ELSE LBRACE line RBRACE
|	IF LPAR expr RPAR LBRACE line RBRACE ELSE stmt
|	IF LPAR assign-expr RPAR LBRACE line RBRACE
|	IF LPAR assign-expr RPAR LBRACE line RBRACE ELSE LBRACE line RBRACE
|	IF LPAR assign-expr RPAR LBRACE line RBRACE ELSE stmt
;

logic-expr:
	expr EQ expr
|	expr EQ_STRICT expr
|	expr INEQ expr
|	expr INEQ_STRICT expr
|	expr LT expr
|	ID LT expr
|	expr LT_EQ expr
|	expr GT expr
|	expr GT_EQ expr
|	expr LOGICAL_NULL expr
|	expr LOGICAL_AND expr
|	expr LOGICAL_OR expr
;

class-def:
	CLASS ID LBRACE class-att-list RBRACE
;

class-att-list:
	SEMI class-att-list
|	class-att SEMI class-att-list
|	class-att
|	%empty
;

class-att:
	ID COLON var-type
|	access-modif ID COLON var-type
|	ID LPAR params RPAR LBRACE line RBRACE
|	ID LPAR params RPAR COLON var-type LBRACE line RBRACE
;

access-modif:
	PUBLIC
|	PRIVATE
|	PROTECTED
;

func-def:
	FUNCTION ID { debug("FUNCAAOOOOOO--->1"); } LPAR params RPAR LBRACE line RBRACE
|	FUNCTION ID { debug("FUNCAOOOOOOOO--->2"); } LPAR params RPAR COLON var-type LBRACE line RBRACE
;

params:
	COMMA ID
|	COMMA ID COLON var-type
|	ID COMMA ID
|	ID COLON var-type  COMMA ID COLON var-type
|	ID COLON var-type  COMMA ID
|	ID COLON var-type
|	ID COMMA  ID COLON var-type
|	%empty
;

var-declr:
	LET id-list
|	LET id-list ASSIGN expr 									{ new_var($<tupla.name>2, $<tupla.line>2, UNKNOWN_TYPE); }
|	LET id-list ASSIGN obj-def
|	LET ID COLON var-type 
|	LET ID COLON var-type ASSIGN expr 
|	LET ID COLON var-type LBRACKET RBRACKET 
|	LET ID COLON var-type LBRACKET RBRACKET ASSIGN expr 
|	VAR id-list
|	VAR id-list ASSIGN expr 
|	VAR id-list ASSIGN obj-def 
|	VAR ID COLON var-type 
|	VAR ID COLON var-type ASSIGN expr 
|	VAR ID COLON var-type LBRACKET RBRACKET 
|	VAR ID COLON var-type LBRACKET RBRACKET ASSIGN expr 
|	CONST_RW id-list ASSIGN expr 
|	CONST_RW ID COLON var-type ASSIGN expr 
|	CONST_RW ID COLON var-type LBRACKET RBRACKET ASSIGN expr 
|	CONST_RW id-list ASSIGN obj-def 
;

id-list:
	ID COMMA id-list
|	ID
;

obj-def:
	LBRACE obj-att-list RBRACE
;

obj-att-list:
	COMMA obj-att-list
|	obj-att COMMA obj-att-list
|	obj-att
|	%empty
;

obj-att:
	ID COLON var-val
;

var-type:
	NUMBER
|	STRING
|	UNKNOWN
|	BOOLTYPE
|	ANY
|	VOID_RW
|	NEVER
;

expr:
	idx-safe-expr  	{ debug("expr-1"); } 
|	idx-unsafe-expr { debug("expr-2"); }
|	LPAR expr RPAR  { debug("expr-3"); }
;

idx-unsafe-expr:
	array-expr
|	logic-expr
|	var-obj
;

idx-safe-expr:
	var-val			{ debug("idx-safe-expr-1"); } 
|	var-att
|	arit-expr
|	bitw-expr
|	shift-expr
|	unary-expr
|	vet-idx
|	ID %prec E_ID
;

vet-idx:
	ID LBRACKET idx-safe-expr RBRACKET
;

unary-expr:
	INCREMENT ID
|	INCREMENT var-att
|	DECREMENT ID
|	DECREMENT var-att
|	ID INCREMENT
|	var-att INCREMENT
|	ID DECREMENT
|	var-att DECREMENT
|	LOGICAL_NOT expr
|	BITWISE_NOT expr
;

arit-expr:
	expr PLUS expr
|	expr SUB expr
|	expr MULT expr
|	expr DIV expr
|	expr EXP expr
|	expr REM expr
;

bitw-expr:
	expr BITWISE_AND expr
|	expr BITWISE_OR expr
|	expr BITWISE_XOR expr
;

shift-expr:
	expr LSHIFT expr
|	expr RSHIFT expr
|	expr RSHIFT_UNSIGNED expr
;

var-att:
	ID DOT var-att
|	var-att DOT ID
|	ID DOT var-met
|	var-met DOT ID
|	var-met DOT var-att
|	var-att DOT var-met
|	ID DOT ID
;

var-met:
	ID LPAR args-list RPAR
;

args-list:
	COMMA args-list
|	expr COMMA args-list
|	assign-expr COMMA args-list
|	expr
|	assign-expr
|	%empty
;

var-obj:
	ID LPAR args-list RPAR
|	ID LT var-type GT LPAR args-list RPAR
|	NEW ID LPAR args-list RPAR
|	NEW ID LT var-type GT LPAR args-list RPAR
;

var-val:
	INT_VAL  	{ debug("var-val-1"); }
|	REAL_VAL
|	STR_VAL
|	TRUE_RW
|	FALSE_RW
|	SUB INT_VAL
|	SUB REAL_VAL
|	SUB STR_VAL
|	SUB TRUE_RW
|	SUB FALSE_RW
|	NULL_RW
|	UNDEFINED
;

array-expr:
	LBRACKET elmts-list RBRACKET
;

elmts-list:
	COMMA elmts-list
|	var-val COMMA elmts-list
|	var-val
|	%empty
;

%%

void debug(char* text) {
	printf("DEBUG: %s \t\t yytext:%s\n", text, yytext);	
}

void check_var(char* name) {

    int idx = varExist(vt, name);

	printf("(---Check var---) => \t yytext: %s | \t name: %s | \t idx: %d\n",
			yytext, name, idx);

    if (idx == 0) {
        printf("SEMANTIC ERROR (%d): variable '%s' was not declared.\n",
                yylineno, name);
        exit(EXIT_FAILURE);
    }
}

void new_var(char* name, int line, Type type) {

	printf("(---Add var---) => yytext: %s | \t\t name: %s \t\tline:%d \n",
			yytext, name, line);

    struct node* item = findVar(&vt, name);

    if (item != NULL) {
        printf("SEMANTIC ERROR (%d): variable '%s' already declared at line %d.\n",
        		line, name, getLine(item));
        exit(EXIT_FAILURE);
    }

    addVar(&vt, line, name, type);
}

void add_type(char* name, Type type) {
	changeVarType(&vt, name, type);
	printf("Add type->> %s \t\t var_ant->>%s\n", get_text(type), name);
}

void yyerror(char const* s) {
	printf("SYNTAX ERROR (%d): %s\n", yylineno, s);
	exit(EXIT_FAILURE);
}

int main(void) {

	st = createStrTable();
    vt = createVarTable();

	if (yyparse() == 0)
		printf("Parse successful\n");
	
    printVars(vt);
	printStrs(st);

    freeVars(&vt);
    freeStrs(&st);

    yylex_destroy();

	return 0;
}