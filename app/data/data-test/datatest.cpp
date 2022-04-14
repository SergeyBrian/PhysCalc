#include "datatest.h"
#include "../../exceptions/dataexceptions.h"

DataTest::DataTest(QObject *parent) : QObject(parent)
{
}

void DataTest::testAddValue() {
    DataStorage * storage = new DataStorage();
    storage->addValue("v1", 1, "test", "test");
    storage->addValue("v2", 4.5, "test", "test");
    storage->addValue("v3", true, "test", "test");

    QCOMPARE(storage->getValue<int>("v1"), 1);
    QCOMPARE(storage->getValue<double>("v2"), 4.5);
    QCOMPARE(storage->getValue<bool>("v3"), true);

    delete storage;
}

void DataTest::testDuplicateKeyException()
{
    DataStorage * storage = new DataStorage();
    storage->addValue("v1", 3, "test", "test");

    QVERIFY_EXCEPTION_THROWN(storage->addValue("v1", 4, "test", "test"), DuplicateKeyException);

    delete storage;
}

void DataTest::testKeyNotFoundException()
{
    DataStorage * storage = new DataStorage();

    QVERIFY_EXCEPTION_THROWN(storage->getValue<int>("v"), KeyNotFoundException);

    delete storage;
}

void DataTest::testGetValue()
{
    DataStorage * storage = new DataStorage();

    storage->addValue("v1", 1, "test", "test");
    QCOMPARE(storage->getValue<int>("v1"), 1);

    delete storage;
}

void DataTest::testVariableValue()
{
    Variable v(4, "test", "test value");
    QCOMPARE(v.value<int>(), 4);
}

void DataTest::testVariableName()
{
    Variable v(4, "test", "test value");
    QCOMPARE(v.name(), "test");
}

void DataTest::testVariableDesc()
{
    Variable v(4, "test", "test value");
    QCOMPARE(v.desc(), "test value");
}

void DataTest::testVariableStringValue()
{
    Variable v("test", "test name", "test desc");
    QCOMPARE(v.value<QString>(), "test");
}

QTEST_MAIN(DataTest)
