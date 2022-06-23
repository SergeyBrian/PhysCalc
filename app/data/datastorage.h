#ifndef DATASTORAGE_H
#define DATASTORAGE_H

#include <QMap>
#include <string>

class DataStorage
{
public:
    DataStorage();
    ~DataStorage();

    void addVariable(QString key, double value);
    void setVariableValue(QString key, double value);
    double getValue(QString key);
private:
    bool hasKey(QString key);
    QMap<QString, double> variables;
};

#endif // DATASTORAGE_H
