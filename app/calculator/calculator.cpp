#include "calculator.h"

Calculator::Calculator (DataStorage * storage)
{
    this->storage = storage;
}

double Calculator::$ (QString key)
{
    return (*storage)[key];
}
