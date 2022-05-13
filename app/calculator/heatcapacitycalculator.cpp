#include "heatcapacitycalculator.h"
#include "../exceptions/dataexceptions.h"
#include <cmath>

HeatCapacityCalculator::HeatCapacityCalculator(DataStorage * storage) : Calculator(storage)
{
}

double HeatCapacityCalculator::calculate()
{
    return 0;
}

void HeatCapacityCalculator::calculateC_pmi_p(QString key)
{
    storage->setValue(key, $(""))
}

void HeatCapacityCalculator::calculateByTemp(QString key)
{
    auto T = storage->getValue<std::map<double, double>>("T");


    int c=0;
    int p=0;
    for (auto const & element : T)
    {
        if ($("T")<element.first)
        {
            storage->setValue(key, c+(($("T")-p)/(element.first-p)*(element.second-c)));
        }
        c = element.second;
        p = element.first;
    }
}

