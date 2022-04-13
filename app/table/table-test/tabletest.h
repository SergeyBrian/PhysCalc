#ifndef DATATEST_H
#define DATATEST_H

#include <QObject>
#include <QtTest/QtTest>

#include "../table.h"

class TableTest : public QObject
{
    Q_OBJECT
private slots:
    void testOpenTable();
    void testGetColumn();
    void testGetColumnByNumber();
    void testGetRow();
    void testGetRowByNumber();
    void testGetFullMatrix();
    void testGetMatrix();
    void testGetCell();

    void testWriteColumn();
    void testWriteRow();
    void testWriteCell();

private:
    Table * table;
    static std::vector<QVariant *> test_first_column;
    static std::vector<QVariant *> test_second_column;
    static std::vector<QVariant *> test_first_row;
    static std::vector<QVariant *> test_second_row;
    static std::vector<std::vector<QVariant *>> test_full_matrix;
    static std::vector<std::vector<QVariant *>> test_small_matrix;
    static QVariant * test_cell;

public:
    explicit TableTest (QObject *parent = nullptr);

signals:

};

#endif // DATATEST_H
