#ifndef CALCULATORNOTFOUNDEXCEPTION_H
#define CALCULATORNOTFOUNDEXCEPTION_H

#include "calculatorexception.h"

class CalculatorNotFoundException : public CalculatorException
{
public:
    CalculatorNotFoundException(Calculator * calculator, std::string requestedName);
    std::string what();
    std::string name;
    static std::string message;
};

#endif // CALCULATORNOTFOUNDEXCEPTION_H
