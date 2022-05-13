#ifndef CALCULATORINTERFACE_H
#define CALCULATORINTERFACE_H

#include <QDialog>
#include <QLineEdit>

#include "../enums.h"

#include "heatcapacitywindow.h"
#include "heatingvaluewindow.h"
#include "excessairratiowindow.h"
#include "stoichiometricratiowindow.h"
#include "calculatorwindow.h"

#include "../calculator/calculatorfactory.h"

namespace DialogInterface {
    QDialog * create(Calculators::Calculator calculator, DataStorage * storage);
}

namespace CalculatorInterface {
    double calculate(Calculators::Calculator c, DataStorage * storage);
    void  getValueFromOtherCalculator(Calculators::Calculator c, DataStorage * storage, QLineEdit * targetField);
}

#endif // CALCULATORINTERFACE_H
