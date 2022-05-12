#include "calculator.h"

Calculator::Calculator (DataStorage * storage)
{
    this->storage = storage;
}

double Calculator::$ (QString key)
{
    return (*storage)[key];
}

double Calculator::$ (QString key, double i)
{
    return storage->getValue<QMap<double, double>>(key)[i];
}

double Calculator::$ (QString key, int i)
{
    return storage->getValue<QVector<double>>(key)[i];
}
