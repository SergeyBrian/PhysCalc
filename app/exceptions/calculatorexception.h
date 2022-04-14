#ifndef CALCULATOREXCEPTION_H
#define CALCULATOREXCEPTION_H

#include "../calculator/calculator.h"

class CalculatorException
{
public:
    CalculatorException(Calculator * calculator);
    QString what();
    Calculator * calculator;
};

#endif // CALCULATOREXCEPTION_H
