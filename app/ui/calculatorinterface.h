#ifndef CALCULATORINTERFACE_H
#define CALCULATORINTERFACE_H

#include <QDialog>

#include "../enums.h"

#include "heatcapacitywindow.h"
#include "heatingvaluewindow.h"
#include "excessairratiowindow.h"
#include "stoichiometricratiowindow.h"

#include "../calculator/calculatorfactory.h"

namespace DialogInterface {
    QDialog * create(Calculators::Calculator calculator);
}

namespace CalculatorInterface {
    double calculate(Calculators::Calculator c, DataStorage * storage);
}

#endif // CALCULATORINTERFACE_H
