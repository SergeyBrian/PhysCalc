#include "datastorage.h"
#include "../exceptions/dataexceptions.h"

DataStorage::DataStorage()
{
}

DataStorage::~DataStorage()
{
    qDeleteAll(variables);
    variables.clear();
}

void DataStorage::setValue(QString key, double value)
{
    variables[key] = value;
}

double DataStorage::getValue(QString key)
{
    if (!hasKey(key))
    {
        throw new KeyNotFoundException(key);
    }
    return variables[key];
}

bool DataStorage::hasKey(QString key)
{
    return variables.contains(key);
}
