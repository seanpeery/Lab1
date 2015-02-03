// lex.h
// Edited by Sean Peery
//

#pragma once

#include "cSymbolTable.h"
#include "cSymbol.h"
#include "langparse.h"

extern char *yytext;
extern int yylineno;
extern cSymbolTable *symbolTableRoot;
extern FILE *yyin;          // input file for lexer
extern int yyparse();
extern int yylex();

