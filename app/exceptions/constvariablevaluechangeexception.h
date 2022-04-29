#ifndef CONSTVARIABLEVALUECHANGEEXCEPTION_H
#define CONSTVARIABLEVALUECHANGEEXCEPTION_H

#include "variableexception.h"

class ConstVariableValueChangeException : public VariableException
{
public:
    ConstVariableValueChangeException(Variable * variable);
    Variable * variable;
    QString what();
    static QString message;
};

#endif // CONSTVARIABLEVALUECHANGEEXCEPTION_H
