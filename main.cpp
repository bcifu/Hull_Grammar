#include <iostream>

#include "antlr4-runtime.h"
#include "HullQueryLexer.h"
#include "HullQueryParser.h"
#include "HullQueryBaseListener.h"

using namespace antlr4;

class TreeShapeListener : public HullQueryBaseListener
{
public:
    void enterQuery(ParserRuleContext *ctx) override
    {
        // Do something when entering the key rule.
    }
};

int main(int argc, const char *argv[])
{
    std::ifstream stream;
    stream.open(argv[1]);
    ANTLRInputStream input(stream);
    HullQueryLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    HullQueryLexer parser(&tokens);

    tree::ParseTree *tree = parser.key();
    TreeShapeListener listener;
    tree::ParseTreeWalker::DEFAULT.walk(&listener, tree);

    return 0;
}