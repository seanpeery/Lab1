//lex.h
//Controls global variables and header connections
//Edited by Sean Peery
//Last edited 02/08/2015
#pragma once

#include "cSymbolTable.h"
#include "cAstNode.h"
#include "langparse.h"

extern char *yytext;
extern int yylineno;
extern cSymbolTable *symbolTableRoot;
extern FILE *yyin;          // input file for lexer
extern int yyparse();
extern int yylex();

