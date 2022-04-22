#ifndef VARIABLEEXCEPTION_H
#define VARIABLEEXCEPTION_H

#include "../data/variable.h"

class VariableException
{
public:
    VariableException(Variable * variable);
    Variable * variable;
    QString what();
    static QString message;
};

#endif // VARIABLEEXCEPTION_H
