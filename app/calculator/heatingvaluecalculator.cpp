#include "heatingvaluecalculator.h"
#include "../exceptions/dataexceptions.h"

std::vector<QString> HeatingValueCalculator::variableKeys = {};
std::vector<Variable *> HeatingValueCalculator::variablePlaceholders = {};

HeatingValueCalculator::HeatingValueCalculator(DataStorage * storage) : Calculator(storage)
{
}

std::vector<QString> HeatingValueCalculator::getRequiredVariablesList()
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

double HeatingValueCalculator::calculate()
{
    return 0;
}
