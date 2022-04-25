#include "excessairratiocalculator.h"
#include "../exceptions/dataexceptions.h"

std::vector<QString> ExcessAirRatioCalculator::variableKeys = {};
std::vector<Variable *> ExcessAirRatioCalculator::variablePlaceholders = {};

ExcessAirRatioCalculator::ExcessAirRatioCalculator(DataStorage * storage) : Calculator(storage)
{
}

std::vector<QString> ExcessAirRatioCalculator::getRequiredVariablesList()
{
    for (unsigned int i = 0; i < variableKeys.size(); i++)
    {
        try {
            storage->addValue(variableKeys[i], variablePlaceholders[i]);
        }  catch (DataStorageException * exception) {
            if (DuplicateKeyException * e = static_cast<DuplicateKeyException *>(exception)) {
                qDebug() << e->what() << QString(" Key: ") << e->key;
            }
        }
    }
    return variableKeys;
}

double ExcessAirRatioCalculator::calculate()
{
    return ($("Q_l")*$("k_cc")-(1-$("L_0"))*$("C_pmi")*$("t")+$("L_0")*$("C_pmi_A")*$("t")+$("e_cc"))/($("L_0")*($("C_pmi_A")*$("t")-$("C_pmi_A")*$("t"))) ;
}
