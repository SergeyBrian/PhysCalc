#ifndef EXCESSAIRRATIOCALCULATOR_H
#define EXCESSAIRRATIOCALCULATOR_H

#include "calculator.h"

class ExcessAirRatioCalculator : public Calculator
{
public:
    ExcessAirRatioCalculator(DataStorage * storage);
    double calculate() override;
};

#endif // EXCESSAIRRATIOCALCULATOR_H
