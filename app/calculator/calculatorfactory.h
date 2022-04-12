#ifndef CALCULATORFACTORY_H
#define CALCULATORFACTORY_H

#include "calculator.h"

class CalculatorFactory
{
public:
    Calculator * createCalculator();
    static CalculatorFactory * getFactory();
};

class HeatCapacityCalculatorFactory : public CalculatorFactory {
public:
    Calculator * createCalculator() {
        return new HeatCapacityCalculator();
    }

};

class HeatingValueCalculatorFactory : public CalculatorFactory {
public:
    Calculator * createCalculator() {
        return new HeatingValueCalculator();
    }
};

class ExcessAirRatioCalculatorFactory : public CalculatorFactory {
public:
    Calculator * createCalculator() {
        return new ExcessAirRatioCalculator();
    }
};

#endif // CALCULATORFACTORY_H
