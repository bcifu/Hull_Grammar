#include <iostream>
#include <fstream>
#include <string>
#include "antlr4-runtime.h"
#include "HullQueryLexer.h"
#include "HullQueryParser.h"
#include "HullQueryBaseListener.h"

using namespace antlr4;
using namespace std;

string listToString(list<string> lst){
    string result;
    for(const auto& s : lst){
        result += s;
        result += " ";
    }
    return result;
}

/* Types
 Enum that handles what the valid types are
 A general type class that stores if something is an array or not, and the types.
 An array subtype that should also be inherited from for arrays
 And the instantion of types
*/

enum InputTypes
{
    integer,
    integer_array
};

class InputType {
protected:
    InputTypes t_type;
    bool is_array;

    InputType(InputTypes t, bool ar){
        t_type = t;
        is_array = ar;
    }

    bool isArray(void)
    {
        return is_array;
    }

    bool getType(void){
        return t_type;
    }
};

class Array {
    protected:
    int size;

    Array(int size){
        this->size = size;
    }

    int get_size(void){
        return size;
    }
};

class IntT : public InputType
{
    public:
    IntT(void) : InputType(integer, false){
    }
};

class IntArray : public InputType, public Array
{
    public:
    IntArray(int size) : InputType(integer_array, false), Array(size) {
    }
};

enum ValueType{leftValue, rightValue};

class Value {
    public:
    ValueType type;

    Value(ValueType type){
        this->type = type;
    }
};

class RValue : public Value
{
public:
    string rvaltemp;
    RValue(string tmp) : Value(rightValue)
    {
        rvaltemp = tmp;
    }
};

class LValue : public Value {
    public:
    string var_name;
    RValue* definition;
    InputType* type;
    LValue(string name, InputType* type, RValue* definition) : Value(leftValue){
        var_name = name;
        this->definition = definition;
        this->type = type;
    }
};


//can use parse tree maps
class HullTreeShapeListener : public HullQueryBaseListener {
    public:
        list<LValue> LValList; 

    public: 
    void enterExpr(HullQueryParser::ExprContext *ctx) override {
        HullQueryParser::DeclContext* decl = ctx->decl();

        if(decl == nullptr) return; //not a declaration, don't process here.

        // find right side
        HullQueryParser::ExprContext *right = ctx->expr();
        while (right->expr() != nullptr)
        { // while there are more things to the right
            right = right->expr();
        }
        // set right to be the variable, function, or var.func

        string component = "";

        if (right->var() != nullptr)
        {
            component.append(right->var()->getText());
            component.append(".");
        }

        HullQueryParser::FuncContext *func = right->func();
        while (func != nullptr)
        { // while there are functions to work with
            component.append(func->ID()->getText());
            // What is the best way to handle function arguments
            component.append(".");
            func = func->func();
        }

        InputType* lvtype;
        string type = decl->type()->ID()->getText();
        tree::TerminalNode* num = decl->INT();
        if(num == nullptr){
            lvtype = new IntT();
        } else {
            lvtype = new IntArray(stoi(decl->INT()->getText()));
        }

        RValue* def = new RValue(component);

        LValue* left = new LValue(decl->ID()->getText(), lvtype, def);

        //need to get type

        // std::for_each(varaible_map[variable_name].begin(), varaible_map[variable_name].end(), [](const auto &e) {
        //     std::cout << e << " ";
        // });
        // std::cout << std::endl;

        //toStringTree or getText on terminal
        // std::cout << "Decl: " << decl->ID()->toStringTree() << std::endl;
        string variable_name = decl->ID()->getText();
        //need to handle if several variables assigned (a = b = c.func()), maybe do with other expressions, just assign the right

       
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

    // for (auto iter = cbegin(listener.varaible_map); iter != cend(listener.varaible_map); ++iter){
    //     cout << iter->first << ": " << listToString(iter->second) << endl; 
    // }

    return 0;
}
