#include "calculatortest.h"

CalculatorTest::CalculatorTest(QObject *parent) : QObject(parent)
{
}

void CalculatorTest::testHeatCapacityCalculatorFactory() {
    CalculatorFactory * heatCapacityCalculatorFactory = CalculatorFactory::getFactory();
    QCOMPARE(heatCapacityCalculatorFactory->createCalculator(), new HeatCapacityCalculator());
    delete heatCapacityCalculatorFactory;
}

void CalculatorTest::testHeatingValueCalculatorFactory() {
    CalculatorFactory * heatingValueCalculatorFactory = CalculatorFactory::getFactory();
    QCOMPARE(heatingValueCalculatorFactory->createCalculator(), new HeatingValueCalculator());
    delete heatingValueCalculatorFactory;
}


QTEST_MAIN(CalculatorTest)
