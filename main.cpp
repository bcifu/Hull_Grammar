#include <iostream>
#include <fstream>
#include <string>
#include "antlr4-runtime.h"
#include "HullQueryLexer.h"
#include "HullQueryParser.h"
#include "HullQueryBaseListener.h"
#include "InputTypes.h"
// using namespace InputTypes;

using namespace antlr4;
using namespace std;

enum ValueType{leftValue, rightValue};

class Value {
    public:
    ValueType type;

    Value(ValueType type){
        this->type = type;
    }

    virtual string toString(void){
        return "";
    }
};

enum ExprType{variable, functionE, varfunc, immed, oper, ret};

class RValue;
class FunctionDecl;

class LValue : public Value
{
public:
    string var_name;
    RValue *definition;
    InputType *type;
    LValue(string name, InputType *type, RValue *definition) : Value(leftValue)
    {
        var_name = name;
        this->definition = definition;
        this->type = type;
    }

    virtual string toString(void)
    {
        return var_name + " of " + type->toString() + " = ";
    }
};

class RValue : public Value
{
public:
    ExprType type;
    int immedValue;
    FunctionDecl* func; //change to be pointer to function
    int argCount;
    list<RValue*> arguments;
    LValue *variable; //if referencing a variable
    RValue *lSub; //if it is a funciton, this what it is called on
    RValue *rSub; //if is a function, this is next funciton call

    RValue(ExprType t) : Value(rightValue)
    {
        this->type = t;
        //set up default values
        immedValue = 0;
        argCount = 0;
        func = nullptr;
        lSub = nullptr;
        lSub = nullptr;
        rSub = nullptr;
    }

    virtual string toString(void)
    {
        return "rval";
    }
};

class FunctionDecl
{
public:
    string name;
    InputType *ret_type;
    int argNum;                            // 0 => void
    string* argNames;
    InputType** argTypes;
    Value **body;                          // list of Value* for the body of the function
    int bodyLength;
    friend std::ostream &operator<<(std::ostream &s, const FunctionDecl &fdecl);

    FunctionDecl(string name, InputType *ret_type, int argNum, string* argNames, InputType** argTypes, Value **body, int bodyLength)
    {
        this->name = name;
        this->ret_type = ret_type;
        this->argNum = argNum;
        this->argNames = argNames;
        this->argTypes = argTypes;
        this->body = body;
        this->bodyLength = bodyLength;
    }
};

//can use parse tree property in the listener to retain values as I exit expressions
//could maybe assign LValList to each function???
class HullTreeShapeListener : public HullQueryBaseListener {
    public:
        unordered_map<std::string, FunctionDecl*> func_map;
        unordered_map<std::string, LValue*> var_map; //need to clear for each fucntion
        tree::ParseTreeProperty<Value*> *subexpressionvals = new tree::ParseTreeProperty<Value*>; //need constructor
        list<FunctionDecl*> func_def_order_list;

    private:
    InputType* extractDeclType(HullQueryParser::DeclContext *ctx) {
        InputType *type;
        if (ctx->INT() == nullptr)
        {
            type = new IntT();
            // not array
        }
        else
        {
            type = new IntArray(stoi(ctx->INT()->getText()));
        }
        return type;
    }

    public:
        friend std::ostream &operator<<(std::ostream &s, const HullTreeShapeListener &listener);

    void exitOper(HullQueryParser::OperContext *ctx) override
    {
        RValue* current = new RValue(oper);
        current->lSub = (RValue *) subexpressionvals->get(ctx->expr(0));
        current->rSub = (RValue *) subexpressionvals->get(ctx->expr(1));
        subexpressionvals->put(ctx, current);
    }

    void exitRet(HullQueryParser::RetContext *ctx) override {
        RValue* current = new RValue(ret);
        current->rSub = (RValue *) subexpressionvals->get(ctx->expr());
        subexpressionvals->put(ctx, current);
    }

    void exitImmed(HullQueryParser::ImmedContext *ctx) override {
        RValue* current = new RValue(immed);
        current->immedValue = stoi(ctx->immediate()->getText());
        subexpressionvals->put(ctx, current);
    }

