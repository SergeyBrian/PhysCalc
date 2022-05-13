#include "calculatorinterface.h"

#include "../exceptions/calculatorexceptions.h"
#include "../exceptions/uiexceptions.h"

QDialog * DialogInterface::create(Calculators::Calculator c, DataStorage * storage) {
    return new CalculatorWindow(c, storage);
}

double CalculatorInterface::calculate(Calculators::Calculator c, DataStorage *storage)
{
    QDialog * dialog = DialogInterface::create(c, storage);
    Calculator * calculator = CalculatorFactory::createCalculator(storage, c);
    if (!dialog->exec()) {
        throw DialogCanceledException();
    }
    return calculator->calculate();
}

void CalculatorInterface::getValueFromOtherCalculator(Calculators::Calculator c, DataStorage *storage, QLineEdit *targetField)
{
    try {
        targetField->setText(QString::number(CalculatorInterface::calculate(c, storage)));
    } catch (DialogCanceledException) {
        qDebug("User canceled data receiving");
    }
}
