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
    void calculateC_pmi(QString key = "C_pmi_p");
    void calculateByTemp(QString key = "C_p");
    double calculateByTempHelp(QString key = "T");
    double calculateC_pmsHelp();
    void calculateC_pms(QString key = "C_pms");
};



#endif // HEATCAPACITYCALCULATOR_H
