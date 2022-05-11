#include "heatingvaluecalculator.h"
#include "../exceptions/dataexceptions.h"

HeatingValueCalculator::HeatingValueCalculator(DataStorage * storage) : Calculator(storage)
{
    
}

double HeatingValueCalculator::calculate()
{

    return 0;
}

void HeatingValueCalculator::calculateLiquid()
{
    double Q_vv;
    if(storage->getValue("C_m")->value<QVariant *>()->isNull())
    {
        for(int i=1; i<=n; i++)
        {
            double X;
            X=$("Q_l",i)*$("C_v",i)
            Q_vv+= X;
        }
    }
    else
    {
        for(int i=1; i <= n; i++)
        {
            double X;
            X=$("Q_l", i)*$("C_m",i)*$("p", i);
            Q_vv+= X;
        }
    }
}

void HeatingValueCalculator::calculateSolid()
{

}

void HeatingValueCalculator::calculateVolumetric()
{

}

void HeatingValueCalculator::calculateMass()
{

}
