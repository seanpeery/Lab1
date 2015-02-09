//cAstNode.cpp
//Author: Sean Peery
//Last edited 02/09/2015
#include "cAstNode.h"

/*
* ---Constructors---
* Initalize data for the various parts of the language
*/

//Ast Node constructor
cAstNode::cAstNode()
{}

//Constructor for the block node
BlockNode::BlockNode(unordered_map<string,cSymbol*>* symTable, DeclsNode* decls, StmtsNode* stmts)
	:m_symTable(symTable), m_decls(decls), m_stmts(stmts)
{}

//Constructor for the declaration nodes
DeclsNode::DeclsNode()
{}

//Constructor for the statmente nodes
StmtsNode::StmtsNode()
{}

//Constructor for the scanner node
ScanNode::ScanNode(ExprNode* expr) : m_expr(expr)
{}

//Constructor for the print node
PrintNode::PrintNode(ExprNode* expr) : m_expr(expr)
{}

//Constructor for the node for if statements
IfNode::IfNode(ExprNode* expr, StmtNode* stmt1, StmtNode* stmt2)
	:m_expr(expr), m_stmt1(stmt1), m_stmt2(stmt2)
{}

//Constructor for the node for while loops
WhileNode::WhileNode(ExprNode* expr, StmtNode* stmt)
	:m_expr(expr), m_stmt(stmt)
{}

//Constructor for the nodes for parameters
ParamsNode::ParamsNode()
{}

//Constructor for the parameter node
ParamNode::ParamNode(ExprNode* expr) : m_expr(expr)
{}

//Constructor for the specification for parameters
ParamsSpecNode::ParamsSpecNode()
{}

//Constructor for the parameter specification
ParamSpecNode::ParamSpecNode(VarNode* node) : m_param(node)
{}

//Constructor for variable nodes
VarNode::VarNode(cSymbol* typeId, cSymbol* identifier, ArraySpecNode* arraySpec)
	:m_typeId(typeId), m_identifier(identifier), m_arraySpec(arraySpec)
{}

//Constructor for variable components
VarPartNode::VarPartNode(cSymbol* val, ArrayValNode* ary)
	:m_val(val), m_ary(ary)
{}

//Constructor for variable refrences
VarRefNode::VarRefNode()
{}

//Constructor for array specifications
ArraySpecNode::ArraySpecNode()
{}

//Constructor for array values
ArrayValNode::ArrayValNode()
{}

//Constructor for struct declarations
StructDecl::StructDecl(unordered_map<string,cSymbol*>* symTable, DeclsNode* decls, cSymbol* identifier)
	:m_symTable(symTable), m_decls(decls), m_identifier(identifier)
{}

//Constructor for binary expressions
BinaryExpr::BinaryExpr(ExprNode* lhs, char oper, ExprNode* rhs)
	:m_lhs(lhs), m_oper(oper), m_rhs(rhs)
{}

//Constructor for assignments nodes
AssignmentNode::AssignmentNode(VarRefNode* lhs, ExprNode* rhs)
	:m_lhs(lhs), m_rhs(rhs)
{}

//Constructor for function declarations
FuncDecl::FuncDecl(FuncHeader* header, DeclsNode* decls, StmtsNode* stmts)
	:m_header(header), m_decls(decls), m_stmts(stmts)
{}

//Constructor for function headers
FuncHeader::FuncHeader(FuncPrefix* prefix, ParamsSpecNode* params)
	:m_prefix(prefix), m_params(params)
{}

//Constructor for function prefixs
FuncPrefix::FuncPrefix(cSymbol* typeId, cSymbol* identifier)
	:m_typeId(typeId), m_identifier(identifier)
{}

//Constructor for function calls
FuncCall::FuncCall(cSymbol* identifier, ParamsNode* params)
	:m_identifier(identifier), m_params(params)
{}

//Constructor for return nodes
ReturnNode::ReturnNode(ExprNode* expr) : m_expr(expr)
{}

//Constructor for floating point expressions
FloatExpr::FloatExpr(double val) : m_val(val)
{}

//Constructor for integer expressions
IntExpr::IntExpr(int val) : m_val(val)
{}


/*
* ---ToStrings---
* Outputs the specific strings to represent found data
* Found from test.correct files
*/

