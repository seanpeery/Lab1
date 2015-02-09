%{
// lang lexer definition file
//
// Author: Phil Howard phil.howard@oit.edu
// Edited by Sean Peery
// Last edited 02/08/2015
#include "lex.h"


#define RETURN(a) return Return(a);
static int Return(int val);

%}

%option noyywrap
%option noinput
%option nounput
%option yylineno

	/* definitions go here. period is an example. */
punct			[\.\(\)\[\]\,\;]
integer 		[-]?[0-9]+
floating		[-]?[0-9]*\.?[0-9]+
oper			[\+\*\/\%\<\!\=\-]
comment			"//".*$
ident			[a-zA-Z][a-zA-Z0-9_]*
whitespace		[' '\t\n\r]
%%

	// token definitions go here. "if" is an example.
"if"                        RETURN(IF);
"else"                      RETURN(ELSE);
"while"                     RETURN(WHILE);
"print"                     RETURN(PRINT);
"scan"                      RETURN(SCAN);
"struct"                    RETURN(STRUCT);
"return"                    RETURN(RETURN);
"{"                         return yytext[0];
"}"                         return yytext[0];
{ident}                     { 
                                yylval.symbol = symbolTableRoot->Lookup(yytext);
                                    
                                if(yylval.symbol != nullptr)
                                {
                                    if(yylval.symbol->IsTyped())
                                        RETURN(TYPE_ID);
                                }
                                else
                                    yylval.symbol = symbolTableRoot->InsertSymbol(yytext);
                                    
                                RETURN(IDENTIFIER);
                            }
{ident}						{
								yylval.symbol = symbolTableRoot->InsertSymbol(yytext);
								return (IDENTIFIER);
							}
{integer}					{
                                yylval.int_val = atoi(yytext);
                                RETURN(INT_VAL);
                            }
{floating}					{
                                yylval.float_val = atof(yytext);
                                RETURN(FLOAT_VAL);
                            }
{comment}				   
{punct}|{oper}				RETURN(yytext[0]);
{whitespace}			
.							RETURN(JUNK_TOKEN);
%%

// This function allows us to do extra processing on each token
static int Return(int val)
{
//    printf("Scanned '%s': %d\n", yytext, val);
    return val;
}