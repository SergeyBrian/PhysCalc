#ifndef HEATCAPACITYCALCULATOR_H
#define HEATCAPACITYCALCULATOR_H

#include "calculator.h"
#include <cmath>

class HeatCapacityCalculator : public Calculator
{
public:
    HeatCapacityCalculator(DataStorage * storage);
    double calculate() override;
private:
    void T_szh();
    void T_rassh();
    void R_smesi();
    void end_rassh();
    void end_szh();
};

#endif // HEATCAPACITYCALCULATOR_H
