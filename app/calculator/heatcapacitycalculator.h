#ifndef HEATCAPACITYCALCULATOR_H
#define HEATCAPACITYCALCULATOR_H
#include <cmath>

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
    void calculateC_pmi(QString key = "C_pmi_p");
    void calculateByTemp(QString key = "C_p");
    double calculateByTempHelp(QString key = "T");
    double calculateC_pmsHelp();
    void calculateC_pms(QString key = "C_pms");
};



#endif // HEATCAPACITYCALCULATOR_H
