#ifndef CALCULATORFACTORY_H
#define CALCULATORFACTORY_H

#include <QMetaType>

#include "calculators.h"
#include "../data/datastorage.h"

namespace CalculatorFactory
{
    Calculator * createCalculator(DataStorage * storage, Calculators::Calculator type);
};


#endif // CALCULATORFACTORY_H
