/*
*	lang.y
*	Edited by Sean Peery
*	Last edited 02/21/2015
*/

%{
#include <iostream>
#include "lex.h"
%}

%locations

%union{
    int             int_val;
    double          float_val;
    cAstNode*       ast_node;
    cSymbol*        symbol;
    map<string,cSymbol*>*   sym_table;
    StmtsNode*     stmts_node;
    StmtNode*      stmt_node;
    BlockNode*     block_node;
    ExprNode*       expr_node;
    DeclsNode*     decls_node;
    DeclNode*      decl_node;
    ArraySpecNode*     ary_node;
    ArrayValNode*       ary_val;
    VarRefNode*        var_node;
    VarPartNode*        var_part;
    ParamNode*     param_node;
    ParamsNode*    params_node;
    ParamsSpecNode*    params_spec;
    ParamSpecNode*     param_spec;
    FuncCallNode*      func_node;
    }

%{
    int yyerror(const char *msg);
    void semantic_error(std::string msg);

    cAstNode *yyast_root;
%}

%start  program

%token <symbol>     IDENTIFIER
%token <symbol>     TYPE_ID
%token <int_val>    INT_VAL
%token <float_val>  FLOAT_VAL

%token  SCAN PRINT ARRAY
%token  STRUCT
%token  WHILE IF ELSE 
%token  RETURN
%token  JUNK_TOKEN

%type <ast_node> program
%type <block_node> block
%type <sym_table> open
%type <sym_table> close
%type <decls_node> decls
%type <decl_node> decl
%type <decl_node> var_decl
%type <decl_node> struct_decl
%type <decl_node> func_decl
%type <decl_node> array_decl
%type <decl_node>  func_header
%type <symbol> func_prefix
%type <func_node> func_call
%type <params_spec> paramsspec
%type <param_spec> paramspec
%type <ary_node> arrayspec
%type <stmts_node> stmts
%type <stmt_node> stmt
%type <expr_node> lval
%type <ary_val> arrayval
%type <params_node> params
%type <param_node> param
%type <expr_node> expr
%type <expr_node> term
%type <expr_node> fact
%type <var_node> varref
%type <var_part> varpart

%%

program: block                  { $$ = $1;
                                  yyast_root = $$;
                                  if (yynerrs == 0) 
                                      YYACCEPT;
                                  else
                                      YYABORT;
                                }
block:  open decls stmts close  {
                                    $$ = new BlockNode($1, $2, $3);
                                    
                                }
    |   open stmts close        {
                                    $$ = new BlockNode($1, nullptr, $2);
                                }
open:   '{'                     {
                                    $$ = symbolTableRoot->IncreaseScope();
                                }
close:  '}'                     {
                                    symbolTableRoot->DecreaseScope();
                                }
decls:      decls decl          {
                                    $$ = $1;
                                    $$->Add($2);
                                }
        |   decl                {
                                    $$ = new DeclsNode();
                                    $$->Add($1);
                                }
decl:       var_decl ';'        {
                                    $$ = $1;
                                }
        |   struct_decl ';'     {
                                    $$ = $1;
                                }
        |   func_decl           {
                                    $$ = $1;
                                }
        |   array_decl ';'      {
                                    $$ = $1;          
                                }
        |   error ';'           {}
var_decl:   TYPE_ID IDENTIFIER    
                                {
                                    if(symbolTableRoot->LocalLookUp($2->GetSymbol()) && $2->IsDeclared())
                                    {
                                        $$ = nullptr;
                                        semantic_error("Symbol " + $2->GetSymbol() + " already defined in current scope");
                                        YYERROR;
                                    }
                                    else
                                    {
                                        $2 = symbolTableRoot->InsertSymbol($2->GetSymbol());
                                        $2->SetDeclared();
										$2->InitializeSize($1->GetSize());
                                        $$ = new VarNode($1, $2);
										DeclNode* decl = $1->GetRef();
                                        if(decl == nullptr)
                                            decl = $$;
                                        $2->SetTypeRef($1->GetType(), $1->GetBaseType(), decl);
                                    }
                                }
