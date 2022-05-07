#ifndef TABLE_H
#define TABLE_H

#include <QVariant>

#include <string>
#include <vector>
#include <sstream>
#include <fstream>

class Table
{
public:
    Table(QString tablename);
    Table(QString tablename, QString filename);

    ~Table();

    std::vector<QVariant *> parse(std::string line, char delimiter = ',');
    std::vector<std::vector<QVariant *>> read();

    std::vector<QVariant *> getColumn(int columnNumber = 0);
    std::vector<QVariant *> getRow(int rowNumber = 0);

    std::vector<std::vector<QVariant *>> getMatrix(int beginColumn, int beginRow, int endColumn, int endRow);
    std::vector<std::vector<QVariant *>> getMatrix();

    void writeColumn(std::vector<QVariant *> Column, int columnNumber = 0, int beginRow = 0);
    void writeRow(std::vector<QVariant *> Row, int rowNumber = 0, int beginColumn = 0);
    void writeCell(QVariant * value, int columnNumber, int rowNumber);

    QVariant * getCell(int columnNumber, int rowNumber);


private:
    QString tablename;
    QString filename;
};

#endif // TABLE_H
