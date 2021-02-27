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

void erro_lexico(int err_num)
{
	switch(err_num) {

		case 1:
			// Leitura de simbolo desconhecido
			fprintf(yyout, "LEXICAL ERROR (%d): Unknown symbol %s\n", yylineno, yytext);
			exit(EXIT_FAILURE);
			break;

		case 2:
			// Formato de identificador invalido
			fprintf(yyout, "LEXICAL ERROR (%d): Invalid ID %s\n", yylineno, yytext);
			exit(EXIT_FAILURE);
			break;
	}
}

%}

%x comment

int_val     [0-9]+
real_val    [0-9]+"."[0-9]+
str_val     \"[^"]*\"

id          [a-zA-Z]+[a-zA-Z0-9]*

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


	/* Nao podem ser identificadores */

"break" 			{ processar_token("BREAK"); }
"case"  			{ processar_token("CASE"); }
"catch" 			{ processar_token("CATCH"); }
"class" 			{ processar_token("CLASS"); }
"const" 			{ processar_token("CONST"); }
"continue" 			{ processar_token("CONTINUE"); }
"debugger" 			{ processar_token("DEBUGGER"); }
"default" 			{ processar_token("DEFAULT"); }
"delete" 			{ processar_token("DELETE"); }
"do"  			    { processar_token("DO"); }
"else"  			{ processar_token("ELSE"); }
"enum"  			{ processar_token("ENUM"); }
"export"  			{ processar_token("EXPORT"); }
"extends"  			{ processar_token("EXTENDS"); }
"false"  			{ processar_token("FALSE"); }
"finally"  			{ processar_token("FINALLY"); }
"for"  			    { processar_token("FOR"); }
"function"  		{ processar_token("FUNCTION"); }
"if"  			    { processar_token("IF"); }
"implements" 		{ processar_token("IMPLEMENTS"); }
"import"  			{ processar_token("IMPORT"); }
"in"  			    { processar_token("IN"); }
"instanceof"  		{ processar_token("INSTANCEOF"); }
"interface" 		{ processar_token("INTERFACE"); }
"let"  				{ processar_token("LET"); }
"new"  			    { processar_token("NEW"); }
"null"  			{ processar_token("NULL"); }
"package" 			{ processar_token("PACKAGE"); }
"private" 			{ processar_token("PRIVATE"); }
"protected" 		{ processar_token("PROTECTED"); }
"public" 			{ processar_token("PUBLIC"); }
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


	/* Podem ser identificadores */

"await"  			{ processar_token("AWAIT"); }
"yield"  			{ processar_token("YIELD"); }

"static" 			{ processar_token("STATIC"); }

"as"  				{ processar_token("AS"); }
"async"  			{ processar_token("ASYNC"); }
"from"  			{ processar_token("FROM"); }
"get"  				{ processar_token("GET"); }
"of"  				{ processar_token("OF"); }
"set"  				{ processar_token("SET"); }
"target"  			{ processar_token("TARGET"); }

"any"  			    { processar_token("ANY"); }
"boolean" 			{ processar_token("BOOLEAN"); }
"constructor" 		{ processar_token("CONSTRUCTOR"); }
"declare" 			{ processar_token("DECLARE"); }
"module" 			{ processar_token("MODULE"); }
"require" 			{ processar_token("REQUIRE"); }
"number" 			{ processar_token("NUMBER"); }
"string"  			{ processar_token("STRING"); }
"symbol"  			{ processar_token("SYMBOL"); }
"type"  			{ processar_token("TYPE"); }


	/* Pontuadores */

"+"					{ processar_token("ADD"); }
"++"				{ processar_token("INCREMENT"); }
"+="				{ processar_token("ADD_ASSIGN"); }
"-"					{ processar_token("SUB"); }
"--"				{ processar_token("DECREMENT"); }
"-="				{ processar_token("SUB_ASSIGN"); }
"*"					{ processar_token("MULT"); }
"*="				{ processar_token("MULT_ASSIGN"); }
"/"					{ processar_token("DIV"); }
"/="				{ processar_token("DIV_ASSIGN"); }
"**"				{ processar_token("EXP"); }
"**="				{ processar_token("EXP_ASSIGN"); }
"%%"				{ processar_token("REM"); }
"%%="				{ processar_token("REM_ASSIGN"); }

"~"					{ processar_token("BITWISE_NOT"); }
"&"					{ processar_token("BITWISE_AND"); }
"&="				{ processar_token("BITWISE_AND_ASSIGN"); }
"|"					{ processar_token("BITWISE_OR"); }
"|="				{ processar_token("BITWISE_OR_ASSIGN"); }
"^"					{ processar_token("BITWISE_XOR"); }
"^="				{ processar_token("BITWISE_XOR_ASSIGN"); }

"!"					{ processar_token("LOGICAL_NOT"); }
"??"				{ processar_token("LOGICAL_NULL"); }
"??="				{ processar_token("LOGICAL_NULL_ASSIGN"); }
"&&"				{ processar_token("LOGICAL_AND"); }
"&&="				{ processar_token("LOGICAL_AND_ASSIGN"); }
"||"				{ processar_token("LOGICAL_OR"); }
"||="				{ processar_token("LOGICAL_OR_ASSIGN"); }

"="					{ processar_token("ASSIGN"); }
","					{ processar_token("COMMA"); }
";"					{ processar_token("SEMI"); }
":"					{ processar_token("COLON"); }
"?."				{ processar_token("CHAIN"); }
"|>"				{ processar_token("PIPELINE"); }
"."					{ processar_token("DOT"); }
"..."				{ processar_token("SPREAD"); }

"=="				{ processar_token("EQ"); }
"==="				{ processar_token("EQ_STRICT"); }
"!="				{ processar_token("INEQ"); }
"!=="				{ processar_token("INEQ_STRICT"); }
"<"					{ processar_token("LT"); }
"<="				{ processar_token("LT_EQ"); }
">"					{ processar_token("GT"); }
">="				{ processar_token("GT_EQ"); }

"<<"				{ processar_token("LSHIFT"); }
"<<="				{ processar_token("LSHIFT_ASSIGN"); }
">>"				{ processar_token("RSHIFT"); }
">>="				{ processar_token("RSHIFT_ASSIGN"); }
">>>"				{ processar_token("RSHIFT_UNSIGNED"); }
">>>="				{ processar_token("RSHIFT_UNSIGNED_ASSIGN"); }

"("					{ processar_token("LPAR"); }
")"					{ processar_token("RPAR"); }
"{"					{ processar_token("LBRACE"); }
"}"					{ processar_token("RBRACE"); }
"["					{ processar_token("LBRACKET"); }
"]"					{ processar_token("RBRACKET"); }


	/* Valores */

{int_val}			{ processar_token("INT_VAL"); }
{real_val}			{ processar_token("REAL_VAL"); }
{str_val}			{ processar_token("STR_VAL"); }


	/* Identificadores */

{id}				{ processar_token("ID"); }


	/* Erros */

[0-9]+[a-zA-Z]+		{ erro_lexico(2); }
.           		{ erro_lexico(1); }

%%
