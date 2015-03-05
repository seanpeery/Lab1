%{
// lang lexer definition file
//
// Author: Phil Howard phil.howard@oit.edu
// Edited by Sean Peery
// Last edited 02/21/2015
#include "lex.h"


#define RETURN(a) return Return(a);
static int Return(int val);

%}

%option noyywrap
%option noinput
%option nounput
%option yylineno

    /* definitions go here. period is an example. */
punct           [\.\(\)\[\]\,\;]
integer 		[-]?[0-9]+
floating		[-]?[0-9]*\.?[0-9]+
oper            [\+\*\/\%\<\!\=\-]
comment         "//".*$
ident           [a-zA-Z][a-zA-Z0-9_]*
whitespace		[' '\t\n\r]

%%

    // control scope with curly braces
    // NOTE: This functionality will eventually move to the parser
    // token definitions go here. "if" is an example.
"if"                        RETURN(IF);
"else"                      RETURN(ELSE);
"while"                     RETURN(WHILE);
"print"                     RETURN(PRINT);
"scan"                      RETURN(SCAN);
"array"                     RETURN(ARRAY);
"struct"                    RETURN(STRUCT);
"return"                    RETURN(RETURN);
"{"                         return yytext[0];
"}"                         return yytext[0];

{ident}                     {
                                yylval.symbol = symbolTableRoot->Lookup(yytext);
                                    
                                if(yylval.symbol != nullptr)
                                {
                                    if(yylval.symbol->IsType())
                                        RETURN(TYPE_ID);
                                }
                                else
                                    yylval.symbol = symbolTableRoot->InsertSymbol(yytext);
                                    
                                RETURN(IDENTIFIER);
                            }

{integer}					{
                                yylval.int_val = atoi(yytext);
                                RETURN(INT_VAL);
                            }
{floating}					{
                                yylval.float_val = atof(yytext);
                                RETURN(FLOAT_VAL);
                            }
{comment}                   /* Skip comments */
{punct}|{oper}              RETURN(yytext[0]);
{whitespace}
.                           RETURN(JUNK_TOKEN);
%%

// This function allows us to do extra processing on each token
static int Return(int val)
{
//    printf("Scanned '%s': %d\n", yytext, val);
    return val;
}