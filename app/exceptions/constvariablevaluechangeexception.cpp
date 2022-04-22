#include "constvariablevaluechangeexception.h"

QString message = "Can't change value of const variable";

ConstVariablevalueChangeException::ConstVariablevalueChangeException(Variable * variable) : VariableException(variable)
{
    this->variable = variable;
}
