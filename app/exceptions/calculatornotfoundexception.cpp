#include "calculatornotfoundexception.h"

std::string CalculatorNotFoundException::message = "Calculator with given name was not found";

CalculatorNotFoundException::CalculatorNotFoundException(Calculator * calculator, std::string requestedName) : CalculatorException(calculator)
{
    this->name = requestedName;
}

std::string CalculatorNotFoundException::what()
{
    return this->message;
}
