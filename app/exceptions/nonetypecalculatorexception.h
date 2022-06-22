#ifndef NONETYPECALCULATOREXCEPTION_H
#define NONETYPECALCULATOREXCEPTION_H

#include "calculatorexception.h"

class NoneTypeCalculatorException : public CalculatorException
{
public:
    NoneTypeCalculatorException();
    QString what();
    static QString message;
};

#endif // NONETYPECALCULATOREXCEPTION_H
