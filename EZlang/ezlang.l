%{
#include <stdio.h>
void saida(char*);
void erro_lexico();
%}

%option yylineno

%%
[ \t\n]*					{ /* Fazer nada */ }
\{([^\}]|\n)*\}				{ /* Fazer nada */ }
(program)					{ saida("PROGRAM"); }
(begin)						{ saida("BEGIN"); }
(bool)						{ saida("BOOL"); }
(else)						{ saida("ELSE"); }
(end)						{ saida("END"); }
(false)						{ saida("FALSE"); }
(if)						{ saida("IF"); }
(int)						{ saida("INT"); }
(read)						{ saida("READ"); }
(real)						{ saida("REAL"); }
(repeat)					{ saida("REPEAT"); }
(string)					{ saida("STRING"); }
(then)						{ saida("THEN"); }
(true)						{ saida("TRUE"); }
(until)						{ saida("UNTIL"); }
(var)						{ saida("VAR"); }
(write)						{ saida("WRITE"); }
(:=)						{ saida("ASSIGN"); }
\=							{ saida("EQ"); }
\<							{ saida("LT"); }
\+							{ saida("PLUS"); }
\-							{ saida("MINUS"); }
\*							{ saida("TIMES"); }
\/							{ saida("OVER"); }
\(							{ saida("LPAR"); }
\)							{ saida("RPAR"); }
\;							{ saida("SEMI"); }
\"[^\"]*\"					{ saida("STR_VAL"); }
[_,#]+						{ erro_lexico(); }
[a-zA-Z]+[a-zA-Z]*			{ saida("ID"); }
[0-9]+[0-9]*				{ saida("INT_VAL"); }
[0-9]+[0-9]*\.[0-9]+[0-9]*	{ saida("REAL_VAL"); }
%%


void erro_lexico()
{
	fprintf(yyout, "LEXICAL ERROR (%d): Unknown symbol %s", yylineno, yytext);
	exit(1);
}


void saida(char* type)
{
	printf("%d: %s -> %s\n", yylineno, yytext, type);
}

int main()
{
	yylex();
	return 0;
}
