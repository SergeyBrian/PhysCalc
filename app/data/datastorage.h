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
    void addValue(QString key, T value, QString name, QString description, VariableState state = REQUIRED, QString sourceCalculator = "");
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

#include "datastorage.inl"

#endif // DATASTORAGE_H
