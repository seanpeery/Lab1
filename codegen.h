#pragma once
//*******************************************************
// Purpose: Utility functions for code generation
//
// Author: Philip Howard
// Email:  phil.howard@oit.edu
//
// Date: 2/20/2015
//
//*******************************************************

#include <string>
class codegen
{
public:
    codegen(){}
	bool InitOutput(const char *outfileName);
	bool FinalizeOutput();
	void StartFunctionOutput();
	void EndFunctionOutput();
	void EmitString(std::string str);
	void EmitFloat(double val);
	void RewriteFunctions();
	std::string GenerateLabel();
	void EmitPrintTemp();
	void EmitPrintTemp_F();
	void Reference(int offset, bool isFloat);
	void StackSizeUp(int size);
	void StackSizeDown(int size);
};