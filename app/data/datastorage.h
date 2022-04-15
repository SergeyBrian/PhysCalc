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
    void addValue(QString key, Variable * value);
    template<typename T>
    void addValue(QString key, T value, QString name, QString description, QString sourceCalculator = "");

    Variable * getValue(QString key);
    template<typename T>
    T value(QString key);

    /*
     * This operator is supposed to be used in calculator algorithms
     * when many variable values are required for calculations, it's more
     * convenient to use [] operator to get them
     */
    double operator[] (QString key);
private:
    bool hasKey(QString key);
    std::map<QString, Variable *> values;
};

// Template functions implementation

template<typename T>
void DataStorage::addValue(QString key, T value, QString name, QString description, QString sourceCalculator) {
    Variable * var = new Variable(value, name, description, sourceCalculator);
    this->addValue(key, var);
}

template<typename T>
T DataStorage::value(QString key) {
    return this->getValue(key)->value<T>();
}

#endif // DATASTORAGE_H
