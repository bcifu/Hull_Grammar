
#include "HullQueryBaseListener.h"
#include "HullTreeShapeListener.h"
#include "HullQueryParser.h"
#include "Value.h"

using namespace std;

InputType *HullTreeShapeListener::extractDeclType(HullQueryParser::DeclContext *ctx)
{
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

void HullTreeShapeListener::exitOper(HullQueryParser::OperContext *ctx) 
{
    RValue *current = new RValue(oper);
    current->lSub = (RValue *)subexpressionvals->get(ctx->expr(0));
    current->rSub = (RValue *)subexpressionvals->get(ctx->expr(1));
    subexpressionvals->put(ctx, current);
}

void HullTreeShapeListener::exitRet(HullQueryParser::RetContext *ctx) 
{
    RValue *current = new RValue(ret);
    current->rSub = (RValue *)subexpressionvals->get(ctx->expr());
    subexpressionvals->put(ctx, current);
}

void HullTreeShapeListener::exitImmed(HullQueryParser::ImmedContext *ctx) 
{
    RValue *current = new RValue(immed);
    current->immedValue = stoi(ctx->immediate()->getText());
    subexpressionvals->put(ctx, current);
}

void HullTreeShapeListener::exitAssign(HullQueryParser::AssignContext *ctx) 
{
    InputType *type = extractDeclType(ctx->decl());

    string name = ctx->decl()->ID()->getText();
    LValue *var = new LValue(name, type, (RValue *)subexpressionvals->get(ctx->expr()));
    var_map[name] = var;
    subexpressionvals->put(ctx, var);
}

// if this throws an error it is because the variable has not been mapped
void HullTreeShapeListener::exitVariable(HullQueryParser::VariableContext *ctx) 
{
    RValue *current = new RValue(variable);
    current->variable = var_map[ctx->var()->getText()];
    subexpressionvals->put(ctx, current);
}

void HullTreeShapeListener::exitFunc(HullQueryParser::FuncContext *ctx) 
{
    RValue *current = new RValue(functionE);
    current->func = func_map[ctx->ID()->getText()];
    current->argName = ctx->ID()->getText();
    current->argCount = ctx->arglist()->expr().size();
    for (HullQueryParser::ExprContext *ectx : ctx->arglist()->expr())
    {
        current->arguments.push_back((RValue *)subexpressionvals->get(ectx));
    }

    if (ctx->func() != nullptr)
    {
        current->rSub = (RValue *)subexpressionvals->get(ctx->func());
    } else {
        current->rSub = nullptr;
    }

    subexpressionvals->put(ctx, current);
}

void HullTreeShapeListener::exitLambda(HullQueryParser::LambdaContext *ctx){
    RValue *current = new RValue(lambda);
    current->argName = ctx->var()->getText();
    current->rSub = (RValue *) subexpressionvals->get(ctx->expr());
    subexpressionvals->put(ctx, current);
}

void HullTreeShapeListener::exitFunction(HullQueryParser::FunctionContext *ctx) 
{
    subexpressionvals->put(ctx, subexpressionvals->get(ctx->func()));
}

void HullTreeShapeListener::exitVarfunc(HullQueryParser::VarfuncContext *ctx) 
{
    RValue *current = (RValue *)subexpressionvals->get(ctx->func());
    RValue *lvar = new RValue(variable);
    lvar->variable = var_map[ctx->var()->getText()];
    current->lSub = lvar;
    subexpressionvals->put(ctx, current);
}

InputType *HullTreeShapeListener::getFuncDecRetType(HullQueryParser::FuncdeclretContext *ctx)
{
    InputType *type;
    if (ctx->VOID() != nullptr)
    {
        type = new VoidT();
    }
    else if (ctx->INT() == nullptr)
    {
        type = new IntT();
    }
    else
    {
        type = new IntArray(stoi(ctx->INT()->getText()));
    }
    return type;
}

void HullTreeShapeListener::exitFuncdecl(HullQueryParser::FuncdeclContext *ctx) 
{
    InputType *type = getFuncDecRetType(ctx->funcdeclret());

    int argNum;
    string *argNames;
    InputType **argTypes;
    if (ctx->VOID() != nullptr)
    { // no argument (null passed)
        argNum = 0;
        argNames = nullptr;
        argTypes = nullptr;
    }
    else
    {
        HullQueryParser::ParamlistContext *params = ctx->paramlist();
        argNum = params->decl().size();
        argNames = new string[argNum];
        argTypes = new InputType *[argNum];
        for (int i = 0; i < argNum; i++)
        {
            HullQueryParser::DeclContext *decl = params->decl()[i];
            InputType *type = extractDeclType(decl);
            argNames[i] = decl->ID()->getText();
            argTypes[i] = type;
        }
    }

    int bodyLength = ctx->body()->expr().size();
    Value **body = new Value *[bodyLength];
    for (int i = 0; i < bodyLength; i++)
    {
        body[i] = subexpressionvals->get(ctx->body()->expr(i));
    }

    var_map.clear(); // clear variables for next function.

    FunctionDecl *func = new FunctionDecl(ctx->ID()->getText(), type, argNum, argNames, argTypes, body, bodyLength);
    func_map[ctx->ID()->getText()] = func;
    func_def_order_list.push_back(func);
}

std::ostream &operator<<(std::ostream &s, const HullTreeShapeListener &listener)
{
    for (FunctionDecl *fdecl : listener.func_def_order_list)
    {
        s << (*fdecl);
    }
    return s;
}

