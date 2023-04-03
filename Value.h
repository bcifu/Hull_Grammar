#ifndef VALUEHEADER
#define VALUEHEADER

#include <string>
#include <list>
#include "InputTypes.h"


using namespace std;

enum ValueType
{
    leftValue,
    rightValue
};

class Value
{
public:
    ValueType type;

    Value(ValueType type)
    {
        this->type = type;
    }

    virtual string toString(void)
    {
        return "";
    }
};

enum ExprType
{
    variable,
    functionE,
    varfunc,
    immed,
    oper,
    ret
};

class RValue;
class FunctionDecl;

class LValue : public Value
{
public:
    string var_name;
    RValue *definition;
    InputType *type;
    LValue(string name, InputType *type, RValue *definition);
    string toString(void);
};

class RValue : public Value
{
public:
    ExprType type;
    int immedValue;
    FunctionDecl *func; // change to be pointer to function
    int argCount;
    std::list<RValue *> arguments;
    LValue *variable; // if referencing a variable
    RValue *lSub;     // if it is a funciton, this what it is called on
    RValue *rSub;     // if is a function, this is next funciton call
    string funcName;

    RValue(ExprType t);
    string toString(void);
};

class FunctionDecl
{
public:
    string name;
    InputType *ret_type;
    int argNum; // 0 => void
    string *argNames;
    InputType **argTypes;
    Value **body; // list of Value* for the body of the function
    int bodyLength;
    friend std::ostream &operator<<(std::ostream &s, const FunctionDecl &fdecl);

    FunctionDecl(string name, InputType *ret_type, int argNum, string *argNames, InputType **argTypes, Value **body, int bodyLength);
};

#endif