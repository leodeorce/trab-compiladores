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
	var-declr SEMI					{ debug("stmt", 1); }
|	func-def						{ debug("stmt", 2); }
|	class-def						{ debug("stmt", 3); }
|	expr SEMI						{ debug("stmt", 4); }
|	assign-expr SEMI				{ debug("stmt", 5); }
|	if-stmt							{ debug("stmt", 6); }
|	while-stmt						{ debug("stmt", 7); }
|	do-while-stmt					{ debug("stmt", 8); }
|	for-stmt						{ debug("stmt", 9); }
|	RETURN SEMI						{ debug("stmt", 10); }
|	RETURN expr SEMI				{ debug("stmt", 11); }
|	BREAK SEMI						{ debug("stmt", 12); }
|	CONTINUE SEMI					{ debug("stmt", 13); }
;

assign-expr:
	var-att assignment expr			{ debug("assign-expr", 1); }
|	ID assignment expr				{ debug("assign-expr", 2); }
|	vet-idx assignment expr			{ debug("assign-expr", 3); }
;

for-stmt:
	FOR LPAR assign-expr SEMI expr SEMI expr RPAR LBRACE line RBRACE				{ debug("for-stmt", 1); }
|	FOR LPAR assign-expr SEMI expr SEMI assign-expr RPAR LBRACE line RBRACE			{ debug("for-stmt", 2); }
|	FOR LPAR assign-expr SEMI expr SEMI RPAR LBRACE line RBRACE						{ debug("for-stmt", 3); }
|	FOR LPAR assign-expr SEMI SEMI expr RPAR LBRACE line RBRACE						{ debug("for-stmt", 4); }
|	FOR LPAR assign-expr SEMI SEMI assign-expr RPAR LBRACE line RBRACE				{ debug("for-stmt", 5); }
|	FOR LPAR assign-expr SEMI SEMI RPAR LBRACE line RBRACE							{ debug("for-stmt", 6); }
|	FOR LPAR var-declr SEMI expr SEMI expr RPAR LBRACE line RBRACE					{ debug("for-stmt", 7); }
|	FOR LPAR var-declr SEMI expr SEMI assign-expr RPAR LBRACE line RBRACE			{ debug("for-stmt", 8); }
|	FOR LPAR var-declr SEMI expr SEMI RPAR LBRACE line RBRACE						{ debug("for-stmt", 9); }
|	FOR LPAR var-declr SEMI SEMI expr RPAR LBRACE line RBRACE						{ debug("for-stmt", 10); }
|	FOR LPAR var-declr SEMI SEMI assign-expr RPAR LBRACE line RBRACE				{ debug("for-stmt", 11); }
|	FOR LPAR var-declr SEMI SEMI RPAR LBRACE line RBRACE							{ debug("for-stmt", 12); }
|	FOR LPAR SEMI expr SEMI expr RPAR LBRACE line RBRACE							{ debug("for-stmt", 13); }
|	FOR LPAR SEMI expr SEMI assign-expr RPAR LBRACE line RBRACE						{ debug("for-stmt", 14); }
|	FOR LPAR SEMI expr SEMI RPAR LBRACE line RBRACE									{ debug("for-stmt", 15); }
|	FOR LPAR SEMI SEMI expr RPAR LBRACE line RBRACE									{ debug("for-stmt", 16); }
|	FOR LPAR SEMI SEMI assign-expr RPAR LBRACE line RBRACE							{ debug("for-stmt", 17); }
|	FOR LPAR SEMI SEMI RPAR LBRACE line RBRACE										{ debug("for-stmt", 18); }
;

assignment:
	ASSIGN							{ debug("assignment", 1); }
