#include "excessairratiocalculator.h"
#include "../exceptions/dataexceptions.h"

ExcessAirRatioCalculator::ExcessAirRatioCalculator(DataStorage * storage) : Calculator(storage)
{
}

double ExcessAirRatioCalculator::calculate()
{
    double L_0 = $("L_0");
    double Q_l = $("Q_l");
    double E = $("E");
    double e_cc = $("e_cc");
    double T_b = $("T_b");
    double T_e = $("T_e");
    double C_pmi_b = $("C_pmi_b");
    double C_pms_A_b = $("C_pms_A_b");
    double C_pms_A_e = $("C_pms_A_e");

    double result = (Q_l*E - (1 + L_0)*C_pmi_b*T_e + L_0*C_pms_A_e*T_e + e_cc) /\
                    (L_0*C_pms_A_e*T_e - C_pms_A_b*T_b);

    storage->writeValue("a", result);
    return result;
}
