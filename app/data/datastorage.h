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
    template<typename T>
    void addValue(QString key, T value, QString name, QString description, VariableState state = REQUIRED,
                  Calculators::Calculator sourceCalculator = Calculators::NONE);

    template<typename T>
    void addValue(QString key, QString name, QString description, Calculators::Calculator sourceCalculator = Calculators::NONE);

    template<typename T>
    void setValue(QString key, T value);

    Variable * getValue(QString key);

    double getValueDouble(QString key);

    bool hasKey(QString key);

    void setVariablesReplaceable(std::vector<QString> keys);

    int getGroupId(QString key);

    std::vector<QString> getKeysByGroupId(int groupId);

    double operator[] (QString key);
    void addValue(QString key, Variable * value);

private:
    int maxGroupId_;
    void setGroupId(QString key, int groupId);
    std::map<QString, std::pair<Variable *, int>> values;
};

#endif // DATASTORAGE_H
