%option outfile="scanner.c"
%option noyywrap
%option nounput
%option noinput
%option yylineno

%{

#include <stdio.h>
#include "parser.h"

void processar_token(char*);
void erro_lexico(int);

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


	/* Nao podem ser identificadores */

"break" 			{ processar_token("BREAK"); return BREAK; }
"case"  			{ processar_token("CASE"); return CASE; }
"catch" 			{ processar_token("CATCH"); return CATCH; }
"class" 			{ processar_token("CLASS"); return CLASS; }
"const" 			{ processar_token("CONST_RW"); return CONST_RW; }
"continue" 			{ processar_token("CONTINUE"); return CONTINUE; }
"debugger" 			{ processar_token("DEBUGGER"); return DEBUGGER; }
"default" 			{ processar_token("DEFAULT"); return DEFAULT; }
"delete" 			{ processar_token("DELETE"); return DELETE; }
"do"  			    { processar_token("DO"); return DO; }
"else"  			{ processar_token("ELSE"); return ELSE; }
"enum"  			{ processar_token("ENUM"); return ENUM; }
"export"  			{ processar_token("EXPORT"); return EXPORT; }
"extends"  			{ processar_token("EXTENDS"); return EXTENDS; }
"false"  			{ processar_token("FALSE_RW"); return FALSE_RW; }
"finally"  			{ processar_token("FINALLY"); return FINALLY; }
"for"  			    { processar_token("FOR"); return FOR; }
"function"  		{ processar_token("FUNCTION"); return FUNCTION; }
"if"  			    { processar_token("IF"); return IF; }
"implements" 		{ processar_token("IMPLEMENTS"); return IMPLEMENTS; }
"import"  			{ processar_token("IMPORT"); return IMPORT; }
"in"  			    { processar_token("IN"); return IN; }
"instanceof"  		{ processar_token("INSTANCEOF"); return INSTANCEOF; }
"interface" 		{ processar_token("INTERFACE"); return INTERFACE; }
"let"  				{ processar_token("LET"); return LET; }
"new"  			    { processar_token("NEW"); return NEW; }
"null"  			{ processar_token("NULL_RW"); return NULL_RW; }
"package" 			{ processar_token("PACKAGE"); return PACKAGE; }
"private" 			{ processar_token("PRIVATE"); return PRIVATE; }
"protected" 		{ processar_token("PROTECTED"); return PROTECTED; }
"public" 			{ processar_token("PUBLIC"); return PUBLIC; }
"return"  			{ processar_token("RETURN"); return RETURN; }
"super"  			{ processar_token("SUPER"); return SUPER; }
"switch"  			{ processar_token("SWITCH"); return SWITCH; }
"this"  			{ processar_token("THIS"); return THIS; }
"throw"  			{ processar_token("THROW"); return THROW; }
"true"  			{ processar_token("TRUE_RW"); return TRUE_RW; }
"try"  			    { processar_token("TRY"); return TRY; }
"typeof"  			{ processar_token("TYPEOF"); return TYPEOF; }
"var"  			    { processar_token("VAR"); return VAR; }
"void"  			{ processar_token("VOID_RW"); return VOID_RW; }
"while"  			{ processar_token("WHILE"); return WHILE; }
"with"  			{ processar_token("WITH"); return WITH; }


	/* Podem ser identificadores */

"await"  			{ processar_token("AWAIT"); return AWAIT; }
"yield"  			{ processar_token("YIELD"); return YIELD; }

"static" 			{ processar_token("STATIC"); return STATIC; }

"as"  				{ processar_token("AS"); return AS; }
"async"  			{ processar_token("ASYNC"); return ASYNC; }
"from"  			{ processar_token("FROM"); return FROM; }
"get"  				{ processar_token("GET"); return GET; }
"of"  				{ processar_token("OF"); return OF; }
"set"  				{ processar_token("SET"); return SET; }
"target"  			{ processar_token("TARGET"); return TARGET; }

"any"  			    { processar_token("ANY"); return ANY; }
"boolean" 			{ processar_token("BOOLTYPE"); return BOOLTYPE; }
"constructor" 		{ processar_token("CONSTRUCTOR"); return CONSTRUCTOR; }
"declare" 			{ processar_token("DECLARE"); return DECLARE; }
"module" 			{ processar_token("MODULE"); return MODULE; }
"require" 			{ processar_token("REQUIRE"); return REQUIRE; }
"number" 			{ processar_token("NUMBER"); return NUMBER; }
"string"  			{ processar_token("STRING"); return STRING; }
"symbol"  			{ processar_token("SYMBOL"); return SYMBOL; }
"type"  			{ processar_token("TYPE"); return TYPE; }


	/* Pontuadores */

"="					{ processar_token("ASSIGN"); return ASSIGN; }
"=>"				{ processar_token("ARROW"); return ARROW; }
","					{ processar_token("COMMA"); return COMMA; }
";"					{ processar_token("SEMI"); return SEMI; }
":"					{ processar_token("COLON"); return COLON; }
"?"					{ processar_token("TERNARY"); return TERNARY; }
"?."				{ processar_token("CHAIN"); return CHAIN; }
"|>"				{ processar_token("PIPELINE"); return PIPELINE; }
"."					{ processar_token("DOT"); return DOT; }
"..."				{ processar_token("SPREAD"); return SPREAD; }

"+"					{ processar_token("PLUS"); return PLUS; }
"++"				{ processar_token("INCREMENT"); return INCREMENT; }
"+="				{ processar_token("PLUS_ASSIGN"); return PLUS_ASSIGN; }
"-"					{ processar_token("SUB"); return SUB; }
"--"				{ processar_token("DECREMENT"); return DECREMENT; }
"-="				{ processar_token("SUB_ASSIGN"); return SUB_ASSIGN; }
"*"					{ processar_token("MULT"); return MULT; }
"*="				{ processar_token("MULT_ASSIGN"); return MULT_ASSIGN; }
"/"					{ processar_token("DIV"); return DIV; }
"/="				{ processar_token("DIV_ASSIGN"); return DIV_ASSIGN; }
"**"				{ processar_token("EXP"); return EXP; }
"**="				{ processar_token("EXP_ASSIGN"); return EXP_ASSIGN; }
"%%"				{ processar_token("REM"); return REM; }
"%%="				{ processar_token("REM_ASSIGN"); return REM_ASSIGN; }

"~"					{ processar_token("BITWISE_NOT"); return BITWISE_NOT; }
"&"					{ processar_token("BITWISE_AND"); return BITWISE_AND; }
"&="				{ processar_token("BITWISE_AND_ASSIGN"); return BITWISE_AND_ASSIGN; }
"|"					{ processar_token("BITWISE_OR"); return BITWISE_OR; }
"|="				{ processar_token("BITWISE_OR_ASSIGN"); return BITWISE_OR_ASSIGN; }
"^"					{ processar_token("BITWISE_XOR"); return BITWISE_XOR; }
"^="				{ processar_token("BITWISE_XOR_ASSIGN"); return BITWISE_XOR_ASSIGN; }

"!"					{ processar_token("LOGICAL_NOT"); return LOGICAL_NOT; }
"??"				{ processar_token("LOGICAL_NULL"); return LOGICAL_NULL; }
"??="				{ processar_token("LOGICAL_NULL_ASSIGN"); return LOGICAL_NULL_ASSIGN; }
"&&"				{ processar_token("LOGICAL_AND"); return LOGICAL_AND; }
"&&="				{ processar_token("LOGICAL_AND_ASSIGN"); return LOGICAL_AND_ASSIGN; }
"||"				{ processar_token("LOGICAL_OR"); return LOGICAL_OR; }
"||="				{ processar_token("LOGICAL_OR_ASSIGN"); return LOGICAL_OR_ASSIGN; }

"=="				{ processar_token("EQ"); return EQ; }
"==="				{ processar_token("EQ_STRICT"); return EQ_STRICT; }
"!="				{ processar_token("INEQ"); return INEQ; }
"!=="				{ processar_token("INEQ_STRICT"); return INEQ_STRICT; }
"<"					{ processar_token("LT"); return LT; }
"<="				{ processar_token("LT_EQ"); return LT_EQ; }
">"					{ processar_token("GT"); return GT; }
">="				{ processar_token("GT_EQ"); return GT_EQ; }

"<<"				{ processar_token("LSHIFT"); return LSHIFT; }
"<<="				{ processar_token("LSHIFT_ASSIGN"); return LSHIFT_ASSIGN; }
">>"				{ processar_token("RSHIFT"); return RSHIFT; }
">>="				{ processar_token("RSHIFT_ASSIGN"); return RSHIFT_ASSIGN; }
">>>"				{ processar_token("RSHIFT_UNSIGNED"); return RSHIFT_UNSIGNED; }
">>>="				{ processar_token("RSHIFT_UNSIGNED_ASSIGN"); return RSHIFT_UNSIGNED_ASSIGN; }

"("					{ processar_token("LPAR"); return LPAR; }
")"					{ processar_token("RPAR"); return RPAR; }
"{"					{ processar_token("LBRACE"); return LBRACE; }
"}"					{ processar_token("RBRACE"); return RBRACE; }
"["					{ processar_token("LBRACKET"); return LBRACKET; }
"]"					{ processar_token("RBRACKET"); return RBRACKET; }


	/* Valores */

{int_val}				{ processar_token("INT_VAL"); return INT_VAL; }
{real_val}				{ processar_token("REAL_VAL"); return REAL_VAL; }
{str_quotes_val}		{ processar_token("STR_VAL"); return STR_VAL; }
{str_apost_val}			{ processar_token("STR_VAL"); return STR_VAL; }
{str_crasis_val}		{ processar_token("STR_VAL"); return STR_VAL; }


	/* Identificadores */

{id}				{ processar_token("ID"); return ID; }


	/* Erros */

{real_val}[a-zA-Z]+		{ erro_lexico(3); }
[0-9]+[a-zA-Z]+			{ erro_lexico(2); }
.           			{ erro_lexico(1); }

%%

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

		case 3:
			// Formato de valor invalido
			fprintf(yyout, "LEXICAL ERROR (%d): Invalid value %s\n", yylineno, yytext);
			exit(EXIT_FAILURE);
			break;
	}
}