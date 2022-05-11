#ifndef HEATINGVALUECALCULATOR_H
#define HEATINGVALUECALCULATOR_H

#include "calculator.h"

class HeatingValueCalculator : public Calculator
{
public:
    HeatingValueCalculator(DataStorage * storage);
    double calculate() override;
private:
    void calculateLiquid();
    void calculateSolid();
    void calculateVolumetric();
    void calculateMass();
};

#endif // HEATINGVALUECALCULATOR_H
