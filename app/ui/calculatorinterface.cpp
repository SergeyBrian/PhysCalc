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

std::vector<QString> CalculatorInterface::getVariablesList(Calculators::Calculator c)
{
    std::vector<QString> list;
    switch (c)
    {
    case Calculators::EXCESS_AIR_RATIO:
        list = {
            "Q_l", "L_0", "k_cc", "e_cc", "t", "C_pmi_A", "C_pmi"
        };
        break;
    case Calculators::HEAT_CAPACITY:
        list = {
            "T", "R", "a", "L_0", "E_A", "H", "E"
        };
        break;
    case Calculators::HEATING_VALUE:
        list = {
            "n", "L_0"
        };
        break;
    case Calculators::STOICHIOMETRIC_RATIO:
        list = {
            "M"
        };
        break;
    }
    return list;
}
