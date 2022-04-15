#ifndef HEATCAPACITYCALCULATOR_H
#define HEATCAPACITYCALCULATOR_H

#include "calculator.h"

class HeatCapacityCalculator : public Calculator
{
public:
    HeatCapacityCalculator(DataStorage * storage);
    std::vector<QString> getRequiredVariablesList() override;
    double calculate() override;
private:
    static std::vector<QString> variableKeys;
    static std::vector<Variable *> variablePlaceholders;
};

#endif // HEATCAPACITYCALCULATOR_H
