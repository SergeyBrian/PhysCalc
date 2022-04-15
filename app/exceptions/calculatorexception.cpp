#include "calculatorexception.h"

CalculatorException::CalculatorException(Calculator * calculator)
{
    this->calculator = calculator;
}
