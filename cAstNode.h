//cAstNode.h
//Author: Sean Peery
//Last edited 02/09/2015
#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include <list>
#include "cSymbol.h"
using std::string;
using std::unordered_map;
using std::list;

//Base node class
class cAstNode
{
    public:
		cAstNode ();
        virtual string toString() = 0;
};

//Statement nodes
class StmtNode : public cAstNode
{
    public:
        virtual string toString() = 0;
};

//Node for multiple statments
class StmtsNode : public cAstNode
{
    public:
        StmtsNode();
        string toString();
        void Add(StmtNode* data);
        
    private:
        list<StmtNode*> m_stmts; //list of statments       
};

//Declaration node
class DeclNode
{
    public:
        virtual string toString() = 0;
};

//Node for multiple declaraions
class DeclsNode : public cAstNode
{
    public:
        DeclsNode();
        string toString();
        void Add(DeclNode* data);
        
    private:
        list<DeclNode*> m_decls; //list of declarations   
};

//Block node (needs to be places after stmts and decls)
class BlockNode : public StmtNode
{
    public:
        BlockNode(unordered_map<string,cSymbol*>* symTable, DeclsNode* decls = nullptr, StmtsNode* stmts = nullptr);
        string toString();
    
    private:
        unordered_map<string,cSymbol*>* m_symTable;
        DeclsNode * m_decls;
        StmtsNode * m_stmts;
};

//Expression node class
class ExprNode
{
    public:
      virtual string toString() = 0;
      
    protected:
      ExprNode* m_expr;
};

//Nodes used for outputing data
class PrintNode: public StmtNode
{
    public:
        PrintNode(ExprNode* expr);
        string toString();
		//string toScreen
    private:
        ExprNode* m_expr;
};

//Nodes used for reading data
class ScanNode: public StmtNode
{
    public:
        ScanNode(ExprNode* expr);
        string toString();
    
    private:
        ExprNode* m_expr;
};

//If statment node
class IfNode: public StmtNode
{
    public:
        IfNode(ExprNode* expr, StmtNode* stmt1, StmtNode* stmt2 = nullptr);
        string toString();
    
    private:
        ExprNode* m_expr;
        StmtNode* m_stmt1;
        StmtNode* m_stmt2;
};

//Return statement node
class ReturnNode: public StmtNode
{
    public:
        ReturnNode(ExprNode* expr);
        string toString();
    
    private:
        ExprNode* m_expr;
};

//While loop node
class WhileNode: public StmtNode
{
    public:
        WhileNode(ExprNode* expr, StmtNode* stmt);
        string toString();
    
    private:
        ExprNode* m_expr;
        StmtNode* m_stmt;
};

//Array value
class ArrayValNode
{
    public:
        ArrayValNode();
        void Add(ExprNode* val);
        string toString();
        
    private:
        list<ExprNode*> m_val;
};

//Components of variables
class VarPartNode : public ExprNode
{
    public:
        VarPartNode(cSymbol* val, ArrayValNode* ary);
        string toString();
    private:
        cSymbol* m_val;
        ArrayValNode* m_ary;
};

//Variable references
class VarRefNode : public ExprNode
{
    public:
        VarRefNode();
        string toString();
        void Add(VarPartNode* part);
    
    private:
        list<VarPartNode*> m_parts;
};

//Node for assigning data from right to left
class AssignmentNode: public StmtNode
{
    public:
        AssignmentNode(VarRefNode* lhs, ExprNode* rhs);
        string toString();
    
    private:
        VarRefNode* m_lhs;
        ExprNode* m_rhs;
};

//Parameter node
class ParamNode
{
    public:
        ParamNode(ExprNode* expr);
        string toString();
    
    private:
        ExprNode* m_expr;
};

//Node for multiple parameters
class ParamsNode : public StmtNode
{
    public:
        ParamsNode();
        string toString();
        void Add(ParamNode* param);
        
    private:
        list<ParamNode*> m_params;
};

//Array specifications
class ArraySpecNode
{
    public:
        ArraySpecNode();
        string toString();
        void Add(int val);
    
    private:
        list<int> m_array;
};

//Variable node
class VarNode : public DeclNode
{
    public:
        VarNode(cSymbol* typeId, cSymbol* identifier, ArraySpecNode* arraySpec);
        string toString();
    
    private:
        cSymbol* m_typeId;
        cSymbol* m_identifier;
        ArraySpecNode* m_arraySpec;
};

//Parameter specifications
class ParamSpecNode
{
    public:
        ParamSpecNode(VarNode* node);
        string toString();
    
    private:
        VarNode* m_param;
    
};

//Specifications for multiple paramters
class ParamsSpecNode : public StmtNode
{
    public:
        ParamsSpecNode();
        string toString();
        void Add(ParamSpecNode* param);
        
    private:
        list<ParamSpecNode*> m_params;
};

//Function prefix
class FuncPrefix
{
    public:
        FuncPrefix(cSymbol* typeId, cSymbol* identifier);
        string toString();
    
    private:
        cSymbol* m_typeId;
        cSymbol* m_identifier;
};

//Header of functions
class FuncHeader
{
    public:
        FuncHeader(FuncPrefix* prefix, ParamsSpecNode* params = nullptr);
        string toString();
    
    private:
        FuncPrefix* m_prefix;
        ParamsSpecNode* m_params;
        
};

//Fucntion declaration
class FuncDecl : public DeclNode
{
    public:
        FuncDecl(FuncHeader* header, DeclsNode* decls = nullptr, StmtsNode* stmts = nullptr);
        string toString();
    
    private:
        FuncHeader* m_header;
        DeclsNode*  m_decls;
        StmtsNode*  m_stmts;
};

//Function call
class FuncCall : public StmtNode, public ExprNode
{
    public:
        FuncCall(cSymbol* identifier, ParamsNode* params);
        string toString();
    
    private:
        cSymbol* m_identifier;
        ParamsNode* m_params;
};

//Struct declaration
class StructDecl : public DeclNode
{
    public:
        StructDecl(unordered_map<string,cSymbol*>* symTable, DeclsNode* decls, cSymbol* identifier);
        string toString();
    
    private:
        unordered_map<string,cSymbol*>* m_symTable;
        DeclsNode* m_decls;
        cSymbol* m_identifier;
        
};

//Integer expression
class IntExpr : public ExprNode
{
    public:
        IntExpr(int val);
        string toString();
    
    private:
        int m_val;
};

//Float expression
class FloatExpr : public ExprNode
{
    public:
        FloatExpr(double val);
        string toString();
    private:
        double m_val;
};

//Binary expression
class BinaryExpr : public ExprNode
{
    public:
        BinaryExpr(ExprNode* lhs, char oper, ExprNode* rhs);
        string toString();
    private:
        ExprNode* m_rhs;
        char m_oper;
        ExprNode* m_lhs;
        
};