|	LOGICAL_NULL_ASSIGN				{ debug("assignment", 2); }
|	LOGICAL_AND_ASSIGN				{ debug("assignment", 3); }
|	LOGICAL_OR_ASSIGN				{ debug("assignment", 4); }
|	PLUS_ASSIGN						{ debug("assignment", 5); }
|	SUB_ASSIGN						{ debug("assignment", 6); }
|	MULT_ASSIGN						{ debug("assignment", 7); }
|	DIV_ASSIGN						{ debug("assignment", 8); }
|	EXP_ASSIGN						{ debug("assignment", 9); }
|	REM_ASSIGN						{ debug("assignment", 10); }
|	BITWISE_AND_ASSIGN				{ debug("assignment", 11); }
|	BITWISE_OR_ASSIGN				{ debug("assignment", 12); }
|	BITWISE_XOR_ASSIGN				{ debug("assignment", 13); }
|	LSHIFT_ASSIGN					{ debug("assignment", 14); }
|	RSHIFT_ASSIGN					{ debug("assignment", 15); }
|	RSHIFT_UNSIGNED_ASSIGN			{ debug("assignment", 16); }
;

do-while-stmt:
	DO LBRACE line RBRACE WHILE LPAR expr RPAR		{ debug("do-while-stmt", 1); }
;

while-stmt:
	WHILE LPAR expr RPAR LBRACE line RBRACE		{ debug("while-stmt", 1); }
;

if-stmt:
	IF LPAR expr RPAR LBRACE line RBRACE								{ debug("if-stmt", 1); }
|	IF LPAR expr RPAR LBRACE line RBRACE ELSE LBRACE line RBRACE		{ debug("if-stmt", 2); }
|	IF LPAR expr RPAR LBRACE line RBRACE ELSE stmt						{ debug("if-stmt", 3); }
;

logic-expr:
	expr EQ expr								{ debug("logic-expr", 1); }
|	expr EQ_STRICT expr							{ debug("logic-expr", 2); }
|	expr INEQ expr								{ debug("logic-expr", 3); }
|	expr INEQ_STRICT expr						{ debug("logic-expr", 4); }
|	expr LT expr								{ debug("logic-expr", 5); }
|	ID LT expr									{ debug("logic-expr", 6); }
|	expr LT_EQ expr								{ debug("logic-expr", 7); }
|	expr GT expr								{ debug("logic-expr", 8); }
|	expr GT_EQ expr								{ debug("logic-expr", 9); }
|	expr LOGICAL_NULL expr						{ debug("logic-expr", 10); }
|	expr LOGICAL_AND expr						{ debug("logic-expr", 11); }
|	expr LOGICAL_OR expr						{ debug("logic-expr", 12); }
;

class-def:
	CLASS ID LBRACE class-att-list RBRACE		{ debug("class-def", 1); }
;

class-att-list:
	SEMI class-att-list					{ debug("class-att-list", 1); }
|	class-att SEMI class-att-list		{ debug("class-att-list", 2); }
|	class-att							{ debug("class-att-list", 3); }
|	%empty								{ debug("class-att-list", 4); }
;

class-att:
	ID COLON var-type											{ debug("class-att", 1); }
|	access-modif ID COLON var-type								{ debug("class-att", 2); }
|	ID LPAR params RPAR LBRACE line RBRACE						{ debug("class-att", 3); }
|	ID LPAR params RPAR COLON var-type LBRACE line RBRACE		{ debug("class-att", 4); }
;

access-modif:
	PUBLIC			{ debug("access-modif", 1); }
|	PRIVATE			{ debug("access-modif", 2); }
|	PROTECTED		{ debug("access-modif", 3); }
;

func-def:
	FUNCTION ID LPAR params RPAR LBRACE line RBRACE										{ debug("func-def", 1); }
|	FUNCTION ID LPAR params RPAR COLON var-type LBRACE line RBRACE						{ debug("func-def", 2); }
;

params:
	COMMA ID										{ debug("params", 1); }
