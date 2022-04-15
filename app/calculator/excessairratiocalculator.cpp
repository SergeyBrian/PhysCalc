#include "excessairratiocalculator.h"
#include "../exceptions/dataexceptions.h"

std::vector<QString> ExcessAirRatioCalculator::variableKeys = {};
std::vector<Variable *> ExcessAirRatioCalculator::variablePlaceholders = {};

ExcessAirRatioCalculator::ExcessAirRatioCalculator(DataStorage * storage) : Calculator(storage)
{
}

std::vector<QString> ExcessAirRatioCalculator::getRequiredVariablesList()
{
    for (int i = 0; i < variableKeys.size(); i++)
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
    return 0;
}
