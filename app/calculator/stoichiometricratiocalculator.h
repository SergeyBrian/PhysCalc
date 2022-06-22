#ifndef STOICHIOMETRICRATIOCALCULATOR_H
#define STOICHIOMETRICRATIOCALCULATOR_H

#include "calculator.h"

class StoichiometricRatioCalculator : public Calculator
{
public:
    StoichiometricRatioCalculator(DataStorage * storage);
    double calculate() override;
};

#endif // STOICHIOMETRICRATIOCALCULATOR_H
