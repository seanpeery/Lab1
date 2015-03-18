//lex.h
//Controls global variables and header connections
//Edited by Sean Peery
//Last edited 02/20/2015

#pragma once

#include "cSymbolTable.h"
#include "cAstNode.h"
#include "ExprNode.h"
#include "BlockNode.h"
#include "IntExprNode.h"
#include "FloatExprNode.h"
#include "BinaryExprNode.h"
#include "DeclsNode.h"
#include "DeclNode.h"
#include "StmtsNode.h"
#include "StmtNode.h"
#include "VarNode.h"
#include "VarRefNode.h"
#include "VarPartNode.h"
#include "StructDeclNode.h"
#include "ArraySpecNode.h"
#include "ArrayValNode.h"
#include "ArrayDeclNode.h"
#include "ParamNode.h"
#include "ParamSpecNode.h"
#include "ParamsNode.h"
#include "ParamsSpecNode.h"
#include "FuncDeclNode.h"
#include "FuncCallNode.h"
#include "ScanNode.h"
#include "IfNode.h"
#include "ReturnNode.h"
#include "WhileNode.h"
#include "AssignmentNode.h"
#include "PrintNode.h"
#include "langparse.h"
#include "codegen.h"

extern char *yytext;
extern int yylineno;
extern cSymbolTable *symbolTableRoot;
extern FILE *yyin;          // input file for lexer
extern int yyparse();
extern int yylex();
extern int yynerrs;
extern codegen* generate;
