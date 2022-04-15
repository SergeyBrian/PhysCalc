#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QDebug>

#include "../data/datastorage.h"
#include "../table/tablemanager.h"

class Calculator
{
public:
    Calculator(DataStorage * storage);
    DataStorage * storage;
    virtual double calculate() = 0;
    virtual std::vector<QString> getRequiredVariablesList() = 0;
protected:
    double $(QString key);
};

#endif // CALCULATOR_H
