#include <iostream>
#include <fstream>
#include <string>
#include "antlr4-runtime.h"
#include "HullQueryLexer.h"
#include "HullQueryParser.h"
#include "HullQueryBaseListener.h"
#include "InputTypes.h"
#include "Value.h"
#include "HullTreeShapeListener.h"

using namespace antlr4;
using namespace std;


int main(int argc, char *argv[])
{
    if(argc == 1){
        std::cout << "Mising input file.n" << std::endl;
        exit(0);
    }

    std::ifstream inputfile;
    inputfile.open(argv[1]);

    //set up to read from file
    antlr4::ANTLRInputStream input(inputfile);

    //set up lexer
    HullQueryLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);

    HullQueryParser parser(&tokens);

    //std::cout << parser.expr()->toStringTree() << std::endl;

    tree::ParseTree *tree = parser.query();
    HullTreeShapeListener listener;

    tree::ParseTreeWalker::DEFAULT.walk(&listener, tree);

    std::cout << listener << std::endl;

    return 0;
}
