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
int yylex_destroy(void);

void check_var(char*);
void new_var(char*, int, Type);
void debug(char*);
void add_type(char*, Type);
void type_error(char*, Type, Type);

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
		Type type;
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
	var-declr SEMI 			{ debug("stmt-1"); }
|	func-def 				{ debug("stmt-2"); }
|	class-def
|	expr SEMI				{ debug("stmt-4"); }
|	assign-expr SEMI		{ debug("stmt-5"); }
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
|	ID assignment expr			{ debug("assign-expr-2");
									check_var($<tupla.name>1); }
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
	FUNCTION ID LPAR params RPAR LBRACE line RBRACE					{ debug("func-def-1");
																		/*new_var($<tupla.name>2, $<tupla.line>2, FUNCTION_TYPE);*/ }
|	FUNCTION ID LPAR params RPAR COLON var-type LBRACE line RBRACE	{ debug("func-def-2");
																		/*new_var($<tupla.name>2, $<tupla.line>2, FUNCTION_TYPE);*/ }
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
	LET id-list												{ debug("var-declr-1");
																new_var($<tupla.name>2, $<tupla.line>2, UNKNOWN_TYPE); }
|	LET id-list ASSIGN expr									{ debug("var-declr-2");
																new_var($<tupla.name>2, $<tupla.line>2, $<tupla.type>4); }
|	LET id-list ASSIGN obj-def

|	LET ID COLON var-type 									{ debug("var-declr-4");
																new_var($<tupla.name>2, $<tupla.line>2, $<tupla.type>4); }
|	LET ID COLON var-type ASSIGN expr						{ debug("var-declr-5");
																new_var($<tupla.name>2, $<tupla.line>2, $<tupla.type>4); }
|	LET ID COLON var-type LBRACKET RBRACKET

|	LET ID COLON var-type LBRACKET RBRACKET ASSIGN expr

|	VAR id-list												{ debug("var-declr-8");
																new_var($<tupla.name>2, $<tupla.line>2, UNKNOWN_TYPE); }
|	VAR id-list ASSIGN expr									{ debug("var-declr-9");
																new_var($<tupla.name>2, $<tupla.line>2, $<tupla.type>4); }
|	VAR id-list ASSIGN obj-def

|	VAR ID COLON var-type 									{ debug("var-declr-4");
																new_var($<tupla.name>2, $<tupla.line>2, $<tupla.type>4); }
|	VAR ID COLON var-type ASSIGN expr						{ debug("var-declr-12");
																new_var($<tupla.name>2, $<tupla.line>2, $<tupla.type>4); }
|	VAR ID COLON var-type LBRACKET RBRACKET

|	VAR ID COLON var-type LBRACKET RBRACKET ASSIGN expr

|	CONST_RW id-list ASSIGN expr							{ debug("var-declr-15");
																new_var($<tupla.name>2, $<tupla.line>2, $<tupla.type>4); }
|	CONST_RW ID COLON var-type ASSIGN expr					{ debug("var-declr-16");
																new_var($<tupla.name>2, $<tupla.line>2, $<tupla.type>4); }
|	CONST_RW ID COLON var-type LBRACKET RBRACKET ASSIGN expr

|	CONST_RW id-list ASSIGN obj-def
;

id-list:
	ID COMMA id-list
|	ID					{ debug("var-declr-2"); }
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
	NUMBER		{ debug("var-type-1"); $<tupla.type>$ = NUMBER_TYPE; }
|	STRING		{ debug("var-type-2"); $<tupla.type>$ = STRING_TYPE; }
|	UNKNOWN		{ debug("var-type-3"); $<tupla.type>$ = UNKNOWN_TYPE; }
|	BOOLTYPE	{ debug("var-type-4"); $<tupla.type>$ = BOOLEAN_TYPE; }
|	ANY			{ debug("var-type-5"); $<tupla.type>$ = ANY_TYPE; }
|	VOID_RW		{ debug("var-type-6"); $<tupla.type>$ = VOID_TYPE; }
|	NEVER		{ debug("var-type-7"); $<tupla.type>$ = NEVER_TYPE; }
;

expr:
	idx-safe-expr  	{ debug("expr-1"); }
|	idx-unsafe-expr { debug("expr-2"); }
|	LPAR expr RPAR  { debug("expr-3"); $<tupla>$ = $<tupla>2; }
;

idx-unsafe-expr:
	array-expr		{ debug("idx-unsafe-expr-1"); }
