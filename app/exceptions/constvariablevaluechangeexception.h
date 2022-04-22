#ifndef CONSTVARIABLEVALUECHANGEEXCEPTION_H
#define CONSTVARIABLEVALUECHANGEEXCEPTION_H

#include "variableexception.h"

class ConstVariablevalueChangeException : public VariableException
{
public:
    ConstVariablevalueChangeException(Variable * variable);
    Variable * variable;
    QString what();
    static QString message;
};

#endif // CONSTVARIABLEVALUECHANGEEXCEPTION_H
