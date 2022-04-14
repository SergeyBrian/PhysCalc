#include "datastorage.h"
#include "../exceptions/dataexceptions.h"

DataStorage::DataStorage()
{

}

void DataStorage::addValue(std::string key, Variable *value)
{
    if (this->hasKey(key)) {
        throw DuplicateKeyException(this, key);
    }
    this->values.insert({key, value});
}

bool DataStorage::hasKey(std::string key)
{
    return this->values.find(key) != this->values.end();
}