    void exitAssign(HullQueryParser::AssignContext *ctx) override { 
        InputType* type = extractDeclType(ctx->decl());

        string name = ctx->decl()->ID()->getText();
        LValue *var = new LValue(name, type, (RValue *)subexpressionvals->get(ctx->expr()));
        var_map[name] = var;
        subexpressionvals->put(ctx, var);
    }

    //if this throws an error it is because the variable has not been mapped
    void exitVariable(HullQueryParser::VariableContext *ctx) override {
        RValue *current = new RValue(variable);
        current->variable = var_map[ctx->var()->getText()];
        subexpressionvals->put(ctx, current);
    }

    void exitFunc(HullQueryParser::FuncContext *ctx) override {
        RValue *current = new RValue(functionE);
        current->func = func_map[ctx->ID()->getText()];
        current->argCount = ctx->arglist()->expr().size();
        for(HullQueryParser::ExprContext *ectx : ctx->arglist()->expr()){
            current->arguments.push_back((RValue *) subexpressionvals->get(ectx));
        }

        if(ctx->func() != nullptr){
            current->rSub = (RValue *) subexpressionvals->get(ctx->func());
        }

        subexpressionvals->put(ctx, current);
    }

    void exitFunction(HullQueryParser::FunctionContext *ctx) override {
        subexpressionvals->put(ctx, subexpressionvals->get(ctx->func()));
    }

    void exitVarfunc(HullQueryParser::VarfuncContext *ctx) override {
        RValue *current = (RValue *) subexpressionvals->get(ctx->func());
        RValue *lvar = new RValue(variable);
        lvar->variable = var_map[ctx->var()->getText()];
        current->lSub = lvar;
        subexpressionvals->put(ctx, current);
    }

    InputType* getFuncDecRetType(HullQueryParser::FuncdeclretContext *ctx)  {
        InputType* type;
        if(ctx->VOID() != nullptr){
            type = new VoidT();
        } else if(ctx->INT() == nullptr){
            type = new IntT();
        } else {
            type = new IntArray(stoi(ctx->INT()->getText()));
        }
        return type;
    }

    void exitFuncdecl(HullQueryParser::FuncdeclContext *ctx) override {
        InputType* type = getFuncDecRetType(ctx->funcdeclret());

        int argNum;
        string *argNames;
        InputType **argTypes;
        if(ctx->VOID() != nullptr){ //no argument (null passed)
            argNum = 0;
            argNames = nullptr;
            argTypes = nullptr;
        } else {
            HullQueryParser::ParamlistContext *params = ctx->paramlist();
            argNum = params->decl().size();
            argNames = new string[argNum];
            argTypes = new InputType*[argNum];
            for(int i = 0; i < argNum; i++){
                HullQueryParser::DeclContext *decl = params->decl()[i]; 
                InputType* type = extractDeclType(decl);
                argNames[i] = decl->ID()->getText();
                argTypes[i] = type;
            }
        }

        int bodyLength = ctx->body()->expr().size();
        Value** body = new Value*[bodyLength];
        for(int i = 0; i < bodyLength; i++){
            body[i] = subexpressionvals->get(ctx->body()->expr(i));
        }

        var_map.clear(); //clear variables for next function.

        FunctionDecl *func = new FunctionDecl(ctx->ID()->getText(), type, argNum, argNames, argTypes, body, bodyLength);
        func_map[ctx->ID()->getText()] = func;
        func_def_order_list.push_back(func);
    }
};

std::ostream &operator<<(std::ostream &s, const HullTreeShapeListener &listener){
    for (FunctionDecl* fdecl : listener.func_def_order_list){
        s << (*fdecl);
    }
    return s;
}

std::ostream &operator<<(std::ostream &s, const FunctionDecl &fdecl){    
    s << "Function: " << fdecl.name << " "<< fdecl.ret_type->toString() << " Arguments: " << endl;
    for (int i = 0; i < fdecl.argNum; i++)
    {
        s << fdecl.argNames[i] << ": " << fdecl.argTypes[i]->toString() << endl;
    }
    s << endl;
    for (int i = 0; i < fdecl.bodyLength; i++){
        s << fdecl.body[i]->toString() << endl;;
    }
    s << endl;
    return s;
}

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
