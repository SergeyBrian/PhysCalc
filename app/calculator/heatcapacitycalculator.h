#ifndef HEATCAPACITYCALCULATOR_H
#define HEATCAPACITYCALCULATOR_H
#include <cmath>

#include "calculator.h"

class HeatCapacityCalculator : public Calculator
{
public:
    HeatCapacityCalculator(DataStorage * storage);
    double calculate() override;

private:
    void calculateC_pmi_p(QString key = "C_pmi_p");
    void calculateByTemp(QString key = "C_p")

};



#endif // HEATCAPACITYCALCULATOR_H
