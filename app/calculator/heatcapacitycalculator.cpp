#include "heatcapacitycalculator.h"
#include "../exceptions/dataexceptions.h"
#include <cmath>

HeatCapacityCalculator::HeatCapacityCalculator(DataStorage * storage) : Calculator(storage)
{
}
void HeatCapacityCalculator::R_smesi(){
    storage->writeValue("R",(   ( (($("a")-1)*$("L_0")*$("R_a"))/(1+$("a")*$("L_0"))   )+( ((1+$("L_0"))*$("R_g"))/(1+$("a")*$("L_0"))     )  ));

}
void HeatCapacityCalculator::T_szh()
{
    if($("T_e")==0){
        storage->writeValue("T_e",($("T_b")-$("T_b")*(pow((3,14),( ($("R_a") )/(calculateByTempHelp() ) ))-1 )*(1/$("E"))));
       }

    else
    {
        storage->writeValue("T_e",($("T_b")-$("T_b")*(pow((3,14),( ($("R_a") )/(calculateC_pmsHelp() ) ))-1 )*(1/$("E"))));


    }
    storage->writeValue("C_p_b",((($("H"))/($("E")))/(($("T_e"))-$("T_b"))));

}
void HeatCapacityCalculator::T_rassh()
{
    storage->writeValue("R",(   ( (($("a")-1)*$("L_0")*$("R_a"))/(1+$("a")*$("L_0"))   )+( ((1+$("L_0"))*$("R_g"))/(1+$("a")*$("L_0"))     )  ));
    if($("T_e")==0){
        storage->writeValue("T_e",($("T_b")-$("T_b")*(1-pow((3,14),( ($("R") )/(calculateByTempHelp() ) )) )*($("E"))));

    }
    else{
       storage->writeValue("T_e",($("T_b")-$("T_b")*(1-pow((3,14),( ($("R") )/(calculateC_pmsHelp()) ) )) )*($("E")));
    }
    storage->writeValue("C_p_b",((($("H"))*($("E")))/(($("T_b"))-$("T_e"))));
}
void HeatCapacityCalculator::end_szh()
{

    T_szh();
    double h=0;
    double k=$("C_p_b");
    while(true)
    {
       T_szh();
       h=($("C_p_b"));
       if(std::min(k,h)/std::max(k,h)<0.01){
           break;
    }

    }
}
void HeatCapacityCalculator::end_rassh()
{
    T_rassh();
    double h=0;
    double k=$("C_p_b");
    while(true)
    {
       T_rassh();
       h=($("C_p_b"));
       if(std::min(k,h)/std::max(k,h)<0.01){
           break;
    }

    }
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
