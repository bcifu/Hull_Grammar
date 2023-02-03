#include <iostream>
#include <fstream>
#include <string>
#include "antlr4-runtime.h"
#include "HullQueryLexer.h"
#include "HullQueryParser.h"
#include "HullQueryBaseListener.h"

using namespace antlr4;
using namespace std;

class HullTreeShapeListener : public HullQueryBaseListener {
    public:
        unordered_map<std::string, list<string>> varaible_map; 

    public: 
    void enterExpr(HullQueryParser::ExprContext *ctx) override {
        HullQueryParser::DeclContext* decl = ctx->decl();

        if(decl == nullptr) return; //not a declaration, don't process here.

        //toStringTree or getText on terminal
        std::cout << "Decl: " << decl->ID()->toStringTree() << std::endl;
        string variable_name = decl->ID()->getText();
        //need to handle if several variables assigned (a = b = c.func()), maybe do with other expressions, just assign the right

        //find right side
        HullQueryParser::ExprContext* right = ctx->expr();
        while(right->expr() != nullptr) { //while there are more things to the right
            right = right->expr();
        }
        //set right to be the variable, function, or var.func

        this->varaible_map[variable_name] = {};

        if(right->var() != nullptr){
            this->varaible_map[variable_name].push_back(right->var()->getText());
        }

        std::for_each(varaible_map[variable_name].begin(), varaible_map[variable_name].end(), [](const auto &e) {
            std::cout << e << " ";
        });
        std::cout << std::endl;
    }
};

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

    return 0;
}
