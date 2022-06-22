#include "nonetypecalculatorexception.h"

QString NoneTypeCalculatorException::message = "Calculator with given name was not found";

NoneTypeCalculatorException::NoneTypeCalculatorException() : CalculatorException(nullptr)
{
}

QString NoneTypeCalculatorException::what()
{
    return this->message;
}
