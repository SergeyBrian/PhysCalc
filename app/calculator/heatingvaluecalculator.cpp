#include "heatingvaluecalculator.h"
#include "../exceptions/dataexceptions.h"

HeatingValueCalculator::HeatingValueCalculator(DataStorage * storage) : Calculator(storage)
{
}

double HeatingValueCalculator::calculate()
{
    return 0;
}
