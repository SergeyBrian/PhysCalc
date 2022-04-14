#include "calculatorfactory.h"

Calculator * CalculatorFactory::createCalculator(DataStorage * storage) {
    std::string calculatorName = storage->getValue<std::string>("CURRENT_CALCULATOR");
    if (calculatorName == "HEAT_CAPACITY")
        return new HeatCapacityCalculator(storage);
    if (calculatorName == "HEATING_VALUE")
        return new HeatingValueCalculator(storage);
    if (calculatorName == "EXCESS_AIR_RATIO")
        return new ExcessAirRatioCalculator(storage);
}
