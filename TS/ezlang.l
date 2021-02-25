%{
#include <stdio.h>
void saida(char*);
void erro_lexico();
%}

%option yylineno

%%
[ \t\n]*					{ /* Fazer nada */ }
\{([^\}]|\n)*\}				{ /* Fazer nada */ }



(break) 			 { saida ("BREAK"); }
(as)  			     { saida ("AS"); }
(any)  			     { saida ("ANY"); }
(case)  			 { saida ("CASE"); }
(implements) 		 { saida ("IMPLEMENTS"); }
(boolean) 			 { saida ("BOOLEAN"); }
(catch) 			 { saida ("CATCH"); }
(interface) 		 { saida ("INTERFACE"); }
(constructor) 		 { saida ("CONSTRUCTOR"); }
(class) 			 { saida ("CLASS"); }
(let)  			     { saida ("LET"); }
(declare) 			 { saida ("DECLARE"); }
(const) 			 { saida ("CONST"); }
(package) 			 { saida ("PACKAGE"); }
(get)  			     { saida ("GET"); }
(continue) 			 { saida ("CONTINUE"); }
(private) 			 { saida ("PRIVATE"); }
(module) 			 { saida ("MODULE"); }
(debugger) 			 { saida ("DEBUGGER"); }
(protected) 		 { saida ("PROTECTED"); }
(require) 			 { saida ("REQUIRE"); }
(default) 			 { saida ("DEFAULT"); }
(public) 			 { saida ("PUBLIC"); }
(number) 			 { saida ("NUMBER"); }
(delete) 			 { saida ("DELETE"); }
(static) 			 { saida ("STATIC"); }
(set)  			     { saida ("SET"); }
(do)  			     { saida ("DO"); }
(yield)  			 { saida ("YIELD"); }
(string)  			 { saida ("STRING"); }
(else)  			 { saida ("ELSE"); }
(symbol)  			 { saida ("SYMBOL"); }
(enum)  			 { saida ("ENUM"); }
(type)  			 { saida ("TYPE"); }
(export)  			 { saida ("EXPORT"); }
(from)  			 { saida ("FROM"); }
(extends)  			 { saida ("EXTENDS"); }
(of)  			     { saida ("OF"); }
(false)  			 { saida ("FALSE"); }
(finally)  			 { saida ("FINALLY"); }
(for)  			     { saida ("FOR"); }
(function)  		 { saida ("FUNCTION"); }
(if)  			     { saida ("IF"); }
(import)  			 { saida ("IMPORT"); }
(in)  			     { saida ("IN"); }
(instanceof)  		 { saida ("INSTANCEOF"); }
(new)  			     { saida ("NEW"); }
(null)  			 { saida ("NULL"); }
(return)  			 { saida ("RETURN"); }
(super)  			 { saida ("SUPER"); }
(switch)  			 { saida ("SWITCH"); }
(this)  			 { saida ("THIS"); }
(throw)  			 { saida ("THROW"); }
(true)  			 { saida ("TRUE"); }
(try)  			     { saida ("TRY"); }
(typeof)  			 { saida ("TYPEOF"); }
(var)  			     { saida ("VAR"); }
(void)  			 { saida ("VOID"); }
(while)  			 { saida ("WHILE"); }
(with)  			 { saida ("WITH"); }



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
[a-zA-Z]+[a-zA-Z]*			{ saida("ID"); }
[0-9]+[0-9]*				{ saida("INT_VAL"); }
[0-9]+[0-9]*\.[0-9]+[0-9]*	{ saida("REAL_VAL"); }

[_,#]+						{ erro_lexico(); }
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

int yywrap(){return(1);}