|	COMMA ID COLON var-type							{ debug("params", 2); }
|	ID COMMA ID										{ debug("params", 3); }
|	ID COLON var-type COMMA ID COLON var-type		{ debug("params", 4); }
|	ID COLON var-type COMMA ID						{ debug("params", 5); }
|	ID COLON var-type								{ debug("params", 6); }
|	ID COMMA ID COLON var-type						{ debug("params", 7); }
|	%empty											{ debug("params", 8); }
;

var-declr:
	LET id-list													{ debug("var-declr", 1); }
|	LET id-list ASSIGN expr										{ debug("var-declr", 2); }
|	LET id-list ASSIGN obj-def									{ debug("var-declr", 3); }
|	LET ID COLON var-type										{ debug("var-declr", 4); }
|	LET ID COLON var-type ASSIGN expr							{ debug("var-declr", 5); }
|	LET ID COLON var-type LBRACKET RBRACKET						{ debug("var-declr", 6); }
|	LET ID COLON var-type LBRACKET RBRACKET ASSIGN expr			{ debug("var-declr", 7); }
|	VAR id-list													{ debug("var-declr", 8); }
|	VAR id-list ASSIGN expr										{ debug("var-declr", 9); }
|	VAR id-list ASSIGN obj-def									{ debug("var-declr", 10); }
|	VAR ID COLON var-type										{ debug("var-declr", 11); }
|	VAR ID COLON var-type ASSIGN expr							{ debug("var-declr", 12); }
|	VAR ID COLON var-type LBRACKET RBRACKET						{ debug("var-declr", 13); }
|	VAR ID COLON var-type LBRACKET RBRACKET ASSIGN expr			{ debug("var-declr", 14); }
|	CONST_RW id-list ASSIGN expr								{ debug("var-declr", 15); }
|	CONST_RW ID COLON var-type ASSIGN expr						{ debug("var-declr", 16); }
|	CONST_RW ID COLON var-type LBRACKET RBRACKET ASSIGN expr	{ debug("var-declr", 17); }
|	CONST_RW id-list ASSIGN obj-def								{ debug("var-declr", 18); }
;

id-list:
	ID COMMA id-list				{ debug("id-list", 1); }
|	ID								{ debug("id-list", 2); }
;

obj-def:
	LBRACE obj-att-list RBRACE			{ debug("obj-def", 1); }
;

obj-att-list:
	COMMA obj-att-list					{ debug("obj-att-list", 1); }
|	obj-att COMMA obj-att-list			{ debug("obj-att-list", 2); }
|	obj-att								{ debug("obj-att-list", 3); }
|	%empty								{ debug("obj-att-list", 4); }
;

obj-att:
	ID COLON var-val					{ debug("obj-att", 1); }
;

var-type:
	NUMBER						{ debug("var-type", 1); }
|	STRING						{ debug("var-type", 2); }
|	UNKNOWN						{ debug("var-type", 3); }
|	BOOLTYPE					{ debug("var-type", 4); }
|	ANY							{ debug("var-type", 5); }
|	VOID_RW						{ debug("var-type", 6); }
|	NEVER						{ debug("var-type", 7); }
;

expr:
	idx-safe-expr		{ debug("expr", 1); }
|	idx-unsafe-expr		{ debug("expr", 2); }
|	LPAR expr RPAR		{ debug("expr", 3); }
;

idx-unsafe-expr:
	array-expr			{ debug("idx-unsafe-expr", 1); }
|	logic-expr			{ debug("idx-unsafe-expr", 2); }
|	var-obj				{ debug("idx-unsafe-expr", 3); }
;

idx-safe-expr:
	var-val				{ debug("idx-safe-expr", 1); }
|	var-att				{ debug("idx-safe-expr", 2); }
|	arit-expr			{ debug("idx-safe-expr", 3); }
|	bitw-expr			{ debug("idx-safe-expr", 4); }
|	shift-expr			{ debug("idx-safe-expr", 5); }
|	unary-expr			{ debug("idx-safe-expr", 6); }
|	vet-idx				{ debug("idx-safe-expr", 7); }
|	ID %prec E_ID		{ debug("idx-safe-expr", 8); }
;

