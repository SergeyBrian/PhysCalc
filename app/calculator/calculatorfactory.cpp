#include "calculatorfactory.h"

#include "../exceptions/calculatorexceptions.h"

Calculator * CalculatorFactory::createCalculator(DataStorage * storage, Calculators::Calculator type) {
    switch (type) {
    case Calculators::HEATING_VALUE:
        return new HeatingValueCalculator(storage);
        break;
    case Calculators::HEAT_CAPACITY:
        return new HeatCapacityCalculator(storage);
        break;
    case Calculators::EXCESS_AIR_RATIO:
        return new ExcessAirRatioCalculator(storage);
        break;
    case Calculators::STOICHIOMETRIC_RATIO:
        return new StoichiometricRatioCalculator(storage);
        break;
    case Calculators::NONE:
        throw NoneTypeCalculatorException();
    }
}
