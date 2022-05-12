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
    auto Q = storage->getValue<std::vector<double>>("C_l");
    auto C = storage->getValue<std::vector<double>>("C_v");

    if(storage->getValue("C_m")->isEmpty())
    {
        for(int i=1; i < Q.size(); i++)
        {
            double X;
            X=$("Q_l",i)*$("C_v",i);
            Q_vv+= X;
        }
    }
    else
    {
        for(int i=1; i < Q.size(); i++)
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
    auto Q = storage->getValue<std::vector<double>>("C_l");
    auto C = storage->getValue<std::vector<double>>("C_v");

    if(storage->getValue("C_m")->isEmpty())
        {
        for(int i=1; i < Q.size(); i++)
        {
            double X;
            X=$("Q_l",i)*$("C_v",i);
            Q_vv+= X;
        }
    }
    else
    {
        double M;
        for(int i=1; i < Q.size(); i++)
        {
            M=$("C_m",i)/$("M",i);
        }
        for(int i=1; i < Q.size(); i++)
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
