#ifndef CALCULATORTEST_H
#define CALCULATORTEST_H

#include <QObject>
#include <QtTest/QtTest>

#include "../calculatorfactory.h"

class CalculatorTest : public QObject
{
    Q_OBJECT
private slots:
    void testHeatCapacityCalculatorFactory();
    void testHeatingValueCalculatorFactory();



public:
    explicit CalculatorTest(QObject *parent = nullptr);

signals:

};

#endif // CALCULATORTEST_H
