%option outfile="scanner.c"
%option noyywrap
%option nounput
%option noinput
%option yylineno

%{

#include <stdio.h>
#include "types.h"
#include "list.h"
#include "tupla.h"
#include "ast.h"
#include "parser.h"

void erro_lexico();

extern Str_table *st;
extern void change_node(Tupla*, AST*);
extern AST* tupla_get_node(Tupla*);

%}

%x comment

int_val     		[0-9]+
real_val    		[0-9]+"."[0-9]+
str_quotes_val     	\"[^"]*\"
str_apost_val     	\'[^']*\'
str_crasis_val     	\`[^`]*\`

id          	[a-zA-Z$_]+[a-zA-Z0-9$_]*

whitespace      [ \t\n]+
comment			"//"+.*

%%

	/* Ignorados */

"/*"					{ BEGIN(comment); }
<comment>[^*\n]*		{ /* Fazer nada */ }
<comment>"*"+[^*/\n]*	{ /* Fazer nada */ }
<comment>\n				{ /* Fazer nada */ }
<comment>"*"+"/"		{ BEGIN(INITIAL); }

{whitespace}			{ /* Fazer nada */ }
{comment}				{ /* Fazer nada */ }


	/* Palavras reservadas */

"break" 			{ return BREAK; }
"case"  			{ return CASE; }
"catch" 			{ return CATCH; }
"class" 			{ return CLASS; }
"const" 			{ return CONST_RW; }
"continue" 			{ return CONTINUE; }
"debugger" 			{ return DEBUGGER; }
"default" 			{ return DEFAULT; }
"delete" 			{ return DELETE; }
"do"  			    { return DO; }
"else"  			{ return ELSE; }
"enum"  			{ return ENUM; }
"export"  			{ return EXPORT; }
"extends"  			{ return EXTENDS; }

"false"  			{ yylval = new_tupla(NULL, yylineno,
					      BOOLEAN_TYPE, new_node(BOOL_VAL_NODE, 0, BOOLEAN_TYPE));
					  return FALSE_RW; }

"finally"  			{ return FINALLY; }
"for"  			    { return FOR; }
"function"  		{ return FUNCTION; }
"if"  			    { return IF; }
"implements" 		{ return IMPLEMENTS; }
"import"  			{ return IMPORT; }
"in"  			    { return IN; }
"instanceof"  		{ return INSTANCEOF; }
"interface" 		{ return INTERFACE; }
"let"  				{ return LET; }
"new"  			    { return NEW; }
"null"  			{ return NULL_RW; }
"package" 			{ return PACKAGE; }
"private" 			{ return PRIVATE; }
"protected" 		{ return PROTECTED; }
"public" 			{ return PUBLIC; }
"return"  			{ return RETURN; }
"super"  			{ return SUPER; }
"switch"  			{ return SWITCH; }
"this"  			{ return THIS; }
"throw"  			{ return THROW; }

"true"  			{ yylval = new_tupla(NULL, yylineno,
					      BOOLEAN_TYPE, new_node(BOOL_VAL_NODE, 1, BOOLEAN_TYPE));
					  return TRUE_RW; }

"try"  			    { return TRY; }
"typeof"  			{ return TYPEOF; }
"var"  			    { return VAR; }
"void"  			{ return VOID_RW; }
"while"  			{ return WHILE; }
"with"  			{ return WITH; }
"await"  			{ return AWAIT; }
"yield"  			{ return YIELD; }
"static" 			{ return STATIC; }
"as"  				{ return AS; }
"async"  			{ return ASYNC; }
"from"  			{ return FROM; }
"get"  				{ return GET; }
"of"  				{ return OF; }
"set"  				{ return SET; }
"target"  			{ return TARGET; }
"any"  			    { return ANY; }
"boolean" 			{ return BOOLTYPE; }
"constructor" 		{ return CONSTRUCTOR; }
"declare" 			{ return DECLARE; }
"module" 			{ return MODULE; }
"require" 			{ return REQUIRE; }
"never" 			{ return NEVER; }
"number" 			{ return NUMBER; }
"string"  			{ return STRING; }
"symbol"  			{ return SYMBOL; }
"type"  			{ return TYPE; }
"undefined"			{ return UNDEFINED; }
"unknown"  			{ return UNKNOWN; }


	/* Pontuadores */

"="					{ return ASSIGN; }
"=>"				{ return ARROW; }
","					{ return COMMA; }
";"					{ return SEMI; }
":"					{ return COLON; }
"?"					{ return TERNARY; }
"?."				{ return CHAIN; }
"|>"				{ return PIPELINE; }
"."					{ return DOT; }
"..."				{ return SPREAD; }

"+"					{ return PLUS; }
"++"				{ return INCREMENT; }
"+="				{ return PLUS_ASSIGN; }
"-"					{ return SUB; }
"--"				{ return DECREMENT; }
"-="				{ return SUB_ASSIGN; }
"*"					{ return MULT; }
"*="				{ return MULT_ASSIGN; }
"/"					{ return DIV; }
"/="				{ return DIV_ASSIGN; }
"**"				{ return EXP; }
"**="				{ return EXP_ASSIGN; }
"%"					{ return REM; }
"%="				{ return REM_ASSIGN; }

"~"					{ return BITWISE_NOT; }
"&"					{ return BITWISE_AND; }
"&="				{ return BITWISE_AND_ASSIGN; }
"|"					{ return BITWISE_OR; }
"|="				{ return BITWISE_OR_ASSIGN; }
"^"					{ return BITWISE_XOR; }
"^="				{ return BITWISE_XOR_ASSIGN; }

"!"					{ return LOGICAL_NOT; }
"??"				{ return LOGICAL_NULL; }
"??="				{ return LOGICAL_NULL_ASSIGN; }
"&&"				{ return LOGICAL_AND; }
"&&="				{ return LOGICAL_AND_ASSIGN; }
"||"				{ return LOGICAL_OR; }
"||="				{ return LOGICAL_OR_ASSIGN; }

"=="				{ return EQ; }
"==="				{ return EQ_STRICT; }
"!="				{ return INEQ; }
"!=="				{ return INEQ_STRICT; }
"<"					{ return LT; }
"<="				{ return LT_EQ; }
">"					{ return GT; }
">="				{ return GT_EQ; }

"<<"				{ return LSHIFT; }
"<<="				{ return LSHIFT_ASSIGN; }
">>"				{ return RSHIFT; }
">>="				{ return RSHIFT_ASSIGN; }
">>>"				{ return RSHIFT_UNSIGNED; }
">>>="				{ return RSHIFT_UNSIGNED_ASSIGN; }

"("					{ return LPAR; }
")"					{ return RPAR; }
"{"					{ return LBRACE; }
"}"					{ return RBRACE; }
"["					{ return LBRACKET; }
"]"					{ return RBRACKET; }


	/* Valores */

{int_val}				{
							yylval = new_tupla(NULL, yylineno,
						    	NUMBER_TYPE, new_node(NUM_VAL_NODE, 0, NUMBER_TYPE));
						  	set_double_data(tupla_get_node(yylval), (double) atof(yytext));
						  	return INT_VAL;
						}

{real_val}				{
							yylval = new_tupla(NULL, yylineno,
						        NUMBER_TYPE, new_node(NUM_VAL_NODE, 0, NUMBER_TYPE));
						  	set_double_data(tupla_get_node(yylval), (double) atof(yytext));
						  	return REAL_VAL;
						}

{str_quotes_val}		{
							yylval = new_tupla(NULL, yylineno, STRING_TYPE,
								new_node(STR_VAL_NODE, addStr(&st, yytext), STRING_TYPE));
						  	return STR_VAL;
						}

{str_apost_val}			{
							yylval = new_tupla(NULL, yylineno, STRING_TYPE,
								new_node(STR_VAL_NODE, addStr(&st, yytext), STRING_TYPE));
						  	return STR_VAL;
						}

{str_crasis_val}		{
							yylval = new_tupla(NULL, yylineno, STRING_TYPE,
								new_node(STR_VAL_NODE, addStr(&st, yytext), STRING_TYPE));
						  	return STR_VAL;
						}


	/* Identificadores */

{id}				{ yylval = new_tupla(strdup(yytext), yylineno, UNKNOWN_TYPE, NULL);
					  return ID; }


	/* Erros */

.           		{ erro_lexico(); }

%%

void erro_lexico()
{
	// Leitura de simbolo desconhecido
	fprintf(yyout, "LEXICAL ERROR (%d): Unknown symbol %s\n", yylineno, yytext);
	exit(EXIT_FAILURE);
}
