#ifndef INPUTTYPESHEADER
#define INPUTTYPESHEADER

#include <string>
#include "InputTypes.h"

enum InputTypes
{
    integer,
    integer_array,
    void_ty
};

class InputType
{
protected:
    InputTypes t_type;
    bool is_array;

    InputType(InputTypes t, bool ar)
    {
        t_type = t;
        is_array = ar;
    }

    bool isArray(void)
    {
        return is_array;
    }

    bool getType(void)
    {
        return t_type;
    }

public:
    std::string toString(void);
    friend std::ostream &operator<<(std::ostream &s, const InputType &it);
};

class Array
{
protected:
    int size;

    Array(int size)
    {
        this->size = size;
    }

    int get_size(void)
    {
        return size;
    }
};

class IntT : public InputType
{
public:
    IntT(void) : InputType(integer, false)
    {
    }
};

class IntArray : public InputType, public Array
{
public:
    IntArray(int size) : InputType(integer_array, false), Array(size)
    {
    }
};

class VoidT : public InputType
{
public:
    VoidT(void) : InputType(void_ty, false)
    {
    }
};

#endif