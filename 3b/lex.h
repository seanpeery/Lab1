#pragma once
#include "cSymbolTable.h"
#include "cSymbol.h"
#include "parse.h"
int yyparse();
int yylex();
extern char *yytext;
extern int yylineno;
extern FILE *yyin;
extern cSymbolTable *symbolTableRoot;
extern int yyparse();
extern int yylex();
