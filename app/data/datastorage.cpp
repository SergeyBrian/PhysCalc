#include "datastorage.h"
#include "../exceptions/dataexceptions.h"

DataStorage::DataStorage()
{

}

void DataStorage::addValue(std::string key, QVariant *value)
{
    if (this->hasKey(key)) {
        throw DuplicateKeyException(this, key);
    }
    this->values.insert({key, value});
}

QVariant * DataStorage::getValue(std::string key) {
    if (!this->hasKey(key)) {
        throw KeyNotFoundException(this, key);
    }
    return this->values[key];
}

bool DataStorage::hasKey(std::string key)
{
    return this->values.find(key) != this->values.end();
}
