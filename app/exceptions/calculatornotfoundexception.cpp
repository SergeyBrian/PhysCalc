#include "calculatornotfoundexception.h"

QString CalculatorNotFoundException::message = "Calculator with given name was not found";

CalculatorNotFoundException::CalculatorNotFoundException(Calculator * calculator, QString requestedName) : CalculatorException(calculator)
{
    this->name = requestedName;
}

QString CalculatorNotFoundException::what()
{
    return this->message;
}
