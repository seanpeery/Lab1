//***********************************************************************
// Purpose: main routine for LANG compiler
//
// Author: Philip Howard
// Email:  phil.howard@oit.edu
//
// Date: 2/7/2015
//
//***********************************************************************
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "cSymbolTable.h"
#include "lex.h"
#include "cAstNode.h"
#include "langparse.h"

extern cAstNode *yyast_root;

int main(int argc, char **argv)
{
    std::cout << "Sean Peery" << std::endl;

    const char *outfile_name;
    int result = 0;
    std::streambuf *cout_buf = std::cout.rdbuf();

    // set up input based on argv[1]
    if (argc > 1)
    {
        yyin = fopen(argv[1], "r");
        if (yyin == NULL)
        {
            std::cerr << "ERROR: Unable to open file " << argv[1] << "\n";
            exit(-1);
        }
    }

    // setup output based on argv[2]
    if (argc > 2)
    {
        outfile_name = argv[2];
    } else {
        outfile_name = "/dev/tty";
    }

    std::ofstream output(outfile_name);
    if (!output.is_open())
    {
        std::cerr << "ERROR: Unable to open file " << outfile_name << "\n";
        exit(-1);
    }
    std::cout.rdbuf(output.rdbuf());

    // parse the source file
    result = yyparse();
    if (result == 0)
    {
        // print the AST
        std::cout << yyast_root->toString() << std::endl;
    } else {
        std::cout << yynerrs << " Errors in compile\n";
    }

    if (yylex() != 0)
    {
        std::cout << "Junk at end of program\n";
    }

    // restore cout
    output.close();
    std::cout.rdbuf(cout_buf);

    return result;
}
