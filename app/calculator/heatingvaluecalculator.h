#ifndef HEATINGVALUECALCULATOR_H
#define HEATINGVALUECALCULATOR_H

#include "calculator.h"

class HeatingValueCalculator : public Calculator
{
public:
    HeatingValueCalculator(DataStorage * storage);
    std::vector<QString> getRequiredVariablesList() override;
    double calculate() override;
private:
    static std::vector<QString> variableKeys;
    static std::vector<Variable *> variablePlaceholders;
};

#endif // HEATINGVALUECALCULATOR_H
