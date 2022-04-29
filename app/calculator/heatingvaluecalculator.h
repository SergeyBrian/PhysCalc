#ifndef HEATINGVALUECALCULATOR_H
#define HEATINGVALUECALCULATOR_H

#include "calculator.h"

class HeatingValueCalculator : public Calculator
{
public:
    HeatingValueCalculator(DataStorage * storage);
    double calculate() override;
};

#endif // HEATINGVALUECALCULATOR_H
