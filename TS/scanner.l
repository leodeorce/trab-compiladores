%option outfile="scanner.c"
%option noyywrap
%option nounput
%option noinput
%option yylineno

%{

#include <stdio.h>

void processar_token(char* type)
{
	printf("%d: %s -> %s\n", yylineno, yytext, type);
}

void erro_lexico()
{
	fprintf(yyout, "LEXICAL ERROR (%d): Unknown symbol %s\n", yylineno, yytext);
	exit(EXIT_FAILURE);
}

%}

int_val     [0-9]+
real_val    [0-9]+"."[0-9]+
str_val     \"[^"]*\"

id          [a-zA-Z]+

ignore      [ \t\n]+

%%

{ignore}			{ /* Fazer nada */ }

"{"					{ processar_token("PLACEHOLDER"); }
"}"					{ processar_token("PLACEHOLDER"); }
","					{ processar_token("PLACEHOLDER"); }

	/* Palavras reservadas */
"break" 			{ processar_token("BREAK"); }
"as"  			    { processar_token("AS"); }
"any"  			    { processar_token("ANY"); }
"case"  			{ processar_token("CASE"); }
"implements" 		{ processar_token("IMPLEMENTS"); }
"boolean" 			{ processar_token("BOOLEAN"); }
"catch" 			{ processar_token("CATCH"); }
"interface" 		{ processar_token("INTERFACE"); }
"constructor" 		{ processar_token("CONSTRUCTOR"); }
"class" 			{ processar_token("CLASS"); }
"let"  			    { processar_token("LET"); }
"declare" 			{ processar_token("DECLARE"); }
"const" 			{ processar_token("CONST"); }
"package" 			{ processar_token("PACKAGE"); }
"get"  			    { processar_token("GET"); }
"continue" 			{ processar_token("CONTINUE"); }
"private" 			{ processar_token("PRIVATE"); }
"module" 			{ processar_token("MODULE"); }
"debugger" 			{ processar_token("DEBUGGER"); }
"protected" 		{ processar_token("PROTECTED"); }
"require" 			{ processar_token("REQUIRE"); }
"default" 			{ processar_token("DEFAULT"); }
"public" 			{ processar_token("PUBLIC"); }
"number" 			{ processar_token("NUMBER"); }
"delete" 			{ processar_token("DELETE"); }
"static" 			{ processar_token("STATIC"); }
"set"  			    { processar_token("SET"); }
"do"  			    { processar_token("DO"); }
"yield"  			{ processar_token("YIELD"); }
"string"  			{ processar_token("STRING"); }
"else"  			{ processar_token("ELSE"); }
"symbol"  			{ processar_token("SYMBOL"); }
"enum"  			{ processar_token("ENUM"); }
"type"  			{ processar_token("TYPE"); }
"export"  			{ processar_token("EXPORT"); }
"from"  			{ processar_token("FROM"); }
"extends"  			{ processar_token("EXTENDS"); }
"of"  			    { processar_token("OF"); }
"false"  			{ processar_token("FALSE"); }
"finally"  			{ processar_token("FINALLY"); }
"for"  			    { processar_token("FOR"); }
"function"  		{ processar_token("FUNCTION"); }
"if"  			    { processar_token("IF"); }
"import"  			{ processar_token("IMPORT"); }
"in"  			    { processar_token("IN"); }
"instanceof"  		{ processar_token("INSTANCEOF"); }
"new"  			    { processar_token("NEW"); }
"null"  			{ processar_token("NULL"); }
"return"  			{ processar_token("RETURN"); }
"super"  			{ processar_token("SUPER"); }
"switch"  			{ processar_token("SWITCH"); }
"this"  			{ processar_token("THIS"); }
"throw"  			{ processar_token("THROW"); }
"true"  			{ processar_token("TRUE"); }
"try"  			    { processar_token("TRY"); }
"typeof"  			{ processar_token("TYPEOF"); }
"var"  			    { processar_token("VAR"); }
"void"  			{ processar_token("VOID"); }
"while"  			{ processar_token("WHILE"); }
"with"  			{ processar_token("WITH"); }

	/* Operadores */
":"					{ processar_token("PLACEHOLDER"); }
":="				{ processar_token("ASSIGN"); }
"="					{ processar_token("EQ"); }
"<"					{ processar_token("LT"); }
"+"					{ processar_token("PLUS"); }
"-"					{ processar_token("MINUS"); }
"*"					{ processar_token("TIMES"); }
"/"					{ processar_token("OVER"); }
"("					{ processar_token("LPAR"); }
")"					{ processar_token("RPAR"); }
";"					{ processar_token("SEMI"); }

	/* Variaveis */
{int_val}			{ processar_token("INT_VAL"); }
{real_val}			{ processar_token("REAL_VAL"); }
{str_val}			{ processar_token("STR_VAL"); }

	/* Identificadores */
{id}				{ processar_token("ID"); }

	/* Erros */
.           		{ erro_lexico(); }

%%
