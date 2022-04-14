#include "calculatortest.h"

CalculatorTest::CalculatorTest(QObject *parent) : QObject(parent)
{
}

void CalculatorTest::testHeatCapacityCalculatorFactory()
{
    DataStorage * storage = new DataStorage();
    storage->addValue("CURRENT_CALCULATOR", "HEAT_CAPACITY", "", "");
    Calculator * calc = CalculatorFactory::createCalculator(storage);
    delete storage;
    delete calc;
}

void CalculatorTest::testHeatingValueCalculatorFactory()
{
    DataStorage * storage = new DataStorage();
    storage->addValue("CURRENT_CALCULATOR", "HEATING_VALUE", "", "");
    Calculator * calc = CalculatorFactory::createCalculator(storage);
    delete storage;
    delete calc;
}


QTEST_MAIN(CalculatorTest)