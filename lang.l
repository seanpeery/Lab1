%{
// lang lexer definition file
//
// Author: Phil Howard phil.howard@oit.edu

#include "tokens.h"

#define RETURN(a) return Return(a);
static int Return(int val);

%}

%option noyywrap
%option noinput
%option nounput
%option yylineno


punct			[\)\(\}\{\]\[\;\,\.]
operator		[+\-\*\/%=]|"=="|"||"|"&&"
integer			[-+]?[0-9]*
floating		[-+]?[0-9]*\.?[0-9]+
whitespace		[' '/t/n]
identifiers		[_a-zA-Z][_a-zA-Z0-9]*
comments		"//".*

junk			[@$#:]

%%

"if"			RETURN(IF);
"then"			RETURN(THEN);
"else"			RETURN(ELSE);
"for"			RETURN(FOR);
"while"			RETURN(WHILE);
"print"			RETURN(PRINT);
"scan"			RETURN(SCAN);
"char"			RETURN(CHAR);
"int"			RETURN(INT);
"float"			RETURN(FLOAT);
"struct"		RETURN(STRUCT);
"return"		RETURN(RETURN_TOK);

{comments}		{}
{punct}			RETURN(yytext[0]);
{operator}		RETURN(OPERATOR);
{integer}		RETURN(INT_VAL);
{floating}		RETURN(FLOAT_VAL);
{whitespace}	{}
{identifiers}	RETURN(IDENTIFIER);

{junk}			RETURN (JUNK_TOKEN);
%%

// This function allows us to do extra processing on each token
static int Return(int val)
{
//	printf("Scanned '%s': %d\n", yytext, val);
	return val;
}

