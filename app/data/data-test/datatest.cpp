#include "datatest.h"
#include "../../exceptions/dataexceptions.h"
#include "../../exceptions/variableexceptions.h"

DataTest::DataTest(QObject *parent) : QObject(parent)
{
}

void DataTest::testAddValue() {
    DataStorage * storage = new DataStorage();
    storage->addValue("v1", 1, "test", "test");
    storage->addValue("v2", 4.5, "test", "test");
    storage->addValue("v3", true, "test", "test");
    storage->addValue("v4", "test_string", "test", "test");

    QCOMPARE(storage->getValue<int>("v1"), 1);
    QCOMPARE(storage->getValue<double>("v2"), 4.5);
    QCOMPARE(storage->getValue<bool>("v3"), true);
    QCOMPARE(storage->getValue<QString>("v4"), "test_string");

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

void DataTest::testVariableWithSourceCalc()
{
    DataStorage * storage = new DataStorage();
    storage->addValue("v", (double)0, "var", "desc", REQUIRED, "HEAT_CAPACITY");
    Variable * var = storage->getValue("v");
    if (var->calc().isEmpty()) {
        QFAIL("Source calculator was not set");
    }
    delete storage;
}

void DataTest::testVariableType()
{
    Variable v((double)5, "test", "test value");
    QCOMPARE(v.type(), typeid(double).name());
}

void DataTest::testVariableStringValue()
{
    Variable v("test", "test name", "test desc");
    QCOMPARE(v.value<QString>(), "test");
}


void DataTest::testGetterOperatorOverload()
{
    DataStorage * storage = new DataStorage();
    storage->addValue("v", 14, "test", "test");
    DataStorage $ = (*storage);

    QCOMPARE($["v"], 14);
    delete storage;
}

void DataTest::testConstVariable()
{
    DataStorage * storage = new DataStorage();
    storage->addValue("v", 1, "test name", "test description", CONST);
    QVERIFY_EXCEPTION_THROWN(storage->setValue("v", 10), ConstVariableValueChangeException);
    delete storage;
}

void DataTest::testSetVariableValue()
{
    DataStorage * storage = new DataStorage();
    storage->addValue("v", 1, "test name", "test description");
    storage->setValue("v", 2);
    QCOMPARE(storage->getValue<int>("v"), 2);
    delete storage;
}

void DataTest::testNullInitializedVariable()
{
    DataStorage * storage = new DataStorage();
    storage->addValue<int>("v", "test name", "test description");
    storage->setValue("v", 4);
    QCOMPARE(storage->getValue<int>("v"), 4);
    delete storage;
}

void DataTest::testOptionalVariables()
{
    DataStorage * storage = new DataStorage();
    storage->addValue("v1", 1, "variable 1", "");
    storage->addValue("v2", 2, "variable 2", "");
    storage->addValue("v3", 3, "variable 3", "");
    storage->setVariablesReplaceable(std::vector<QString>{"v1", "v2"});
    int groupId = storage->getGroupId("v1");
    std::vector<QString> expectedResult = {"v1", "v2"};
    QCOMPARE(storage->getKeysByGroupId(groupId), expectedResult);
    delete storage;
}

QTEST_MAIN(DataTest)
