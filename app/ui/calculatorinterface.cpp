#include "calculatorinterface.h"

#include "../exceptions/calculatorexceptions.h"

QDialog * DialogInterface::create(Calculators::Calculator c) {
    switch (c) {
    case Calculators::HEATING_VALUE:
        return new HeatingValueWindow();
        break;
    case Calculators::HEAT_CAPACITY:
        return new HeatCapacityCalculatorWindow();
        break;
    case Calculators::EXCESS_AIR_RATIO:
        return new ExcessAirRatioWindow();
        break;
    case Calculators::STOICHIOMETRIC_RATIO:
        return new StoichiometricRatioWindow();
        break;
    case Calculators::NONE:
        throw NoneTypeCalculatorException();
        break;
    }
}

double CalculatorInterface::calculate(Calculators::Calculator c, DataStorage *storage)
{
    QDialog * dialog = DialogInterface::create(c);
    Calculator * calculator = CalculatorFactory::createCalculator(storage, c);
    dialog->exec();
    return calculator->calculate();
}
