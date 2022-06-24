#ifndef TABLE_H
#define TABLE_H

#include <QString>
#include <QStringList>
#include <QVector>
#include <QMap>
#include <QFile>

class Table
{
public:
    Table(QString filename);
    ~Table();
    QVector<double> getRow(int row);
    QVector<double> getColumn(int column);
    double getCell(int row, int column);

private:
    QString filename;
    QVector<QVector<double>> content;
    QVector<double> parse(QString line, char delimeter = ',');
};

#endif // TABLE_H
