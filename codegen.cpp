//*******************************************************
// Purpose: Utility routines used for code generation
//
// Author: Philip Howard
// Email:  phil.howard@oit.edu
//
// Date: 2/20/2015
//
//*******************************************************

#include <iostream>
#include <string>
#include "codegen.h"

// prefix for generated source file
static const std::string CODE_PREFIX =
    std::string("#include <stdio.h>\n") +
    "#define MEM_SIZE 100000\n" +
	"#define INT_VAL(temp_placeHolder) (*(int*)(&Memory[temp_placeHolder]))\n" +
    "#define FLOAT_VAL(temp_placeHolder) (*(float*)(&Memory[temp_placeHolder]))\n" +
    "char Memory[MEM_SIZE];\n" +
    "int Frame_Pointer;\n" +
    "int Stack_Pointer;\n" +
    "int Temp;\n" +
    "double Temp_F;\n" +
    "int main() { \n" +
    "Frame_Pointer=0;\n" +
    "Stack_Pointer=0;\n";

// postfix for generated source file
static const std::string CODE_POSTFIX =
    "  return 0;\n}\n";

// used to keep track of whether we are outputting to function or main file
// zero means main file, positive indicates nested function depth
static int Is_Swapped_Output = 0;

// Output files
static FILE *Output = NULL;
static FILE *Functions = NULL;
static int  Next_Label = 1;

//*****************************************
// Open output files and write the prefix
bool codegen::InitOutput(const char *outfileName)
{
    Functions = tmpfile();
    if (Functions == NULL)
    {
        std::cerr << "Unable to open tmpfile for functions" << std::endl;
        return false;
    }

    Output = fopen(outfileName, "w");
    if (Output == NULL)
    {
        std::cerr << "Unable to open " << outfileName << 
           " for output." << std::endl;
        return false;
    }

    EmitString(CODE_PREFIX);

    return true;
}
//*****************************************
// output postfix, copy functions to tail of main file and close files
bool codegen::FinalizeOutput()
{
    EmitString(CODE_POSTFIX);
    RewriteFunctions();
    fclose(Output);
    fclose(Functions);
    return true;
}
//*****************************************
// Start writing to a function. Functions can be nested, and this function
// accomodates that.
void codegen::StartFunctionOutput()
{
    if (!Is_Swapped_Output)
    {
        FILE *temp = Output;
        Output = Functions;
        Functions = temp;
    }
    Is_Swapped_Output++;
}
//*****************************************
// Stop writing a function. This function can handle nested functions
void codegen::EndFunctionOutput()
{
    Is_Swapped_Output--;
    if (!Is_Swapped_Output)
    {
        FILE *temp = Output;
        Output = Functions;
        Functions = temp;
    }
}
//*****************************************
// write a string to the output
void codegen::EmitString(std::string str)
{
    fprintf(Output, "%s", str.c_str());
}
//*****************************************
// write a floating point constant to the output
void codegen::EmitFloat(double val)
{
    fprintf(Output, "%f", val);
}
//*****************************************
// Copy the function file to the end of the main output file
void codegen::RewriteFunctions()
{
    char buff[1000];

    rewind(Functions);
    while (fgets(buff, sizeof(buff), Functions))
    {
        fputs(buff, Output);
    }
}
//*****************************************
// Generate a unique label for GOTO statements
std::string codegen::GenerateLabel()
{
    Next_Label++;
    std::string label("LABEL_");
    label += std::to_string(Next_Label);
    return label;
}
//*****************************************
// write a print statement where the value to be printed is in Temp
void codegen::EmitPrintTemp()
{
    fprintf(Output, "printf(\"%%d\\n\", Temp);\n");
}
//*****************************************
// write a print statement where the value to be printed is in Temp
void codegen::EmitPrintTemp_F()
{
    fprintf(Output, "printf(\"%%6.4f\\n\", Temp_F);\n");
}

void codegen::Reference(int offset, bool isFloat)
{
    if(isFloat)
        fprintf(Output, "FLOAT_VAL(Frame_Pointer+%d)", offset);
    else
        fprintf(Output,"INT_VAL(Frame_Pointer+%d)", offset);
}


void codegen::StackSizeUp(int size)
{
    fprintf(Output, "Stack_Pointer += %d;\n", size);
}


void codegen::StackSizeDown(int size)
{
    fprintf(Output, "Stack_Pointer -= %d;\n", size);
}

