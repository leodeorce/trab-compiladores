%output "parser.c"
%defines "parser.h"
%define parse.error verbose
%define parse.lac full

%{

#include <stdio.h>
#include <stdlib.h>

int yylex(void);
void yyerror(char const*);
void debug(char*, int);

int yylineno;

%}

%token ASSIGN ARROW COMMA SEMI COLON TERNARY CHAIN PIPELINE DOT SPREAD PLUS INCREMENT PLUS_ASSIGN SUB DECREMENT SUB_ASSIGN MULT MULT_ASSIGN DIV DIV_ASSIGN EXP EXP_ASSIGN REM REM_ASSIGN BITWISE_NOT BITWISE_AND BITWISE_AND_ASSIGN BITWISE_OR BITWISE_OR_ASSIGN BITWISE_XOR BITWISE_XOR_ASSIGN LOGICAL_NOT LOGICAL_NULL LOGICAL_NULL_ASSIGN LOGICAL_AND LOGICAL_AND_ASSIGN LOGICAL_OR LOGICAL_OR_ASSIGN EQ EQ_STRICT INEQ INEQ_STRICT LT LT_EQ GT GT_EQ LSHIFT LSHIFT_ASSIGN RSHIFT RSHIFT_ASSIGN RSHIFT_UNSIGNED RSHIFT_UNSIGNED_ASSIGN LPAR RPAR LBRACE RBRACE LBRACKET RBRACKET INT_VAL REAL_VAL STR_VAL ID	BREAK CASE CATCH CLASS CONST_RW CONTINUE DEBUGGER DEFAULT DELETE DO ELSE ENUM EXPORT EXTENDS FALSE_RW FINALLY FOR FUNCTION IF IMPLEMENTS IMPORT IN INSTANCEOF INTERFACE LET NEW NULL_RW PACKAGE PRIVATE PROTECTED PUBLIC RETURN SUPER SWITCH THIS THROW TRUE_RW TRY TYPEOF VAR VOID_RW WHILE WITH AWAIT YIELD STATIC AS ASYNC FROM GET OF SET TARGET ANY BOOLTYPE CONSTRUCTOR DECLARE MODULE REQUIRE NEVER NUMBER STRING SYMBOL TYPE UNDEFINED UNKNOWN

/*%right	EQ EQ_STRICT INEQ INEQ_STRICT LT LT_EQ GT GT_EQ
%left	PLUS SUB
%left	MULT DIV REM
%right	EXP*/

%%

line:
	stmt-list					{ debug("line", 1); }
|	%empty						{ debug("line", 2); }
;

stmt-list:
	stmt-list stmt 				{ debug("stmt-list", 1); }
|	stmt						{ debug("stmt-list", 2); }
;

stmt:
	let-stmt					{ debug("stmt", 1); }
|	var-stmt					{ debug("stmt", 2); }
;

let-stmt:
	LET ID SEMI														{ debug("let-stmt", 1); }
|	LET ID ASSIGN expr SEMI											{ debug("let-stmt", 2); }
|	LET ID COLON var-type SEMI										{ debug("let-stmt", 3); }
|	LET ID COLON var-type ASSIGN expr SEMI							{ debug("let-stmt", 4); }
|	LET ID COLON var-type LBRACKET RBRACKET SEMI					{ debug("let-stmt", 5); }
|	LET ID COLON var-type LBRACKET RBRACKET ASSIGN expr SEMI		{ debug("let-stmt", 6); }
;

var-type:
	NUMBER						{ debug("var-type", 1); }
|	STRING						{ debug("var-type", 2); }
|	UNKNOWN						{ debug("var-type", 3); }
|	BOOLTYPE					{ debug("var-type", 4); }
|	ANY							{ debug("var-type", 5); }
|	VOID_RW						{ debug("var-type", 6); }
|	NULL_RW						{ debug("var-type", 7); }
|	UNDEFINED					{ debug("var-type", 8); }
|	NEVER						{ debug("var-type", 9); }
;

var-stmt:
	VAR ID ASSIGN expr SEMI		{ debug("var-stmt", 1); }
;

expr:
	array-expr				{ debug("expr", 1); }
|	var-val					{ debug("expr", 2); }
|	obj-declr				{ debug("expr", 3); }
;

obj-declr:
	ID LPAR elmts-list RPAR							{ debug("obj-declr", 1); }
|	ID LT var-type GT LPAR elmts-list RPAR			{ debug("obj-declr", 2); }
|	NEW ID LPAR elmts-list RPAR						{ debug("obj-declr", 3); }
|	NEW ID LT var-type GT LPAR elmts-list RPAR		{ debug("obj-declr", 4); }
;

var-val:
	INT_VAL								{ debug("var-val", 1); }
|	REAL_VAL							{ debug("var-val", 2); }
|	STR_VAL								{ debug("var-val", 3); }
|	TRUE_RW								{ debug("var-val", 4); }
|	FALSE_RW							{ debug("var-val", 5); }
|	NULL_RW								{ debug("var-val", 6); }
|	UNDEFINED							{ debug("var-val", 7); }
;

array-expr:
	LBRACKET elmts-list RBRACKET		{ debug("array-expr", 1); }
;

elmts-list:
	COMMA elmts-list					{ debug("elmts-list", 1); }
|	var-val COMMA elmts-list			{ debug("elmts-list", 2); }
|	var-val								{ debug("elmts-list", 3); }
|	%empty								{ debug("elmts-list", 4); }
;

%%

void debug(char* nonT, int item)
{
	printf("Linha %d Non-T \"%s\" item %d\n", yylineno, nonT, item);
}

void yyerror(char const* s)
{
	printf("SYNTAX ERROR (%d): %s\n", yylineno, s);
	exit(EXIT_FAILURE);
}

int main(void)
{
	if (yyparse() == 0)
		printf("Parse successful\n");

	return 0;
}