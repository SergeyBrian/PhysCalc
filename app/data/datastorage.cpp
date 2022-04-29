#include "datastorage.h"
#include "../exceptions/dataexceptions.h"

DataStorage::DataStorage()
{
    this->maxGroupId_ = 0;
}

void DataStorage::addValue(QString key, Variable *value)
{
    if (this->hasKey(key)) {
        throw DuplicateKeyException(this, key);
    }
    this->values.insert({key, {value, this->maxGroupId_}});
    this->maxGroupId_ ++;
}

int DataStorage::getGroupId(QString key)
{
    return this->values[key].second;
}

std::vector<QString> DataStorage::getKeysByGroupId(int groupId)
{
    std::vector<QString> keys;
    for (auto & variable : values) {
        int currentVariableGroupId = variable.second.second;
        if (currentVariableGroupId == groupId) {
            keys.push_back(variable.first);
        }
    }
    return keys;
}

void DataStorage::setGroupId(QString key, int groupId)
{
    this->values[key].second = groupId;
    this->values[key].first->setState(OPTIONAL);
}

double DataStorage::operator[] (QString key)
{
    return this->getValue<double>(key);
}

bool DataStorage::hasKey(QString key)
{
    return this->values.find(key) != this->values.end();
}

void DataStorage::setVariablesReplaceable(std::vector<QString> keys)
{
    int groupId = -1;
    for (auto & key : keys) {
        if (groupId == -1) {
            groupId = this->getGroupId(key);
            continue;
        }
        this->setGroupId(key, groupId);
    }
}

Variable *DataStorage::getValue(QString key)
{
    if (!this->hasKey(key)) {
        throw KeyNotFoundException(this, key);
    }
    return this->values[key].first;
}
