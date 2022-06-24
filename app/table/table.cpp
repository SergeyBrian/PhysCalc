#include "table.h"
#include "../exceptions/tableexceptions.h"

Table::Table(QString filename)
{
    QFile inputfile(filename);
    QString line;

    if (!inputfile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        throw new FileAccessFailedException(filename);
    }

    while (!inputfile.atEnd())
    {
        QString line = inputfile.readLine();
        this->content.push_back(parse(line));
    }
}

Table::~Table()
{

}

QVector<double> Table::parse(QString line, char delimeter)
{
    QVector<QString> result =  line.split(QLatin1Char(delimeter), Qt::SkipEmptyParts).toVector();
    return QVector<double> (result.begin(), result.end());
}

QVector<double> Table::getRow(int row)
{
    return content[row];
}

QVector<double> Table::getColumn(int column)
{
    QVector<double> result;
    for (const auto& row : content)
    {
        result.push_back(row[column]);
    }
    return result;
}

double Table::getCell(int row, int column)
{
    return content[row][column];
}
