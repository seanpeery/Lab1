/***********************************************************************
// Purpose: Parser definition for LANG compiler
//
// Author: Philip Howard
// Email:  phil.howard@oit.edu
//
// Date: 2/7/2015
//
//***********************************************************************/

%{
#include <iostream>
#include "cAstNode.h"
#include "cBlockNode.h"
#include "cExprNode.h"
#include "cPrintNode.h"
#include "cScanNode.h"
#include "cReturnNode.h"
#include "cDeclsNode.h"
#include "cStmtsNode.h"
#include "cVarDeclNode.h"
#include "cArrayDeclNode.h"
#include "cStructDeclNode.h"
#include "cVarRefNode.h"
#include "cIfNode.h"
#include "cWhileNode.h"
#include "cAssignNode.h"
#include "cFuncNode.h"
#include "cFuncCallNode.h"
#include "cParamsNode.h"
#include "cParamNode.h"
#include "cArraySpecNode.h"
#include "cArrayValNode.h"

#include "cSymbol.h"
#include "cScope.h"
#include "cSymbolTable.h"
#include "lex.h"
%}

%locations

%union{
    int             int_val;
    double          float_val;
    cAstNode*       ast_node;
    cSymbol*        symbol;
    cScope*         sym_table;
    }

%{
    int yyerror(const char *msg);
    int yywarning(const char *msg);
	void semantic_error(std::string msg);
    cAstNode *yyast_root;
    cSymbolTable *symbolTableRoot = cSymbolTable::CreateDefaultTable();
%}

%start  program

%token <symbol>    IDENTIFIER
%token <symbol>    TYPE_ID

%token <int_val>    INT_VAL
%token <float_val>  FLOAT_VAL

%token  SCAN PRINT
%token  WHILE IF ELSE 
%token  STRUCT
%token  RETURN
%token  JUNK_TOKEN
%token 	ARRAY

%type <ast_node> program
%type <ast_node> block
%type <sym_table> open
%type <sym_table> close
%type <ast_node> decls
%type <ast_node> decl
%type <ast_node> var_decl
%type <ast_node> array_decl
%type <ast_node> struct_decl
%type <ast_node> func_decl
%type <ast_node>  func_header
%type <symbol>  func_prefix
%type <ast_node> func_call
%type <ast_node> paramsspec
%type <ast_node> paramspec
%type <ast_node> arrayspec
%type <ast_node> stmts
%type <ast_node> stmt
%type <ast_node> lval
%type <ast_node> arrayval
%type <ast_node> params
%type <ast_node> param
%type <ast_node> expr
%type <ast_node> term
%type <ast_node> fact
%type <ast_node> varref
%type <ast_node> varpart

%%

program: block                  { $$ = $1;
                                  yyast_root = $$;
                                  if (yynerrs == 0) 
                                      YYACCEPT;
                                  else
                                      YYABORT;
                                }
block:   open decls stmts close { $$ = new cBlockNode($2, $3);
								}

       | open stmts close       { $$ = new cBlockNode(NULL, $2);
								}
								
open:   '{'                     { $$ = NULL;
                                  symbolTableRoot->IncreaseScope(); 
                                }

close:  '}'                     { $$ = NULL;
                                  symbolTableRoot->DecreaseScope(); 
                                }

decls:      decls decl          { $$ = $1; 
                                  static_cast<cDeclsNode *>($1)->AddNode($2); 
                                }
        |   decl                { $$ = new cDeclsNode($1);
								}

decl:       var_decl ';'        { $$ = $1; }
		|	array_decl ';'		{ $$ = $1; }
        |   struct_decl ';'     { $$ = $1; }
        |   func_decl           { $$ = $1; }
        |   error ';'           { $$ = NULL; }

var_decl:   TYPE_ID IDENTIFIER
								{
									$$ = new cVarDeclNode($1, $2);
								}
array_decl:   ARRAY TYPE_ID IDENTIFIER arrayspec
                                {
									$3 = symbolTableRoot->Lookup($3->getName());
									if ($3 == NULL) 
									{
										$3 = symbolTableRoot->Insert($3->getName());
									}


									$$ = new cArrayDeclNode($2, $3, $4);
								}
struct_decl:  STRUCT open decls close IDENTIFIER
                                {
									$5 = symbolTableRoot->Lookup($5->getName());
									if ($5 == NULL) 
									{
										$5 = symbolTableRoot->Insert($5->getName());
									}


									$$ = new cStructDeclNode($2, $3, $5);
								}
func_decl:  func_header ';'
                          { $$ = $1;
                            symbolTableRoot->DecreaseScope();
                          }
        |   func_header  '{' decls stmts '}'
                          { $$ = $1;
                            cFuncNode *fDecl = 
                                static_cast<cFuncNode *>($1);
                            fDecl->SetDetails($3, $4);
                            symbolTableRoot->DecreaseScope();
                          }
        |   func_header  '{' stmts '}'
                          { $$ = $1;
                            cFuncNode *fDecl = 
                                static_cast<cFuncNode *>($1);
                            fDecl->SetDetails(NULL, $3);
                            symbolTableRoot->DecreaseScope();
                          }
