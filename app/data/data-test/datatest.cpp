#include "datatest.h"
#include "../../exceptions/dataexceptions.h"

DataTest::DataTest(QObject *parent) : QObject(parent)
{
}

void DataTest::testSetVariableValue()
{
    DataStorage * storage = new DataStorage();
    storage->setValue("v", 2);
    QCOMPARE(storage->getValue("v"), 2);
    delete storage;
}

void DataTest::testGetValue()
{
    DataStorage * storage = new DataStorage();

    storage->setValue("v1", 1);
    QCOMPARE(storage->getValue("v1"), 1);

    delete storage;
}

void DataTest::testKeyNotFoundException()
{
    DataStorage * storage = new DataStorage();
    QVERIFY_EXCEPTION_THROWN(storage->getValue("v"), KeyNotFoundException);

}


QTEST_MAIN(DataTest)
