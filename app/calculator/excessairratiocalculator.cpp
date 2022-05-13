#include "excessairratiocalculator.h"
#include "../exceptions/dataexceptions.h"

ExcessAirRatioCalculator::ExcessAirRatioCalculator(DataStorage * storage) : Calculator(storage)
{
}

double ExcessAirRatioCalculator::calculate()
{
    return ($("Q_l")*$("k_cc")-(1-$("L_0"))*$("C_pmi")*$("t")+$("L_0")*$("C_pmi_A")*$("t")+$("e_cc"))/($("L_0")*($("C_pmi_A")*$("t")-$("C_pmi_A")*$("t"))) ;
}