array_decl:   ARRAY TYPE_ID IDENTIFIER arrayspec
                                {
                                    if(symbolTableRoot->LocalLookUp($3->GetSymbol()) && $3->IsDeclared())
                                    {
                                        $$ = nullptr;
                                        semantic_error("Symbol " + $3->GetSymbol() + " already defined in current scope");
                                        YYERROR;
                                    }
                                    else
                                    {
                                        $3 = symbolTableRoot->InsertSymbol($3->GetSymbol());
                                        $3->SetTypeFlag();
                                        $3->SetDeclared();
                                        $$ = new ArrayDeclNode($2, $3, $4);
                                        $3->SetTypeRef($3->GetSymbol(), $2->GetSymbol(), $$);
                                    }
                                }
struct_decl:  STRUCT open decls close IDENTIFIER    
                                {
                                    if(symbolTableRoot->LocalLookUp($5->GetSymbol()) && $5->IsDeclared())
                                    {
                                        $$ = nullptr;
                                        semantic_error("Symbol " + $5->GetSymbol() + " already defined in current scope");
                                        YYERROR;
                                    }
                                    else
                                    {
                                        $5 = symbolTableRoot->InsertSymbol($5->GetSymbol());
                                        $5->SetTypeFlag();
                                        $5->SetDeclared();
                                        $$ = new StructDeclNode($2, $3, $5);
                                        $5->SetTypeRef($5->GetSymbol(), $5->GetSymbol(), $$);
                                    }
                                    
                                }
func_decl:  func_header ';'
                                {
                                    $$ = $1;
                                    symbolTableRoot->DecreaseScope();
                                }
        |   func_header  '{' decls stmts '}'
                                {
                                    $$ = $1;
                                    FuncDeclNode* node = dynamic_cast<FuncDeclNode*>($$);
                                    node->SetDecls($3);
                                    node->SetStmts($4);
                                    symbolTableRoot->DecreaseScope();
                                }
        |   func_header  '{' stmts '}'
                                {
                                    $$ = $1;
                                    ((FuncDeclNode*)$$)->SetStmts($3);
                                    symbolTableRoot->DecreaseScope();
                                }
func_header: func_prefix paramsspec ')'
                                {
                                    $$ = new FuncDeclNode($1, $2);
                                }
        |    func_prefix ')'    {
                                    $$ = new FuncDeclNode($1);
                                }
func_prefix: TYPE_ID IDENTIFIER '('
                                {
                                    if(symbolTableRoot->LocalLookUp($2->GetSymbol()) && $2->IsDeclared())
                                    {
                                        $$ = nullptr;
                                        semantic_error("Symbol " + $2->GetSymbol() + " already defined in current scope");
                                        YYERROR;
                                    }
                                    else
                                    {
                                        $$ = symbolTableRoot->InsertSymbol($2->GetSymbol());
                                        $$->SetDeclared();
										$$->InitializeSize($1->GetSize());
                                        $$->SetTypeRef($1->GetSymbol(), $1->GetSymbol(), $1->GetRef());
                                        symbolTableRoot->IncreaseScope();
                                    }
                                }
paramsspec:     
            paramsspec',' paramspec 
                                {
                                    if($1 == nullptr)
                                        $1 = new ParamsSpecNode();
                                    $$ = $1;
                                    $$->Add($3);
                                }
        |   paramspec           {
                                    $$ = new ParamsSpecNode();
                                    $$->Add($1);
                                }

paramspec:  var_decl            {
                                    $$ = new ParamSpecNode((VarNode*)$1);
                                }

arrayspec:  arrayspec '[' INT_VAL ']'
                                {
                                    if($1 == NULL)
                                        $1 = new ArraySpecNode();
                                    $$ = $1;
                                    $$->Add($3);
                                }
        |   /* empty */         {
                                    $$ = NULL;
                                }

stmts:      stmts stmt          {
                                    $$ = $1;
                                    if($2 != nullptr)
                                        $$->Add($2);
                                }
        |   stmt                {
                                    $$ = new StmtsNode();
                                    if($1 != nullptr)
                                        $$->Add($1);
                                }