vet-idx:
	ID LBRACKET idx-safe-expr RBRACKET		{ debug("vet-idx", 1); }
;

unary-expr:
	INCREMENT ID			{ debug("unary-expr", 1); }
|	INCREMENT var-att		{ debug("unary-expr", 2); }
|	DECREMENT ID			{ debug("unary-expr", 3); }
|	DECREMENT var-att		{ debug("unary-expr", 4); }
|	ID INCREMENT			{ debug("unary-expr", 5); }
|	var-att INCREMENT		{ debug("unary-expr", 6); }
|	ID DECREMENT			{ debug("unary-expr", 7); }
|	var-att DECREMENT		{ debug("unary-expr", 8); }
|	LOGICAL_NOT expr		{ debug("unary-expr", 9); }
|	BITWISE_NOT expr		{ debug("unary-expr", 10); }
;

arit-expr:
	expr PLUS expr			{ debug("arit-expr", 1); }
|	expr SUB expr			{ debug("arit-expr", 2); }
|	expr MULT expr			{ debug("arit-expr", 3); }
|	expr DIV expr			{ debug("arit-expr", 4); }
|	expr EXP expr			{ debug("arit-expr", 5); }
|	expr REM expr			{ debug("arit-expr", 6); }
;

bitw-expr:
	expr BITWISE_AND expr			{ debug("bitw-expr", 1); }
|	expr BITWISE_OR expr			{ debug("bitw-expr", 2); }
|	expr BITWISE_XOR expr			{ debug("bitw-expr", 3); }
;

shift-expr:
	expr LSHIFT expr				{ debug("shift-expr", 1); }
|	expr RSHIFT expr				{ debug("shift-expr", 2); }
|	expr RSHIFT_UNSIGNED expr		{ debug("shift-expr", 3); }
;

var-att:
	ID DOT var-att				{ debug("var-att", 1); }
|	var-att DOT ID				{ debug("var-att", 2); }
|	ID DOT var-met				{ debug("var-att", 3); }
|	var-met DOT ID				{ debug("var-att", 4); }
|	var-met DOT var-att			{ debug("var-att", 5); }
|	var-att DOT var-met			{ debug("var-att", 6); }
|	ID DOT ID					{ debug("var-att", 7); }
;

var-met:
	ID LPAR args-list RPAR		{ debug("var-met", 1); }
;

args-list:
	COMMA args-list					{ debug("args-list", 1); }
|	expr COMMA args-list			{ debug("args-list", 2); }
|	expr							{ debug("args-list", 3); }
|	%empty							{ debug("args-list", 4); }
;

var-obj:
	ID LPAR args-list RPAR									{ debug("var-obj", 1); }
|	ID LT var-type GT LPAR args-list RPAR					{ debug("var-obj", 2); }
|	NEW ID LPAR args-list RPAR								{ debug("var-obj", 3); }
|	NEW ID LT var-type GT LPAR args-list RPAR				{ debug("var-obj", 4); }
;

var-val:
	INT_VAL								{ debug("var-val", 1); }
|	REAL_VAL							{ debug("var-val", 2); }
|	STR_VAL								{ debug("var-val", 3); }
|	TRUE_RW								{ debug("var-val", 4); }
|	FALSE_RW							{ debug("var-val", 5); }
|	SUB INT_VAL							{ debug("var-val", 6); }
|	SUB REAL_VAL						{ debug("var-val", 7); }
|	SUB STR_VAL							{ debug("var-val", 8); }
|	SUB TRUE_RW							{ debug("var-val", 9); }
|	SUB FALSE_RW						{ debug("var-val", 10); }
|	NULL_RW								{ debug("var-val", 11); }
|	UNDEFINED							{ debug("var-val", 12); }
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