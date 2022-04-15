#include "heatcapacitycalculator.h"
#include "../exceptions/dataexceptions.h"

std::vector<QString> HeatCapacityCalculator::variableKeys = {};
std::vector<Variable *> HeatCapacityCalculator::variablePlaceholders = {};

HeatCapacityCalculator::HeatCapacityCalculator(DataStorage * storage) : Calculator(storage)
{
}

std::vector<QString> HeatCapacityCalculator::getRequiredVariablesList()
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

double HeatCapacityCalculator::calculate()
{
    return 0;
}
