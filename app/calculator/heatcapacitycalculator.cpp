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

void HeatCapacityCalculator::calculateC_pmi(QString key)
{
    storage->writeValue(key, (calculateByTempHelp("T_b")*$("T_b")-calculateByTempHelp("T_e")*$("T_e"))/($("T_b")-$("T_e")));
}

void HeatCapacityCalculator::calculateC_pms(QString key)
{
    storage->writeValue(key, (calculateByTempHelp("T_b")*log($("T_b")/273.15)-calculateByTempHelp("T_e")*log($("T_e")/273.15))/log($("T_b")/$("T_e")));
}

double HeatCapacityCalculator::calculateC_pmsHelp()
{
    return (calculateByTempHelp("T_b")*log($("T_b")/273.15)-calculateByTempHelp("T_e")*log($("T_e")/273.15))/log($("T_b")/$("T_e"));
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
            storage->writeValue(key, c+(($("T")-p)/(element.first-p)*(element.second-c)));
        }
        c = element.second;
        p = element.first;
    }
}

double HeatCapacityCalculator::calculateByTempHelp(QString key)
{
    auto T_pm_c = storage->getValue<std::map<double, double>>("T");


    int c=0;
    int p=0;
    for (auto const & element : T_pm_c)
    {
        if ($(key)<element.first)
        {
            return c+(($(key)-p)/(element.first-p)*(element.second-c));
        }
        c = element.second;
        p = element.first;
    }
}