stmt:       IF '(' expr ')' stmt 
                                {
                                    $$ = new IfNode($3, $5);
                                }
        |   IF '(' expr ')' stmt ELSE stmt
                                {
                                    $$ = new IfNode($3, $5, $7);
                                }
        |   WHILE '(' expr ')' stmt
                                {
                                    $$ = new WhileNode($3, $5);
                                }
        |   PRINT '(' expr ')' ';'
                                {
                                    $$ = new PrintNode($3);
                                }
        |   SCAN '(' lval ')' ';'
                                {
                                    $$ = new ScanNode($3);
                                }
        |   lval '=' expr ';'   {
                                    $$ = new AssignmentNode((VarRefNode*)$1, $3);
                                    
                                    if($$->SemanticError())
                                    {
                                        $$ = nullptr;
                                        semantic_error("Cannot assign " + $3->GetBaseType() + " to " + $1->GetBaseType());
                                    }
                                    
                                }
		|   lval '=' func_call ';'
                                {
                                    $$ = new AssignmentNode((VarRefNode*)$1, $3);
                                    
                                    if($$->SemanticError())
                                    {
                                        $$ = nullptr;
                                        semantic_error("Cannot assign\n");
                                    }
                                }
        |   func_call ';'       {
                                   $$ = $1;
                                }
        |   block               {
                                    $$ = $1;
                                }
        |   RETURN expr ';'     {
                                    $$ = new ReturnNode($2);
                                }
        |   error ';'           {}

func_call:  IDENTIFIER '(' params ')' 
                                {
                                    $$ = new FuncCallNode($1, $3);                              
                                }
varref:   varref '.' varpart    {
                                    $$ = $1;
                                    $$->Add($3);
                                    if($$->SemanticError())
                                    {
                                        semantic_error($$->GetErrorMsg());
                                        YYERROR;
                                    }
                                }
        | varpart               {
                                    $$ = new VarRefNode();
                                    $$->Add($1);
                                    if($$->SemanticError())
                                    {
                                        semantic_error($$->GetErrorMsg());
                                        YYERROR;
                                    }
                                }

varpart:  IDENTIFIER arrayval   {
                                    $$ = new VarPartNode($1,$2);
                                }

lval:     varref                {
                                    $$ = $1;
                                }
arrayval: arrayval '[' expr ']' {
                                    if($1 == nullptr)
                                        $1 = new ArrayValNode();
                                    $$ = $1;
                                    $$->Add($3);
                                }
        |   /* empty */         {
                                    $$ = NULL;
                                }

params:     params',' param     {
                                    if($1 == nullptr)
                                        $1 = new ParamsNode();
                                    $$ = $1;
                                    $$->Add($3);
                                }
        |   param               {
                                    $$ = new ParamsNode();
                                    $$->Add($1);
                                }

param:      expr                {
                                    $$ = new ParamNode($1);
                                }
        |   /* empty */         {
                                    $$ = NULL;
                                }

expr:       expr '+' term       {
                                    $$ = new BinaryExprNode($1, '+', $3);
                                }
        |   expr '-' term       {
                                    $$ = new BinaryExprNode($1, '-', $3);
                                }
        |   term                {
                                    $$ = $1;
                                }

term:       term '*' fact       {
                                    $$ = new BinaryExprNode($1, '*', $3);
                                }
        |   term '/' fact       {
                                    $$ = new BinaryExprNode($1, '/', $3);
                                }
        |   term '%' fact       {
                                    $$ = new BinaryExprNode($1, '%', $3);
                                }
        |   fact                {
                                    $$ = $1;
                                }

fact:        '(' expr ')'       {
                                    $$ = $2;
                                }
        |   INT_VAL             {
                                   $$ = new IntExprNode($1);
                                }
        |   FLOAT_VAL           {
                                   $$ = new FloatExprNode($1);
                                }
        |   varref              {
                                   $$ = $1;
                                }


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