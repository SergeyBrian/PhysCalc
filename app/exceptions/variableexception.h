#ifndef VARIABLEEXCEPTION_H
#define VARIABLEEXCEPTION_H

#include "../data/variable.h"

class VariableException
{
public:
    VariableException(Variable * variable);
    Variable * variable;
    QString what();
};

#endif // VARIABLEEXCEPTION_H
