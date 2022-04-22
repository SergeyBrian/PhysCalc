#include "variableexception.h"

VariableException::VariableException(Variable * variable)
{
    this->variable = variable;
}

QString VariableException::what()
{
    return this->message;
}
