#include <string>
#include "InputTypes.h"

using namespace std;

const string nameTT[] = {"integer", "integer_array", "void"};

string InputType::toString(void) {
    return (nameTT[this->t_type]);
}