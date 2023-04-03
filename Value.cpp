#include <string>
#include <iostream>

#include "Value.h"
#include "InputTypes.h"


using namespace std;

LValue::LValue(string name, InputType *type, RValue *definition) : Value(leftValue){
    var_name = name;
    this->definition = definition;
    this->type = type;
}

string LValue::toString(void)
{
    return var_name + " of " + type->toString() + " = ";
}

RValue::RValue(ExprType t) : Value(rightValue)
{
    this->type = t;
    // set up default values
    immedValue = 0;
    argCount = 0;
    func = nullptr;
    lSub = nullptr;
    lSub = nullptr;
    rSub = nullptr;
}

string RValue::toString(void)
{
    return "rval";
}

FunctionDecl::FunctionDecl(string name, InputType *ret_type, int argNum, string *argNames, InputType **argTypes, Value **body, int bodyLength)
{
    this->name = name;
    this->ret_type = ret_type;
    this->argNum = argNum;
    this->argNames = argNames;
    this->argTypes = argTypes;
    this->body = body;
    this->bodyLength = bodyLength;
}

std::ostream &operator<<(std::ostream &s, const FunctionDecl &fdecl)
{
    s << "Function: " << fdecl.name << " " << fdecl.ret_type->toString() << " Arguments: " << endl;
    for (int i = 0; i < fdecl.argNum; i++)
    {
        s << fdecl.argNames[i] << ": " << fdecl.argTypes[i]->toString() << endl;
    }
    s << endl;
    for (int i = 0; i < fdecl.bodyLength; i++)
    {
        s << fdecl.body[i]->toString() << endl;
        ;
    }
    s << endl;
    return s;
}