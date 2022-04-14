#ifndef DATASTORAGE_H
#define DATASTORAGE_H

#include <QVariant>

#include <map>
#include <string>

#include "variable.h"


class DataStorage
{
public:
    DataStorage();
    void addValue(std::string key, Variable * value);
    template<typename T>
    void addValue(std::string key, T value, std::string name, std::string description);

    template<typename T>
    T getValue(std::string key);
private:
    bool hasKey(std::string key);
    std::map<std::string, Variable *> values;
};

// Template functions implementation

template<typename T>
void DataStorage::addValue(std::string key, T value, std::string name, std::string description)
{
    Variable * var = new Variable(value, name, description);
    this->addValue(key, var);
}

template<typename T>
T DataStorage::getValue(std::string key) {
    if (!this->hasKey(key)) {
        throw KeyNotFoundException(this, key);
    }
    return this->values[key]->value<T>();
}

#endif // DATASTORAGE_H
