%{
//***********************************************************************
// Purpose: Scanner definition for LANG compiler
//
// Author: Philip Howard
// Email:	phil.howard@oit.edu
//
// Date: 2/7/2015
//
//***********************************************************************

#include "cAstNode.h"
#include "cSymbolTable.h"
#include "cSymbol.h"
#include "lex.h"
#include "langparse.h"

#define RETURN(a) return Return(a);
static int Return(int val);

%}

%option noyywrap
%option noinput
%option nounput
%option yylineno


period			['.']
whitespace		[' ''\t''\n']
letter			[A-Za-z]
digit			[0-9]
punctuation	 [(){}\[\];,\.]
operator		[+\-*/%=]|"=="|"&&"|"||"
integer		 0|([1-9][0-9]*)
float			{integer}|({integer}\.{digit}+)
xfloat			(0{period}0)|(0{period}{digit}*[1-9])|([1-9]{digit}*{period}{digit}*[1-9])
identifier		{letter}({letter}|{digit}|"_")*
%%

"//"(.)+$					{}
{whitespace}+				{}
{punctuation}				RETURN(yytext[0]);
{operator}					RETURN(yytext[0]);
"if"						RETURN(IF);
"else"						RETURN(ELSE);
"while"					 RETURN(WHILE);
"print"					 RETURN(PRINT);
"scan"						RETURN(SCAN);
"int"						{ yylval.symbol = symbolTableRoot->Lookup("int");
								RETURN(TYPE_ID);
							}
"float"					 { yylval.symbol = symbolTableRoot->Lookup("float");
								RETURN(TYPE_ID);
							}
"char"						{ yylval.symbol = symbolTableRoot->Lookup("char");
								RETURN(TYPE_ID);
							}
"array"						RETURN(ARRAY);
"struct"					RETURN(STRUCT);
"return"					RETURN(RETURN);
{integer}					yylval.int_val = atoi(yytext); RETURN(INT_VAL);
{integer}|({integer}\.{digit}+) yylval.float_val = atof(yytext); RETURN(FLOAT_VAL);
{identifier}				{
								yylval.symbol = symbolTableRoot->Lookup(yytext);
								
								if (yylval.symbol == NULL) 
								{
									yylval.symbol = symbolTableRoot->Insert(yytext);
								}
								else
								{
									yylval.symbol->mFirst = false;
								}
//								std::cout << ".l";

								if (yylval.symbol->IsType()) RETURN(TYPE_ID);

								RETURN(IDENTIFIER);
							}
.							RETURN(JUNK_TOKEN);	// discard anything not recognized

%%

static int Return(int val)
{
//	printf("Scanned '%s': %d\n", yytext, val);
	return val;
}

