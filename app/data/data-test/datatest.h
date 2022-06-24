#ifndef DATATEST_H
#define DATATEST_H

#include <QObject>
#include <QtTest/QtTest>

#include "../datastorage.h"

class DataTest : public QObject
{
    Q_OBJECT
private slots:
    void testSetVariableValue();
    void testKeyNotFoundException();
    void testGetValue();
public:
    explicit DataTest(QObject *parent = nullptr);

signals:

};

#endif // DATATEST_H
