%{
// lang lexer definition file
//
// Author: Phil Howard phil.howard@oit.edu
// Edited by Sean Peery

#include "cSymbolTable.h"
#include "langparse.h"
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
digit           [\-]?[0-9]+
oper            [\+\*\/\%\<\!\=\-]
comment         "//".*$
ident           [a-zA-Z][a-zA-Z0-9_]*

%%

    // control scope with curly braces
    // NOTE: This functionality will eventually move to the parser
    // token definitions go here. "if" is an example.
"end"                       RETURN(END);
"if"                        RETURN(IF);
"then"                      RETURN(THEN);
"else"                      RETURN(ELSE);
"while"                     RETURN(WHILE);
"print"                     RETURN(PRINT);
"scan"                      RETURN(SCAN);
"int"                       RETURN(INT_VAL);
"float"                     RETURN(FLOAT_VAL);
"char"                      RETURN(CHAR);
"struct"                    RETURN(STRUCT);
"return"                    RETURN(RETURN_TOK);
"for"                       RETURN(FOR);
"{"                         {
                                symbolTableRoot->IncreaseScope();  
                                return yytext[0];
                            }
"}"                         {
                                symbolTableRoot->DecreaseScope();
                                return yytext[0];
                            }
{ident}                     {
                                yylval.symbol = symbolTableRoot->InsertSymbol(yytext);
                                return IDENTIFIER;
                            }
{digit}                     RETURN(INT_VAL);
{digit}"."{digit}           RETURN(FLOAT_VAL);
{comment}                   
{punct}|{oper}              RETURN(yytext[0]);
[ \t\n\r]                   
.                           RETURN(JUNK_TOKEN);
%%

// This function allows us to do extra processing on each token
static int Return(int val)
{
//    printf("Scanned '%s': %d\n", yytext, val);
    return val;
}