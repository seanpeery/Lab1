#pragma once
int yyparse();
int yylex();
extern char *yytext;
extern int yynerrs;
extern int yylineno;
extern FILE *yyin;
extern cSymbolTable *symbolTableRoot;
