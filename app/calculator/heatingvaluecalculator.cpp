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
    if(storage->getValue("C_m")->isEmpty())
    {
        for(int i=1; i<=n; i++)
        {
            double X;
            X=$("Q_l",i)*$("C_v",i);
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

void HeatingValueCalculator::calculateGas()
{
    double Q_vv;
    if(storage->getValue("C_m")->isEmpty())
        {
        for(int i=1; i<=n; i++)
        {
            double X;
            X=$("Q_l",i)*$("C_v",i);
            Q_vv+= X;
        }
    }
    else
    {
        double M;
        for(int i=1; i<=n; i++)
        {
            M=$("C_m",i)/$("M",i);
        }
        for(int i=1; i<=n; i++)
        {
            double X;
            X=$("Q_l",i)*$("C_m",i)*$("m",i)*M/$("M",i);
            Q_vv+= X;
        }
    }
}

void HeatingValueCalculator::calculateVolumetric()
{

}

void HeatingValueCalculator::calculateMass()
{

}
