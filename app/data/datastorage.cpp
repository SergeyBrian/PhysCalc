#include "datastorage.h"
#include "../exceptions/dataexceptions.h"

DataStorage::DataStorage()
{

}

void DataStorage::addValue(std::string key, QVariant *value)
{
    if (this->values.find(key) != this->values.end()) {
        throw DuplicateKeyException(this, key);
    }
    this->values.insert({key, value});
}

QVariant * DataStorage::getValue(std::string key) {
    if (this->values.find(key) == this->values.end()) {
        throw KeyNotFoundException(this, key);
    }
    return this->values[key];
}
