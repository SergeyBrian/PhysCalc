#include "constvariablevaluechangeexception.h"

QString ConstVariableValueChangeException::message = "Can't change value of const variable";

ConstVariableValueChangeException::ConstVariableValueChangeException(Variable * variable) : VariableException(variable)
{
    this->variable = variable;
}

QString ConstVariableValueChangeException::what()
{
    return this->message;
}
