// Template functions implementation

#include "datastorage.h"

template<typename T>
void DataStorage::addValue(QString key, QString name, QString description, Calculators::Calculator sourceCalculator) {
    Variable * var = new Variable(name, description, sourceCalculator);
    this->addValue(key, var);
}

template<typename T>
void DataStorage::setValue(QString key, T value) {
    Variable * var = this->getValue(key);
    var->value(value);
}

template<typename T>
void DataStorage::addValue(QString key, T value, QString name, QString description, VariableState state, Calculators::Calculator sourceCalculator) {
    Variable * var = new Variable(value, name, description, sourceCalculator, state);
    this->addValue(key, var);
}

template<typename T>
void DataStorage::writeValue(QString key, T value) {
    try {
        this->addValue(key, value);
    }  catch (DuplicateKeyException * e) {
        this->setValue(key, value);
    }
}

template<typename T>
T DataStorage::getValue(QString key) {
    return this->getValue(key)->value<T>();
}

