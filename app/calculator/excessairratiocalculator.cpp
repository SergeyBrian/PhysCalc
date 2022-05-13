#include "excessairratiocalculator.h"
#include "../exceptions/dataexceptions.h"

ExcessAirRatioCalculator::ExcessAirRatioCalculator(DataStorage * storage) : Calculator(storage)
{
    storage->addValue<double>("L_0", "L<sub>0</sub>", "Стехиометрическое отношение", Calculators::STOICHIOMETRIC_RATIO);
    storage->addValue<double>("Q_l", "Q<sup>н</sup>", "Низшая теплота сгорания топлива", Calculators::HEATING_VALUE);
    storage->addValue<double>("k_cc", "η<sub>к.с.</sub>", "Коэффициент полноты сгорания");
    storage->addValue<double>("e_cc", "h<sub>топ</sub>", "Энтальпия топлива");
    storage->addValue<double>("T_b", "T<sub>нач.</sub>", "Температура начала процесса");
    storage->addValue<double>("T_e", "T<sub>кон.</sub>", "Температура конца процесса");
    storage->addValue<double>("C_pmi_b", "C<sub>pmi(a=1)</sub>(T<sub>нач.</sub>)", "Теплоемкость продуктов сгорания в начале", Calculators::HEAT_CAPACITY);
    storage->addValue<double>("C_pms_A_e", "C<sub>pmВ</sub>(T<sub>кон.</sub>)", "Теплоемкость в конце", Calculators::HEAT_CAPACITY);
    storage->addValue<double>("C_pms_A_b", "C<sub>pmВ</sub>(T<sub>нач.</sub>)", "Теплоемкость в начале", Calculators::HEAT_CAPACITY);
}

double ExcessAirRatioCalculator::calculate()
{
    double L_0 = $("L_0");
    double Q_l = $("Q_l");
    double k_cc = $("k_cc");
    double e_cc = $("e_cc");
    double T_b = $("T_b");
    double T_e = $("T_e");
    double C_pmi_b = $("C_pmi_b");
    double C_pms_A_b = $("C_pms_A_b");
    double C_pms_A_e = $("C_pms_A_e");

    double result = (Q_l*k_cc - (1 + L_0)*C_pmi_b*T_e + L_0*C_pms_A_e*T_e + e_cc) /\
                    (L_0*C_pms_A_e*T_e - C_pms_A_b*T_b);

    storage->writeValue("a", result);
    return result;
}
