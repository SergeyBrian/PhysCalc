#ifndef EXCESSAIRRATIOCALCULATOR_H
#define EXCESSAIRRATIOCALCULATOR_H

#include "calculator.h"

class ExcessAirRatioCalculator : public Calculator
{
public:
    ExcessAirRatioCalculator(DataStorage * storage);
    std::vector<QString> getRequiredVariablesList() override;
    double calculate() override;
private:
    static std::vector<QString> variableKeys;
    static std::vector<Variable *> variablePlaceholders;
};

#endif // EXCESSAIRRATIOCALCULATOR_H
