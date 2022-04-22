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
    void addValue(QString key, T value, QString name, QString description, VariableState state = VARIABLE, QString sourceCalculator = "");
    template<typename T>
    void setValue(QString key, T valule);

    Variable * getValue(QString key);
    template<typename T>
    T value(QString key);

    double operator[] (QString key);
private:
    bool hasKey(QString key);
    std::map<QString, Variable *> values;
};

// Template functions implementation

template<typename T>
void DataStorage::setValue(QString key, T value) {
    Variable * var = this->getValue(key);
    var->value(value);
}

template<typename T>
void DataStorage::addValue(QString key, T value, QString name, QString description, VariableState state, QString sourceCalculator) {
    Variable * var = new Variable(value, name, description, sourceCalculator, state);
    this->addValue(key, var);
}

template<typename T>
T DataStorage::value(QString key) {
    return this->getValue(key)->value<T>();
}

#endif // DATASTORAGE_H
