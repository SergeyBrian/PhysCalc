#include "table.h"

Table::Table(QString tablename, QString filename) : tablename(std::move(tablename))
{
    std::ifstream inputfile;
    inputfile.open(filename.toStdString());
    std::string line = "";

    while (getline(inputfile, line)) {

        lines.push_back(parse(line));
    }
}

Table::~Table()
{

}

std::vector<QVariant *> Table::parse(std::string line, char delimiter)
{
    std::vector<QVariant *> values;
    std::stringstream inLine(line);

    std::string tempColumn = "";
    while (getline(inLine, tempColumn, delimiter))
    {
        auto* temp = new QVariant(QString::fromStdString(tempColumn));
        values.push_back(temp);
    }
    return values;
}

std::vector<QVariant *> Table::getColumn(int columnNumber)
{
    std::vector<QVariant *> output;
    for(unsigned int i = 0; i < lines.size(); i++)
        output.push_back(lines[i][columnNumber]);

    return output;
}

std::vector<QVariant *> Table::getRow(int rowNumber)
{
    return lines[rowNumber];
}

//std::vector<std::vector<QVariant *> > Table::getMatrix(int beginColumn, int beginRow, int endColumn, int endRow)
//{
//    std::vector<std::vector<QVariant *>> output;
//    for(int i = beginRow; i <= endRow; i++)
//    {
//        for(int j = beginColumn; j <=  endColumn; j++)
//        {
//            output[i - beginRow].push_back(lines[i][j]);
//        }
//    }
//    return output;
//}

//std::vector<std::vector<QVariant *> > Table::getMatrix()
//{
//    return lines;
//}

void Table::writeColumn(std::vector<QVariant *> Column, int columnNumber, int beginRow)
{
    for(unsigned int i = beginRow; i < beginRow + Column.size(); i++)
    {
        lines[i].assign(columnNumber, Column[i - beginRow]);
    }
}

void Table::writeRow(std::vector<QVariant *> Row, int rowNumber, int beginColumn)
{
    for(unsigned int i = beginColumn; i < beginColumn + Row.size(); i++)
    {
        lines[rowNumber].assign(i, Row[i-beginColumn]);
    }
}

void Table::writeCell(QVariant *value, int columnNumber, int rowNumber)
{
    lines[rowNumber].assign(columnNumber, value);
}

QVariant *Table::getCell(int columnNumber, int rowNumber)
{
    QVariant *output = lines[rowNumber][columnNumber];
    return output;
}
