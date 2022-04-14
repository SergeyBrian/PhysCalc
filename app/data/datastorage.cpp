#include "datastorage.h"
#include "../exceptions/dataexceptions.h"

DataStorage::DataStorage()
{

}

void DataStorage::addValue(QString key, Variable *value)
{
    if (this->hasKey(key)) {
        throw DuplicateKeyException(this, key);
    }
    this->values.insert({key, value});
}

double DataStorage::operator[] (QString key)
{
    return this->value<double>(key);
}

bool DataStorage::hasKey(QString key)
{
    return this->values.find(key) != this->values.end();
}

Variable *DataStorage::getValue(QString key)
{
    if (!this->hasKey(key)) {
        throw KeyNotFoundException(this, key);
    }
    return this->values[key];
}
