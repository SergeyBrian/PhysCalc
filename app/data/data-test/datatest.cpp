#include "datatest.h"
#include "../../exceptions/dataexceptions.h"

DataTest::DataTest(QObject *parent) : QObject(parent)
{
}

void DataTest::testAddValue() {
    DataStorage * storage = new DataStorage();
    storage->addValue("v1", new QVariant(1));
    storage->addValue("v2", new QVariant(4.5));
    storage->addValue("v3", new QVariant(true));

    QCOMPARE(storage->getValue("v1")->toInt(), 1);
    QCOMPARE(storage->getValue("v2")->toDouble(), 4.5);
    QCOMPARE(storage->getValue("v3")->toBool(), true);

    delete storage;
}

void DataTest::testDuplicateKeyException()
{
    DataStorage * storage = new DataStorage();
    storage->addValue("v1", new QVariant(3));

    QVERIFY_EXCEPTION_THROWN(storage->addValue("v1", new QVariant(4)), DuplicateKeyException);

    delete storage;
}

void DataTest::testKeyNotFoundException()
{
    DataStorage * storage = new DataStorage();

    QVERIFY_EXCEPTION_THROWN(storage->getValue("v"), KeyNotFoundException);

    delete storage;
}

QTEST_MAIN(DataTest)
