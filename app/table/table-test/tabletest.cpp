#include "tabletest.h"
#include "../../exceptions/dataexceptions.h"

std::vector<QVariant *> TableTest::test_first_column {new QVariant(1), new QVariant(4), new QVariant(7)};
std::vector<QVariant *> TableTest::test_second_column {new QVariant(2), new QVariant(5), new QVariant(8)};
std::vector<QVariant *> TableTest::test_first_row {new QVariant(1), new QVariant(2), new QVariant(3)};
std::vector<QVariant *> TableTest::test_second_row {new QVariant(4), new QVariant(5), new QVariant(6)};

std::vector<std::vector<QVariant *>> TableTest::test_full_matrix {{new QVariant(1), new QVariant(2), new QVariant(3)},
                                                                  {new QVariant(4), new QVariant(5), new QVariant(6)},
                                                                  {new QVariant(7), new QVariant(8), new QVariant(9)}};
std::vector<std::vector<QVariant *>> TableTest::test_small_matrix {{new QVariant(5), new QVariant(6)},
                                                                   {new QVariant(8), new QVariant(9)}};
QVariant * TableTest::test_cell = new QVariant(5);

void TableTest::testOpenTable()
{
    this->table = new Table("test_table", "table.csv");
}

void TableTest::testGetColumn()
{
    std::vector<QVariant *> column;
    column = table->getColumn();
    QCOMPARE(column, TableTest::test_first_column);
}

void TableTest::testGetColumnByNumber()
{
    std::vector<QVariant *> column;
    column = table->getColumn(1);
    QCOMPARE(column, TableTest::test_second_column);
}

void TableTest::testGetRow()
{
    std::vector<QVariant *> row;
    row = table->getRow();
    QCOMPARE(row, TableTest::test_first_row);
}

void TableTest::testGetRowByNumber()
{
    std::vector<QVariant *> row;
    row = table->getRow(1);
    QCOMPARE(row, TableTest::test_second_row);

}

void TableTest::testGetFullMatrix()
{
    std::vector<std::vector<QVariant *>> matrix;
    matrix = table->getMatrix();
    QCOMPARE(matrix, TableTest::test_full_matrix);
}

void TableTest::testGetMatrix()
{
    std::vector<std::vector<QVariant *>> matrix;
    matrix = table->getMatrix(1, 1, 2, 2);
    QCOMPARE(matrix, TableTest::test_small_matrix);

}

void TableTest::testGetCell()
{
    QVariant * cell;
    cell = table->getCell(1, 1);
    QCOMPARE(cell, TableTest::test_cell);
}

void TableTest::testWriteColumn()
{

}

void TableTest::testWriteRow()
{

}

void TableTest::testWriteCell()
{
}

TableTest::TableTest(QObject *parent) : QObject(parent)
{
}


QTEST_MAIN(TableTest)