|	logic-expr		{ debug("idx-unsafe-expr-2"); }
|	var-obj			{ debug("idx-unsafe-expr-3"); }
;

idx-safe-expr:
	var-val			{ debug("idx-safe-expr-1"); }
|	var-att			{ debug("idx-safe-expr-2"); }
|	arit-expr		{ debug("idx-safe-expr-3"); }
|	bitw-expr		{ debug("idx-safe-expr-4"); }
|	shift-expr		{ debug("idx-safe-expr-5"); }
|	unary-expr		{ debug("idx-safe-expr-6"); }
|	vet-idx			{ debug("idx-safe-expr-7"); }
|	ID %prec E_ID	{ debug("idx-safe-expr-8");
						check_var($<tupla.name>1); }
;

vet-idx:
	ID LBRACKET idx-safe-expr RBRACKET
;

unary-expr:

	INCREMENT ID			{ debug("unary-expr-1");
								check_var($<tupla.name>2); }
|	INCREMENT var-att

|	DECREMENT ID			{ debug("unary-expr-3");
								check_var($<tupla.name>2); }
|	DECREMENT var-att

|	ID INCREMENT			{ debug("unary-expr-5");
								check_var($<tupla.name>1); }
|	var-att INCREMENT

|	ID DECREMENT			{ debug("unary-expr-7");
								check_var($<tupla.name>1); }
|	var-att DECREMENT

|	LOGICAL_NOT expr

|	BITWISE_NOT expr
;

arit-expr:
	expr PLUS expr
|	expr SUB expr		{ debug("arit-expr-2"); }
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
	INT_VAL			{ debug("var-val-1"); $<tupla.type>$ = NUMBER_TYPE; }
|	REAL_VAL		{ debug("var-val-2"); $<tupla.type>$ = NUMBER_TYPE; }
|	STR_VAL			{ debug("var-val-3"); $<tupla.type>$ = STRING_TYPE; }
|	TRUE_RW			{ debug("var-val-4"); $<tupla.type>$ = BOOLEAN_TYPE; }
|	FALSE_RW		{ debug("var-val-5"); $<tupla.type>$ = BOOLEAN_TYPE; }
|	SUB INT_VAL		{ debug("var-val-6"); $<tupla.type>$ = NUMBER_TYPE; }
|	SUB REAL_VAL	{ debug("var-val-7"); $<tupla.type>$ = NUMBER_TYPE; }
|	SUB STR_VAL		{ debug("var-val-8"); $<tupla.type>$ = STRING_TYPE; }
|	SUB TRUE_RW		{ debug("var-val-9"); $<tupla.type>$ = BOOLEAN_TYPE; }
|	SUB FALSE_RW	{ debug("var-val-10"); $<tupla.type>$ = BOOLEAN_TYPE; }
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
	printf("DEBUG\t%s\n", text);	
}

void check_var(char* name) {

    struct node* item = findVar(vt, name);

	printf("CHECK_VAR\tyylineno: %d,\tname: %s\n", yylineno, name);

    if (item == NULL) {
        printf("SEMANTIC ERROR (%d): variable '%s' was not declared.\n", yylineno, name);
        exit(EXIT_FAILURE);
    }
}

void new_var(char* name, int line, Type type) {

	printf("NEW_VAR\t\tyylineno: %d,\tname: %s,\tline: %d,\ttype: %s\n", yylineno, name, line, get_text(type));

    struct node* item = findVar(vt, name);

    if (item != NULL) {
        printf("SEMANTIC ERROR (%d): variable '%s' already declared at line %d.\n",
        		line, name, getLine(item));
        exit(EXIT_FAILURE);
    }

    addVar(&vt, line, name, type);
}

void add_type(char* name, Type type) {
	printf("ADD_TYPE\t\t%s\tname: %s\n", get_text(type), name);
	changeVarType(vt, name, type);
}

void check_assign(Type left, Type right) {

	// Com referencia ao lado esquerdo, verifica se o direito eh um tipo aceito para atribuicao.
    if ( left == NUMBER_TYPE && !(right == NUMBER_TYPE || right == ANY_TYPE) ) type_error("=", left, right);
    if ( left == STRING_TYPE &&
         !(right == STRING_TYPE || right == ANY_TYPE || right == NEVER_TYPE) ) type_error("=", left, right);
    if ( left == UNKNOWN_TYPE && 1 ) type_error("=", left, right);
	// Continuar
}

void type_error(char* op, Type left, Type right) {

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