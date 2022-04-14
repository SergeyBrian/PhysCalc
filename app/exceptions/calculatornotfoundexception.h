#ifndef CALCULATORNOTFOUNDEXCEPTION_H
#define CALCULATORNOTFOUNDEXCEPTION_H

#include "calculatorexception.h"

class CalculatorNotFoundException : public CalculatorException
{
public:
    CalculatorNotFoundException(Calculator * calculator, QString requestedName);
    QString what();
    QString name;
    static QString message;
};

#endif // CALCULATORNOTFOUNDEXCEPTION_H
