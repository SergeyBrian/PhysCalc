#ifndef TABLE_H
#define TABLE_H

#include <QVariant>

#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>

class Table
{
public:
    Table(QString tablename);
    Table(QString tablename, QString filename);

    ~Table();

    std::vector<QVariant *> getColumn(int columnNumber);
    std::vector<QVariant *> getColumn();

    std::vector<QVariant *> getRow(int rowNumber);
    std::vector<QVariant *> getRow();

    std::vector<std::vector<QVariant *>> getMatrix(int beginColumn, int beginRow, int endColumn, int endRow);
    std::vector<std::vector<QVariant *>> getMatrix();

    void writeColumn(std::vector<QVariant *> Column);
    void writeColumn(std::vector<QVariant *> Column, int columnNumber);
    void writeColumn(std::vector<QVariant *> Column, int columnNumber, int beginRow);

    void writeRow(std::vector<QVariant *> Row);
    void writeRow(std::vector<QVariant *> Row, int rowNumber);
    void writeRow(std::vector<QVariant *> Row, int rowNumber, int beginColumn);

    void writeCell(QVariant * value, int columnNumber, int rowNumber);

    QVariant * getCell(int columnNumber, int rowNumber);


private:
    QString tablename;
    QString filename;
};

#endif // TABLE_H
