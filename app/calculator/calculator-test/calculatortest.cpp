#include "calculatortest.h"

#include "../../exceptions/calculatorexceptions.h"

CalculatorTest::CalculatorTest(QObject *parent) : QObject(parent)
{
}

void CalculatorTest::testHeatCapacityCalculatorFactory()
{
    DataStorage * storage = new DataStorage();
    Calculator * calc = CalculatorFactory::createCalculator(storage, Calculators::HEAT_CAPACITY);
    delete storage;
    delete calc;
}

void CalculatorTest::testHeatingValueCalculatorFactory()
{
    DataStorage * storage = new DataStorage();
    Calculator * calc = CalculatorFactory::createCalculator(storage, Calculators::HEATING_VALUE);
    delete storage;
    delete calc;
}

void CalculatorTest::testCalculatorNotFoundException()
{
    DataStorage * storage = new DataStorage();
    QVERIFY_EXCEPTION_THROWN(CalculatorFactory::createCalculator(storage, Calculators::NONE), NoneTypeCalculatorException);
}


QTEST_MAIN(CalculatorTest)
