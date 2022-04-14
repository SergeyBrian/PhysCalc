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
    void addValue(std::string key, QVariant * value);
    QVariant * getValue(std::string key);
    template<typename T>
    T getValue(std::string key) {
        // TODO: Add real conversion ability check (e.g. string containing text becomes 0 after conversion to int)
        QVariant * result = this->getValue(key);
        return result->value<T>();
    }
private:
    bool hasKey(std::string key);
    std::map<std::string, QVariant *> values;
};

#endif // DATASTORAGE_H
