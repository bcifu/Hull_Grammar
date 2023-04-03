#ifndef HULLTREESHAPELISTENEREHADER
#define HULLTREESHAPELISTENEREHADER

#include "Value.h"
#include "HullQueryBaseListener.h"
#include "HullQueryParser.h"

using namespace antlr4;
using namespace std;

// can use parse tree property in the listener to retain values as I exit expressions
// could maybe assign LValList to each function???
class HullTreeShapeListener : public HullQueryBaseListener
{
public:
    unordered_map<std::string, FunctionDecl *> func_map;
    unordered_map<std::string, LValue *> var_map;                                               // need to clear for each fucntion
    tree::ParseTreeProperty<Value *> *subexpressionvals = new tree::ParseTreeProperty<Value *>; // need constructor
    list<FunctionDecl *> func_def_order_list;

private:
    InputType *extractDeclType(HullQueryParser::DeclContext *ctx);

public:
    friend std::ostream &operator<<(std::ostream &s, const HullTreeShapeListener &listener);

    void exitOper(HullQueryParser::OperContext *ctx) override;

    void exitRet(HullQueryParser::RetContext *ctx) override;

    void exitImmed(HullQueryParser::ImmedContext *ctx) override;

    void exitAssign(HullQueryParser::AssignContext *ctx) override;

    // if this throws an error it is because the variable has not been mapped
    void exitVariable(HullQueryParser::VariableContext *ctx) override;

    void exitFunc(HullQueryParser::FuncContext *ctx) override;

    void exitFunction(HullQueryParser::FunctionContext *ctx) override;

    void exitVarfunc(HullQueryParser::VarfuncContext *ctx) override;

    InputType *getFuncDecRetType(HullQueryParser::FuncdeclretContext *ctx);

    void exitFuncdecl(HullQueryParser::FuncdeclContext *ctx) override;

    HullTreeShapeListener(void) {

    };
};

#endif