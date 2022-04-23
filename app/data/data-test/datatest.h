#ifndef DATATEST_H
#define DATATEST_H

#include <QObject>
#include <QtTest/QtTest>

#include "../datastorage.h"

class DataTest : public QObject
{
    Q_OBJECT
private slots:
    void testAddValue();
    void testDuplicateKeyException();
    void testKeyNotFoundException();
    void testGetValue();

    void testVariableValue();
    void testVariableName();
    void testVariableDesc();
    void testVariableType();
    void testVariableStringValue();
    void testVariableWithSourceCalc();

    void testGetterOperatorOverload();

    void testConstVariable();
    void testSetVariableValue();

    void testNullInitializedVariable();

public:
    explicit DataTest(QObject *parent = nullptr);

signals:

};

#endif // DATATEST_H