func_header: func_prefix paramsspec ')'
                          { $$ = new cFuncNode($1, $2); }
        |    func_prefix ')'
                          { $$ = new cFuncNode($1, NULL); }
func_prefix: TYPE_ID IDENTIFIER '('
                          {
							$2 = symbolTableRoot->Lookup($2->getName());
							if ($2 == NULL) 
							{
								$2 = symbolTableRoot->Insert($2->getName());
							}

							$$ = symbolTableRoot->Lookup($2->getName());
                            $$->SetFuncType($1->GetType()); 
                            symbolTableRoot->IncreaseScope();
                          }
paramsspec:     
            paramsspec',' paramspec 
                                { $$ = $1;
                                  static_cast<cParamsNode *>($1)->AddNode($3); 
                                }
        |   paramspec           { $$ = new cParamsNode($1); }

paramspec:  var_decl            { $$ = $1;}

arrayspec:  arrayspec '[' INT_VAL ']'
                            { if ($1 == NULL)
                                $$ = new cArraySpecNode($3);
                              else 
                              {
                                $$ = $1;
                                static_cast<cArraySpecNode *>($1)->AddNode($3);
                              }
                            }
        |   /* empty */         { $$ = NULL; }

stmts:      stmts stmt          { $$ = $1; 
                                  static_cast<cStmtsNode *>($1)->AddNode($2); 
                                }
        |   stmt                { $$ = new cStmtsNode($1); }

stmt:       IF '(' expr ')' stmt 
                                { $$ = new cIfNode($3, $5, NULL); }
        |   IF '(' expr ')' stmt ELSE stmt
                                { $$ = new cIfNode($3, $5, $7); }
        |   WHILE '(' expr ')' stmt
                                { $$ = new cWhileNode($3, $5); }
        |   PRINT '(' expr ')' ';'
                                { $$ = new cPrintNode($3); }
        |   SCAN '(' lval ')' ';'
                                { $$ = new cScanNode($3); }
        |   lval '=' expr ';'   { $$ = new cAssignNode($1, $3); }
        |   func_call ';'       { $$ = $1; }
        |   block               { $$ = $1; }
        |   RETURN expr ';'     { $$ = new cReturnNode($2); }
        |   error ';'           { $$ = NULL; }

func_call:  IDENTIFIER '(' params ')' 
                                {
									$1 = symbolTableRoot->Lookup($1->getName());
									if ($1 == NULL) 
									{
										$1 = symbolTableRoot->Insert($1->getName());
									}

									$$ = new cFuncCallNode($1, $3);
								}
func_call:  IDENTIFIER '(' ')' 
                                {
									$1 = symbolTableRoot->Lookup($1->getName());
									if ($1 == NULL) 
									{
										$1 = symbolTableRoot->Insert($1->getName());
									}

									$$ = new cFuncCallNode($1, NULL);
								}
varref:   varref '.' varpart    { $$ = $1;
                                  static_cast<cVarRefNode *>($1)->AddNode($3);
                                }
        | varpart               { $$ = $1; }

varpart:  IDENTIFIER arrayval   {
									$1 = symbolTableRoot->Lookup($1->getName());
									if ($1 == NULL) 
									{
										$1 = symbolTableRoot->Insert($1->getName());
									}

										
									$$ = new cVarRefNode($1, $2);
								}

lval:     varref                { $$ = $1; }
arrayval: arrayval '[' expr ']' 
                              { if ($1 == NULL)
                                  $$ = new cArrayValNode($3);
                                else 
                                {
                                  $$ = $1;
                                  static_cast<cArrayValNode *>($1)->AddNode($3);
                                }
                              }
        |   /* empty */         { $$ = NULL; }

params:     params',' param
                                { $$ = $1;
                                  static_cast<cParamNode *>($1)->AddNode($3);
                                }
        |   param               { $$ = new cParamNode($1); }

param:      expr
                                { $$ = $1; }

expr:       expr '+' term       { $$ = new cExprNode($1, '+', $3); }
        |   expr '-' term       { $$ = new cExprNode($1, '-', $3); }
        |   term                { $$ = $1; }

term:       term '*' fact       { $$ = new cExprNode($1, '*', $3); }
        |   term '/' fact       { $$ = new cExprNode($1, '/', $3); }
        |   term '%' fact       { $$ = new cExprNode($1, '%', $3); }
        |   fact                { $$ = $1; }

fact:        '(' expr ')'       { $$ = $2; }
        |   INT_VAL             { $$ = new cExprNode($1); }
        |   FLOAT_VAL           { $$ = new cExprNode($1); }
        |   varref              { $$ = $1; }
        |   func_call           { $$ = $1; }


%%

int yyerror(const char *msg)
{
    std::cerr << "ERROR: " << msg << " at symbol "
        << yytext << " on line " << yylineno << "\n";

    return 0;
}

void semantic_error(std::string msg)
{
    std::cout << "ERROR: " << msg << 
                 " on line " << yylineno << std::endl;

    yynerrs++;
}
