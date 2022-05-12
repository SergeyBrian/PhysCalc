#include "calculatorinterface.h"

#include "../exceptions/calculatorexceptions.h"

QDialog * DialogInterface::create(Calculators::Calculator c, DataStorage * storage) {
    switch (c) {
    case Calculators::HEATING_VALUE:
        return new HeatingValueWindow(storage);
        break;
    case Calculators::HEAT_CAPACITY:
        return new HeatCapacityCalculatorWindow(storage);
        break;
    case Calculators::EXCESS_AIR_RATIO:
        return new ExcessAirRatioWindow(storage);
        break;
    case Calculators::STOICHIOMETRIC_RATIO:
        return new StoichiometricRatioWindow(storage);
        break;
    case Calculators::NONE:
        throw NoneTypeCalculatorException();
        break;
    }
}

double CalculatorInterface::calculate(Calculators::Calculator c, DataStorage *storage)
{
    QDialog * dialog = DialogInterface::create(c, storage);
    Calculator * calculator = CalculatorFactory::createCalculator(storage, c);
    dialog->exec();
    return calculator->calculate();
}
