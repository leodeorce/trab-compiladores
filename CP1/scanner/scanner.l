%option outfile="scanner.c"
%option noyywrap
%option nounput
%option noinput
%option yylineno

%{

#include <stdio.h>

void processar_token(char*);
void erro_lexico();

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

"break" 			{ processar_token("BREAK"); }
"case"  			{ processar_token("CASE"); }
"catch" 			{ processar_token("CATCH"); }
"class" 			{ processar_token("CLASS"); }
"const" 			{ processar_token("CONST_RW"); }
"continue" 			{ processar_token("CONTINUE"); }
"debugger" 			{ processar_token("DEBUGGER"); }
"default" 			{ processar_token("DEFAULT"); }
"delete" 			{ processar_token("DELETE"); }
"do"  			    { processar_token("DO"); }
"else"  			{ processar_token("ELSE"); }
"enum"  			{ processar_token("ENUM"); }
"export"  			{ processar_token("EXPORT"); }
"extends"  			{ processar_token("EXTENDS"); }
"false"  			{ processar_token("FALSE_RW"); }
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
"null"  			{ processar_token("NULL_RW"); }
"package" 			{ processar_token("PACKAGE"); }
"private" 			{ processar_token("PRIVATE"); }
"protected" 		{ processar_token("PROTECTED"); }
"public" 			{ processar_token("PUBLIC"); }
"return"  			{ processar_token("RETURN"); }
"super"  			{ processar_token("SUPER"); }
"switch"  			{ processar_token("SWITCH"); }
"this"  			{ processar_token("THIS"); }
"throw"  			{ processar_token("THROW"); }
"true"  			{ processar_token("TRUE_RW"); }
"try"  			    { processar_token("TRY"); }
"typeof"  			{ processar_token("TYPEOF"); }
"var"  			    { processar_token("VAR"); }
"void"  			{ processar_token("VOID_RW"); }
"while"  			{ processar_token("WHILE"); }
"with"  			{ processar_token("WITH"); }
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
"boolean" 			{ processar_token("BOOLTYPE"); }
"constructor" 		{ processar_token("CONSTRUCTOR"); }
"declare" 			{ processar_token("DECLARE"); }
"module" 			{ processar_token("MODULE"); }
"require" 			{ processar_token("REQUIRE"); }
"never" 			{ processar_token("NEVER"); }
"number" 			{ processar_token("NUMBER"); }
"string"  			{ processar_token("STRING"); }
"symbol"  			{ processar_token("SYMBOL"); }
"type"  			{ processar_token("TYPE"); }
"undefined"			{ processar_token("UNDEFINED"); }
"unknown"  			{ processar_token("UNKNOWN"); }


	/* Pontuadores */

"="					{ processar_token("ASSIGN"); }
"=>"				{ processar_token("ARROW"); }
","					{ processar_token("COMMA"); }
";"					{ processar_token("SEMI"); }
":"					{ processar_token("COLON"); }
"?"					{ processar_token("TERNARY"); }
"?."				{ processar_token("CHAIN"); }
"|>"				{ processar_token("PIPELINE"); }
"."					{ processar_token("DOT"); }
"..."				{ processar_token("SPREAD"); }

"+"					{ processar_token("PLUS"); }
"++"				{ processar_token("INCREMENT"); }
"+="				{ processar_token("PLUS_ASSIGN"); }
"-"					{ processar_token("SUB"); }
"--"				{ processar_token("DECREMENT"); }
"-="				{ processar_token("SUB_ASSIGN"); }
"*"					{ processar_token("MULT"); }
"*="				{ processar_token("MULT_ASSIGN"); }
"/"					{ processar_token("DIV"); }
"/="				{ processar_token("DIV_ASSIGN"); }
"**"				{ processar_token("EXP"); }
"**="				{ processar_token("EXP_ASSIGN"); }
"%"					{ processar_token("REM"); }
"%="				{ processar_token("REM_ASSIGN"); }

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

{int_val}				{ processar_token("INT_VAL"); }
{real_val}				{ processar_token("REAL_VAL"); }
{str_quotes_val}		{ processar_token("STR_VAL"); }
{str_apost_val}			{ processar_token("STR_VAL"); }
{str_crasis_val}		{ processar_token("STR_VAL"); }


	/* Identificadores */

{id}				{ processar_token("ID"); }


	/* Erros */

.           		{ erro_lexico(); }

%%

void processar_token(char* type)
{
	printf("%d: %s -> %s\n", yylineno, yytext, type);
}

void erro_lexico()
{
	// Leitura de simbolo desconhecido
	fprintf(yyout, "LEXICAL ERROR (%d): Unknown symbol %s\n", yylineno, yytext);
	exit(EXIT_FAILURE);
}