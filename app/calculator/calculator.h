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
protected:
    double $(QString key);
    double $(QString key, double i);
    double $(QString key, int i);
};

#endif // CALCULATOR_H