//
string BlockNode::toString()
{
	string temp = "BLOCK:\n{\n";
	if(m_decls != nullptr)
		temp += m_decls->toString();
	if(m_stmts != nullptr)
		temp += m_stmts->toString();
	
	temp += "\n}";
	return temp;
}
//
string PrintNode::toString()
{
	return "PRINT: " + m_expr->toString();
}
//
string StmtsNode::toString()
{
	string temp = "STMTS:\n{\n";
	for(auto &stmt : m_stmts)
		temp += stmt->toString()+ "\n";
	temp += "}";
	return temp;
}
//
string ScanNode::toString()
{
	return "SCAN: " + m_expr->toString();
}
//
string IfNode::toString()
{
	string temp = "(IF: " + m_expr->toString() + "\n" + m_stmt1->toString() + "\n";
	
	if(m_stmt2 != nullptr)
		temp += "ELSE:\n" + m_stmt2->toString() + "\n";
	
	temp += ")";
	
	return temp;
}
//
string ReturnNode::toString()
{
	return "RETURN: " + m_expr->toString();
}
//
string WhileNode::toString()
{
	return "(WHILE: " + m_expr->toString() + "\n" + m_stmt->toString() + "\n)";
}
//
string AssignmentNode::toString()
{
	return "(ASSIGN: " + m_lhs->toString() + " = " + m_rhs->toString() + ")" ;
}
//
string ParamsNode::toString()
{
	string temp = "(PARAM:";

	for(auto &param : m_params)
		temp += param->toString()+" ";
	
	temp += ")\n";
	return temp;
}
//
string ParamNode::toString()
{
	return m_expr->toString();
}
//
string ParamSpecNode::toString()
{
	return m_param->toString();
}
//
string ParamsSpecNode::toString()
{
	string temp = "(PARAMS:";
	
	for(auto &param : m_params)
		temp += " " +param->toString();
	
	temp += ")\n";
	
	return temp;
}
//
string FuncHeader::toString()
{
	string temp = m_prefix->toString();
	
	if(m_params != nullptr)
		temp += " " + m_params->toString();
	else
		temp += "()";
	
	return temp;
}
//
string FuncDecl::toString()
{
	string temp = "(FUNC: " + m_header->toString();
	
	if(m_decls != nullptr)
		temp += m_decls->toString();
	
	if(m_stmts != nullptr)
		temp += m_stmts->toString();
	
	temp += "\n)";
	
	return temp;
}
//
string FuncCall::toString()
{
	return "(FUNC CALL: " + m_identifier->toString() + m_params->toString() + ")\n";
}
//
string DeclsNode::toString()
{
	string temp = "DECLS:\n{\n";
	
	for(auto &decl : m_decls)
		temp += decl->toString()+ "\n";
	
	temp += "}\n";
	
	return temp;
}
//
string VarNode::toString()
{
	string temp = "VAR: ";
	
	temp += m_typeId->toString() + " " + m_identifier->toString();
	if(m_arraySpec != nullptr)
		temp += " " + m_arraySpec->toString();
	
	return temp;
}
//
string StructDecl::toString()
{
	string temp = "STRUCT: ";
	
	temp += m_decls->toString() + " " + m_identifier->toString();
	
	return temp;
}
//
string VarRefNode::toString()
{
	string temp = "\0";
	
	list<VarPartNode*>::iterator iter;
	
	for(iter = m_parts.begin(); iter != m_parts.end(); ++iter )
	{
		temp += "(VarRef: " + (*iter)->toString();
		
		if(iter != m_parts.begin())
			temp += ")";
		else if(m_parts.size() > 1)
			temp += "\n";
	}
	 
	temp += ")";
	return temp;
}
//
string VarPartNode::toString()
{
	string temp = m_val->toString();
	
	if(m_ary != nullptr)
		temp += "[" + m_ary->toString() + "]";
	
	return temp;
}
//
string ArrayValNode::toString()
{
	string temp = "(ARRAYVAL:";
	
	for(auto &expr : m_val)
		temp += " " + expr->toString();
	
	temp += ")\n";
	
	return temp;
}
//
string ArraySpecNode::toString()
{
	string temp = "(ARRAYSPEC:";

	for(auto &i : m_array)
		temp += " " + std::to_string(i);

	temp += ")\n";
		//Return string
	return temp;
}
//
string FuncPrefix::toString()
{
	return m_identifier->toString();
}
//
string IntExpr::toString()
{
	return "(EXPR: " + std::to_string(m_val) + ")";
}
//
string FloatExpr::toString()
{
	return "(EXPR: " + std::to_string(m_val) + ")";
}
//
string BinaryExpr::toString()
{
	return "(EXPR: " + m_lhs->toString() + " " + m_oper + " " + m_rhs->toString() + ")";
}


/*
* ---Adds---
* For components that call themselves to extend the declration size
* Each adds to a list of nodes contained within the class
*/

//
void DeclsNode::Add(DeclNode* data)
{
	m_decls.push_back(data);
}
//
void StmtsNode::Add(StmtNode* data)
{
	m_stmts.push_back(data);
}
//
void ParamsNode::Add(ParamNode* param)
{
	m_params.push_back(param);
}
//
void ParamsSpecNode::Add(ParamSpecNode* param)
{
	m_params.push_back(param);
}
//
void ArraySpecNode::Add(int val)
{
	m_array.push_back(val);
}
//
void VarRefNode::Add(VarPartNode* part)
{
	m_parts.push_back(part);
}
//
void ArrayValNode::Add(ExprNode* val)
{
	m_val.push_back(val);
}
