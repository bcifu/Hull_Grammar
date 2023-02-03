#include <iostream>
#include <fstream>
#include <string>
#include "antlr4-runtime.h"
#include "HullQueryLexer.h"
#include "HullQueryParser.h"

using namespace antlr4;
using namespace std;
using namespace HullQuery;

int main(int argc, char *argv[])
{
    if(argc == 1){
        std::cout << "Mising input file.n\n" << std::endl;
        exit(0);
    }

    std::ifstream inputfile;
    inputfile.open(argv[1]);

    antlr4::ANTLRInputStream input(std::string("int a[50] = signal();\nint b = function();\nint c[50] = a.process();\nint d[50] = c.process2(b).finish();"));

    HullQueryLexer lexer(&input);

    antlr4::CommonTokenStream tokens(&lexer);

    HullQueryParser parser(&tokens);

    std::cout << parser.expr()->toStringTree() << std::endl;

    return 0;
}
